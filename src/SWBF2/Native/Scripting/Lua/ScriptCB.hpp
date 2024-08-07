
#pragma once

#include <lua.h>
#include <lauxlib.h>

namespace SWBF2::Native::Scripting::Lua
{
    int ScriptCB_DoFile(lua_State *);
    int ScriptCB_GetPlatform(lua_State *);
    int ScriptCB_GetLanguage(lua_State *);
    int ScriptCB_FormatTimeString(lua_State *);
    int ScriptCB_GetVKeyboardCharacter(lua_State *);
    int ScriptCB_IsLegalGamespyString(lua_State *);
    int ScriptCB_tounicode(lua_State *);
    int ScriptCB_UnicodeStrCat(lua_State *);
    int ScriptCB_ununicode(lua_State *);
    int ScriptCB_getlocalizestr(lua_State *);
    int ScriptCB_usprintf(lua_State *);
    int ScriptCB_ustrupper(lua_State *);
    int ScriptCB_srand(lua_State *);
    int ScriptCB_random(lua_State *);
    int ScriptCB_GetDateStr(lua_State *);
    int ScriptCB_GetShellActive(lua_State *);
    int ScriptCB_SetAutoAcquireControllers(lua_State *);
    int ScriptCB_ReadAllControllers(lua_State *);
    int ScriptCB_UnbindController(lua_State *);
    int ScriptCB_GetPrimaryController(lua_State *);
    int ScriptCB_GetSecondaryController(lua_State *);
    int ScriptCB_IsControllerConnected(lua_State *);
    int ScriptCB_IsControllerBound(lua_State *);
    int ScriptCB_SwapPrimaryController(lua_State *);
    int ScriptCB_SetHotController(lua_State *);
    int ScriptCB_RestorePrimaryController(lua_State *);
    int ScriptCB_SetIgnoreControllerRemoval(lua_State *);
    int ScriptCB_GetNumControllers(lua_State *);
    int ScriptCB_GetMaxControllers(lua_State *);
    int ScriptCB_GetAutoNetIsDedicated(lua_State *);
    int ScriptCB_GetAutoNetGameName(lua_State *);
    int ScriptCB_GetAutoGetPlayerCount(lua_State *);
    int ScriptCB_SetupAutoNetMissions(lua_State *);
    int ScriptCB_SetupAutoNetIsLan(lua_State *);
    int ScriptCB_GetAutoNetScript(lua_State *);
    int ScriptCB_ReadLeftstick(lua_State *);
    int ScriptCB_SetQuitPlayer(lua_State *);
    int ScriptCB_GetQuitPlayer(lua_State *);
    int ScriptCB_GetMaxMissionQueue(lua_State *);
    int ScriptCB_SetMissionNames(lua_State *);
    int ScriptCB_SetTeamNames(lua_State *);
    int ScriptCB_EnterMission(lua_State *);
    int ScriptCB_LaunchDemo(lua_State *);
    int ScriptCB_Reboot(lua_State *);
    int ScriptCB_GetPausingViewport(lua_State *);
    int ScriptCB_GetPausingJoystick(lua_State *);
    int ScriptCB_PausingIsPrimary(lua_State *);
    int ScriptCB_GetBuildStr(lua_State *);
    int ScriptCB_UpdateScreen(lua_State *);
    int ScriptCB_UnlockableState(lua_State *);
    int ScriptCB_UnlockUnlockable(lua_State *);
    int ScriptCB_ShouldShowLegal(lua_State *);
    int ScriptCB_PauseDemoTimer(lua_State *);
    int ScriptCB_ShouldShowDemoPostscreen(lua_State *);
    int ScriptCB_ShouldCheckDNAS(lua_State *);
    int ScriptCB_DoneCheckDNAS(lua_State *);
    int ScriptCB_HasSeenDNASEULA(lua_State *);
    int ScriptCB_SetHasSeenDNASEULA(lua_State *);
    int ScriptCB_ShouldCheckPatch(lua_State *);
    int ScriptCB_DoneCheckPatch(lua_State *);
    int ScriptCB_IndexMultipageText(lua_State *);
    int ScriptCB_ShowMultipageText(lua_State *);
    int ScriptCB_SetDCMap(lua_State *);
    int ScriptCB_HideDownloadableContent(lua_State *);
    int ScriptCB_RestartMission(lua_State *);
    int ScriptCB_Unpause(lua_State *);
    int ScriptCB_SkipToPlayerList(lua_State *);
    int ScriptCB_ResetSkipToPlayerList(lua_State *);
    int ScriptCB_CheckPlayerListDone(lua_State *);
    int ScriptCB_GetMissionTime(lua_State *);
    int ScriptCB_Freecamera(lua_State *);
    int ScriptCB_IsGameOver(lua_State *);
    int ScriptCB_QuitToShell(lua_State *);
    int ScriptCB_QuitToWindows(lua_State *);
    int ScriptCB_MinimizeWindow(lua_State *);
    int ScriptCB_QuitFromStats(lua_State *);
    int ScriptCB_GetTeamName(lua_State *);
    int ScriptCB_GetSPProgress(lua_State *);
    int ScriptCB_SetSPProgress(lua_State *);
    int ScriptCB_GetLastBattleVictory(lua_State *);
    int ScriptCB_SetLastBattleVictoryValid(lua_State *);
    int ScriptCB_MetagameSetBonus(lua_State *);
    int ScriptCB_MetagameSetSide(lua_State *);
    int ScriptCB_DisableFlyerShadows(lua_State *);
    int ScriptCB_EnableScene(lua_State *);
    int ScriptCB_PostLoadHack(lua_State *);
    int ScriptCB_IFObj_SetPos(lua_State *);
    int ScriptCB_IFObj_GetPos(lua_State *);
    int ScriptCB_IFObj_SetBasicRotation(lua_State *);
    int ScriptCB_IFObj_SetRelativeRotation(lua_State *);
    int ScriptCB_IFObj_SetRotation(lua_State *);
    int ScriptCB_IFObj_SetAlpha(lua_State *);
    int ScriptCB_IFObj_GetAlpha(lua_State *);
    int ScriptCB_IFObj_SetColor(lua_State *);
    int ScriptCB_IFObj_GetColor(lua_State *);
    int ScriptCB_IFObj_SetZOrder(lua_State *);
    int ScriptCB_IFObj_GetZOrder(lua_State *);
    int ScriptCB_IFObj_BringToFront(lua_State *);
    int ScriptCB_IFObj_SendToBack(lua_State *);
    int ScriptCB_IFObj_Enable(lua_State *);
    int ScriptCB_IFObj_IsEnabled(lua_State *);
    int ScriptCB_IFObj_IsGroup(lua_State *);
    int ScriptCB_IFObj_SetVis(lua_State *);
    int ScriptCB_IFObj_SetEnabled(lua_State *);
    int ScriptCB_IFObj_GetVis(lua_State *);
    int ScriptCB_IFObj_SetWidthHeight(lua_State *);
    int ScriptCB_IFObj_GetWidthHeight(lua_State *);
    int ScriptCB_IFObj_SetPosition(lua_State *);
    int ScriptCB_IFObj_GetPosition(lua_State *);
    int ScriptCB_IFObj_MouseOver(lua_State *);
    int ScriptCB_IFObj_TestHotSpot(lua_State *);
    int ScriptCB_IFObj_CreateHotSpot(lua_State *);
    int ScriptCB_IFObj_RemoveHotSpot(lua_State *);
    int ScriptCB_GetFontHeight(lua_State *);
    int ScriptCB_IFText_SetString(lua_State *);
    int ScriptCB_IFText_SetUString(lua_State *);
    int ScriptCB_IFText_SetTextPosition(lua_State *);
    int ScriptCB_IFText_SetFont(lua_State *);
    int ScriptCB_IFText_SetJustify(lua_State *);
    int ScriptCB_IFText_SetTextBreak(lua_State *);
    int ScriptCB_IFText_SetTextScale(lua_State *);
    int ScriptCB_IFText_GetTextScaleX(lua_State *);
    int ScriptCB_IFText_GetTextScaleY(lua_State *);
    int ScriptCB_IFText_GetTextExtent(lua_State *);
    int ScriptCB_IFText_GetDisplayRect(lua_State *);
    int ScriptCB_IFText_SetIntercharacterSpacin(lua_State *);
    int ScriptCB_IFText_GetIntercharacterSpacin(lua_State *);
    int ScriptCB_IFText_SetTextBox(lua_State *);
    int ScriptCB_IFText_GetTextBox(lua_State *);
    int ScriptCB_IFText_SetTextStyle(lua_State *);
    int ScriptCB_IFText_SetLeading(lua_State *);
    int ScriptCB_IFText_GetLeading(lua_State *);
    int ScriptCB_IFFlashyText_Setup(lua_State *);
    int ScriptCB_IFFlashyText_SetTextColor(lua_State *);
    int ScriptCB_IFFlashyText_SetBackground(lua_State *);
    int ScriptCB_IFFlashyText_SetBackgroundSize(lua_State *);
    int ScriptCB_IFFlashyText_SetBackgroundRigh(lua_State *);
    int ScriptCB_IFFlashyText_StartFlashiness(lua_State *);
    int ScriptCB_IFImage_SetTexture(lua_State *);
    int ScriptCB_IFImage_GetRect(lua_State *);
    int ScriptCB_IFImage_SetRect(lua_State *);
    int ScriptCB_IFImage_GetTexCoords(lua_State *);
    int ScriptCB_IFImage_SetTexCoords(lua_State *);
    int ScriptCB_IFMaskImage_SetMaskTexture(lua_State *);
    int ScriptCB_IFMaskImage_SetMaskTexCoords(lua_State *);
    int ScriptCB_IFMaskImage_GetMaskTexCoords(lua_State *);
    int ScriptCB_IFBorder_SetTexture(lua_State *);
    int ScriptCB_IFBorder_GetRect(lua_State *);
    int ScriptCB_IFBorder_SetRect(lua_State *);
    int ScriptCB_IFBorder_GetTexCoords(lua_State *);
    int ScriptCB_IFBorder_SetTexCoords(lua_State *);
    int ScriptCB_IFModel_SetModel(lua_State *);
    int ScriptCB_IFModel_SetAnimation(lua_State *);
    int ScriptCB_IFModel_QueueAnimation(lua_State *);
    int ScriptCB_IFModel_SetAnimationBanks(lua_State *);
    int ScriptCB_IFModel_SetAnimationTime(lua_State *);
    int ScriptCB_IFModel_AttachModel(lua_State *);
    int ScriptCB_IFModel_SetScale(lua_State *);
    int ScriptCB_IFModel_GetScale(lua_State *);
    int ScriptCB_IFModel_SetRotation(lua_State *);
    int ScriptCB_IFModel_GetRotation(lua_State *);
    int ScriptCB_IFModel_SetTranslation(lua_State *);
    int ScriptCB_IFModel_GetTranslation(lua_State *);
    int ScriptCB_IFModel_SetDepth(lua_State *);
    int ScriptCB_IFModel_GetDepth(lua_State *);
    int ScriptCB_IFModel_SetOmegaY(lua_State *);
    int ScriptCB_IFModel_SetLighting(lua_State *);
    int ScriptCB_IFModel_UpdateAnimation(lua_State *);
    int ScriptCB_IFModel_SetAnimationLooping(lua_State *);
    int ScriptCB_AddIFScreen(lua_State *);
    int ScriptCB_SetIFScreenViewport(lua_State *);
    int ScriptCB_EndIFScreen(lua_State *);
    int ScriptCB_IsFileExist(lua_State *);
    int ScriptCB_IFObj_GetCPointer(lua_State *);
    int ScriptCB_IFObj_SetScreenPosition(lua_State *);
    int ScriptCB_IFObj_SetUseSafezone(lua_State *);
    int ScriptCB_EndIFObj(lua_State *);
    int ScriptCB_AddIFText(lua_State *);
    int ScriptCB_AddIFFlashyText(lua_State *);
    int ScriptCB_AddIFImage(lua_State *);
    int ScriptCB_AddIFMaskImage(lua_State *);
    int ScriptCB_AddIFBorder(lua_State *);
    int ScriptCB_AddIFModel(lua_State *);
    int ScriptCB_AddIFContainer(lua_State *);
    int ScriptCB_SetIFScreen(lua_State *);
    int ScriptCB_PushScreen(lua_State *);
    int ScriptCB_PopScreen(lua_State *);
    int ScriptCB_IsScreenInStack(lua_State *);
    int ScriptCB_OpenPopup(lua_State *);
    int ScriptCB_ClosePopup(lua_State *);
    int ScriptCB_IsPopupOpen(lua_State *);
    int ScriptCB_SetIgnoreInputs(lua_State *);
    int ScriptCB_OpenMovie(lua_State *);
    int ScriptCB_CloseMovie(lua_State *);
    int ScriptCB_PlayMovie(lua_State *);
    int ScriptCB_IsMoviePlaying(lua_State *);
    int ScriptCB_AreMoviePropertiesPlaying(lua_State *);
    int ScriptCB_StopMovie(lua_State *);
    int ScriptCB_SetMovieAudioBus(lua_State *);
    int ScriptCB_IsPropertyPlayingNow(lua_State *);
    int ScriptCB_PlayInGameMovie(lua_State *);
    int ScriptCB_StopInGameMovie(lua_State *);
    int ScriptCB_GetScreenInfo(lua_State *);
    int ScriptCB_GetSafeScreenInfo(lua_State *);
    int ScriptCB_IsErrorBoxOpen(lua_State *);
    int ScriptCB_OpenErrorBox(lua_State *);
    int ScriptCB_CloseErrorBox(lua_State *);
    int ScriptCB_GetErrorLevel(lua_State *);
    int ScriptCB_GetConsoleCmds(lua_State *);
    int ScriptCB_DoConsoleCmd(lua_State *);
    int ScriptCB_GetLeaderBoardPlayerData(lua_State *);
    int ScriptCB_DownloadLeaderBoardData(lua_State *);
    int ScriptCB_LeaderBoardDownloadDone(lua_State *);
    int ScriptCB_CancelLeaderBoardPlayerData(lua_State *);
    int ScriptCB_SetLeaderBoardID(lua_State *);
    int ScriptCB_ResetLeaderBoardPlayerData(lua_State *);
    int ScriptCB_EnumerateLeaderBoard(lua_State *);
    int ScriptCB_EnumerateLeaderBoardDone(lua_State *);
    int ScriptCB_GetEnumerateLeaderBoardData(lua_State *);
    int ScriptCB_IsEnableLeaderBoard(lua_State *);
    int ScriptCB_SetSunlight(lua_State *);
    int ScriptCB_ResetControl(lua_State *);
    int ScriptCB_SetBinding(lua_State *);
    int ScriptCB_GetActionFromIdx(lua_State *);
    int ScriptCB_GetKeyBoardCmds(lua_State *);
    int ScriptCB_EnableCursor(lua_State *);
    int ScriptCB_MrMrsEval(lua_State *);
    int ScriptCB_GetEntityMesh(lua_State *);
    int ScriptCB_GetEntityWeaponMesh(lua_State *);
    int ScriptCB_GetEntityLabel(lua_State *);
    int ScriptCB_GetIFaceLighting(lua_State *);
    int ScriptCB_SetIFaceLighting(lua_State *);
    int ScriptCB_RemoveTexture(lua_State *);
    int ScriptCB_ShowLoadDisplay(lua_State *);
    int ScriptCB_SetInputRepeat(lua_State *);
    int ScriptCB_GetLoginList(lua_State *);
    int ScriptCB_IsCurProfileDirty(lua_State *);
    int ScriptCB_IsProfileDirty(lua_State *);
    int ScriptCB_SetProfileNotDirty(lua_State *);
    int ScriptCB_LoadSavePopupResult(lua_State *);
    int ScriptCB_DoInitialMemcardCheck(lua_State *);
    int ScriptCB_StartInitialMemcardCheck(lua_State *);
    int ScriptCB_StartPreOp(lua_State *);
    int ScriptCB_IsPlayerLoggedIn(lua_State *);
    int ScriptCB_GetCurrentProfileName(lua_State *);
    int ScriptCB_GetProfileName(lua_State *);
    int ScriptCB_GetCurrentProfileNetName(lua_State *);
    int ScriptCB_GetCurrentPCTitleVersion(lua_State *);
    int ScriptCB_AddProfile(lua_State *);
    int ScriptCB_SwapActiveProfileSlots(lua_State *);
    int ScriptCB_StartLoadProfile(lua_State *);
    int ScriptCB_MakeFakeProfiles(lua_State *);
    int ScriptCB_SetProfileAsDefault(lua_State *);
    int ScriptCB_RestoreDefaultProfile(lua_State *);
    int ScriptCB_MarkCurrentProfile(lua_State *);
    int ScriptCB_ReloadMarkedProfile(lua_State *);
    int ScriptCB_HasProfileChanged(lua_State *);
    int ScriptCB_StartDeleteProfile(lua_State *);
    int ScriptCB_StartSaveProfile(lua_State *);
    int ScriptCB_StartLoadMetagame(lua_State *);
    int ScriptCB_StartSaveMetagame(lua_State *);
    int ScriptCB_StartDeleteMetagame(lua_State *);
    int ScriptCB_IsCurrentMetagame(lua_State *);
    int ScriptCB_StartLoadCampaign(lua_State *);
    int ScriptCB_StartSaveCampaign(lua_State *);
    int ScriptCB_StartDeleteCampaign(lua_State *);
    int ScriptCB_IsCurrentCampaign(lua_State *);
    int ScriptCB_TrimLoginName(lua_State *);
    int ScriptCB_GetUniqueLoginName(lua_State *);
    int ScriptCB_IsUniqueLoginName(lua_State *);
    int ScriptCB_MarkMemoryCard(lua_State *);
    int ScriptCB_CheckMemoryCardMark(lua_State *);
    int ScriptCB_IsMemoryCardUnformatted(lua_State *);
    int ScriptCB_IsMemoryCardInsertted(lua_State *);
    int ScriptCB_DoesProfileExistOnCard(lua_State *);
    int ScriptCB_InMemoryProfileMode(lua_State *);
    int ScriptCB_SetMemoryProfileMode(lua_State *);
    int ScriptCB_CheckIfOkToExitMemoryMode(lua_State *);
    int ScriptCB_GetSavedMetagameList(lua_State *);
    int ScriptCB_StartNewMetagame(lua_State *);
    int ScriptCB_DoesMetagameExistOnCard(lua_State *);
    int ScriptCB_GetSavedCampaignList(lua_State *);
    int ScriptCB_StartNewCampaign(lua_State *);
    int ScriptCB_DoesCampaignExistOnCard(lua_State *);
    int ScriptCB_Logout(lua_State *);
    int ScriptCB_SaveMetagameState(lua_State *);
    int ScriptCB_LoadMetagameState(lua_State *);
    int ScriptCB_ClearMetagameState(lua_State *);
    int ScriptCB_IsMetagameStateSaved(lua_State *);
    int ScriptCB_SaveCampaignState(lua_State *);
    int ScriptCB_LoadCampaignState(lua_State *);
    int ScriptCB_ClearCampaignState(lua_State *);
    int ScriptCB_IsCampaignStateSaved(lua_State *);
    int ScriptCB_SetInTrainingMission(lua_State *);
    int ScriptCB_GetInTrainingMission(lua_State *);
    int ScriptCB_SaveMissionSetup(lua_State *);
    int ScriptCB_LoadMissionSetup(lua_State *);
    int ScriptCB_ClearMissionSetup(lua_State *);
    int ScriptCB_IsMissionSetupSaved(lua_State *);
    int ScriptCB_PlayerSuicide(lua_State *);
    int ScriptCB_AutoNetJoin(lua_State *);
    int ScriptCB_GetOnlineService(lua_State *);
    int ScriptCB_SetAmHost(lua_State *);
    int ScriptCB_GetAmHost(lua_State *);
    int ScriptCB_GetWasHost(lua_State *);
    int ScriptCB_InNetGame(lua_State *);
    int ScriptCB_SetInNetGame(lua_State *);
    int ScriptCB_InMultiplayer(lua_State *);
    int ScriptCB_InNetSession(lua_State *);
    int ScriptCB_NetWasHost(lua_State *);
    int ScriptCB_NetWasDedicated(lua_State *);
    int ScriptCB_NetWasDedicatedQuit(lua_State *);
    int ScriptCB_NetWasClient(lua_State *);
    int ScriptCB_IsDedicated(lua_State *);
    int ScriptCB_SetDedicated(lua_State *);
    int ScriptCB_IsInShell(lua_State *);
    int ScriptCB_IsAutoNet(lua_State *);
    int ScriptCB_EndAutoNet(lua_State *);
    int ScriptCB_GetAutoNetMode(lua_State *);
    int ScriptCB_OpenNetShell(lua_State *);
    int ScriptCB_IsNetworkOn(lua_State *);
    int ScriptCB_CloseNetShell(lua_State *);
    int ScriptCB_IsBootInvitePending(lua_State *);
    int ScriptCB_GetAutoAssignTeams(lua_State *);
    int ScriptCB_SetNumBots(lua_State *);
    int ScriptCB_GetGameName(lua_State *);
    int ScriptCB_SetGameName(lua_State *);
    int ScriptCB_SetConnectType(lua_State *);
    int ScriptCB_GetConnectType(lua_State *);
    int ScriptCB_EnableJournal(lua_State *);
    int ScriptCB_EnablePlayback(lua_State *);
    int ScriptCB_GetLatestError(lua_State *);
    int ScriptCB_GetError(lua_State *);
    int ScriptCB_ClearError(lua_State *);
    int ScriptCB_IsLoginDone(lua_State *);
    int ScriptCB_IsLoggedIn(lua_State *);
    int ScriptCB_GetLoginName(lua_State *);
    int ScriptCB_StartLoginDedicatedServer(lua_State *);
    int ScriptCB_StartLogin(lua_State *);
    int ScriptCB_CancelLogin(lua_State *);
    int ScriptCB_TrackLoginErrors(lua_State *);
    int ScriptCB_IsGuest(lua_State *);
    int ScriptCB_BeginLobby(lua_State *);
    int ScriptCB_GetLobbyPlayerlist(lua_State *);
    int ScriptCB_UpdateLobby(lua_State *);
    int ScriptCB_HasServerLaunched(lua_State *);
    int ScriptCB_LaunchLobby(lua_State *);
    int ScriptCB_CancelLobby(lua_State *);
    int ScriptCB_LobbyAction(lua_State *);
    int ScriptCB_VoteKick(lua_State *);
    int ScriptCB_VoteOrNominate(lua_State *);
    int ScriptCB_BeginSessionList(lua_State *);
    int ScriptCB_ClearPrevSessionId(lua_State *);
    int ScriptCB_GetSessionListPercent(lua_State *);
    int ScriptCB_UpdateSessionList(lua_State *);
    int ScriptCB_LaunchSessionList(lua_State *);
    int ScriptCB_CancelSessionList(lua_State *);
    int ScriptCB_PauseSessionList(lua_State *);
    int ScriptCB_IsSessionReady(lua_State *);
    int ScriptCB_GetExtraSessionInfo(lua_State *);
    int ScriptCB_GetFilters(lua_State *);
    int ScriptCB_SetFilters(lua_State *);
    int ScriptCB_ApplyFilters(lua_State *);
    int ScriptCB_GetSessionSortMode(lua_State *);
    int ScriptCB_SetSessionSortMode(lua_State *);
    int ScriptCB_SetAsFavorite(lua_State *);
    int ScriptCB_GetSessionList(lua_State *);
    int ScriptCB_NextHost(lua_State *);
    int ScriptCB_PreviousHost(lua_State *);
    int ScriptCB_IsSpecialJoinPending(lua_State *);
    int ScriptCB_IsCmdlineJoinPending(lua_State *);
    int ScriptCB_IsGamespyArcadePasswordReady(lua_State *);
    int ScriptCB_GetCmdlineLogin(lua_State *);
    int ScriptCB_BeginQuickmatch(lua_State *);
    int ScriptCB_BeginJoinIP(lua_State *);
    int ScriptCB_BeginJoinSpecial(lua_State *);
    int ScriptCB_UpdateQuickmatch(lua_State *);
    int ScriptCB_LaunchQuickmatch(lua_State *);
    int ScriptCB_CancelQuickmatch(lua_State *);
    int ScriptCB_IsQuickmatchDone(lua_State *);
    int ScriptCB_IsQuickmatchPassworded(lua_State *);
    int ScriptCB_CanSupportMaxPlayers(lua_State *);
    int ScriptCB_IsBadNetworkConnection(lua_State *);
    int ScriptCB_BeginJoin(lua_State *);
    int ScriptCB_UpdateJoin(lua_State *);
    int ScriptCB_LaunchJoin(lua_State *);
    int ScriptCB_CancelJoin(lua_State *);
    int ScriptCB_IsJoinDone(lua_State *);
    int ScriptCB_BeginLeave(lua_State *);
    int ScriptCB_UpdateLeave(lua_State *);
    int ScriptCB_LaunchLeave(lua_State *);
    int ScriptCB_CancelLeave(lua_State *);
    int ScriptCB_IsLeaveDone(lua_State *);
    int ScriptCB_IsNetHWPresent(lua_State *);
    int ScriptCB_IsNetCableIn(lua_State *);
    int ScriptCB_SetNoticeNoCable(lua_State *);
    int ScriptCB_GetIPAddr(lua_State *);
    int ScriptCB_SetNetLoginName(lua_State *);
    int ScriptCB_GetLobbyPlayerFlags(lua_State *);
    int ScriptCB_GetGSProfileInfo(lua_State *);
    int ScriptCB_SetGSProfileInfo(lua_State *);
    int ScriptCB_BeginFriends(lua_State *);
    int ScriptCB_CancelFriends(lua_State *);
    int ScriptCB_UpdateFriends(lua_State *);
    int ScriptCB_GetFriendStateStr(lua_State *);
    int ScriptCB_GetFriendActions(lua_State *);
    int ScriptCB_DoFriendAction(lua_State *);
    int ScriptCB_GetFriendListIcon(lua_State *);
    int ScriptCB_AllowSkipDNAS(lua_State *);
    int ScriptCB_CheckForPatch(lua_State *);
    int ScriptCB_SkipToNTGUI(lua_State *);
    int ScriptCB_GetSkipToNTGUIProfileName(lua_State *);
    int ScriptCB_ResetSkipToNTGUI(lua_State *);
    int ScriptCB_GetLobbyPlayerCount(lua_State *);
    int ScriptCB_VoiceEnable(lua_State *);
    int ScriptCB_GetVoiceEnable(lua_State *);
    int ScriptCB_SetVoiceLocalEchoEnable(lua_State *);
    int ScriptCB_SetVoiceSendPreset(lua_State *);
    int ScriptCB_GetVoiceSendPreset(lua_State *);
    int ScriptCB_SetVoiceReceivePreset(lua_State *);
    int ScriptCB_GetVoiceReceivePreset(lua_State *);
    int ScriptCB_SetVoiceSendEnable(lua_State *);
    int ScriptCB_GetVoiceSendStatus(lua_State *);
    int ScriptCB_SetVoiceReceiveEnable(lua_State *);
    int ScriptCB_GetVoiceReceiveStatus(lua_State *);
    int ScriptCB_GetVoiceRenderConnected(lua_State *);
    int ScriptCB_GetVoiceCaptureConnected(lua_State *);
    int ScriptCB_GetVoiceTVGain(lua_State *);
    int ScriptCB_CanClientLeaveStats(lua_State *);
    int ScriptCB_SearchStatsRank(lua_State *);
    int ScriptCB_GetBandwidth(lua_State *);
    int ScriptCB_SetBandwidth(lua_State *);
    int ScriptCB_GetPlayerAwardsEnabled(lua_State *);
    int ScriptCB_SetPlayerAwardsEnabled(lua_State *);
    int ScriptCB_LastSignInError(lua_State *);
    int ScriptCB_SetSplitscreen(lua_State *);
    int ScriptCB_GetNumCameras(lua_State *);
    int ScriptCB_IsSplitscreen(lua_State *);
    int ScriptCB_WasSplitscreen(lua_State *);
    int ScriptCB_SetPlayerSide(lua_State *);
    int ScriptCB_SetDifficulty(lua_State *);
    int ScriptCB_GetDifficulty(lua_State *);
    int ScriptCB_GetCTFCaptureLimit(lua_State *);
    int ScriptCB_GetHuntMaxTimeLimit(lua_State *);
    int ScriptCB_GetHuntScoreLimit(lua_State *);
    int ScriptCB_ShowHuntScoreLimit(lua_State *);
    int ScriptCB_GetCTFMaxTimeLimit(lua_State *);
    int ScriptCB_GetAssaultScoreLimit(lua_State *);
    int ScriptCB_GetUberScoreLimit(lua_State *);
    int ScriptCB_SetUberScoreLimit(lua_State *);
    int ScriptCB_GetCONMaxTimeLimit(lua_State *);
    int ScriptCB_GetCONNumBots(lua_State *);
    int ScriptCB_GetCTFNumBots(lua_State *);
    int ScriptCB_GetASSNumBots(lua_State *);
    int ScriptCB_SetNumBots_(lua_State *);
    int ScriptCB_GetFunctionIdForAnalogId(lua_State *);
    int ScriptCB_SetFunctionIdForAnalogId(lua_State *);
    int ScriptCB_GetFunctionIdForButtonId(lua_State *);
    int ScriptCB_SetFunctionIdForButtonId(lua_State *);
    int ScriptCB_SetSpectatorMode(lua_State *);
    int ScriptCB_GetSpectatorMode(lua_State *);
    int ScriptCB_SetCanSwitchSides(lua_State *);
    int ScriptCB_SetGameRules(lua_State *);
    int ScriptCB_GetGameRules(lua_State *);
    int ScriptCB_SetAIDifficulty(lua_State *);
    int ScriptCB_IsMetaAllMapsOn(lua_State *);
    int ScriptCB_SetMetaAllMapsOn(lua_State *);
    int ScriptCB_GetYAxisFlip(lua_State *);
    int ScriptCB_SetYAxisFlip(lua_State *);
    int ScriptCB_GetMouseTurnAssist(lua_State *);
    int ScriptCB_SetMouseTurnAssist(lua_State *);
    int ScriptCB_GetControlScale(lua_State *);
    int ScriptCB_SetControlScale(lua_State *);
    int ScriptCB_ResetGameOptionsToDefault(lua_State *);
    int ScriptCB_ResetSoundToDefault(lua_State *);
    int ScriptCB_ResetOnlineOptionsToDefault(lua_State *);
    int ScriptCB_ResetControlsToDefault(lua_State *);
    int ScriptCB_GetGeneralOptions(lua_State *);
    int ScriptCB_SetGeneralOptions(lua_State *);
    int ScriptCB_IsHorizontalSplitScreen(lua_State *);
    int ScriptCB_SetHorizontalSplitScreen(lua_State *);
    int ScriptCB_SetHUDScale(lua_State *);
    int ScriptCB_GetHUDScale(lua_State *);
    int ScriptCB_NextToolTipState(lua_State *);
    int ScriptCB_PrevToolTipState(lua_State *);
    int ScriptCB_SetToolTipState(lua_State *);
    int ScriptCB_ResetToolTips(lua_State *);
    int ScriptCB_SetControlMode(lua_State *);
    int ScriptCB_GetControlMode(lua_State *);
    int ScriptCB_GetSideSelectButtonSetting(lua_State *);
    int ScriptCB_SetOnlineOpts(lua_State *);
    int ScriptCB_GetOnlineOpts(lua_State *);
    int ScriptCB_GetNetGameDefaults(lua_State *);
    int ScriptCB_SetNetGameDefaults(lua_State *);
    int ScriptCB_GetNetHeroDefaults(lua_State *);
    int ScriptCB_SetNetHeroDefaults(lua_State *);
    int ScriptCB_GetMouseSensitivity(lua_State *);
    int ScriptCB_GetJoySensitivity(lua_State *);
    int ScriptCB_GetDeadZone(lua_State *);
    int ScriptCB_SetMouseSensitivity(lua_State *);
    int ScriptCB_SetJoySensitivity(lua_State *);
    int ScriptCB_SetDeadZone(lua_State *);
    int ScriptCB_IsJoystickEnabled(lua_State *);
    int ScriptCB_SetJoystickEnabled(lua_State *);
    int ScriptCB_SetReticuleTransparency(lua_State *);
    int ScriptCB_GetReticuleTransparency(lua_State *);
    int ScriptCB_FillResolutionTable(lua_State *);
    int ScriptCB_FillMultisampleTable(lua_State *);
    int ScriptCB_SetResolution(lua_State *);
    int ScriptCB_GetIdealResolution(lua_State *);
    int ScriptCB_GetCustomResolution(lua_State *);
    int ScriptCB_GetPCVideoOptions(lua_State *);
    int ScriptCB_GetCustomVideoOptions(lua_State *);
    int ScriptCB_GetAutodetectPCVideoOptions(lua_State *);
    int ScriptCB_SetPCVideoOptions(lua_State *);
    int ScriptCB_SetPCBrightnessContrast(lua_State *);
    int ScriptCB_IsPCVideoFixedFunction(lua_State *);
    int ScriptCB_GetProfileJoinIP(lua_State *);
    int ScriptCB_SetProfileJoinIP(lua_State *);
    int ScriptCB_ResetPCVideoOptionsToDefault(lua_State *);
    int ScriptCB_SetMouseMark(lua_State *);
    int ScriptCB_ResetMouseMark(lua_State *);
    int ScriptCB_CheckMouseMark(lua_State *);
    int ScriptCB_GetKeyboardPCFlags(lua_State *);
    int ScriptCB_EnableCursor_(lua_State *);
    int ScriptCB_SndBusFade(lua_State *);
    int ScriptCB_SndPlaySound(lua_State *);
    int ScriptCB_SetBleedingRepeatTime(lua_State *);
    int ScriptCB_SetSpawnDisplayGain(lua_State *);
    int ScriptCB_PlayInGameMusic(lua_State *);
    int ScriptCB_StopInGameMusic(lua_State *);
    int ScriptCB_EnableCommandPostVO(lua_State *);
    int ScriptCB_EnableHeroMusic(lua_State *);
    int ScriptCB_EnableHeroVO(lua_State *);
    int ScriptCB_TriggerSoundRegionEnable(lua_State *);
    int ScriptCB_GetVolumes(lua_State *);
    int ScriptCB_SetVolumes(lua_State *);
    int ScriptCB_EffectsEnabled(lua_State *);
    int ScriptCB_ToggleEffects(lua_State *);
    int ScriptCB_HWSupport(lua_State *);
    int ScriptCB_GetOutputMode(lua_State *);
    int ScriptCB_PreviousOutputMode(lua_State *);
    int ScriptCB_NextOutputMode(lua_State *);
    int ScriptCB_SetOutputMode(lua_State *);
    int ScriptCB_GetMixConfig(lua_State *);
    int ScriptCB_PreviousMixConfig(lua_State *);
    int ScriptCB_NextMixConfig(lua_State *);
    int ScriptCB_SetMixConfig(lua_State *);
    int ScriptCB_GetEAXVersion(lua_State *);
    int ScriptCB_GetMixConfigChanged(lua_State *);
    int ScriptCB_SetBassManagement(lua_State *);
    int ScriptCB_GetBassManagement(lua_State *);
    int ScriptCB_PlayAuditionEffect(lua_State *);
    int ScriptCB_SetShellMusic(lua_State *);
    int ScriptCB_SetShellMusicInterval(lua_State *);
    int ScriptCB_IsShellMusicPlaying(lua_State *);
    int ScriptCB_ShellPlayDelayedStream(lua_State *);
    int ScriptCB_SoundEnable(lua_State *);
    int ScriptCB_SoundDisable(lua_State *);
    int ScriptCB_SetDopplerFactor(lua_State *);
    int ScriptCB_ClientGotStats(lua_State *);
    int ScriptCB_SetTeamStatsSortMode(lua_State *);
    int ScriptCB_GetTeamstats(lua_State *);
    int ScriptCB_TeamStatsGetTeam1(lua_State *);
    int ScriptCB_TeamStatsGetTeamColor(lua_State *);
    int ScriptCB_TeamStatsSetTitles(lua_State *);
    int ScriptCB_PersonalStatsSetTitles(lua_State *);
    int ScriptCB_TeamStatsValidatePos(lua_State *);
    int ScriptCB_GetPersonalStats(lua_State *);
    int ScriptCB_GetAwardStats(lua_State *);
    int ScriptCB_GetMedalStats(lua_State *);
    int ScriptCB_GetCareerPersonalStats(lua_State *);
    int ScriptCB_GetCareerRank(lua_State *);
    int ScriptCB_GetCareerMedals(lua_State *);
    int ScriptCB_GetCareerMedalLevel(lua_State *);
    int ScriptCB_SetPlayerStatsPoints(lua_State *);
    int ScriptCB_GetRank(lua_State *);
    int ScriptCB_GetPlayerIDAtRank(lua_State *);
}
