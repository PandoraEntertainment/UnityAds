
#pragma once

#include "UnityAdsFunctions.generated.h"



UCLASS(NotBlueprintable)
class UUnityAdsFunctions : public UObject {
	GENERATED_BODY()
	
public:

#if PLATFORM_ANDROID
	static void InitJavaFunctions();
#endif

	// rewarded video

	UFUNCTION(BlueprintPure, meta = (Keywords = "UnityAds ad advertising video"), Category = "UnityAds|Rewarded Video")
	static bool UnityAdsHasRewardedVideo();
	
	UFUNCTION(BlueprintCallable, meta = (Keywords = "UnityAds ad advertising video"), Category = "UnityAds|Rewarded Video")
	static void UnityAdsShowRewardedVideo();

	

};
