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
static const JNINativeMethod methods[] =
{
	{"hello", "(I)I", print_hello},
	{"prints", "(Ljava/lang/String;)Ljava/lang/String;", print_string},
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
