
#include "UnityAdsPrivatePCH.h"

#if PLATFORM_ANDROID

#include "Android/AndroidJNI.h"
#include "AndroidApplication.h"

#define INIT_JAVA_METHOD(name, signature) \
if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true)) { \
	name = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, #name, signature, false); \
	check(name != NULL); \
} else { \
	check(0); \
}

#define DECLARE_JAVA_METHOD(name) \
static jmethodID name = NULL;


DECLARE_JAVA_METHOD(AndroidThunkJava_UnityAds_HasRewardedVideo);
DECLARE_JAVA_METHOD(AndroidThunkJava_UnityAds_ShowRewardedVideo);

void UUnityAdsFunctions::InitJavaFunctions()
{
	INIT_JAVA_METHOD(AndroidThunkJava_UnityAds_HasRewardedVideo, "()Z");
	INIT_JAVA_METHOD(AndroidThunkJava_UnityAds_ShowRewardedVideo, "()V");
}
#undef DECLARE_JAVA_METHOD
#undef INIT_JAVA_METHOD


//This function is declared in the Java-defined class, GameActivity.java: "public native void nativeUnityAdsonUnityAdsReady();"
extern "C" void Java_com_epicgames_ue4_GameActivity_nativeUnityAdsonUnityAdsReady(JNIEnv* jenv, jobject thiz)
{

	FSimpleDelegateGraphTask::CreateAndDispatchWhenReady(
		FSimpleDelegateGraphTask::FDelegate::CreateLambda([=]()
	{
		UUnityAdsComponent::onUnityAdsReadyDelegate.Broadcast();
	}),
		TStatId(),
		nullptr,
		ENamedThreads::GameThread
		);
}


//This function is declared in the Java-defined class, GameActivity.java: "public native void nativeUnityAdsDidCompleteRewardedVideo();"
extern "C" void Java_com_epicgames_ue4_GameActivity_nativeUnityAdsonUnityAdsFinish(JNIEnv* jenv, jobject thiz)
{
	

	FSimpleDelegateGraphTask::CreateAndDispatchWhenReady(
		FSimpleDelegateGraphTask::FDelegate::CreateLambda([=]()
	{
		UUnityAdsComponent::onUnityAdsFinishDelegate.Broadcast();
	}),
		TStatId(),
		nullptr,
		ENamedThreads::GameThread
		);
}

#endif

void UUnityAdsFunctions::UnityAdsShowRewardedVideo() {

#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true))
	{
		

		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_UnityAds_ShowRewardedVideo);

	

		UE_LOG(LogAndroid, Warning, TEXT("I found the java method AdColonyShowV4VCReward\n"));
	}
	else
	{
		UE_LOG(LogAndroid, Warning, TEXT("ERROR Could note get Java ENV\n"));
	}
#endif
}

bool UUnityAdsFunctions::UnityAdsHasRewardedVideo() {

#if PLATFORM_IOS

#elif PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true))
	{
		

		bool ret = FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_UnityAds_HasRewardedVideo );

		

		UE_LOG(LogAndroid, Warning, TEXT("I found the java method AdColonyHasRewardedVideo\n"));

		return ret;
	}
	else
	{
		UE_LOG(LogAndroid, Warning, TEXT("ERROR Could note get Java ENV\n"));
	}
#endif

	return false;
}