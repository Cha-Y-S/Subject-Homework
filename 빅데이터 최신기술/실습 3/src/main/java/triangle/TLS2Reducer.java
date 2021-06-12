package triangle;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;

import java.io.IOException;
import java.util.ArrayList;

public class TLS2Reducer extends Reducer<Text, IntWritable, Text, IntWritable> {

	IntWritable ov = new IntWritable();

	@Override
	protected void reduce(Text key, Iterable<IntWritable> values, Context context) throws IOException, InterruptedException {
		ArrayList<Integer> nodes = new ArrayList<Integer>();
		Boolean hasNegOne = false;

		for(IntWritable v: values){
			if(v.get() ==  - 1){
				hasNegOne = true;
			} else {
				nodes.add(v.get());
			}
		}

		if(hasNegOne) {
			for(int n : nodes){
				ov.set(n);
				context.write(key, ov);
			}
		}
	}
}
