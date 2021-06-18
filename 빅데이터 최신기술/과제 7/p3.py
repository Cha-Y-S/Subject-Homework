from pyspark import SparkConf, SparkContext

conf = SparkConf().setAppName("p3")
sc = SparkContext(conf=conf)

# Load Dataset
#data = sc.textFile("graph_sample.txt")
data = sc.textFile("com-amazon.ungraph.txt")

# Get Node's Degree
degree = data.map(lambda line: tuple(map(int, line.split("\t")))).flatMap(lambda x: x).map(lambda x: (x, 1)).reduceByKey(lambda x,y: x+y).sortByKey()

# Save Node's Degree As Text File
degree.saveAsTextFile("p3")