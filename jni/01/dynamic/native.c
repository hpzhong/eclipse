#include <stdio.h>
#include <jni.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

jint print_hello(JNIEnv *env, jobject cls, jint val)
{
	printf("Hello, World!, value=%d\n", val);
}

jstring JNICALL print_string(JNIEnv *env, jobject cls, jstring str)
{
	const jbyte *cstr;

	cstr = (*env)->GetStringUTFChars(env, str, NULL);
	if (cstr == NULL) {
		return NULL; /* Out Of Memory Error already thrown */
	}

	printf("Get string from java :%s\n", cstr);
	(*env)->ReleaseStringUTFChars(env, str, cstr);

	return (*env)->NewStringUTF(env, "return from c");
}

jint print_array(JNIEnv *env, jobject cls, jintArray arr)
{
	jint *carr;
	jint i, sum = 0;
	carr = (*env)->GetIntArrayElements(env, arr, NULL);
	if (carr == NULL) {
		return 0; /* exception occurred */
	}
	for (i=0; i< (*env)->GetArrayLength(env, arr); i++) {
		sum += carr[i];
	}
	(*env)->ReleaseIntArrayElements(env, arr, carr, 0);
	return sum;
}

static const JNINativeMethod methods[] =
{
	{"hello", "(I)I", print_hello},
	{"prints", "(Ljava/lang/String;)Ljava/lang/String;", print_string},
	{"print_array", "([I)I", print_array},
};

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *jvm, void *reserved)
{
	JNIEnv *env;
	jclass cls;

	if ((*jvm)->GetEnv(jvm, (void **)&env, JNI_VERSION_1_4)) {
		return JNI_ERR; /* JNI version not supported */
	}
	cls = (*env)->FindClass(env, "Sample");
	if (cls == NULL) {
		return JNI_ERR;
	}

	/* 2. map java hello <-->c c_hello */
	if ((*env)->RegisterNatives(env, cls, methods, ARRAY_SIZE(methods)) < 0)
		return JNI_ERR;

	return JNI_VERSION_1_4;
}
