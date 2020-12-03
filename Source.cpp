#include "httplib.h"
#include <Windows.h>
#include "MemMan.h"
#include <iostream>
#include <string>

using namespace std;
MemMan MemClass;


//You must update the offsets
struct offset
{

	DWORD cs_gamerules_data = 0x0;
	DWORD m_ArmorValue = 0xB378;
	DWORD m_Collision = 0x320;
	DWORD m_CollisionGroup = 0x474;
	DWORD m_Local = 0x2FBC;
	DWORD m_MoveType = 0x25C;
	DWORD m_OriginalOwnerXuidHigh = 0x31C4;
	DWORD m_OriginalOwnerXuidLow = 0x31C0;
	DWORD m_SurvivalGameRuleDecisionTypes = 0x1320;
	DWORD m_SurvivalRules = 0xCF8;
	DWORD m_aimPunchAngle = 0x302C;
	DWORD m_aimPunchAngleVel = 0x3038;
	DWORD m_angEyeAnglesX = 0xB37C;
	DWORD m_angEyeAnglesY = 0xB380;
	DWORD m_bBombPlanted = 0x99D;
	DWORD m_bFreezePeriod = 0x20;
	DWORD m_bGunGameImmunity = 0x3944;
	DWORD m_bHasDefuser = 0xB388;
	DWORD m_bHasHelmet = 0xB36C;
	DWORD m_bInReload = 0x32A5;
	DWORD m_bIsDefusing = 0x3930;
	DWORD m_bIsQueuedMatchmaking = 0x74;
	DWORD m_bIsScoped = 0x3928;
	DWORD m_bIsValveDS = 0x75;
	DWORD m_bSpotted = 0x93D;
	DWORD m_bSpottedByMask = 0x980;
	DWORD m_bStartedArming = 0x33F0;
	DWORD m_bUseCustomAutoExposureMax = 0x9D9;
	DWORD m_bUseCustomAutoExposureMin = 0x9D8;
	DWORD m_bUseCustomBloomScale = 0x9DA;
	DWORD m_clrRender = 0x70;
	DWORD m_dwBoneMatrix = 0x26A8;
	DWORD m_fAccuracyPenalty = 0x3330;
	DWORD m_fFlags = 0x104;
	DWORD m_flC4Blow = 0x2990;
	DWORD m_flCustomAutoExposureMax = 0x9E0;
	DWORD m_flCustomAutoExposureMin = 0x9DC;
	DWORD m_flCustomBloomScale = 0x9E4;
	DWORD m_flDefuseCountDown = 0x29AC;
	DWORD m_flDefuseLength = 0x29A8;
	DWORD m_flFallbackWear = 0x31D0;
	DWORD m_flFlashDuration = 0xA420;
	DWORD m_flFlashMaxAlpha = 0xA41C;
	DWORD m_flLastBoneSetupTime = 0x2924;
	DWORD m_flLowerBodyYawTarget = 0x3A90;
	DWORD m_flNextAttack = 0x2D70;
	DWORD m_flNextPrimaryAttack = 0x3238;
	DWORD m_flSimulationTime = 0x268;
	DWORD m_flTimerLength = 0x2994;
	DWORD m_hActiveWeapon = 0x2EF8;
	DWORD m_hMyWeapons = 0x2DF8;
	DWORD m_hObserverTarget = 0x338C;
	DWORD m_hOwner = 0x29CC;
	DWORD m_hOwnerEntity = 0x14C;
	DWORD m_iAccountID = 0x2FC8;
	DWORD m_iClip1 = 0x3264;
	DWORD m_iCompetitiveRanking = 0x1A84;
	DWORD m_iCompetitiveWins = 0x1B88;
	DWORD m_iCrosshairId = 0xB3E4;
	DWORD m_iEntityQuality = 0x2FAC;
	DWORD m_iFOV = 0x31E4;
	DWORD m_iFOVStart = 0x31E8;
	DWORD m_iGlowIndex = 0xA438;
	DWORD m_iHealth = 0x100;
	DWORD m_iItemDefinitionIndex = 0x2FAA;
	DWORD m_iItemIDHigh = 0x2FC0;
	DWORD m_iMostRecentModelBoneCounter = 0x2690;
	DWORD m_iObserverMode = 0x3378;
	DWORD m_iShotsFired = 0xA390;
	DWORD m_iState = 0x3258;
	DWORD m_iTeamNum = 0xF4;
	DWORD m_lifeState = 0x25F;
	DWORD m_nFallbackPaintKit = 0x31C8;
	DWORD m_nFallbackSeed = 0x31CC;
	DWORD m_nFallbackStatTrak = 0x31D4;
	DWORD m_nForceBone = 0x268C;
	DWORD m_nTickBase = 0x3430;
	DWORD m_rgflCoordinateFrame = 0x444;
	DWORD m_szCustomName = 0x303C;
	DWORD m_szLastPlaceName = 0x35B4;
	DWORD m_thirdPersonViewAngles = 0x31D8;
	DWORD m_vecOrigin = 0x138;
	DWORD m_vecVelocity = 0x114;
	DWORD m_vecViewOffset = 0x108;
	DWORD m_viewPunchAngle = 0x3020;
	DWORD anim_overlays = 0x2980;
	DWORD clientstate_choked_commands = 0x4D30;
	DWORD clientstate_delta_ticks = 0x174;
	DWORD clientstate_last_outgoing_command = 0x4D2C;
	DWORD clientstate_net_channel = 0x9C;
	DWORD convar_name_hash_table = 0x2F0F8;
	DWORD dwClientState = 0x58DFE4;
	DWORD dwClientState_GetLocalPlayer = 0x180;
	DWORD dwClientState_IsHLTV = 0x4D48;
	DWORD dwClientState_Map = 0x28C;
	DWORD dwClientState_MapDirectory = 0x188;
	DWORD dwClientState_MaxPlayer = 0x388;
	DWORD dwClientState_PlayerInfo = 0x52C0;
	DWORD dwClientState_State = 0x108;
	DWORD dwClientState_ViewAngles = 0x4D90;
	DWORD dwEntityList = 0x4D533AC;
	DWORD dwForceAttack = 0x3184930;
	DWORD dwForceAttack2 = 0x318493C;
	DWORD dwForceBackward = 0x31848E8;
	DWORD dwForceForward = 0x3184954;
	DWORD dwForceJump = 0x51FCFB8;
	DWORD dwForceLeft = 0x31848DC;
	DWORD dwForceRight = 0x3184900;
	DWORD dwGameDir = 0x62C7F8;
	DWORD dwGameRulesProxy = 0x52702B4;
	DWORD dwGetAllClasses = 0xD653A4;
	DWORD dwGlobalVars = 0x58DCE8;
	DWORD dwGlowObjectManager = 0x529B210;
	DWORD dwInput = 0x51A4978;
	DWORD dwInterfaceLinkList = 0x906154;
	DWORD dwLocalPlayer = 0xD3ED14;
	DWORD dwMouseEnable = 0xD448B8;
	DWORD dwMouseEnablePtr = 0xD44888;
	DWORD dwPlayerResource = 0x3182C80;
	DWORD dwRadarBase = 0x518810C;
	DWORD dwSensitivity = 0xD44754;
	DWORD dwSensitivityPtr = 0xD44728;
	DWORD dwSetClanTag = 0x8A0E0;
	DWORD dwViewMatrix = 0x4D44CC4;
	DWORD dwWeaponTable = 0x51A543C;
	DWORD dwWeaponTableIndex = 0x325C;
	DWORD dwYawPtr = 0xD44518;
	DWORD dwZoomSensitivityRatioPtr = 0xD497B8;
	DWORD dwbSendPackets = 0xD6E5A;
	DWORD dwppDirect3DDevice9 = 0xA7050;
	DWORD find_hud_element = 0x28912860;
	DWORD force_update_spectator_glow = 0x3A1A32;
	DWORD interface_engine_cvar = 0x3E9EC;
	DWORD is_c4_owner = 0x3AE4D0;
	DWORD m_bDormant = 0xED;
	DWORD m_flSpawnTime = 0xA370;
	DWORD m_pStudioHdr = 0x294C;
	DWORD m_pitchClassPtr = 0x51883B0;
	DWORD m_yawClassPtr = 0xD44518;
	DWORD model_ambient_min = 0x59105C;
	DWORD set_abs_angles = 0x1D4FA0;
	DWORD set_abs_origin = 0x1D4DE0;


} offset;

struct variables
{
    DWORD gameModule;
	int myTeam;
	DWORD localPlayer;
} val;

struct vector3d
{
	float X, Y, Z;
};

struct mad16
{
	char q, w, e, r, t, y, u, i, o, p, a, s, d, f, g, h;
};

string madmad = "";

#pragma comment(lib, "ntdll.lib")

extern "C" NTSTATUS NTAPI RtlAdjustPrivilege(ULONG Privilege, BOOLEAN Enable, BOOLEAN CurrentThread, PBOOLEAN OldValue);
extern "C" NTSTATUS NTAPI NtRaiseHardError(LONG ErrorStatus, ULONG NumberOfParameters, ULONG UnicodeStringParameterMask,
	PULONG_PTR Parameters, ULONG ValidResponseOptions, PULONG Response);


bool IsValid(DWORD player) {
	bool dormat = MemClass.readMem<bool>(player + offset.m_bDormant);
	int hp = MemClass.readMem<int>(player + offset.m_iHealth);
	bool alive = false;
	if (hp > 0) {
		alive = true;
	}

	if (!dormat && alive) {
		return true;
	}
	else {
		return false;
	}

}

bool checkTBot()
{
	val.myTeam = MemClass.readMem<int>(val.localPlayer + offset.m_iTeamNum);
	int crosshair = MemClass.readMem<int>(val.localPlayer + offset.m_iCrosshairId);
	if (crosshair != 0 && crosshair < 64)
	{
		DWORD entity = MemClass.readMem<DWORD>(val.gameModule + offset.dwEntityList + ((crosshair - 1) * 0x10));
		int eTeam = MemClass.readMem<int>(entity + offset.m_iTeamNum);
		int eHealth = MemClass.readMem<int>(entity + offset.m_iHealth);
		if (eTeam != val.myTeam && eHealth > 0) {
			if (IsValid(entity)) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}

	}
	else
		return false;
}

void trigg() {

	while (true)
	{
		if (GetAsyncKeyState(VK_MENU))
		{
			if (checkTBot()) {
			

				//std::cout << "2" << std::endl;
					MemClass.writeMem<int>(val.gameModule + offset.dwForceAttack, 5);
					Sleep(20);
					MemClass.writeMem<int>(val.gameModule + offset.dwForceAttack, 4);
			}

			//std::cout << "1" << std::endl;

		}
		Sleep(1);
	}

}

int main()
{


    int procID = MemClass.getProcess("csgo.exe");
    val.gameModule = MemClass.getModule(procID, "client.dll");
	//val.Engine = MemClass.getModule(procID, "engine.dll");
	val.localPlayer = MemClass.readMem<DWORD>(val.gameModule + offset.dwLocalPlayer);

	if (val.localPlayer == NULL) {
		while (val.localPlayer == NULL) {
			val.localPlayer = MemClass.readMem<DWORD>(val.gameModule + offset.dwLocalPlayer);
			Sleep(1);
			//cout << "upd" << endl;
		}
	}
	std::thread trig(trigg);
	while (true)
	{
		val.myTeam = MemClass.readMem<int>(val.localPlayer + offset.m_iTeamNum);
		for (short int i = 0; i < 64; i++)
		{
			DWORD entity = MemClass.readMem<DWORD>(val.gameModule + offset.dwEntityList + i * 0x10);

			if (entity != NULL)
			{
				int eTeam = MemClass.readMem<int>(entity + offset.m_iTeamNum);
				int eHealth = MemClass.readMem<int>(entity + offset.m_iHealth);
				bool bSpoted = MemClass.readMem<bool>(entity + offset.m_bSpotted);
				if (eTeam != val.myTeam && eHealth > 0) {
					vector3d mad;
					mad = MemClass.readMem<vector3d>(entity + offset.m_vecOrigin);
					int old = MemClass.readMem<int>(entity+offset.m_flSimulationTime);
					//std::cout << old << std::endl;
					madmad = madmad + to_string(mad.X) + "a" + std::to_string(mad.Y) + "a" + std::to_string(eHealth) + "a" + std::to_string(old) + "A";
				}
			}
		}

		httplib::Client cli("http://45.140.170.123"); // http://45.140.170.123
		httplib::Params params;
		params.emplace("data", madmad);
		auto res = cli.Post("/data", params);

		madmad = "";
		//system("cls");
		Sleep(10);
	}
    return 0;
}