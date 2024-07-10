
#include <lauxlib.h>

#include "Core.hpp"
#include "GameScripts.hpp"

#include "Native/Scripting/Lua/LuaCallbacks.hpp"
#include "Native/Scripting/Lua/ScriptCB.hpp"

namespace SWBF2::Native::Scripting::Lua
{
    static const luaL_reg cbs[] =
    {
        { "ScriptCB_DoFile", ScriptCB_DoFile },
        { "ScriptCB_GetPlatform", ScriptCB_GetPlatform },
        { "ScriptCB_GetLanguage", ScriptCB_GetLanguage },
        { "ScriptCB_FormatTimeString", ScriptCB_FormatTimeString },
        { "ScriptCB_GetVKeyboardCharacter", ScriptCB_GetVKeyboardCharacter },
        { "ScriptCB_IsLegalGamespyString", ScriptCB_IsLegalGamespyString },
        { "ScriptCB_tounicode", ScriptCB_tounicode },
        { "ScriptCB_UnicodeStrCat", ScriptCB_UnicodeStrCat },
        { "ScriptCB_ununicode", ScriptCB_ununicode },
        { "ScriptCB_getlocalizestr", ScriptCB_getlocalizestr },
        { "ScriptCB_usprintf", ScriptCB_usprintf },
        { "ScriptCB_ustrupper", ScriptCB_ustrupper },
        { "ScriptCB_srand", ScriptCB_srand },
        { "ScriptCB_random", ScriptCB_random },
        { "ScriptCB_GetDateStr", ScriptCB_GetDateStr },
        { "ScriptCB_GetShellActive", ScriptCB_GetShellActive },
        { "ScriptCB_SetAutoAcquireControllers", ScriptCB_SetAutoAcquireControllers },
        { "ScriptCB_ReadAllControllers", ScriptCB_ReadAllControllers },
        { "ScriptCB_UnbindController", ScriptCB_UnbindController },
        { "ScriptCB_GetPrimaryController", ScriptCB_GetPrimaryController },
        { "ScriptCB_GetSecondaryController", ScriptCB_GetSecondaryController },
        { "ScriptCB_IsControllerConnected", ScriptCB_IsControllerConnected },
        { "ScriptCB_IsControllerBound", ScriptCB_IsControllerBound },
        { "ScriptCB_SwapPrimaryController", ScriptCB_SwapPrimaryController },
        { "ScriptCB_SetHotController", ScriptCB_SetHotController },
        { "ScriptCB_RestorePrimaryController", ScriptCB_RestorePrimaryController },
        { "ScriptCB_SetIgnoreControllerRemoval", ScriptCB_SetIgnoreControllerRemoval },
        { "ScriptCB_GetNumControllers", ScriptCB_GetNumControllers },
        { "ScriptCB_GetMaxControllers", ScriptCB_GetMaxControllers },
        { "ScriptCB_GetAutoNetIsDedicated", ScriptCB_GetAutoNetIsDedicated },
        { "ScriptCB_GetAutoNetGameName", ScriptCB_GetAutoNetGameName },
        { "ScriptCB_GetAutoGetPlayerCount", ScriptCB_GetAutoGetPlayerCount },
        { "ScriptCB_SetupAutoNetMissions", ScriptCB_SetupAutoNetMissions },
        { "ScriptCB_SetupAutoNetIsLan", ScriptCB_SetupAutoNetIsLan },
        { "ScriptCB_GetAutoNetScript", ScriptCB_GetAutoNetScript },
        { "ScriptCB_ReadLeftstick", ScriptCB_ReadLeftstick },
        { "ScriptCB_SetQuitPlayer", ScriptCB_SetQuitPlayer },
        { "ScriptCB_GetQuitPlayer", ScriptCB_GetQuitPlayer },
        { "ScriptCB_GetMaxMissionQueue", ScriptCB_GetMaxMissionQueue },
        { "ScriptCB_SetMissionNames", ScriptCB_SetMissionNames },
        { "ScriptCB_SetTeamNames", ScriptCB_SetTeamNames },
        { "ScriptCB_EnterMission", ScriptCB_EnterMission },
        { "ScriptCB_LaunchDemo", ScriptCB_LaunchDemo },
        { "ScriptCB_Reboot", ScriptCB_Reboot },
        { "ScriptCB_GetPausingViewport", ScriptCB_GetPausingViewport },
        { "ScriptCB_GetPausingJoystick", ScriptCB_GetPausingJoystick },
        { "ScriptCB_PausingIsPrimary", ScriptCB_PausingIsPrimary },
        { "ScriptCB_GetBuildStr", ScriptCB_GetBuildStr },
        { "ScriptCB_UpdateScreen", ScriptCB_UpdateScreen },
        { "ScriptCB_UnlockableState", ScriptCB_UnlockableState },
        { "ScriptCB_UnlockUnlockable", ScriptCB_UnlockUnlockable },
        { "ScriptCB_ShouldShowLegal", ScriptCB_ShouldShowLegal },
        { "ScriptCB_PauseDemoTimer", ScriptCB_PauseDemoTimer },
        { "ScriptCB_ShouldShowDemoPostscreen", ScriptCB_ShouldShowDemoPostscreen },
        { "ScriptCB_ShouldCheckDNAS", ScriptCB_ShouldCheckDNAS },
        { "ScriptCB_DoneCheckDNAS", ScriptCB_DoneCheckDNAS },
        { "ScriptCB_HasSeenDNASEULA", ScriptCB_HasSeenDNASEULA },
        { "ScriptCB_SetHasSeenDNASEULA", ScriptCB_SetHasSeenDNASEULA },
        { "ScriptCB_ShouldCheckPatch", ScriptCB_ShouldCheckPatch },
        { "ScriptCB_DoneCheckPatch", ScriptCB_DoneCheckPatch },
        { "ScriptCB_IndexMultipageText", ScriptCB_IndexMultipageText },
        { "ScriptCB_ShowMultipageText", ScriptCB_ShowMultipageText },
        { "ScriptCB_SetDCMap", ScriptCB_SetDCMap },
        { "ScriptCB_HideDownloadableContent", ScriptCB_HideDownloadableContent },
        { "ScriptCB_RestartMission", ScriptCB_RestartMission },
        { "ScriptCB_Unpause", ScriptCB_Unpause },
        { "ScriptCB_SkipToPlayerList", ScriptCB_SkipToPlayerList },
        { "ScriptCB_ResetSkipToPlayerList", ScriptCB_ResetSkipToPlayerList },
        { "ScriptCB_CheckPlayerListDone", ScriptCB_CheckPlayerListDone },
        { "ScriptCB_GetMissionTime", ScriptCB_GetMissionTime },
        { "ScriptCB_Freecamera", ScriptCB_Freecamera },
        { "ScriptCB_IsGameOver", ScriptCB_IsGameOver },
        { "ScriptCB_QuitToShell", ScriptCB_QuitToShell },
        { "ScriptCB_QuitToWindows", ScriptCB_QuitToWindows },
        { "ScriptCB_MinimizeWindow", ScriptCB_MinimizeWindow },
        { "ScriptCB_QuitFromStats", ScriptCB_QuitFromStats },
        { "ScriptCB_GetTeamName", ScriptCB_GetTeamName },
        { "ScriptCB_GetSPProgress", ScriptCB_GetSPProgress },
        { "ScriptCB_SetSPProgress", ScriptCB_SetSPProgress },
        { "ScriptCB_GetLastBattleVictory", ScriptCB_GetLastBattleVictory },
        { "ScriptCB_SetLastBattleVictoryValid", ScriptCB_SetLastBattleVictoryValid },
        { "ScriptCB_MetagameSetBonus", ScriptCB_MetagameSetBonus },
        { "ScriptCB_MetagameSetSide", ScriptCB_MetagameSetSide },
        { "ScriptCB_DisableFlyerShadows", ScriptCB_DisableFlyerShadows },
        { "ScriptCB_EnableScene", ScriptCB_EnableScene },
        { "ScriptCB_PostLoadHack", ScriptCB_PostLoadHack },
        { "ScriptCB_IFObj_SetPos", ScriptCB_IFObj_SetPos },
        { "ScriptCB_IFObj_GetPos", ScriptCB_IFObj_GetPos },
        { "ScriptCB_IFObj_SetBasicRotation", ScriptCB_IFObj_SetBasicRotation },
        { "ScriptCB_IFObj_SetRelativeRotation", ScriptCB_IFObj_SetRelativeRotation },
        { "ScriptCB_IFObj_SetRotation", ScriptCB_IFObj_SetRotation },
        { "ScriptCB_IFObj_SetAlpha", ScriptCB_IFObj_SetAlpha },
        { "ScriptCB_IFObj_GetAlpha", ScriptCB_IFObj_GetAlpha },
        { "ScriptCB_IFObj_SetColor", ScriptCB_IFObj_SetColor },
        { "ScriptCB_IFObj_GetColor", ScriptCB_IFObj_GetColor },
        { "ScriptCB_IFObj_SetZOrder", ScriptCB_IFObj_SetZOrder },
        { "ScriptCB_IFObj_GetZOrder", ScriptCB_IFObj_GetZOrder },
        { "ScriptCB_IFObj_BringToFront", ScriptCB_IFObj_BringToFront },
        { "ScriptCB_IFObj_SendToBack", ScriptCB_IFObj_SendToBack },
        { "ScriptCB_IFObj_Enable", ScriptCB_IFObj_Enable },
        { "ScriptCB_IFObj_IsEnabled", ScriptCB_IFObj_IsEnabled },
        { "ScriptCB_IFObj_IsGroup", ScriptCB_IFObj_IsGroup },
        { "ScriptCB_IFObj_SetVis", ScriptCB_IFObj_SetVis },
        { "ScriptCB_IFObj_SetEnabled", ScriptCB_IFObj_SetEnabled },
        { "ScriptCB_IFObj_GetVis", ScriptCB_IFObj_GetVis },
        { "ScriptCB_IFObj_SetWidthHeight", ScriptCB_IFObj_SetWidthHeight },
        { "ScriptCB_IFObj_GetWidthHeight", ScriptCB_IFObj_GetWidthHeight },
        { "ScriptCB_IFObj_SetPosition", ScriptCB_IFObj_SetPosition },
        { "ScriptCB_IFObj_GetPosition", ScriptCB_IFObj_GetPosition },
        { "ScriptCB_IFObj_MouseOver", ScriptCB_IFObj_MouseOver },
        { "ScriptCB_IFObj_TestHotSpot", ScriptCB_IFObj_TestHotSpot },
        { "ScriptCB_IFObj_CreateHotSpot", ScriptCB_IFObj_CreateHotSpot },
        { "ScriptCB_IFObj_RemoveHotSpot", ScriptCB_IFObj_RemoveHotSpot },
        { "ScriptCB_GetFontHeight", ScriptCB_GetFontHeight },
        { "ScriptCB_IFText_SetString", ScriptCB_IFText_SetString },
        { "ScriptCB_IFText_SetUString", ScriptCB_IFText_SetUString },
        { "ScriptCB_IFText_SetTextPosition", ScriptCB_IFText_SetTextPosition },
        { "ScriptCB_IFText_SetFont", ScriptCB_IFText_SetFont },
        { "ScriptCB_IFText_SetJustify", ScriptCB_IFText_SetJustify },
        { "ScriptCB_IFText_SetTextBreak", ScriptCB_IFText_SetTextBreak },
        { "ScriptCB_IFText_SetTextScale", ScriptCB_IFText_SetTextScale },
        { "ScriptCB_IFText_GetTextScaleX", ScriptCB_IFText_GetTextScaleX },
        { "ScriptCB_IFText_GetTextScaleY", ScriptCB_IFText_GetTextScaleY },
        { "ScriptCB_IFText_GetTextExtent", ScriptCB_IFText_GetTextExtent },
        { "ScriptCB_IFText_GetDisplayRect", ScriptCB_IFText_GetDisplayRect },
        { "ScriptCB_IFText_SetIntercharacterSpacin", ScriptCB_IFText_SetIntercharacterSpacin },
        { "ScriptCB_IFText_GetIntercharacterSpacin", ScriptCB_IFText_GetIntercharacterSpacin },
        { "ScriptCB_IFText_SetTextBox", ScriptCB_IFText_SetTextBox },
        { "ScriptCB_IFText_GetTextBox", ScriptCB_IFText_GetTextBox },
        { "ScriptCB_IFText_SetTextStyle", ScriptCB_IFText_SetTextStyle },
        { "ScriptCB_IFText_SetLeading", ScriptCB_IFText_SetLeading },
        { "ScriptCB_IFText_GetLeading", ScriptCB_IFText_GetLeading },
        { "ScriptCB_IFFlashyText_Setup", ScriptCB_IFFlashyText_Setup },
        { "ScriptCB_IFFlashyText_SetTextColor", ScriptCB_IFFlashyText_SetTextColor },
        { "ScriptCB_IFFlashyText_SetBackground", ScriptCB_IFFlashyText_SetBackground },
        { "ScriptCB_IFFlashyText_SetBackgroundSize", ScriptCB_IFFlashyText_SetBackgroundSize },
        { "ScriptCB_IFFlashyText_SetBackgroundRigh", ScriptCB_IFFlashyText_SetBackgroundRigh },
        { "ScriptCB_IFFlashyText_StartFlashiness", ScriptCB_IFFlashyText_StartFlashiness },
        { "ScriptCB_IFImage_SetTexture", ScriptCB_IFImage_SetTexture },
        { "ScriptCB_IFImage_GetRect", ScriptCB_IFImage_GetRect },
        { "ScriptCB_IFImage_SetRect", ScriptCB_IFImage_SetRect },
        { "ScriptCB_IFImage_GetTexCoords", ScriptCB_IFImage_GetTexCoords },
        { "ScriptCB_IFImage_SetTexCoords", ScriptCB_IFImage_SetTexCoords },
        { "ScriptCB_IFMaskImage_SetMaskTexture", ScriptCB_IFMaskImage_SetMaskTexture },
        { "ScriptCB_IFMaskImage_SetMaskTexCoords", ScriptCB_IFMaskImage_SetMaskTexCoords },
        { "ScriptCB_IFMaskImage_GetMaskTexCoords", ScriptCB_IFMaskImage_GetMaskTexCoords },
        { "ScriptCB_IFBorder_SetTexture", ScriptCB_IFBorder_SetTexture },
        { "ScriptCB_IFBorder_GetRect", ScriptCB_IFBorder_GetRect },
        { "ScriptCB_IFBorder_SetRect", ScriptCB_IFBorder_SetRect },
        { "ScriptCB_IFBorder_GetTexCoords", ScriptCB_IFBorder_GetTexCoords },
        { "ScriptCB_IFBorder_SetTexCoords", ScriptCB_IFBorder_SetTexCoords },
        { "ScriptCB_IFModel_SetModel", ScriptCB_IFModel_SetModel },
        { "ScriptCB_IFModel_SetAnimation", ScriptCB_IFModel_SetAnimation },
        { "ScriptCB_IFModel_QueueAnimation", ScriptCB_IFModel_QueueAnimation },
        { "ScriptCB_IFModel_SetAnimationBanks", ScriptCB_IFModel_SetAnimationBanks },
        { "ScriptCB_IFModel_SetAnimationTime", ScriptCB_IFModel_SetAnimationTime },
        { "ScriptCB_IFModel_AttachModel", ScriptCB_IFModel_AttachModel },
        { "ScriptCB_IFModel_SetScale", ScriptCB_IFModel_SetScale },
        { "ScriptCB_IFModel_GetScale", ScriptCB_IFModel_GetScale },
        { "ScriptCB_IFModel_SetRotation", ScriptCB_IFModel_SetRotation },
        { "ScriptCB_IFModel_GetRotation", ScriptCB_IFModel_GetRotation },
        { "ScriptCB_IFModel_SetTranslation", ScriptCB_IFModel_SetTranslation },
        { "ScriptCB_IFModel_GetTranslation", ScriptCB_IFModel_GetTranslation },
        { "ScriptCB_IFModel_SetDepth", ScriptCB_IFModel_SetDepth },
        { "ScriptCB_IFModel_GetDepth", ScriptCB_IFModel_GetDepth },
        { "ScriptCB_IFModel_SetOmegaY", ScriptCB_IFModel_SetOmegaY },
        { "ScriptCB_IFModel_SetLighting", ScriptCB_IFModel_SetLighting },
        { "ScriptCB_IFModel_UpdateAnimation", ScriptCB_IFModel_UpdateAnimation },
        { "ScriptCB_IFModel_SetAnimationLooping", ScriptCB_IFModel_SetAnimationLooping },
        { "ScriptCB_AddIFScreen", ScriptCB_AddIFScreen },
        { "ScriptCB_SetIFScreenViewport", ScriptCB_SetIFScreenViewport },
        { "ScriptCB_EndIFScreen", ScriptCB_EndIFScreen },
        { "ScriptCB_IsFileExist", ScriptCB_IsFileExist },
        { "ScriptCB_IFObj_GetCPointer", ScriptCB_IFObj_GetCPointer },
        { "ScriptCB_IFObj_SetScreenPosition", ScriptCB_IFObj_SetScreenPosition },
        { "ScriptCB_IFObj_SetUseSafezone", ScriptCB_IFObj_SetUseSafezone },
        { "ScriptCB_EndIFObj", ScriptCB_EndIFObj },
        { "ScriptCB_AddIFText", ScriptCB_AddIFText },
        { "ScriptCB_AddIFFlashyText", ScriptCB_AddIFFlashyText },
        { "ScriptCB_AddIFImage", ScriptCB_AddIFImage },
        { "ScriptCB_AddIFMaskImage", ScriptCB_AddIFMaskImage },
        { "ScriptCB_AddIFBorder", ScriptCB_AddIFBorder },
        { "ScriptCB_AddIFModel", ScriptCB_AddIFModel },
        { "ScriptCB_AddIFContainer", ScriptCB_AddIFContainer },
        { "ScriptCB_SetIFScreen", ScriptCB_SetIFScreen },
        { "ScriptCB_PushScreen", ScriptCB_PushScreen },
        { "ScriptCB_PopScreen", ScriptCB_PopScreen },
        { "ScriptCB_IsScreenInStack", ScriptCB_IsScreenInStack },
        { "ScriptCB_OpenPopup", ScriptCB_OpenPopup },
        { "ScriptCB_ClosePopup", ScriptCB_ClosePopup },
        { "ScriptCB_IsPopupOpen", ScriptCB_IsPopupOpen },
        { "ScriptCB_SetIgnoreInputs", ScriptCB_SetIgnoreInputs },
        { "ScriptCB_OpenMovie", ScriptCB_OpenMovie },
        { "ScriptCB_CloseMovie", ScriptCB_CloseMovie },
        { "ScriptCB_PlayMovie", ScriptCB_PlayMovie },
        { "ScriptCB_IsMoviePlaying", ScriptCB_IsMoviePlaying },
        { "ScriptCB_AreMoviePropertiesPlaying", ScriptCB_AreMoviePropertiesPlaying },
        { "ScriptCB_StopMovie", ScriptCB_StopMovie },
        { "ScriptCB_SetMovieAudioBus", ScriptCB_SetMovieAudioBus },
        { "ScriptCB_IsPropertyPlayingNow", ScriptCB_IsPropertyPlayingNow },
        { "ScriptCB_PlayInGameMovie", ScriptCB_PlayInGameMovie },
        { "ScriptCB_StopInGameMovie", ScriptCB_StopInGameMovie },
        { "ScriptCB_GetScreenInfo", ScriptCB_GetScreenInfo },
        { "ScriptCB_GetSafeScreenInfo", ScriptCB_GetSafeScreenInfo },
        { "ScriptCB_IsErrorBoxOpen", ScriptCB_IsErrorBoxOpen },
        { "ScriptCB_OpenErrorBox", ScriptCB_OpenErrorBox },
        { "ScriptCB_CloseErrorBox", ScriptCB_CloseErrorBox },
        { "ScriptCB_GetErrorLevel", ScriptCB_GetErrorLevel },
        { "ScriptCB_GetConsoleCmds", ScriptCB_GetConsoleCmds },
        { "ScriptCB_DoConsoleCmd", ScriptCB_DoConsoleCmd },
        { "ScriptCB_GetLeaderBoardPlayerData", ScriptCB_GetLeaderBoardPlayerData },
        { "ScriptCB_DownloadLeaderBoardData", ScriptCB_DownloadLeaderBoardData },
        { "ScriptCB_LeaderBoardDownloadDone", ScriptCB_LeaderBoardDownloadDone },
        { "ScriptCB_CancelLeaderBoardPlayerData", ScriptCB_CancelLeaderBoardPlayerData },
        { "ScriptCB_SetLeaderBoardID", ScriptCB_SetLeaderBoardID },
        { "ScriptCB_ResetLeaderBoardPlayerData", ScriptCB_ResetLeaderBoardPlayerData },
        { "ScriptCB_EnumerateLeaderBoard", ScriptCB_EnumerateLeaderBoard },
        { "ScriptCB_EnumerateLeaderBoardDone", ScriptCB_EnumerateLeaderBoardDone },
        { "ScriptCB_GetEnumerateLeaderBoardData", ScriptCB_GetEnumerateLeaderBoardData },
        { "ScriptCB_IsEnableLeaderBoard", ScriptCB_IsEnableLeaderBoard },
        { "ScriptCB_SetSunlight", ScriptCB_SetSunlight },
        { "ScriptCB_ResetControl", ScriptCB_ResetControl },
        { "ScriptCB_SetBinding", ScriptCB_SetBinding },
        { "ScriptCB_GetActionFromIdx", ScriptCB_GetActionFromIdx },
        { "ScriptCB_GetKeyBoardCmds", ScriptCB_GetKeyBoardCmds },
        { "ScriptCB_EnableCursor", ScriptCB_EnableCursor },
        { "ScriptCB_MrMrsEval", ScriptCB_MrMrsEval },
        { "ScriptCB_GetEntityMesh", ScriptCB_GetEntityMesh },
        { "ScriptCB_GetEntityWeaponMesh", ScriptCB_GetEntityWeaponMesh },
        { "ScriptCB_GetEntityLabel", ScriptCB_GetEntityLabel },
        { "ScriptCB_GetIFaceLighting", ScriptCB_GetIFaceLighting },
        { "ScriptCB_SetIFaceLighting", ScriptCB_SetIFaceLighting },
        { "ScriptCB_RemoveTexture", ScriptCB_RemoveTexture },
        { "ScriptCB_ShowLoadDisplay", ScriptCB_ShowLoadDisplay },
        { "ScriptCB_SetInputRepeat", ScriptCB_SetInputRepeat },
        { "ScriptCB_GetLoginList", ScriptCB_GetLoginList },
        { "ScriptCB_IsCurProfileDirty", ScriptCB_IsCurProfileDirty },
        { "ScriptCB_IsProfileDirty", ScriptCB_IsProfileDirty },
        { "ScriptCB_SetProfileNotDirty", ScriptCB_SetProfileNotDirty },
        { "ScriptCB_LoadSavePopupResult", ScriptCB_LoadSavePopupResult },
        { "ScriptCB_DoInitialMemcardCheck", ScriptCB_DoInitialMemcardCheck },
        { "ScriptCB_StartInitialMemcardCheck", ScriptCB_StartInitialMemcardCheck },
        { "ScriptCB_StartPreOp", ScriptCB_StartPreOp },
        { "ScriptCB_IsPlayerLoggedIn", ScriptCB_IsPlayerLoggedIn },
        { "ScriptCB_GetCurrentProfileName", ScriptCB_GetCurrentProfileName },
        { "ScriptCB_GetProfileName", ScriptCB_GetProfileName },
        { "ScriptCB_GetCurrentProfileNetName", ScriptCB_GetCurrentProfileNetName },
        { "ScriptCB_GetCurrentPCTitleVersion", ScriptCB_GetCurrentPCTitleVersion },
        { "ScriptCB_AddProfile", ScriptCB_AddProfile },
        { "ScriptCB_SwapActiveProfileSlots", ScriptCB_SwapActiveProfileSlots },
        { "ScriptCB_StartLoadProfile", ScriptCB_StartLoadProfile },
        { "ScriptCB_MakeFakeProfiles", ScriptCB_MakeFakeProfiles },
        { "ScriptCB_SetProfileAsDefault", ScriptCB_SetProfileAsDefault },
        { "ScriptCB_RestoreDefaultProfile", ScriptCB_RestoreDefaultProfile },
        { "ScriptCB_MarkCurrentProfile", ScriptCB_MarkCurrentProfile },
        { "ScriptCB_ReloadMarkedProfile", ScriptCB_ReloadMarkedProfile },
        { "ScriptCB_HasProfileChanged", ScriptCB_HasProfileChanged },
        { "ScriptCB_StartDeleteProfile", ScriptCB_StartDeleteProfile },
        { "ScriptCB_StartSaveProfile", ScriptCB_StartSaveProfile },
        { "ScriptCB_StartLoadMetagame", ScriptCB_StartLoadMetagame },
        { "ScriptCB_StartSaveMetagame", ScriptCB_StartSaveMetagame },
        { "ScriptCB_StartDeleteMetagame", ScriptCB_StartDeleteMetagame },
        { "ScriptCB_IsCurrentMetagame", ScriptCB_IsCurrentMetagame },
        { "ScriptCB_StartLoadCampaign", ScriptCB_StartLoadCampaign },
        { "ScriptCB_StartSaveCampaign", ScriptCB_StartSaveCampaign },
        { "ScriptCB_StartDeleteCampaign", ScriptCB_StartDeleteCampaign },
        { "ScriptCB_IsCurrentCampaign", ScriptCB_IsCurrentCampaign },
        { "ScriptCB_TrimLoginName", ScriptCB_TrimLoginName },
        { "ScriptCB_GetUniqueLoginName", ScriptCB_GetUniqueLoginName },
        { "ScriptCB_IsUniqueLoginName", ScriptCB_IsUniqueLoginName },
        { "ScriptCB_MarkMemoryCard", ScriptCB_MarkMemoryCard },
        { "ScriptCB_CheckMemoryCardMark", ScriptCB_CheckMemoryCardMark },
        { "ScriptCB_IsMemoryCardUnformatted", ScriptCB_IsMemoryCardUnformatted },
        { "ScriptCB_IsMemoryCardInsertted", ScriptCB_IsMemoryCardInsertted },
        { "ScriptCB_DoesProfileExistOnCard", ScriptCB_DoesProfileExistOnCard },
        { "ScriptCB_InMemoryProfileMode", ScriptCB_InMemoryProfileMode },
        { "ScriptCB_SetMemoryProfileMode", ScriptCB_SetMemoryProfileMode },
        { "ScriptCB_CheckIfOkToExitMemoryMode", ScriptCB_CheckIfOkToExitMemoryMode },
        { "ScriptCB_GetSavedMetagameList", ScriptCB_GetSavedMetagameList },
        { "ScriptCB_StartNewMetagame", ScriptCB_StartNewMetagame },
        { "ScriptCB_DoesMetagameExistOnCard", ScriptCB_DoesMetagameExistOnCard },
        { "ScriptCB_GetSavedCampaignList", ScriptCB_GetSavedCampaignList },
        { "ScriptCB_StartNewCampaign", ScriptCB_StartNewCampaign },
        { "ScriptCB_DoesCampaignExistOnCard", ScriptCB_DoesCampaignExistOnCard },
        { "ScriptCB_Logout", ScriptCB_Logout },
        { "ScriptCB_SaveMetagameState", ScriptCB_SaveMetagameState },
        { "ScriptCB_LoadMetagameState", ScriptCB_LoadMetagameState },
        { "ScriptCB_ClearMetagameState", ScriptCB_ClearMetagameState },
        { "ScriptCB_IsMetagameStateSaved", ScriptCB_IsMetagameStateSaved },
        { "ScriptCB_SaveCampaignState", ScriptCB_SaveCampaignState },
        { "ScriptCB_LoadCampaignState", ScriptCB_LoadCampaignState },
        { "ScriptCB_ClearCampaignState", ScriptCB_ClearCampaignState },
        { "ScriptCB_IsCampaignStateSaved", ScriptCB_IsCampaignStateSaved },
        { "ScriptCB_SetInTrainingMission", ScriptCB_SetInTrainingMission },
        { "ScriptCB_GetInTrainingMission", ScriptCB_GetInTrainingMission },
        { "ScriptCB_SaveMissionSetup", ScriptCB_SaveMissionSetup },
        { "ScriptCB_LoadMissionSetup", ScriptCB_LoadMissionSetup },
        { "ScriptCB_ClearMissionSetup", ScriptCB_ClearMissionSetup },
        { "ScriptCB_IsMissionSetupSaved", ScriptCB_IsMissionSetupSaved },
        { "ScriptCB_PlayerSuicide", ScriptCB_PlayerSuicide },
        { "ScriptCB_AutoNetJoin", ScriptCB_AutoNetJoin },
        { "ScriptCB_GetOnlineService", ScriptCB_GetOnlineService },
        { "ScriptCB_SetAmHost", ScriptCB_SetAmHost },
        { "ScriptCB_GetAmHost", ScriptCB_GetAmHost },
        { "ScriptCB_GetWasHost", ScriptCB_GetWasHost },
        { "ScriptCB_InNetGame", ScriptCB_InNetGame },
        { "ScriptCB_SetInNetGame", ScriptCB_SetInNetGame },
        { "ScriptCB_InMultiplayer", ScriptCB_InMultiplayer },
        { "ScriptCB_InNetSession", ScriptCB_InNetSession },
        { "ScriptCB_NetWasHost", ScriptCB_NetWasHost },
        { "ScriptCB_NetWasDedicated", ScriptCB_NetWasDedicated },
        { "ScriptCB_NetWasDedicatedQuit", ScriptCB_NetWasDedicatedQuit },
        { "ScriptCB_NetWasClient", ScriptCB_NetWasClient },
        { "ScriptCB_IsDedicated", ScriptCB_IsDedicated },
        { "ScriptCB_SetDedicated", ScriptCB_SetDedicated },
        { "ScriptCB_IsInShell", ScriptCB_IsInShell },
        { "ScriptCB_IsAutoNet", ScriptCB_IsAutoNet },
        { "ScriptCB_EndAutoNet", ScriptCB_EndAutoNet },
        { "ScriptCB_GetAutoNetMode", ScriptCB_GetAutoNetMode },
        { "ScriptCB_OpenNetShell", ScriptCB_OpenNetShell },
        { "ScriptCB_IsNetworkOn", ScriptCB_IsNetworkOn },
        { "ScriptCB_CloseNetShell", ScriptCB_CloseNetShell },
        { "ScriptCB_IsBootInvitePending", ScriptCB_IsBootInvitePending },
        { "ScriptCB_GetAutoAssignTeams", ScriptCB_GetAutoAssignTeams },
        { "ScriptCB_SetNumBots", ScriptCB_SetNumBots },
        { "ScriptCB_GetGameName", ScriptCB_GetGameName },
        { "ScriptCB_SetGameName", ScriptCB_SetGameName },
        { "ScriptCB_SetConnectType", ScriptCB_SetConnectType },
        { "ScriptCB_GetConnectType", ScriptCB_GetConnectType },
        { "ScriptCB_EnableJournal", ScriptCB_EnableJournal },
        { "ScriptCB_EnablePlayback", ScriptCB_EnablePlayback },
        { "ScriptCB_GetLatestError", ScriptCB_GetLatestError },
        { "ScriptCB_GetError", ScriptCB_GetError },
        { "ScriptCB_ClearError", ScriptCB_ClearError },
        { "ScriptCB_IsLoginDone", ScriptCB_IsLoginDone },
        { "ScriptCB_IsLoggedIn", ScriptCB_IsLoggedIn },
        { "ScriptCB_GetLoginName", ScriptCB_GetLoginName },
        { "ScriptCB_StartLoginDedicatedServer", ScriptCB_StartLoginDedicatedServer },
        { "ScriptCB_StartLogin", ScriptCB_StartLogin },
        { "ScriptCB_CancelLogin", ScriptCB_CancelLogin },
        { "ScriptCB_TrackLoginErrors", ScriptCB_TrackLoginErrors },
        { "ScriptCB_IsGuest", ScriptCB_IsGuest },
        { "ScriptCB_BeginLobby", ScriptCB_BeginLobby },
        { "ScriptCB_GetLobbyPlayerlist", ScriptCB_GetLobbyPlayerlist },
        { "ScriptCB_UpdateLobby", ScriptCB_UpdateLobby },
        { "ScriptCB_HasServerLaunched", ScriptCB_HasServerLaunched },
        { "ScriptCB_LaunchLobby", ScriptCB_LaunchLobby },
        { "ScriptCB_CancelLobby", ScriptCB_CancelLobby },
        { "ScriptCB_LobbyAction", ScriptCB_LobbyAction },
        { "ScriptCB_VoteKick", ScriptCB_VoteKick },
        { "ScriptCB_VoteOrNominate", ScriptCB_VoteOrNominate },
        { "ScriptCB_BeginSessionList", ScriptCB_BeginSessionList },
        { "ScriptCB_ClearPrevSessionId", ScriptCB_ClearPrevSessionId },
        { "ScriptCB_GetSessionListPercent", ScriptCB_GetSessionListPercent },
        { "ScriptCB_UpdateSessionList", ScriptCB_UpdateSessionList },
        { "ScriptCB_LaunchSessionList", ScriptCB_LaunchSessionList },
        { "ScriptCB_CancelSessionList", ScriptCB_CancelSessionList },
        { "ScriptCB_PauseSessionList", ScriptCB_PauseSessionList },
        { "ScriptCB_IsSessionReady", ScriptCB_IsSessionReady },
        { "ScriptCB_GetExtraSessionInfo", ScriptCB_GetExtraSessionInfo },
        { "ScriptCB_GetFilters", ScriptCB_GetFilters },
        { "ScriptCB_SetFilters", ScriptCB_SetFilters },
        { "ScriptCB_ApplyFilters", ScriptCB_ApplyFilters },
        { "ScriptCB_GetSessionSortMode", ScriptCB_GetSessionSortMode },
        { "ScriptCB_SetSessionSortMode", ScriptCB_SetSessionSortMode },
        { "ScriptCB_SetAsFavorite", ScriptCB_SetAsFavorite },
        { "ScriptCB_GetSessionList", ScriptCB_GetSessionList },
        { "ScriptCB_NextHost", ScriptCB_NextHost },
        { "ScriptCB_PreviousHost", ScriptCB_PreviousHost },
        { "ScriptCB_IsSpecialJoinPending", ScriptCB_IsSpecialJoinPending },
        { "ScriptCB_IsCmdlineJoinPending", ScriptCB_IsCmdlineJoinPending },
        { "ScriptCB_IsGamespyArcadePasswordReady", ScriptCB_IsGamespyArcadePasswordReady },
        { "ScriptCB_GetCmdlineLogin", ScriptCB_GetCmdlineLogin },
        { "ScriptCB_BeginQuickmatch", ScriptCB_BeginQuickmatch },
        { "ScriptCB_BeginJoinIP", ScriptCB_BeginJoinIP },
        { "ScriptCB_BeginJoinSpecial", ScriptCB_BeginJoinSpecial },
        { "ScriptCB_UpdateQuickmatch", ScriptCB_UpdateQuickmatch },
        { "ScriptCB_LaunchQuickmatch", ScriptCB_LaunchQuickmatch },
        { "ScriptCB_CancelQuickmatch", ScriptCB_CancelQuickmatch },
        { "ScriptCB_IsQuickmatchDone", ScriptCB_IsQuickmatchDone },
        { "ScriptCB_IsQuickmatchPassworded", ScriptCB_IsQuickmatchPassworded },
        { "ScriptCB_CanSupportMaxPlayers", ScriptCB_CanSupportMaxPlayers },
        { "ScriptCB_IsBadNetworkConnection", ScriptCB_IsBadNetworkConnection },
        { "ScriptCB_BeginJoin", ScriptCB_BeginJoin },
        { "ScriptCB_UpdateJoin", ScriptCB_UpdateJoin },
        { "ScriptCB_LaunchJoin", ScriptCB_LaunchJoin },
        { "ScriptCB_CancelJoin", ScriptCB_CancelJoin },
        { "ScriptCB_IsJoinDone", ScriptCB_IsJoinDone },
        { "ScriptCB_BeginLeave", ScriptCB_BeginLeave },
        { "ScriptCB_UpdateLeave", ScriptCB_UpdateLeave },
        { "ScriptCB_LaunchLeave", ScriptCB_LaunchLeave },
        { "ScriptCB_CancelLeave", ScriptCB_CancelLeave },
        { "ScriptCB_IsLeaveDone", ScriptCB_IsLeaveDone },
        { "ScriptCB_IsNetHWPresent", ScriptCB_IsNetHWPresent },
        { "ScriptCB_IsNetCableIn", ScriptCB_IsNetCableIn },
        { "ScriptCB_SetNoticeNoCable", ScriptCB_SetNoticeNoCable },
        { "ScriptCB_GetIPAddr", ScriptCB_GetIPAddr },
        { "ScriptCB_SetNetLoginName", ScriptCB_SetNetLoginName },
        { "ScriptCB_GetLobbyPlayerFlags", ScriptCB_GetLobbyPlayerFlags },
        { "ScriptCB_GetGSProfileInfo", ScriptCB_GetGSProfileInfo },
        { "ScriptCB_SetGSProfileInfo", ScriptCB_SetGSProfileInfo },
        { "ScriptCB_BeginFriends", ScriptCB_BeginFriends },
        { "ScriptCB_CancelFriends", ScriptCB_CancelFriends },
        { "ScriptCB_UpdateFriends", ScriptCB_UpdateFriends },
        { "ScriptCB_GetFriendStateStr", ScriptCB_GetFriendStateStr },
        { "ScriptCB_GetFriendActions", ScriptCB_GetFriendActions },
        { "ScriptCB_DoFriendAction", ScriptCB_DoFriendAction },
        { "ScriptCB_GetFriendListIcon", ScriptCB_GetFriendListIcon },
        { "ScriptCB_AllowSkipDNAS", ScriptCB_AllowSkipDNAS },
        { "ScriptCB_CheckForPatch", ScriptCB_CheckForPatch },
        { "ScriptCB_SkipToNTGUI", ScriptCB_SkipToNTGUI },
        { "ScriptCB_GetSkipToNTGUIProfileName", ScriptCB_GetSkipToNTGUIProfileName },
        { "ScriptCB_ResetSkipToNTGUI", ScriptCB_ResetSkipToNTGUI },
        { "ScriptCB_GetLobbyPlayerCount", ScriptCB_GetLobbyPlayerCount },
        { "ScriptCB_VoiceEnable", ScriptCB_VoiceEnable },
        { "ScriptCB_GetVoiceEnable", ScriptCB_GetVoiceEnable },
        { "ScriptCB_SetVoiceLocalEchoEnable", ScriptCB_SetVoiceLocalEchoEnable },
        { "ScriptCB_SetVoiceSendPreset", ScriptCB_SetVoiceSendPreset },
        { "ScriptCB_GetVoiceSendPreset", ScriptCB_GetVoiceSendPreset },
        { "ScriptCB_SetVoiceReceivePreset", ScriptCB_SetVoiceReceivePreset },
        { "ScriptCB_GetVoiceReceivePreset", ScriptCB_GetVoiceReceivePreset },
        { "ScriptCB_SetVoiceSendEnable", ScriptCB_SetVoiceSendEnable },
        { "ScriptCB_GetVoiceSendStatus", ScriptCB_GetVoiceSendStatus },
        { "ScriptCB_SetVoiceReceiveEnable", ScriptCB_SetVoiceReceiveEnable },
        { "ScriptCB_GetVoiceReceiveStatus", ScriptCB_GetVoiceReceiveStatus },
        { "ScriptCB_GetVoiceRenderConnected", ScriptCB_GetVoiceRenderConnected },
        { "ScriptCB_GetVoiceCaptureConnected", ScriptCB_GetVoiceCaptureConnected },
        { "ScriptCB_GetVoiceTVGain", ScriptCB_GetVoiceTVGain },
        { "ScriptCB_CanClientLeaveStats", ScriptCB_CanClientLeaveStats },
        { "ScriptCB_SearchStatsRank", ScriptCB_SearchStatsRank },
        { "ScriptCB_GetBandwidth", ScriptCB_GetBandwidth },
        { "ScriptCB_SetBandwidth", ScriptCB_SetBandwidth },
        { "ScriptCB_GetPlayerAwardsEnabled", ScriptCB_GetPlayerAwardsEnabled },
        { "ScriptCB_SetPlayerAwardsEnabled", ScriptCB_SetPlayerAwardsEnabled },
        { "ScriptCB_LastSignInError", ScriptCB_LastSignInError },
        { "ScriptCB_SetSplitscreen", ScriptCB_SetSplitscreen },
        { "ScriptCB_GetNumCameras", ScriptCB_GetNumCameras },
        { "ScriptCB_IsSplitscreen", ScriptCB_IsSplitscreen },
        { "ScriptCB_WasSplitscreen", ScriptCB_WasSplitscreen },
        { "ScriptCB_SetPlayerSide", ScriptCB_SetPlayerSide },
        { "ScriptCB_SetDifficulty", ScriptCB_SetDifficulty },
        { "ScriptCB_GetDifficulty", ScriptCB_GetDifficulty },
        { "ScriptCB_GetCTFCaptureLimit", ScriptCB_GetCTFCaptureLimit },
        { "ScriptCB_GetHuntMaxTimeLimit", ScriptCB_GetHuntMaxTimeLimit },
        { "ScriptCB_GetHuntScoreLimit", ScriptCB_GetHuntScoreLimit },
        { "ScriptCB_ShowHuntScoreLimit", ScriptCB_ShowHuntScoreLimit },
        { "ScriptCB_GetCTFMaxTimeLimit", ScriptCB_GetCTFMaxTimeLimit },
        { "ScriptCB_GetAssaultScoreLimit", ScriptCB_GetAssaultScoreLimit },
        { "ScriptCB_GetUberScoreLimit", ScriptCB_GetUberScoreLimit },
        { "ScriptCB_SetUberScoreLimit", ScriptCB_SetUberScoreLimit },
        { "ScriptCB_GetCONMaxTimeLimit", ScriptCB_GetCONMaxTimeLimit },
        { "ScriptCB_GetCONNumBots", ScriptCB_GetCONNumBots },
        { "ScriptCB_GetCTFNumBots", ScriptCB_GetCTFNumBots },
        { "ScriptCB_GetASSNumBots", ScriptCB_GetASSNumBots },
        { "ScriptCB_SetNumBots_", ScriptCB_SetNumBots_ },
        { "ScriptCB_GetFunctionIdForAnalogId", ScriptCB_GetFunctionIdForAnalogId },
        { "ScriptCB_SetFunctionIdForAnalogId", ScriptCB_SetFunctionIdForAnalogId },
        { "ScriptCB_GetFunctionIdForButtonId", ScriptCB_GetFunctionIdForButtonId },
        { "ScriptCB_SetFunctionIdForButtonId", ScriptCB_SetFunctionIdForButtonId },
        { "ScriptCB_SetSpectatorMode", ScriptCB_SetSpectatorMode },
        { "ScriptCB_GetSpectatorMode", ScriptCB_GetSpectatorMode },
        { "ScriptCB_SetCanSwitchSides", ScriptCB_SetCanSwitchSides },
        { "ScriptCB_SetGameRules", ScriptCB_SetGameRules },
        { "ScriptCB_GetGameRules", ScriptCB_GetGameRules },
        { "ScriptCB_SetAIDifficulty", ScriptCB_SetAIDifficulty },
        { "ScriptCB_IsMetaAllMapsOn", ScriptCB_IsMetaAllMapsOn },
        { "ScriptCB_SetMetaAllMapsOn", ScriptCB_SetMetaAllMapsOn },
        { "ScriptCB_GetYAxisFlip", ScriptCB_GetYAxisFlip },
        { "ScriptCB_SetYAxisFlip", ScriptCB_SetYAxisFlip },
        { "ScriptCB_GetMouseTurnAssist", ScriptCB_GetMouseTurnAssist },
        { "ScriptCB_SetMouseTurnAssist", ScriptCB_SetMouseTurnAssist },
        { "ScriptCB_GetControlScale", ScriptCB_GetControlScale },
        { "ScriptCB_SetControlScale", ScriptCB_SetControlScale },
        { "ScriptCB_ResetGameOptionsToDefault", ScriptCB_ResetGameOptionsToDefault },
        { "ScriptCB_ResetSoundToDefault", ScriptCB_ResetSoundToDefault },
        { "ScriptCB_ResetOnlineOptionsToDefault", ScriptCB_ResetOnlineOptionsToDefault },
        { "ScriptCB_ResetControlsToDefault", ScriptCB_ResetControlsToDefault },
        { "ScriptCB_GetGeneralOptions", ScriptCB_GetGeneralOptions },
        { "ScriptCB_SetGeneralOptions", ScriptCB_SetGeneralOptions },
        { "ScriptCB_IsHorizontalSplitScreen", ScriptCB_IsHorizontalSplitScreen },
        { "ScriptCB_SetHorizontalSplitScreen", ScriptCB_SetHorizontalSplitScreen },
        { "ScriptCB_SetHUDScale", ScriptCB_SetHUDScale },
        { "ScriptCB_GetHUDScale", ScriptCB_GetHUDScale },
        { "ScriptCB_NextToolTipState", ScriptCB_NextToolTipState },
        { "ScriptCB_PrevToolTipState", ScriptCB_PrevToolTipState },
        { "ScriptCB_SetToolTipState", ScriptCB_SetToolTipState },
        { "ScriptCB_ResetToolTips", ScriptCB_ResetToolTips },
        { "ScriptCB_SetControlMode", ScriptCB_SetControlMode },
        { "ScriptCB_GetControlMode", ScriptCB_GetControlMode },
        { "ScriptCB_GetSideSelectButtonSetting", ScriptCB_GetSideSelectButtonSetting },
        { "ScriptCB_SetOnlineOpts", ScriptCB_SetOnlineOpts },
        { "ScriptCB_GetOnlineOpts", ScriptCB_GetOnlineOpts },
        { "ScriptCB_GetNetGameDefaults", ScriptCB_GetNetGameDefaults },
        { "ScriptCB_SetNetGameDefaults", ScriptCB_SetNetGameDefaults },
        { "ScriptCB_GetNetHeroDefaults", ScriptCB_GetNetHeroDefaults },
        { "ScriptCB_SetNetHeroDefaults", ScriptCB_SetNetHeroDefaults },
        { "ScriptCB_GetMouseSensitivity", ScriptCB_GetMouseSensitivity },
        { "ScriptCB_GetJoySensitivity", ScriptCB_GetJoySensitivity },
        { "ScriptCB_GetDeadZone", ScriptCB_GetDeadZone },
        { "ScriptCB_SetMouseSensitivity", ScriptCB_SetMouseSensitivity },
        { "ScriptCB_SetJoySensitivity", ScriptCB_SetJoySensitivity },
        { "ScriptCB_SetDeadZone", ScriptCB_SetDeadZone },
        { "ScriptCB_IsJoystickEnabled", ScriptCB_IsJoystickEnabled },
        { "ScriptCB_SetJoystickEnabled", ScriptCB_SetJoystickEnabled },
        { "ScriptCB_SetReticuleTransparency", ScriptCB_SetReticuleTransparency },
        { "ScriptCB_GetReticuleTransparency", ScriptCB_GetReticuleTransparency },
        { "ScriptCB_FillResolutionTable", ScriptCB_FillResolutionTable },
        { "ScriptCB_FillMultisampleTable", ScriptCB_FillMultisampleTable },
        { "ScriptCB_SetResolution", ScriptCB_SetResolution },
        { "ScriptCB_GetIdealResolution", ScriptCB_GetIdealResolution },
        { "ScriptCB_GetCustomResolution", ScriptCB_GetCustomResolution },
        { "ScriptCB_GetPCVideoOptions", ScriptCB_GetPCVideoOptions },
        { "ScriptCB_GetCustomVideoOptions", ScriptCB_GetCustomVideoOptions },
        { "ScriptCB_GetAutodetectPCVideoOptions", ScriptCB_GetAutodetectPCVideoOptions },
        { "ScriptCB_SetPCVideoOptions", ScriptCB_SetPCVideoOptions },
        { "ScriptCB_SetPCBrightnessContrast", ScriptCB_SetPCBrightnessContrast },
        { "ScriptCB_IsPCVideoFixedFunction", ScriptCB_IsPCVideoFixedFunction },
        { "ScriptCB_GetProfileJoinIP", ScriptCB_GetProfileJoinIP },
        { "ScriptCB_SetProfileJoinIP", ScriptCB_SetProfileJoinIP },
        { "ScriptCB_ResetPCVideoOptionsToDefault", ScriptCB_ResetPCVideoOptionsToDefault },
        { "ScriptCB_SetMouseMark", ScriptCB_SetMouseMark },
        { "ScriptCB_ResetMouseMark", ScriptCB_ResetMouseMark },
        { "ScriptCB_CheckMouseMark", ScriptCB_CheckMouseMark },
        { "ScriptCB_GetKeyboardPCFlags", ScriptCB_GetKeyboardPCFlags },
        { "ScriptCB_EnableCursor_", ScriptCB_EnableCursor_ },
        { "ScriptCB_SndBusFade", ScriptCB_SndBusFade },
        { "ScriptCB_SndPlaySound", ScriptCB_SndPlaySound },
        { "ScriptCB_SetBleedingRepeatTime", ScriptCB_SetBleedingRepeatTime },
        { "ScriptCB_SetSpawnDisplayGain", ScriptCB_SetSpawnDisplayGain },
        { "ScriptCB_PlayInGameMusic", ScriptCB_PlayInGameMusic },
        { "ScriptCB_StopInGameMusic", ScriptCB_StopInGameMusic },
        { "ScriptCB_EnableCommandPostVO", ScriptCB_EnableCommandPostVO },
        { "ScriptCB_EnableHeroMusic", ScriptCB_EnableHeroMusic },
        { "ScriptCB_EnableHeroVO", ScriptCB_EnableHeroVO },
        { "ScriptCB_TriggerSoundRegionEnable", ScriptCB_TriggerSoundRegionEnable },
        { "ScriptCB_GetVolumes", ScriptCB_GetVolumes },
        { "ScriptCB_SetVolumes", ScriptCB_SetVolumes },
        { "ScriptCB_EffectsEnabled", ScriptCB_EffectsEnabled },
        { "ScriptCB_ToggleEffects", ScriptCB_ToggleEffects },
        { "ScriptCB_HWSupport", ScriptCB_HWSupport },
        { "ScriptCB_GetOutputMode", ScriptCB_GetOutputMode },
        { "ScriptCB_PreviousOutputMode", ScriptCB_PreviousOutputMode },
        { "ScriptCB_NextOutputMode", ScriptCB_NextOutputMode },
        { "ScriptCB_SetOutputMode", ScriptCB_SetOutputMode },
        { "ScriptCB_GetMixConfig", ScriptCB_GetMixConfig },
        { "ScriptCB_PreviousMixConfig", ScriptCB_PreviousMixConfig },
        { "ScriptCB_NextMixConfig", ScriptCB_NextMixConfig },
        { "ScriptCB_SetMixConfig", ScriptCB_SetMixConfig },
        { "ScriptCB_GetEAXVersion", ScriptCB_GetEAXVersion },
        { "ScriptCB_GetMixConfigChanged", ScriptCB_GetMixConfigChanged },
        { "ScriptCB_SetBassManagement", ScriptCB_SetBassManagement },
        { "ScriptCB_GetBassManagement", ScriptCB_GetBassManagement },
        { "ScriptCB_PlayAuditionEffect", ScriptCB_PlayAuditionEffect },
        { "ScriptCB_SetShellMusic", ScriptCB_SetShellMusic },
        { "ScriptCB_SetShellMusicInterval", ScriptCB_SetShellMusicInterval },
        { "ScriptCB_IsShellMusicPlaying", ScriptCB_IsShellMusicPlaying },
        { "ScriptCB_ShellPlayDelayedStream", ScriptCB_ShellPlayDelayedStream },
        { "ScriptCB_SoundEnable", ScriptCB_SoundEnable },
        { "ScriptCB_SoundDisable", ScriptCB_SoundDisable },
        { "ScriptCB_SetDopplerFactor", ScriptCB_SetDopplerFactor },
        { "ScriptCB_ClientGotStats", ScriptCB_ClientGotStats },
        { "ScriptCB_SetTeamStatsSortMode", ScriptCB_SetTeamStatsSortMode },
        { "ScriptCB_GetTeamstats", ScriptCB_GetTeamstats },
        { "ScriptCB_TeamStatsGetTeam1", ScriptCB_TeamStatsGetTeam1 },
        { "ScriptCB_TeamStatsGetTeamColor", ScriptCB_TeamStatsGetTeamColor },
        { "ScriptCB_TeamStatsSetTitles", ScriptCB_TeamStatsSetTitles },
        { "ScriptCB_PersonalStatsSetTitles", ScriptCB_PersonalStatsSetTitles },
        { "ScriptCB_TeamStatsValidatePos", ScriptCB_TeamStatsValidatePos },
        { "ScriptCB_GetPersonalStats", ScriptCB_GetPersonalStats },
        { "ScriptCB_GetAwardStats", ScriptCB_GetAwardStats },
        { "ScriptCB_GetMedalStats", ScriptCB_GetMedalStats },
        { "ScriptCB_GetCareerPersonalStats", ScriptCB_GetCareerPersonalStats },
        { "ScriptCB_GetCareerRank", ScriptCB_GetCareerRank },
        { "ScriptCB_GetCareerMedals", ScriptCB_GetCareerMedals },
        { "ScriptCB_GetCareerMedalLevel", ScriptCB_GetCareerMedalLevel },
        { "ScriptCB_SetPlayerStatsPoints", ScriptCB_SetPlayerStatsPoints },
        { "ScriptCB_GetRank", ScriptCB_GetRank },
        { "ScriptCB_GetPlayerIDAtRank", ScriptCB_GetPlayerIDAtRank }
    };

    void LuaCallbacks::Init()
    {
        for (const auto &cb : cbs)
        {
            GameScripts::Instance()->RegisterCallback(cb.name, cb.func);
        }
    }
}
