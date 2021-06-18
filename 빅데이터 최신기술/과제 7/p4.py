from pyspark import SparkConf, SparkContext

conf = SparkConf().setAppName("p4")
sc = SparkContext(conf=conf)

# Load Dataset
#data = sc.textFile("graph_sample.txt")
data = sc.textFile("com-amazon.ungraph.txt")

# Create Edges
# [((0, 1), -1), ((0, 2), -1), ((0, 3), -1), ((1, 2), -1), ((1, 3), -1), ((2, 3), -1), ((3, 4), -1)]
edges = data.map(lambda line: (tuple(map(int, line.split("\t"))), -1))  # [((0, 1),-1), ((0, 2),-1),...]

# Create Wedges
# [((1, 2), 0), ((1, 3), 0), ((2, 3), 0), ((2, 3), 1)]
wedges = data.map(lambda line: tuple(map(int, line.split("\t")))).groupByKey().map(lambda x: [((v1,v2), x[0]) for v1 in x[1] for v2 in x[1] if v1 < v2]).flatMap(lambda x : x)

# Get Triangles
# [((1, 2), (0, -1)), ((2, 3), (0, -1)), ((2, 3), (1, -1)), ((1, 3), (0, -1))]
triangle = wedges.join(edges)

# Get Node's Triangle Count
node_triangle = triangle.flatMap(lambda x: x).flatMap(lambda x:x).filter(lambda x: x!= -1).map(lambda x: (x, 1)).reduceByKey(lambda x,y: x+y).sortByKey()

# Get Node's Degree
degree = data.map(lambda line: tuple(map(int, line.split("\t")))).flatMap(lambda x: x).map(lambda x: (x, 1)).reduceByKey(lambda x,y: x+y).sortByKey()

# Calculate Each Node's Clustering Coefficient
# x[0]: Node Number   x[1][0]: Count of Node's Triangle   x[1][1]: Degree of Node
# result format: (C.C, Node's Number)
clustering_coefficient = node_triangle.join(degree).map(lambda x: (x[1][0] / ((x[1][1] * (x[1][1] - 1)) / 2), x[0])).sortByKey(False)

# Get Top 10 Node With Biggest CC
rank10 = sc.parallelize(clustering_coefficient.take(10))

# Save Node's Clustering Coefficient As Text File
rank10.saveAsTextFile("p4")