public class Sample {
	static {
		System.loadLibrary("hello");
	}
	static native int hello(int val);
	public static void main(String [] args) {
		hello(100);
	}
}
