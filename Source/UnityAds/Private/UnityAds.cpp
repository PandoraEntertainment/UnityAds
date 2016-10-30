
#include "UnityAdsPrivatePCH.h"
#include "UnityAdsSettings.h"
#include "ISettingsModule.h"

DEFINE_LOG_CATEGORY(LogUnityAds);

#define LOCTEXT_NAMESPACE "UnityAds"

class FUnityAds : public IUnityAds
{
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE( FUnityAds, UnityAds )

void FUnityAds::StartupModule()
{
	// register settings
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "UnityAds",
										 LOCTEXT("RuntimeSettingsName", "UnityAds"),
										 LOCTEXT("RuntimeSettingsDescription", "Configure the UnityAds plugin"),
										 GetMutableDefault<UUnityAdsSettings>()
										 );
	}

#if PLATFORM_ANDROID
	UUnityAdsFunctions::InitJavaFunctions();
#endif
}


void FUnityAds::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
