package triangle;

import org.apache.hadoop.util.ToolRunner;

public class TLS1Test {
	public static void main(String[] args) throws Exception {
		String[] myargs = {"src/test/resources/sample.edge"};
		ToolRunner.run(new TriangleListingStep1(), myargs);
	}
}
