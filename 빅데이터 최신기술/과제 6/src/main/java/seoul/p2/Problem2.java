package seoul.p2;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.conf.Configured;
import org.apache.hadoop.fs.FileSystem;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.DoubleWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.input.TextInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.mapreduce.lib.output.TextOutputFormat;
import org.apache.hadoop.util.Tool;
import org.apache.hadoop.util.ToolRunner;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Problem2 extends Configured implements Tool {

	public static void main(String[] args) throws Exception {
		ToolRunner.run(new Problem2(), args);

		String inputPath = "data.csv_p2.out/part-r-0000";
		int i = 0;
		String line = "";
		String stationCode = "";
		Integer count = Integer.MIN_VALUE;

		while(i < 3){
			// Open HDFS's file
			String nInputPath = inputPath + i;
			Path inFile = new Path(nInputPath);
			FileSystem fs = FileSystem.get(new Configuration());
			BufferedReader br = new BufferedReader(new InputStreamReader(fs.open(inFile)));

			line = "";
			while(true){
				line = br.readLine();
				if(line == null) break;
				StringTokenizer st = new StringTokenizer(line);
				String tStationCode = st.nextToken();
				Integer tValue = Integer.parseInt(st.nextToken());

				if(count < tValue) {
					count = tValue;
					stationCode = tStationCode;
				}
			}
			i++;
		}
		System.out.println("공기질 \"좋음\"이 " + count + "번으로 가장 많이 출력된 지역 코드는 " + stationCode + "입니다.");
	}

	@Override
	public int run(String[] args) throws Exception {
		// Execution in Master Node

		String inputPath = args[0];
		String outputPath = args[0] + "_p2" + ".out";

		// 1. Create Job
		Job job = Job.getInstance(getConf());
		job.setJarByClass(Problem2.class);

		// 2. Setting Mapper
		job.setMapperClass(P2Mapper.class);

		// 3. Setting Reducer
		job.setReducerClass(P2Reducer.class);

		// 4. Setting Mapper Output Key Class
		job.setMapOutputKeyClass(Text.class);
		job.setMapOutputValueClass(Text.class);

		// 5. Setting Input & Output Format Class
		job.setInputFormatClass(TextInputFormat.class);
		job.setOutputFormatClass(TextOutputFormat.class);

		// 6. Setting Input & Output File's Path
		FileInputFormat.addInputPath(job, new Path(inputPath));
		FileOutputFormat.setOutputPath(job, new Path(outputPath));

		job.waitForCompletion(true);

		return 0;
	}
}
