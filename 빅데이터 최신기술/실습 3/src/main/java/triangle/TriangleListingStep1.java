package triangle;

import org.apache.hadoop.conf.Configured;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.input.TextInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.mapreduce.lib.output.TextOutputFormat;
import org.apache.hadoop.util.Tool;
import org.apache.hadoop.util.ToolRunner;

public class TriangleListingStep1 extends Configured implements Tool {

	public static void main(String[] args) throws Exception {
		ToolRunner.run(new TriangleListingStep1(), args);
	}

	@Override
	public int run(String[] args) throws Exception {

		String input = args[0];
		String output = input + ".wedge";

		Job job = Job.getInstance(getConf());
		job.setJarByClass(TriangleListingStep1.class);

		job.setMapperClass(TLS1Mapper.class);

		job.setReducerClass(TLS1Reducer.class);

		job.setMapOutputKeyClass(IntWritable.class);
		job.setMapOutputValueClass(IntWritable.class);

		job.setInputFormatClass(TextInputFormat.class);
		job.setOutputFormatClass(TextOutputFormat.class);

		FileInputFormat.addInputPath(job, new Path(input));
		FileOutputFormat.setOutputPath(job, new Path(output));

		job.waitForCompletion(false);

		return 0;
	}
}
