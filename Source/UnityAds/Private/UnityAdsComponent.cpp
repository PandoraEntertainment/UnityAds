
#include "UnityAdsPrivatePCH.h"

void UUnityAdsComponent::OnRegister()
{
	Super::OnRegister();
	

	UUnityAdsComponent::onUnityAdsReadyDelegate.AddUObject(this, &UUnityAdsComponent::onUnityAdsReady_Handler);

	UUnityAdsComponent::onUnityAdsFinishDelegate.AddUObject(this, &UUnityAdsComponent::onUnityAdsFinish_Handler);
}

void UUnityAdsComponent::OnUnregister()
{
	Super::OnUnregister();
	

	UUnityAdsComponent::onUnityAdsReadyDelegate.RemoveAll(this);

	UUnityAdsComponent::onUnityAdsFinishDelegate.RemoveAll(this);
}

UUnityAdsComponent::FUnityAdsonUnityAdsReadyDelegate UUnityAdsComponent::onUnityAdsReadyDelegate;

UUnityAdsComponent::FUnityAdsonUnityAdsFinishDelegate UUnityAdsComponent::onUnityAdsFinishDelegate;
