package seoul.p1;

import org.apache.hadoop.io.DoubleWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

import java.io.IOException;
import java.util.StringTokenizer;


public class P1Mapper extends Mapper<Object, Text, Text, DoubleWritable> {
	// arg1: Map Input Key type
	// arg2: Map Input Value type
	// arg3: Map Output Key type
	// arg4: Map Output Value type

	Text ok = new Text();
	DoubleWritable ov = new DoubleWritable();

	@Override
	protected void map(Object key, Text value, Context context) throws IOException, InterruptedException {

		// 2017-01-01 00:00, 101, 1, 0.004, 0
		// value.toString().split()
		StringTokenizer st = new StringTokenizer(value.toString(), ",");

		// set Key
		st.nextToken();												// 2017-01-01 00:00
		String stationCode = st.nextToken();	// 101
		String itemCode = st.nextToken();			// 1

		// set Value
		double itemValue = Double.parseDouble(st.nextToken());	// 0.004

		String statusCode = st.nextToken();		// 0
		if(Integer.parseInt(statusCode) != 0) return;	// statusCode == 0 -> normal data
		if(Integer.parseInt(itemCode) != 8) return;	// itemCode == 8 -> PM10

		ok.set(stationCode + "\t" + itemCode);

		ov.set(itemValue);

		// emit
		context.write(ok, ov);
	}
}