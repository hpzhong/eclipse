public class Sample {
	static {
		System.loadLibrary("hello");
	}
	static native int hello(int val);
	static native int print_array(int[] arr);
	static native String prints(String str);
	public static void main(String [] args) {
		int[] array={1,2,3,4,5};
		hello(100);
		System.out.println(prints("from java"));
		System.out.println(print_array(array));
	}
}
