package triangle;

import org.apache.hadoop.conf.Configured;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.input.TextInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.mapreduce.lib.output.TextOutputFormat;
import org.apache.hadoop.util.Tool;
import org.apache.hadoop.util.ToolRunner;

public class TriangleListingStep2 extends Configured implements Tool {

	public static void main(String[] args) throws Exception {
		ToolRunner.run(new TriangleListingStep2(), args);
	}

	@Override
	public int run(String[] args) throws Exception {

		String input_edge = args[0];
		String input_wedge = args[1];
		String output = input_edge + ".out";

		Job job = Job.getInstance(getConf());
		job.setJarByClass(TriangleListingStep2.class);

		job.setMapperClass(TLS2Mapper.class);

		job.setReducerClass(TLS2Reducer.class);

		job.setMapOutputKeyClass(Text.class);
		job.setMapOutputValueClass(IntWritable.class);

		job.setInputFormatClass(TextInputFormat.class);
		job.setOutputFormatClass(TextOutputFormat.class);

		FileInputFormat.addInputPath(job, new Path(input_edge));
		FileInputFormat.addInputPath(job, new Path(input_wedge));
		FileOutputFormat.setOutputPath(job, new Path(output));

		job.waitForCompletion(false);

		return 0;
	}
}
