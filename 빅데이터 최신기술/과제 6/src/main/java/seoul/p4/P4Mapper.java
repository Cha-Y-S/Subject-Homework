package seoul.p4;

import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

import java.io.IOException;
import java.util.StringTokenizer;

public class P4Mapper extends Mapper<Object, Text, Text, Text> {

	Text ok = new Text();
	Text ov = new Text();

	@Override
	protected void map(Object key, Text value, Context context) throws IOException, InterruptedException {
		StringTokenizer st = new StringTokenizer(value.toString(), ",");

		// 2017-01-01 00:00, 101, 1, 0.004, 0
		String dateCode = st.nextToken();		// 2017-01-01 00:00

		StringTokenizer st1 = new StringTokenizer(dateCode);

		st1.nextToken();										// 2017-01-01
		String timeCode = st1.nextToken();	// 00:00

		st.nextToken();											// 101
		String itemCode = st.nextToken();		// 1
		String itemValue = st.nextToken();	// 0.004

		// Process Only normal data
		Integer statusCode = Integer.parseInt(st.nextToken());
		if(statusCode != 0) return;

		ok.set(timeCode);

		ov.set(itemCode + "\t" + itemValue);

		context.write(ok, ov);

	}
}
