package seoul.p2;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;

import java.io.IOException;
import java.util.HashMap;
import java.util.StringTokenizer;

public class P2Reducer extends Reducer<Text, Text, Text, IntWritable> {

	Text ok = new Text();
	IntWritable ov = new IntWritable();

	@Override
	protected void reduce(Text key, Iterable<Text> values, Context context) throws IOException, InterruptedException {
		// 101
		String stationCode = key.toString();

		ok.set(stationCode);

		int cnt = 0;
		HashMap<String, Integer> airMap = new HashMap<String, Integer>();

		for(Text t: values){
			StringTokenizer st = new StringTokenizer(t.toString(), ",");
			String dateCode = st.nextToken();
			if(airMap.containsKey(dateCode)) cnt++;
			else airMap.put(dateCode, 1);
		}

		// set Output Format
		ov.set(cnt);

		// emit
		context.write(ok, ov);
	}
}
