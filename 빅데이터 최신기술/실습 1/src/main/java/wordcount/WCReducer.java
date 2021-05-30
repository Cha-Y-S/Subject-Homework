package wordcount;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;

import java.io.IOException;

public class WCReducer extends Reducer<Text, IntWritable, Text, IntWritable> {
  // arg1: Reduce Input Key type
  // arg2: Reduce Input Value type
  // arg3: Reduce Output Key type
  // arg4: Reduce Output Key type

  IntWritable ov = new IntWritable();

  @Override
  protected void reduce(Text key, Iterable<IntWritable> values, Reducer<Text, IntWritable, Text, IntWritable>.Context context) throws IOException, InterruptedException {
    int sum = 0;
    for(IntWritable v : values) {
      sum += v.get();
    }

    ov.set(sum);
    context.write(key, ov);
  }
}
