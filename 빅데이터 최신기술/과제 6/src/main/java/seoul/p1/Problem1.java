package seoul.p1;

import org.apache.hadoop.conf.Configured;
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

public class Problem1 extends Configured implements Tool {

	public static void main(String[] args) throws Exception {
		ToolRunner.run(new Problem1(), args);
	}

	@Override
	public int run(String[] args) throws Exception {
		// Execution in Master Node

		String inputPath = args[0];
		String outputPath = args[0] + "_p1" + ".out";

		// 1. Create Job
		Job job = Job.getInstance(getConf());
		job.setJarByClass(Problem1.class);

		// 2. Setting Mapper
		job.setMapperClass(P1Mapper.class);

		// 3. Setting Reducer
		job.setReducerClass(P1Reducer.class);

		// 4. Setting Mapper Output Key Class
		job.setMapOutputKeyClass(Text.class);
		job.setMapOutputValueClass(DoubleWritable.class);

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
