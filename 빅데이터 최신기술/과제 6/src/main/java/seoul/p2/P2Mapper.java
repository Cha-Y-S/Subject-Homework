package seoul.p2;

import org.apache.hadoop.io.DoubleWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

import java.io.IOException;
import java.util.StringTokenizer;

public class P2Mapper extends Mapper<Object, Text, Text, Text> {
	// arg1: Map Input Key type
	// arg2: Map Input Value type
	// arg3: Map Output Key type
	// arg4: Map Output Value type

	Text ok = new Text();
	Text ov = new Text();

	@Override
	protected void map(Object key, Text value, Context context) throws IOException, InterruptedException {

		// 2017-01-01 00:00, 101, 1, 0.004, 0
		// value.toString().split()
		StringTokenizer st = new StringTokenizer(value.toString(), ",");

		// set Key
		String dateCode = st.nextToken();												// 2017-01-01 00:00
		String stationCode = st.nextToken();	// 101
		Integer itemCode = Integer.parseInt(st.nextToken());

		// itemCode == 8 -> PM10, itemCode == 9 -> PM2.5
		if(itemCode != 8 && itemCode != 9) return;

		// Set Value
		Double itemValue = Double.parseDouble(st.nextToken());	// 0.004
		switch(itemCode){
			case 8:
				if(!(itemValue <= 30 && itemValue >= 0)) return;
				break;
			case 9:
				if(!(itemValue <= 15 && itemValue >= 0)) return;
				break;
		}

		String statusCode = st.nextToken();		// 0
		if(Integer.parseInt(statusCode) != 0) return;	// statusCode == 0 -> normal data

		ok.set(stationCode);

		ov.set(dateCode + "," + itemCode + "," + itemValue);

		// emit
		context.write(ok, ov);
	}
}
