
#pragma once

#include "UnityAdsFunctions.h"
#include "UnityAdsComponent.generated.h"

UCLASS(ClassGroup=Advertising, HideCategories=(Activation, "Components|Activation", Collision), meta=(BlueprintSpawnableComponent))
class UUnityAdsComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:

	DECLARE_MULTICAST_DELEGATE(FUnityAdsonUnityAdsReadyDelegate);

	static FUnityAdsonUnityAdsReadyDelegate onUnityAdsReadyDelegate;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUnityAdsonUnityAdsReadyDynDelegate);

	UPROPERTY(BlueprintAssignable)
	FUnityAdsonUnityAdsReadyDynDelegate onUnityAdsReady;



	DECLARE_MULTICAST_DELEGATE(FUnityAdsonUnityAdsFinishDelegate);

	static FUnityAdsonUnityAdsFinishDelegate onUnityAdsFinishDelegate;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUnityAdsonUnityAdsFinishDynDelegate);

	UPROPERTY(BlueprintAssignable)
	FUnityAdsonUnityAdsFinishDynDelegate onUnityAdsFinish;


	void OnRegister() override;
	void OnUnregister() override;
	
private:	
	

	void onUnityAdsReady_Handler() { onUnityAdsReady.Broadcast(); }
	void onUnityAdsFinish_Handler() { onUnityAdsFinish.Broadcast(); }
	

};
