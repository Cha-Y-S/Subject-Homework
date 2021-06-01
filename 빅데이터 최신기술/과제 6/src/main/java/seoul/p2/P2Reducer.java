package seoul.p2;

import org.apache.hadoop.io.DoubleWritable;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;

import java.io.IOException;
import java.util.StringTokenizer;

public class P2Reducer extends Reducer<Text, DoubleWritable, Text, IntWritable> {

	Text ok = new Text();
	IntWritable ov = new IntWritable();

	@Override
	protected void reduce(Text key, Iterable<DoubleWritable> values, Context context) throws IOException, InterruptedException {

		StringTokenizer st = new StringTokenizer(key.toString());
		String stationCode = st.nextToken();
		Integer itemCode = Integer.parseInt(st.nextToken());
		String itemName = itemCode == 8 ? "PM10" : "PM2.5";

		ok.set(stationCode + "\t" + itemName);

		int cnt = 0;

		for(DoubleWritable d: values){
			double itemValue = d.get();
			if(itemCode == 8){
				if(itemValue > 0 && itemValue <= 30) cnt++;
			} else {
				if(itemValue > 0 && itemValue <= 15) cnt++;
			}
		}

		// set Output Format
		ov.set(cnt);

		// emit
		context.write(ok, ov);
	}
}
