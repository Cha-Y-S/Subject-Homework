package wordcount;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

import java.io.IOException;
import java.util.StringTokenizer;


public class WCMapper extends Mapper<Object, Text, Text, IntWritable> {
	// arg1: Map Input Key type
	// arg2: Map Input Value type
	// arg3: Map Output Key type
	// arg4: Map Output Value type

	Text ok = new Text();
	IntWritable ov = new IntWritable(1);

	@Override
	protected void map(Object key, Text value, Mapper<Object, Text, Text, IntWritable>.Context context) throws IOException, InterruptedException {
		StringTokenizer st = new StringTokenizer(value.toString());

		while(st.hasMoreTokens()){
			String word = st.nextToken();
			ok.set(word);
			context.write(ok, ov);
		}
	}
}
