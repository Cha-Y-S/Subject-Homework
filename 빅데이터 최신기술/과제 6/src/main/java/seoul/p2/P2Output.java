package seoul.p2;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class P2Output {
	public static void main(String[] args) throws IOException {
		String inputPath = "src/data.csv_p2.out/part-r-00000";
		BufferedReader br = new BufferedReader(new FileReader(inputPath));

		String stationCode = "";
		Integer count = Integer.MIN_VALUE;

		while(true){
			String line = br.readLine();
			if(line == null) break;
			StringTokenizer st = new StringTokenizer(line);
			String tStationCode = st.nextToken();
			Integer tValue = Integer.parseInt(st.nextToken());

			if(count < tValue) {
				count = tValue;
				stationCode = tStationCode;
			}
		}

		System.out.println("공기질 \"좋음\"이 " + count + "번으로 가장 많이 출력된 지역 코드는 " + stationCode + "입니다.");


	}
}
