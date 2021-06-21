from pyspark import SparkConf, SparkContext

conf = SparkConf().setAppName("p1")
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

# Save Total Triangle's Count As Text File
sc.parallelize([triangle.count()]).saveAsTextFile("p1")