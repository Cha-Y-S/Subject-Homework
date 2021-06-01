package seoul.p4;

import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;

import java.io.IOException;
import java.util.StringTokenizer;

public class P4Reducer extends Reducer<Text, Text, Text, Text> {

	Text ok = new Text();
	Text ov = new Text();

	@Override
	protected void reduce(Text key, Iterable<Text> values, Context context) throws IOException, InterruptedException {

		double sumSO2 = 0, sumNO2 = 0, sumCO = 0, sumO3 = 0, sumPM10 = 0, sumPM2d5 = 0;
		int cntSO2 = 0, cntNO2 = 0, cntCO = 0, cntO3 = 0, cntPM10 = 0, cntPM2d5 = 0;

		for(Text t : values){
			StringTokenizer st = new StringTokenizer(t.toString());

			Integer itemCode = Integer.parseInt(st.nextToken());
			Double itemValue = Double.parseDouble(st.nextToken());
			switch(itemCode){
				case 1:
					sumSO2 += itemValue;
					cntSO2++;
					break;
				case 3:
					sumNO2 += itemValue;
					cntNO2++;
					break;
				case 5:
					sumCO += itemValue;
					cntCO++;
					break;
				case 6:
					sumO3 += itemValue;
					cntO3++;
					break;
				case 8:
					sumPM10 += itemValue;
					cntPM10++;
					break;
				case 9:
					sumPM2d5 += itemValue;
					cntPM2d5++;
					break;
			}
		}
		Double avgSO2 = new Double(sumSO2 / cntSO2);
		Double avgNO2 = new Double(sumNO2 / cntNO2);
		Double avgCO = new Double(sumCO / cntCO);
		Double avgO3 = new Double(sumO3 / cntO3);
		Double avgPM10 = new Double(sumPM10 / cntPM10);
		Double avgPM2d5 = new Double(sumPM2d5 / cntPM2d5);

		String ovString = "<" + "SO2: " + avgSO2.toString() + ", NO2: " + avgNO2.toString() + ", CO: " + avgCO + ", O3: " + avgO3.toString() + ", PM10: " + avgPM10.toString() + ", PM2.5: " + avgPM2d5.toString() + ">";

		ov.set(ovString);

		context.write(key, ov);

	}
}
