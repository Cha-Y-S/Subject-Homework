package seoul.p2;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class P2Output {
	public static void main(String[] args) throws IOException {
		String inputPath = "src/data.csv_p2.out/part-r-00000";
		BufferedReader br = new BufferedReader(new FileReader(inputPath));

		String stationCode_PM10 = "";
		String stationCode_PM2d5 = "";
		Integer PM10 = Integer.MIN_VALUE;
		Integer PM2d5 = Integer.MIN_VALUE;

		while(true){
			String line = br.readLine();
			if(line == null) break;
			StringTokenizer st = new StringTokenizer(line);
			String tStationCode = st.nextToken();
			String tItemName = st.nextToken();
			Integer tValue = Integer.parseInt(st.nextToken());

			switch(tItemName) {
				case "PM10":
					if (PM10 < tValue) {
						PM10 = tValue;
						stationCode_PM10 = tStationCode;
					}
					break;
				case "PM2.5":
					if (PM2d5 < tValue) {
						PM2d5 = tValue;
						stationCode_PM2d5 = tStationCode;
					}
			}
		}

		System.out.println("PM10 기준 공기질 \"좋음\"이 " + PM10.toString() +"번으로 가장 많이 관측된 지역 코드는 " + stationCode_PM10 + "입니다.");
		System.out.println("PM2.5 기준 공기질 \"좋음\"이 " + PM2d5.toString() +"번으로 가장 많이 관측된 지역 코드는 " + stationCode_PM2d5 + "입니다.");


	}
}
