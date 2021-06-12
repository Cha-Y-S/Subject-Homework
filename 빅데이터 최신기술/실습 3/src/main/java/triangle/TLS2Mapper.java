package triangle;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

import java.io.IOException;
import java.util.StringTokenizer;

public class TLS2Mapper extends Mapper<Object, Text, Text, IntWritable> {

	Text ok = new Text();
	IntWritable ov = new IntWritable();
	IntWritable negOne = new IntWritable(-1);

	@Override
	protected void map(Object key, Text value, Context context) throws IOException, InterruptedException {
		StringTokenizer st = new StringTokenizer(value.toString());

		int u = Integer.parseInt(st.nextToken());
		int v = Integer.parseInt(st.nextToken());

		if(st.hasMoreTokens()){	// wedge
			int w = Integer.parseInt(st.nextToken());
			ok.set(u + "\t" + v);
			ov.set(w);
			context.write(ok, ov);
		} else {	// edge
			ok.set(u < v ?  u + "\t" + v : v + "\t" + u);
			context.write(ok, negOne);
		}
	}
}
