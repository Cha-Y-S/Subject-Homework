package wordcount;

import org.apache.hadoop.util.ToolRunner;

public class WordCountTest {
	public static void main(String[] args) throws Exception {

		String[] inputargs = new String[1];
		inputargs[0] = "sample.txt";

		ToolRunner.run(new WordCount(), inputargs);
	}
}
