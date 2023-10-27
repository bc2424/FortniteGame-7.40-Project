#include "FortGameInstance.h"

bool UFortGameInstance::UninstallFortniteBROnNextBoot_Implementation(bool bRestartApp, bool bPromptForRestart) {
    return false;
}

bool UFortGameInstance::UninstallAllOptionalContentOnNextBoot_Implementation(bool bRestartApp, bool bPromptForRestart) {
    return false;
}

void UFortGameInstance::SetUserSetting_Implementation(const FString& Key, const FString& Value, FWebJSResponse Response) {
}

void UFortGameInstance::SetOverrideCurrentMusicFFT(float FFT100hz, float FFT2000hz) {
}

void UFortGameInstance::SetNotificationCallback_Implementation(FWebJSFunction Callback) {
}

void UFortGameInstance::SetMultipleUserSettings_Implementation(const TMap<FString, FString>& Settings, FWebJSResponse Response) {
}

void UFortGameInstance::SetHotfixCompleteCallback_Implementation(FWebJSFunction Callback) {
}

void UFortGameInstance::SetFeatureStatusCallback_Implementation(FWebJSFunction Callback) {
}

void UFortGameInstance::SetErrorSimulationCommands_Implementation(const FString& CommandLine) {
}

void UFortGameInstance::SetActiveGameFeature_Implementation(EFortGameFeature Feature, FWebJSResponse Response) {
}

void UFortGameInstance::RequestGameFeatureState_Implementation(EFortGameFeature Feature, EFortGameFeatureState State, FWebJSResponse Response) {
}

void UFortGameInstance::RequestBroadcast_Implementation() {
}

void UFortGameInstance::PauseContentInstall_Implementation() {
}

void UFortGameInstance::OpenUpdateApp_Implementation() {
}

void UFortGameInstance::OnTournamentDataRefreshed() {
}

void UFortGameInstance::IsContentUpToDate_Implementation(EFortGameFeature Feature, FWebJSResponse Response) {
}

void UFortGameInstance::GetUserSetting_Implementation(const FString& Key, FWebJSResponse Response) {
}

void UFortGameInstance::GetProjectVersion_Implementation(FWebJSResponse Response) {
}

void UFortGameInstance::GetHotfixHasApplied_Implementation(FWebJSResponse Response) {
}

void UFortGameInstance::GetDownloadSize_Implementation(EFortGameFeature Feature, FWebJSResponse Response) {
}

void UFortGameInstance::GetContentState_Implementation(EFortGameFeature Feature, FWebJSResponse Response) {
}

void UFortGameInstance::ContinueDelayedStartup() {
}

void UFortGameInstance::ClearOverrideCurrentMusicFFT() {
}

void UFortGameInstance::CheckLatestClient_Implementation(FWebJSResponse Response) {
}

void UFortGameInstance::ChangeActiveGameFeature(const FString& FeatureString) {
}

void UFortGameInstance::CancelContentInstall_Implementation() {
}

UFortGameInstance::UFortGameInstance() {
    this->bBattleRoyaleMatchmakingEnabled = true;
    this->bCreativeModeProfileEnabled = true;
    this->FrontEndPlaylistData.AddDefaulted(6);
    this->bOverridingCurrentEmoteMusicFFT = false;
    this->CurrentEmoteMusicFFT100hz = 0.00f;
    this->CurrentEmoteMusicFFT2000hz = 0.00f;
    this->EmoteMusicEnvelopeBeatCount = 0.00f;
    this->ProfileManager = NULL;
    this->Matchmaking = NULL;
    this->MatchmakingV2 = NULL;
    this->RejoinCheck = NULL;
    this->SocialManager = NULL;
    this->MatchAnalytics = NULL;
    this->SidecarSys = NULL;
    this->bMcpSidecarEnabled = false;
    this->TooltipManager = NULL;
    this->UpdateManager = NULL;
    this->InteractabilityTracker = NULL;
    this->Chatroom = NULL;
    this->SeasonalEventManager = NULL;
    this->TournamentManager = NULL;
    this->MobilePushNotificationManager = NULL;
    this->BroadcastFeatureStatusRate = 0.50f;
    this->CurrentMissionGenerator = NULL;
    this->AppActivationSoundMixManager = NULL;
    this->KairosUIResX = 0;
    this->KairosUIResY = 0;
    this->KairosHotfixCheckTimer = 300.00f;
    this->KairosHotfixCheckVariance = 120.00f;
    this->PlaylistManager = NULL;
    this->MaterialCacheManager = NULL;
    this->ReplayVideoManager = NULL;
}

