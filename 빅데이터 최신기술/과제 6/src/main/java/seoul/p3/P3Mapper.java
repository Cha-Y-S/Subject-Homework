package seoul.p3;

import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

import java.io.IOException;
import java.util.StringTokenizer;

public class P3Mapper extends Mapper<Object, Text, Text, Text> {

	Text ok = new Text();
	Text ov = new Text();

	@Override
	protected void map(Object key, Text value, Context context) throws IOException, InterruptedException {
		// 2017-01-01 00:00, 101, 1, 0.004, 0
		StringTokenizer st = new StringTokenizer(value.toString(), ",");

//		System.out.println(value.toString());

		// Set key
		String timeCode = st.nextToken();			// 2017-01-01 00:00
		String stationCode = st.nextToken();	// 101

//		System.out.println(timeCode + "\t" + stationCode);

		// Set Value
		String itemCode = st.nextToken();			// 1
		Double itemValue = Double.parseDouble(st.nextToken());	// 0.004

//		System.out.println(itemCode + ": " + itemValue.toString());

		// Process Only normal data
		String statusCode = st.nextToken();		// 0
		if(Integer.parseInt(statusCode) != 0) return;	// statusCode == 0 -> normal data

		ok.set(timeCode + "\t" + stationCode);

//		System.out.println(timeCode + "\t" + stationCode);

		ov.set(itemCode + ": " + itemValue.toString());

//		System.out.println(itemCode + ": " + itemValue.toString());

		// emit
		context.write(ok, ov);
	}
}
