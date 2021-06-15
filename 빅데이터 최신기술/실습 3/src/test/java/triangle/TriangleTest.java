package triangle;

import org.apache.hadoop.util.ToolRunner;

public class TriangleTest {
	public static void main(String[] args) throws Exception {
		String[] myargs = {"src/test/resources/sample.edge", "src/test/resources/sample.edge.wedge"};
		ToolRunner.run(new TriangleListingStep1(), myargs);
		ToolRunner.run(new TriangleListingStep2(), myargs);
	}
}

