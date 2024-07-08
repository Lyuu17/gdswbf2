
#include <lua.h>

#include "LuaCallbacks.hpp"
#include "ScriptCB.hpp"

namespace SWBF2::Native::Scripting::Lua
{
    int ScriptCB_DoFile(lua_State *L)
    {
        return 1;
    }

    int ScriptCB_GetPlatform(lua_State *L)
    {
        lua_pushstring(L, "pc");

        return 1;
    }

    int ScriptCB_GetLanguage(lua_State *L)
    {
        lua_pushstring(L, "english");

        return 1;
    }

    int ScriptCB_FormatTimeString(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetVKeyboardCharacter(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsLegalGamespyString(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_tounicode(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_UnicodeStrCat(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_ununicode(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_getlocalizestr(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_usprintf(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_ustrupper(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_srand(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_random(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetDateStr(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetShellActive(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetAutoAcquireControllers(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_ReadAllControllers(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_UnbindController(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetPrimaryController(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetSecondaryController(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsControllerConnected(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsControllerBound(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SwapPrimaryController(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetHotController(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_RestorePrimaryController(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetIgnoreControllerRemoval(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetNumControllers(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetMaxControllers(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetAutoNetIsDedicated(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetAutoNetGameName(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetAutoGetPlayerCount(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetupAutoNetMissions(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetupAutoNetIsLan(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetAutoNetScript(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_ReadLeftstick(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetQuitPlayer(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetQuitPlayer(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetMaxMissionQueue(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetMissionNames(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetTeamNames(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_EnterMission(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_LaunchDemo(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_Reboot(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetPausingViewport(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetPausingJoystick(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_PausingIsPrimary(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetBuildStr(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_UpdateScreen(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_UnlockableState(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_UnlockUnlockable(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_ShouldShowLegal(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_PauseDemoTimer(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_ShouldShowDemoPostscreen(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_ShouldCheckDNAS(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_DoneCheckDNAS(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_HasSeenDNASEULA(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetHasSeenDNASEULA(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_ShouldCheckPatch(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_DoneCheckPatch(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IndexMultipageText(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_ShowMultipageText(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetDCMap(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_HideDownloadableContent(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_RestartMission(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_Unpause(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SkipToPlayerList(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_ResetSkipToPlayerList(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_CheckPlayerListDone(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetMissionTime(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_Freecamera(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsGameOver(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_QuitToShell(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_QuitToWindows(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_MinimizeWindow(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_QuitFromStats(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetTeamName(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetSPProgress(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetSPProgress(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetLastBattleVictory(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetLastBattleVictoryValid(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_MetagameSetBonus(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_MetagameSetSide(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_DisableFlyerShadows(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_EnableScene(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_PostLoadHack(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFObj_SetPos(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFObj_GetPos(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFObj_SetBasicRotation(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFObj_SetRelativeRotation(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFObj_SetRotation(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFObj_SetAlpha(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFObj_GetAlpha(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFObj_SetColor(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFObj_GetColor(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFObj_SetZOrder(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFObj_GetZOrder(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFObj_BringToFront(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFObj_SendToBack(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFObj_Enable(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFObj_IsEnabled(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFObj_IsGroup(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFObj_SetVis(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFObj_SetEnabled(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFObj_GetVis(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFObj_SetWidthHeight(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFObj_GetWidthHeight(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFObj_SetPosition(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFObj_GetPosition(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFObj_MouseOver(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFObj_TestHotSpot(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFObj_CreateHotSpot(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFObj_RemoveHotSpot(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetFontHeight(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFText_SetString(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFText_SetUString(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFText_SetTextPosition(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFText_SetFont(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFText_SetJustify(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFText_SetTextBreak(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFText_SetTextScale(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFText_GetTextScaleX(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFText_GetTextScaleY(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFText_GetTextExtent(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFText_GetDisplayRect(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFText_SetIntercharacterSpacin(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFText_GetIntercharacterSpacin(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFText_SetTextBox(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFText_GetTextBox(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFText_SetTextStyle(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFText_SetLeading(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFText_GetLeading(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFFlashyText_Setup(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFFlashyText_SetTextColor(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFFlashyText_SetBackground(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFFlashyText_SetBackgroundSize(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFFlashyText_SetBackgroundRigh(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFFlashyText_StartFlashiness(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFImage_SetTexture(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFImage_GetRect(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFImage_SetRect(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFImage_GetTexCoords(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFImage_SetTexCoords(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFMaskImage_SetMaskTexture(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFMaskImage_SetMaskTexCoords(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFMaskImage_GetMaskTexCoords(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFBorder_SetTexture(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFBorder_GetRect(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFBorder_SetRect(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFBorder_GetTexCoords(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFBorder_SetTexCoords(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFModel_SetModel(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFModel_SetAnimation(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFModel_QueueAnimation(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFModel_SetAnimationBanks(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFModel_SetAnimationTime(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFModel_AttachModel(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFModel_SetScale(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFModel_GetScale(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFModel_SetRotation(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFModel_GetRotation(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFModel_SetTranslation(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFModel_GetTranslation(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFModel_SetDepth(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFModel_GetDepth(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFModel_SetOmegaY(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFModel_SetLighting(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFModel_UpdateAnimation(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFModel_SetAnimationLooping(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_AddIFScreen(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetIFScreenViewport(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_EndIFScreen(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsFileExist(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFObj_GetCPointer(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFObj_SetScreenPosition(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IFObj_SetUseSafezone(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_EndIFObj(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_AddIFText(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_AddIFFlashyText(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_AddIFImage(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_AddIFMaskImage(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_AddIFBorder(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_AddIFModel(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_AddIFContainer(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetIFScreen(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_PushScreen(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_PopScreen(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsScreenInStack(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_OpenPopup(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_ClosePopup(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsPopupOpen(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetIgnoreInputs(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_OpenMovie(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_CloseMovie(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_PlayMovie(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsMoviePlaying(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_AreMoviePropertiesPlaying(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_StopMovie(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetMovieAudioBus(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsPropertyPlayingNow(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_PlayInGameMovie(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_StopInGameMovie(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetScreenInfo(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetSafeScreenInfo(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsErrorBoxOpen(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_OpenErrorBox(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_CloseErrorBox(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetErrorLevel(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetConsoleCmds(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_DoConsoleCmd(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetLeaderBoardPlayerData(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_DownloadLeaderBoardData(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_LeaderBoardDownloadDone(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_CancelLeaderBoardPlayerData(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetLeaderBoardID(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_ResetLeaderBoardPlayerData(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_EnumerateLeaderBoard(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_EnumerateLeaderBoardDone(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetEnumerateLeaderBoardData(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsEnableLeaderBoard(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetSunlight(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_ResetControl(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetBinding(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetActionFromIdx(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetKeyBoardCmds(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_EnableCursor(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_MrMrsEval(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetEntityMesh(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetEntityWeaponMesh(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetEntityLabel(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetIFaceLighting(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetIFaceLighting(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_RemoveTexture(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_ShowLoadDisplay(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetInputRepeat(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetLoginList(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsCurProfileDirty(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsProfileDirty(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetProfileNotDirty(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_LoadSavePopupResult(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_DoInitialMemcardCheck(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_StartInitialMemcardCheck(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_StartPreOp(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsPlayerLoggedIn(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetCurrentProfileName(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetProfileName(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetCurrentProfileNetName(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetCurrentPCTitleVersion(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_AddProfile(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SwapActiveProfileSlots(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_StartLoadProfile(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_MakeFakeProfiles(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetProfileAsDefault(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_RestoreDefaultProfile(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_MarkCurrentProfile(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_ReloadMarkedProfile(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_HasProfileChanged(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_StartDeleteProfile(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_StartSaveProfile(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_StartLoadMetagame(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_StartSaveMetagame(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_StartDeleteMetagame(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsCurrentMetagame(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_StartLoadCampaign(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_StartSaveCampaign(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_StartDeleteCampaign(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsCurrentCampaign(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_TrimLoginName(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetUniqueLoginName(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsUniqueLoginName(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_MarkMemoryCard(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_CheckMemoryCardMark(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsMemoryCardUnformatted(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsMemoryCardInsertted(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_DoesProfileExistOnCard(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_InMemoryProfileMode(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetMemoryProfileMode(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_CheckIfOkToExitMemoryMode(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetSavedMetagameList(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_StartNewMetagame(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_DoesMetagameExistOnCard(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetSavedCampaignList(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_StartNewCampaign(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_DoesCampaignExistOnCard(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_Logout(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SaveMetagameState(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_LoadMetagameState(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_ClearMetagameState(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsMetagameStateSaved(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SaveCampaignState(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_LoadCampaignState(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_ClearCampaignState(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsCampaignStateSaved(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetInTrainingMission(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetInTrainingMission(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SaveMissionSetup(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_LoadMissionSetup(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_ClearMissionSetup(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsMissionSetupSaved(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_PlayerSuicide(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_AutoNetJoin(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetOnlineService(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetAmHost(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetAmHost(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetWasHost(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_InNetGame(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetInNetGame(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_InMultiplayer(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_InNetSession(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_NetWasHost(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_NetWasDedicated(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_NetWasDedicatedQuit(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_NetWasClient(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsDedicated(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetDedicated(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsInShell(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsAutoNet(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_EndAutoNet(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetAutoNetMode(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_OpenNetShell(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsNetworkOn(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_CloseNetShell(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsBootInvitePending(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetAutoAssignTeams(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetNumBots(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetGameName(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetGameName(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetConnectType(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetConnectType(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_EnableJournal(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_EnablePlayback(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetLatestError(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetError(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_ClearError(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsLoginDone(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsLoggedIn(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetLoginName(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_StartLoginDedicatedServer(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_StartLogin(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_CancelLogin(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_TrackLoginErrors(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsGuest(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_BeginLobby(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetLobbyPlayerlist(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_UpdateLobby(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_HasServerLaunched(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_LaunchLobby(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_CancelLobby(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_LobbyAction(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_VoteKick(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_VoteOrNominate(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_BeginSessionList(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_ClearPrevSessionId(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetSessionListPercent(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_UpdateSessionList(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_LaunchSessionList(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_CancelSessionList(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_PauseSessionList(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsSessionReady(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetExtraSessionInfo(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetFilters(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetFilters(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_ApplyFilters(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetSessionSortMode(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetSessionSortMode(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetAsFavorite(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetSessionList(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_NextHost(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_PreviousHost(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsSpecialJoinPending(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsCmdlineJoinPending(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsGamespyArcadePasswordReady(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetCmdlineLogin(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_BeginQuickmatch(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_BeginJoinIP(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_BeginJoinSpecial(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_UpdateQuickmatch(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_LaunchQuickmatch(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_CancelQuickmatch(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsQuickmatchDone(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsQuickmatchPassworded(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_CanSupportMaxPlayers(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsBadNetworkConnection(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_BeginJoin(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_UpdateJoin(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_LaunchJoin(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_CancelJoin(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsJoinDone(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_BeginLeave(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_UpdateLeave(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_LaunchLeave(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_CancelLeave(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsLeaveDone(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsNetHWPresent(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsNetCableIn(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetNoticeNoCable(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetIPAddr(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetNetLoginName(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetLobbyPlayerFlags(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetGSProfileInfo(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetGSProfileInfo(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_BeginFriends(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_CancelFriends(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_UpdateFriends(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetFriendStateStr(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetFriendActions(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_DoFriendAction(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetFriendListIcon(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_AllowSkipDNAS(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_CheckForPatch(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SkipToNTGUI(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetSkipToNTGUIProfileName(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_ResetSkipToNTGUI(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetLobbyPlayerCount(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_VoiceEnable(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetVoiceEnable(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetVoiceLocalEchoEnable(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetVoiceSendPreset(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetVoiceSendPreset(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetVoiceReceivePreset(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetVoiceReceivePreset(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetVoiceSendEnable(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetVoiceSendStatus(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetVoiceReceiveEnable(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetVoiceReceiveStatus(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetVoiceRenderConnected(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetVoiceCaptureConnected(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetVoiceTVGain(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_CanClientLeaveStats(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SearchStatsRank(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetBandwidth(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetBandwidth(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetPlayerAwardsEnabled(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetPlayerAwardsEnabled(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_LastSignInError(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetSplitscreen(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetNumCameras(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsSplitscreen(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_WasSplitscreen(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetPlayerSide(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetDifficulty(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetDifficulty(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetCTFCaptureLimit(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetHuntMaxTimeLimit(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetHuntScoreLimit(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_ShowHuntScoreLimit(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetCTFMaxTimeLimit(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetAssaultScoreLimit(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetUberScoreLimit(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetUberScoreLimit(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetCONMaxTimeLimit(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetCONNumBots(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetCTFNumBots(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetASSNumBots(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetNumBots_(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetFunctionIdForAnalogId(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetFunctionIdForAnalogId(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetFunctionIdForButtonId(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetFunctionIdForButtonId(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetSpectatorMode(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetSpectatorMode(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetCanSwitchSides(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetGameRules(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetGameRules(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetAIDifficulty(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsMetaAllMapsOn(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetMetaAllMapsOn(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetYAxisFlip(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetYAxisFlip(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetMouseTurnAssist(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetMouseTurnAssist(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetControlScale(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetControlScale(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_ResetGameOptionsToDefault(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_ResetSoundToDefault(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_ResetOnlineOptionsToDefault(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_ResetControlsToDefault(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetGeneralOptions(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetGeneralOptions(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsHorizontalSplitScreen(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetHorizontalSplitScreen(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetHUDScale(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetHUDScale(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_NextToolTipState(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_PrevToolTipState(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetToolTipState(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_ResetToolTips(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetControlMode(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetControlMode(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetSideSelectButtonSetting(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetOnlineOpts(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetOnlineOpts(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetNetGameDefaults(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetNetGameDefaults(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetNetHeroDefaults(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetNetHeroDefaults(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetMouseSensitivity(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetJoySensitivity(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetDeadZone(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetMouseSensitivity(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetJoySensitivity(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetDeadZone(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsJoystickEnabled(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetJoystickEnabled(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetReticuleTransparency(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetReticuleTransparency(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_FillResolutionTable(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_FillMultisampleTable(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetResolution(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetIdealResolution(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetCustomResolution(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetPCVideoOptions(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetCustomVideoOptions(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetAutodetectPCVideoOptions(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetPCVideoOptions(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetPCBrightnessContrast(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsPCVideoFixedFunction(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetProfileJoinIP(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetProfileJoinIP(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_ResetPCVideoOptionsToDefault(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetMouseMark(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_ResetMouseMark(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_CheckMouseMark(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetKeyboardPCFlags(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_EnableCursor_(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SndBusFade(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SndPlaySound(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetBleedingRepeatTime(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetSpawnDisplayGain(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_PlayInGameMusic(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_StopInGameMusic(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_EnableCommandPostVO(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_EnableHeroMusic(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_EnableHeroVO(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_TriggerSoundRegionEnable(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetVolumes(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetVolumes(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_EffectsEnabled(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_ToggleEffects(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_HWSupport(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetOutputMode(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_PreviousOutputMode(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_NextOutputMode(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetOutputMode(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetMixConfig(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_PreviousMixConfig(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_NextMixConfig(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetMixConfig(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetEAXVersion(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetMixConfigChanged(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetBassManagement(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetBassManagement(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_PlayAuditionEffect(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetShellMusic(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetShellMusicInterval(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_IsShellMusicPlaying(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_ShellPlayDelayedStream(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SoundEnable(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SoundDisable(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetDopplerFactor(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_ClientGotStats(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetTeamStatsSortMode(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetTeamstats(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_TeamStatsGetTeam1(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_TeamStatsGetTeamColor(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_TeamStatsSetTitles(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_PersonalStatsSetTitles(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_TeamStatsValidatePos(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetPersonalStats(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetAwardStats(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetMedalStats(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetCareerPersonalStats(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetCareerRank(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetCareerMedals(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetCareerMedalLevel(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_SetPlayerStatsPoints(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetRank(lua_State *L)
    {
        return 0;
    }

    int ScriptCB_GetPlayerIDAtRank(lua_State *L)
    {
        return 0;
    }
}
