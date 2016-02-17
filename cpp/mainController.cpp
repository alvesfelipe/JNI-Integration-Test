/* --------------------------------------------------------------------------
*author: Danilo Assis, Felipe Alves
*date: 16/02/2016
* --------------------------------------------------------------------------
*/

#include "mainController.h"	

namespace main_controller{

		extern "C" {
		/* @Override: Sumarize.h */
		JNIEXPORT void JNICALL Java_Sumarize_summarized
				(JNIEnv *jenv, jobject jobj, jstring jstr);
	};


namespace main_controller{
	MainController(){

	} 		
 	virtual ~MainController(){

 	}
	void sumarizeContent(char* content){
		JavaVMOption options[1];
		JNIEnv *env;
		JavaVM *jvm;
		JavaVMInitArgs vm_args;	
		long status;

		jclass cls;
		jmethodID mid;
		jint mresult;

		options[0].optionString = (char*) "-Djava.class.path=/home/danilo/workspace/mainController/";
		memset(&vm_args, 0, sizeof(vm_args));
		vm_args.version = JNI_VERSION_1_2;
		vm_args.nOptions = 1;
		vm_args.options = options;

		//criando maquina virtual java
		status = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);

		if (status != JNI_ERR){
			cls = env->FindClass("Sumarize");
			if(cls != 0){
				//encontrou a classe
				mid = env->GetStaticMethodID(cls, "summarize","(Ljava/lang/String;)I");
				if (mid != 0){
					//encontrou o metodo. tratar argumento passado
					jstring jstr = env->NewStringUTF(content); 
					//chamada do método estático do java
					mresult = env->CallStaticIntMethod(cls, mid, jstr);
					if (mresult != 1) printf("Error\n");
				}
				else
				{
					printf("Cannot find summarize method\n");
				}
			}
			else
			{
				printf("Cannot find Sumarize class\n");
			}
			jvm->DestroyJavaVM();
		}
	}


	JNIEXPORT void JNICALL Java_Sumarize_summarized(JNIEnv *jenv, jobject jobj, jstring jstr)
	{
		const char *native_str = jenv->GetStringUTFChars(jstr, 0);
			
		printf("Java is calling the native code in C++, sending this message: %s\n", native_str);

		jenv->ReleaseStringUTFChars(jstr, native_str);
		
	}

}//namespace main_controller