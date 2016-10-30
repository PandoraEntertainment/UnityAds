
#pragma once

#include "UnityAdsSettings.generated.h"

UCLASS(config = Engine, defaultconfig)
class UUnityAdsSettings : public UObject
{
	GENERATED_BODY()
	
public:
	UUnityAdsSettings(const FObjectInitializer& ObjectInitializer);
	
	// SDK Ids

	UPROPERTY(Config, EditAnywhere, Category = App, meta = (DisplayName = "App Id"))
	FString AppId;

	UPROPERTY(Config, EditAnywhere, Category = App, meta = (DisplayName = "RewardedVdeo Id"))
	FString RewardedVdeoId;

	
};
