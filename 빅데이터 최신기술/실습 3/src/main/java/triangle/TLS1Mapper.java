package triangle;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

import java.io.IOException;
import java.util.StringTokenizer;

public class TLS1Mapper extends Mapper<Object, Text, IntWritable, IntWritable> {

	IntWritable ou = new IntWritable();
	IntWritable ov = new IntWritable();


	@Override
	protected void map(Object key, Text value, Context context) throws IOException, InterruptedException {
		StringTokenizer st = new StringTokenizer(value.toString());

		ou.set(Integer.parseInt(st.nextToken()));
		ov.set(Integer.parseInt(st.nextToken()));

		if(ou.get() < ov.get())
			context.write(ou, ov);
		else
			context.write(ov, ou);

	}
}
