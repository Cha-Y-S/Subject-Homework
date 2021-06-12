package triangle;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;

import java.io.IOException;
import java.util.ArrayList;

public class TLS1Reducer extends Reducer<IntWritable, IntWritable, Text, IntWritable> {

	Text ok = new Text();

	@Override
	protected void reduce(IntWritable key, Iterable<IntWritable> values, Context context) throws IOException, InterruptedException {
		// key: 1
		// values: 0, 2, 3

		ArrayList<Integer> nodes = new ArrayList<Integer>();

		for(IntWritable v: values)	nodes.add(v.get());

		for(int u : nodes) {
			for(int v: nodes) {
				if(u < v){
					ok.set(u + "\t" + v);
					context.write(ok, key);
				}
			}
		}

		/* output:
		 * (0, 2) 1
		 * (0, 3) 1
		 * (2, 3) 1
		 */
	}
}
