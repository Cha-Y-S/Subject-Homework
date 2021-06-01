package seoul.p3;

import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;

import java.io.IOException;
import java.util.StringTokenizer;

public class P3Reducer extends Reducer<Text, Text, Text, Text> {

	Text ov = new Text();

	@Override
	protected void reduce(Text key, Iterable<Text> values, Context context) throws IOException, InterruptedException {

		String ovString = "";
		String temp = "<";
		for(Text t : values){
//			temp = temp + t.toString() + ", ";
			StringTokenizer st = new StringTokenizer(t.toString(), ":");
			String itemName = "";
			int itemCode = Integer.parseInt(st.nextToken());
			switch(itemCode){
				case 1:
					itemName = "SO2";
					break;
				case 3:
					itemName = "NO2";
					break;
				case 5:
					itemName = "CO";
					break;
				case 6:
					itemName = "O3";
					break;
				case 8:
					itemName = "PM10";
					break;
				case 9:
					itemName = "PM2.5";
					break;
			}
			String itemValue = st.nextToken();
			temp += (itemName + ": " + itemValue + ", ");
		}

		ovString = temp.substring(0, temp.length()-2);
		ovString += ">";

//		System.out.println(ovString);
		ov.set(ovString);

		context.write(key, ov);

	}
}
