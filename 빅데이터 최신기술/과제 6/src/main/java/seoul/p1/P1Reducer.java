package seoul.p1;

import org.apache.hadoop.io.DoubleWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;

import java.io.IOException;

public class P1Reducer extends Reducer<Text, DoubleWritable, Text, Text> {

	Text ov = new Text();

	@Override
	protected void reduce(Text key, Iterable<DoubleWritable> values, Context context) throws IOException, InterruptedException {

		double min = Double.POSITIVE_INFINITY;
		double max = Double.NEGATIVE_INFINITY;

		// set Value(average)
		double sum = 0;
		int cnt = 0;
		for(DoubleWritable d: values){

			double v = d.get();

			if(v < min) min = v;
			if(max < v) max = v;

			sum += v;
			cnt += 1;
		}

		double avg = sum / cnt;

		// set Output Format
		ov.set(avg + "\t" + max + "\t" + min);

		// emit
		context.write(key, ov);
	}
}
