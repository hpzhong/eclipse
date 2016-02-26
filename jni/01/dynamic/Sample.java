public class Sample {
	static {
		System.loadLibrary("hello");
	}
	static native int hello(int val);
	static native String prints(String str);
	public static void main(String [] args) {
		hello(100);
		System.out.println(prints("from java"));
	}
}
