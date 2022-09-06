#include "Offsets.h"
#include <string.h>
#include <string>
#include <xstring>
#include "utils.h"
#include <dwmapi.h>
#include "Definitions.h"
#include <sstream>
#include <stdio.h>
#include <stdio.h>
#include <stdio.h>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <list>
#include <sstream>
#include "xorstr.hpp"
#include <iostream>
#include <tlhelp32.h>
#include <fstream>
#include <filesystem>
#include <Windows.h>
#include <winioctl.h>
#include <lmcons.h>
#include <random>
#include "other.h"
#include <thread>
#include "driver.h"
#include "keybind.h"
#include "others/xor.h"
#include "others/auth.h"
#include "others/program.h"
#include "bytes.h"
#include "kdmapper.hpp"
#include "driver.h"
#include "api.h"
#include "Lazy.h"
#include "debugdetect.h"
#include "integrity_check.h"
#include "Obsidium Sdk/obsidium64.h"
#include "integrity.h"
#pragma comment(lib,"Version.lib")
#pragma comment(lib, "winmm.lib")
//#include <test.h>

#pragma comment(lib, "proxine.lib")
#pragma comment(lib, "urlmon.lib")
bool IsValid = false;
//#include <Users/jnerf/Desktop/vase dravvar/overlay.h>
#pragma comment (lib, "urlmon.lib")
float FOV = 80.0f;
int speed;
int flyspeed;
kernel::driver driver;
uintptr_t PlayerCameraManager;
uintptr_t CurrentWeapon;
static float OrginalPitchMax;
static float OrginalPitchMin;
struct ESettingType {
	struct ESettingType* MouseSensitivityYaw;// 0x00;
	struct ESettingType* MouseSensitivityPitch;// 0x00(0x4)
};
const char* items[] = { "Head", "Neck", "Chest", "Pelvis", "Random" };
static int item_current = 0;



/*
* 
*   __  __        _  ________ _   _ 
 |  \/  |   /\   | |/ /  ____| \ | |
 | \  / |  /  \  | ' /| |__  |  \| |
 | |\/| | / /\ \ |  < |  __| | . ` |
 | |  | |/ ____ \| . \| |    | |\  |
 |_|  |_/_/    \_\_|\_\_|    |_| \_|
    
* 
*/




std::string userid = EncryptString("504"); // ENTER USER ID
std::string ProgramID = EncryptString("wauYlx89SqzV"); // ENTER PROGRAM ID
std::string ProgramName = EncryptString("MakFn Slotted"); // ENTER PROGRAM Name
std::string ProgramEncryption = EncryptString("IGP5G6WCL3NYI814VXTAOXMHFE5QU2DN"); // ENTER PROGRAM Encryption Key
std::string ResponseSuccess = EncryptString("R4P5706L");
std::string ResponseInvalid = EncryptString("UTNSYOX3");
std::string ResponseExpired = EncryptString("6H1YNE83");
std::string ResponseHash = EncryptString("LTIYQKBY");
std::string ResponseHwid = EncryptString("SKMHJS0T");
std::string ResponseBanned = EncryptString("18U5HQ84");

namespace APlayerCameraManager
{
	DWORD DefaultFOV = 0x284;
};

float radarx = 50;
float radary = 700;

DWORD loopDbg(LPVOID in) {

	while (1) {
		if (GetAsyncKeyState(NULL) & 1) {
			
		}
		else
		{
			closethedebuggers();
			Sleep(2400);
			findwindowez();
			Sleep(2400);
			checkurmomez();
			Sleep(2400);
			//thread_context();
		}



	}
}



DWORD loopDbg2(LPVOID in) {

	while (1) {
		if (GetAsyncKeyState(NULL) & 1) {

		}
		else
		{

			is_present();
			Sleep(2400);
			//debug_string();
			Sleep(2400);
			hide_thread();
			remote_is_present();
			Sleep(2400);
		}



	}
}



std::string random_string(std::size_t length)
{

	const std::string CHARACTERS = _xor_("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890").c_str();

	std::random_device random_device;
	std::mt19937 generator(random_device());
	std::uniform_int_distribution<> distribution(0, CHARACTERS.size() - 1);

	std::string random_string;

	for (std::size_t i = 0; i < length; ++i)
	{
		random_string += CHARACTERS[distribution(generator)];
	}

	return random_string;
}


std::string GetNameByID(int id) {
	uint32_t ChunkOffset = (uint32_t)((int)(id) >> 16);
	uint16_t NameOffset = (uint16_t)id;

	uint64_t NamePoolChunk = driver.read<uint64_t>((uint64_t)dravarthangs::base_addy + 0xCCDFD00 + (8 * ChunkOffset) + 16) + (unsigned int)(4 * NameOffset);
	uint16_t nameEntry = driver.read<uint64_t>(NamePoolChunk);

	int nameLength = nameEntry >> 6;
	char buff[1024];
	if ((uint32_t)nameLength)
	{
		for (int x = 0; x < nameLength; ++x)
		{
			buff[x] = driver.read<char>(NamePoolChunk + 4 + x);
		}

		char* v2 = buff;
		signed int v4 = nameLength;
		uint64_t result;
		unsigned int v5;
		unsigned int v7;
		unsigned int v8;


		result = 28;
		v5 = driver.read<uint64_t>(dravarthangs::base_addy + 0xCBCC130) >> 5;;


		if (v4)
		{
			do
			{
				++v2;
				v7 = v5++ | 0xB000;
				v8 = v7 + result;
				v7 = v8 ^ ~*(BYTE*)(v2 - 1);
				result = v8 >> 2;
				*(BYTE*)(v2 - 1) = v7;
			} while (v5 < v4);
		}
		buff[nameLength] = '\0';
		return std::string(buff);
	}
	return "";
}



static std::string GetNameFromFName(int key)
{
	uint64_t NamePoolChunk = driver.read<uint64_t>(dravarthangs::base_addy + 0xCCDFD00 + (8 * (uint32_t)((int)(key) >> 16)) + 16) + (unsigned int)(4 * (uint16_t)key);

	if (driver.read<uint16_t>(NamePoolChunk) < 64)
	{
		auto a1 = driver.read<DWORD>(NamePoolChunk + 4);
		return GetNameByID(a1);
	}

	else
	{
		return GetNameByID(key);
	}
}

static void xCreateWindow();
static void xInitD3d();
static void xMainLoop();
static LRESULT CALLBACK WinProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam);
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

static HWND Window = NULL;
IDirect3D9Ex* p_Object = NULL;
static LPDIRECT3DDEVICE9 D3dDevice = NULL;
static LPDIRECT3DVERTEXBUFFER9 TriBuf = NULL;

FTransform GetBoneIndex(DWORD_PTR mesh, int index) {
	DWORD_PTR bonearray = driver.read<DWORD_PTR>(mesh + Offsets::BoneArray);
	if (bonearray == NULL) {
		bonearray = driver.read<DWORD_PTR>(mesh + Offsets::BoneArray + 0x10);
	}
	return driver.read<FTransform>(bonearray + (index * 0x60));
}

Vector3 GetBoneWithRotation(DWORD_PTR mesh, int id) {
	FTransform bone = GetBoneIndex(mesh, id);
	FTransform ComponentToWorld = driver.read<FTransform>(mesh + 0x240);
	D3DMATRIX Matrix;
	Matrix = MatrixMultiplication(bone.ToMatrixWithScale(), ComponentToWorld.ToMatrixWithScale());
	return Vector3(Matrix._41, Matrix._42, Matrix._43);
}

D3DMATRIX Matrix(Vector3 rot, Vector3 origin = Vector3(0, 0, 0)) {
	double radPitch = (rot.x * double(M_PI) / 180.f);
	double radYaw = (rot.y * double(M_PI) / 180.f);
	double radRoll = (rot.z * double(M_PI) / 180.f);

	double SP = sinf(radPitch);
	double CP = cosf(radPitch);
	double SY = sinf(radYaw);
	double CY = cosf(radYaw);
	double SR = sinf(radRoll);
	double CR = cosf(radRoll);

	D3DMATRIX matrix;
	matrix.m[0][0] = CP * CY;
	matrix.m[0][1] = CP * SY;
	matrix.m[0][2] = SP;
	matrix.m[0][3] = 0.f;

	matrix.m[1][0] = SR * SP * CY - CR * SY;
	matrix.m[1][1] = SR * SP * SY + CR * CY;
	matrix.m[1][2] = -SR * CP;
	matrix.m[1][3] = 0.f;

	matrix.m[2][0] = -(CR * SP * CY + SR * SY);
	matrix.m[2][1] = CY * SR - CR * SP * SY;
	matrix.m[2][2] = CR * CP;
	matrix.m[2][3] = 0.f;

	matrix.m[3][0] = origin.x;
	matrix.m[3][1] = origin.y;
	matrix.m[3][2] = origin.z;
	matrix.m[3][3] = 1.f;

	return matrix;
}

struct CamewaDescwipsion
{
	float FieldOfView;
	Vector3 Rotation;
	Vector3 Location;
};

struct CameraInfo {
	double X, Y, Z;
	double Pitch, Yaw;
};

namespace FVector
{
	double X = 0x0; // double
	double Y = 0x8; // double
	double Z = 0x10; // double
}



CamewaDescwipsion UndetectedCamera(__int64 a1)
{
	CamewaDescwipsion VirtualCamera;
	__int64 v1;
	__int64 v6;
	__int64 v7;
	__int64 v8;

	v1 = driver.read<__int64>(Localplayer + 0xC8);
	__int64 v9 = driver.read<__int64>(v1 + 8);

	VirtualCamera.FieldOfView = FOV / (driver.read<double>(v9 + 0x690) / 1.19f);

	VirtualCamera.Rotation.x = driver.read<double>(v9 + 0x7E0);
	VirtualCamera.Rotation.y = driver.read<double>(a1 + 0x148);

	v6 = driver.read<__int64>(Localplayer + 0x70);
	v7 = driver.read<__int64>(v6 + 0x98);
	v8 = driver.read<__int64>(v7 + 0xF8);

	VirtualCamera.Location = driver.read<Vector3>(v8 + 0x20);
	return VirtualCamera;
}




Vector3 ProjectWorldToScreen(Vector3 WorldLocation)
{
	CamewaDescwipsion vCamera = UndetectedCamera(Rootcomp);
	vCamera.Rotation.x = (asin(vCamera.Rotation.x)) * (180.0 / M_PI);

	D3DMATRIX tempMatrix = Matrix(vCamera.Rotation);

	Vector3 vAxisX = Vector3(tempMatrix.m[0][0], tempMatrix.m[0][1], tempMatrix.m[0][2]);
	Vector3 vAxisY = Vector3(tempMatrix.m[1][0], tempMatrix.m[1][1], tempMatrix.m[1][2]);
	Vector3 vAxisZ = Vector3(tempMatrix.m[2][0], tempMatrix.m[2][1], tempMatrix.m[2][2]);

	Vector3 vDelta = WorldLocation - vCamera.Location;
	Vector3 vTransformed = Vector3(vDelta.Dot(vAxisY), vDelta.Dot(vAxisZ), vDelta.Dot(vAxisX));

	if (vTransformed.z < 1.f)
		vTransformed.z = 1.f;

	return Vector3((Width / 2.0f) + vTransformed.x * (((Width / 2.0f) / tanf(vCamera.FieldOfView * (float)M_PI / 360.f))) / vTransformed.z, (Height / 2.0f) - vTransformed.y * (((Width / 2.0f) / tanf(vCamera.FieldOfView * (float)M_PI / 360.f))) / vTransformed.z, 0);
}

DWORD Menuthread(LPVOID in) {
	while (1) {
		if (GetAsyncKeyState(VK_INSERT) & 1) {
			G::Show_Menu = !G::Show_Menu;
		}
		Sleep(0);

		if (GetAsyncKeyState(VK_F8))
		{
			exit(1);
		}

	}


}


Vector3 AimbotCorrection(float bulletVelocity, float bulletGravity, float targetDistance, Vector3 targetPosition, Vector3 targetVelocity) {
	Vector3 recalculated = targetPosition;
	float gravity = fabs(bulletGravity);
	float time = targetDistance / fabs(bulletVelocity);
	return recalculated;
}


void SetMouseAbsPosition(DWORD x, DWORD y)
{
	INPUT input = { 0 };
	input.type = INPUT_MOUSE;
	input.mi.dwFlags = MOUSEEVENTF_MOVE;
	input.mi.dx = x;
	input.mi.dy = y;
	SendInput(1, &input, sizeof(input));
}
static auto aimbot(float x, float y) -> void {
	float center_x = (ImGui::GetIO().DisplaySize.x / 2);
	float center_y = (ImGui::GetIO().DisplaySize.y / 2);

	int AimSpeed = G::Aim_Speed;
	float target_x = 0;
	float target_y = 0;

	//if (isVisible)
	{
		if (x != 0.f)
		{
			if (x > center_x)
			{
				target_x = -(center_x - x);
				target_x /= G::Aim_Speed;
				if (target_x + center_x > center_x * 2.f) target_x = 0.f;
			}

			if (x < center_x)
			{
				target_x = x - center_x;
				target_x /= G::Aim_Speed;
				if (target_x + center_x < 0.f) target_x = 0.f;
			}
		}

		if (y != 0.f)
		{
			if (y > center_y)
			{
				target_y = -(center_y - y);
				target_y /= G::Aim_Speed;
				if (target_y + center_y > center_y * 2.f) target_y = 0.f;
			}

			if (y < center_y)
			{
				target_y = y - center_y;
				target_y /= G::Aim_Speed;
				if (target_y + center_y < 0.f) target_y = 0.f;
			}
		}

		SetMouseAbsPosition(static_cast<DWORD>(target_x), static_cast<DWORD>(target_y));
	}
}

static auto memory(float x, float y) -> void {
	float center_x = (ImGui::GetIO().DisplaySize.x / 2);
	float center_y = (ImGui::GetIO().DisplaySize.y / 2);

	int AimSpeed = G::Aim_Speed;
	float target_x = 0;
	float target_y = 0;

	//if (isVisible)
	{
		if (x != 0.f)
		{
			if (x > center_x)
			{
				target_x = -(center_x - x);
				target_x /= G::Aim_Speed;
				if (target_x + center_x > center_x * 2.f) target_x = 0.f;
			}

			if (x < center_x)
			{
				target_x = x - center_x;
				target_x /= G::Aim_Speed;
				if (target_x + center_x < 0.f) target_x = 0.f;
			}
		}

		if (y != 0.f)
		{
			if (y > center_y)
			{
				target_y = -(center_y - y);
				target_y /= G::Aim_Speed;
				if (target_y + center_y > center_y * 2.f) target_y = 0.f;
			}

			if (y < center_y)
			{
				target_y = y - center_y;
				target_y /= G::Aim_Speed;
				if (target_y + center_y < 0.f) target_y = 0.f;
			}
		}

		//SetMouseAbsPosition(static_cast<DWORD>(target_x), static_cast<DWORD>(target_y));

	}
}


bool weakspot;
bool llamaesp;
bool ChestESP;

double GetCrossDistance(double x1, double y1, double z1, double x2, double y2, double z2) {
	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

typedef struct _FNlEntity {
	uint64_t Actor;
	int ID;
	uint64_t mesh;
	uint64_t CapsuleComponent;
	std::string name;
}FNlEntity;

std::vector<FNlEntity> entityList;

typedef struct _LootEntity {
	std::string GNames;
	uintptr_t ACurrentItem;
}LootEntity;

static std::vector<LootEntity> LootentityList;


void FilledRect(int x, int y, int w, int h, ImColor color)
{
	ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color)), 0, 0);
}

void draw_cornered_box(int x, int y, int w, int h, ImColor color, int thickness) {
	float line_w = (w / 3);
	float line_h = (h / 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(x, y), ImVec2(x, y + line_h), color, thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(x, y), ImVec2(x + line_w, y), color, thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(x + w - line_w, y), ImVec2(x + w, y), color, thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(x + w, y), ImVec2(x + w, y + line_h), color, thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(x, y + h - line_h), ImVec2(x, y + h), color, thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(x, y + h), ImVec2(x + line_w, y + h), color, thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(x + w - line_w, y + h), ImVec2(x + w, y + h), color, thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(x + w, y + h - line_h), ImVec2(x + w, y + h), color, thickness);
}


void DrawLine(int x1, int y1, int x2, int y2, const ImU32& color, int thickness)
{
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(x1, y1), ImVec2(x2, y2), ImGui::GetColorU32(color), thickness);
}

void DrawRect(int x, int y, int w, int h, RGBA* color, int thickness)
{
	ImGui::GetOverlayDrawList()->AddRect(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), 0, 0, thickness);
}

void DrawLine2(int x1, int y1, int x2, int y2, RGBA* color, int thickness)
{
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(x1, y1), ImVec2(x2, y2), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 153.0, color->B / 51.0, color->A / 255.0)), thickness);
}

std::string WStringToUTF8(const wchar_t* lpwcszWString)
{
	char* pElementText;
	int iTextLen = ::WideCharToMultiByte(CP_UTF8, 0, (LPWSTR)lpwcszWString, -1, NULL, 0, NULL, NULL);
	pElementText = new char[iTextLen + 1];
	memset((void*)pElementText, 0, (iTextLen + 1) * sizeof(char));
	::WideCharToMultiByte(CP_UTF8, 0, (LPWSTR)lpwcszWString, -1, pElementText, iTextLen, NULL, NULL);
	std::string strReturn(pElementText);
	delete[] pElementText;
	return strReturn;
}

std::wstring MBytesToWString(const char* lpcszString)
{
	int len = strlen(lpcszString);
	int unicodeLen = ::MultiByteToWideChar(CP_ACP, 0, lpcszString, -1, NULL, 0);
	wchar_t* pUnicode = new wchar_t[unicodeLen + 1];
	memset(pUnicode, 0, (unicodeLen + 1) * sizeof(wchar_t));
	::MultiByteToWideChar(CP_ACP, 0, lpcszString, -1, (LPWSTR)pUnicode, unicodeLen);
	std::wstring wString = (wchar_t*)pUnicode;
	delete[] pUnicode;
	return wString;
}

void DrawString(float fontSize, int x, int y, RGBA* color, bool bCenter, bool stroke, const char* pText, ...)
{
	va_list va_alist;
	char buf[1024] = { 0 };
	va_start(va_alist, pText);
	_vsnprintf_s(buf, sizeof(buf), pText, va_alist);
	va_end(va_alist);
	std::string text = WStringToUTF8(MBytesToWString(buf).c_str());
	if (bCenter)
	{
		ImVec2 textSize = ImGui::CalcTextSize(text.c_str());
		x = x - textSize.x / 2;
		y = y - textSize.y;
	}
	if (stroke)
	{
		ImGui::GetOverlayDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x + 1, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
		ImGui::GetOverlayDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x - 1, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
		ImGui::GetOverlayDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x + 1, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
		ImGui::GetOverlayDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x - 1, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
	}
	ImGui::GetOverlayDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), text.c_str());
}

//namespace Addresses {
//
//	AFortPawn* LocalPawn{};
//
//
//
//}


//
//class AFortPawn {
//	BOOL K2_TeleportTo(const Vector3& DestRotation) {
//		if (!this)
//			return {};
//
//		uintptr_t DestLocationRoot = driver.read<uintptr_t>(uintptr_t(this) + Offsets::RootComponent);
//		driver.write<char>(DestLocationRoot + Offsets::RootComponent, 0);
//		driver.write<Vector3>(DestLocationRoot + Offsets::RootComponent, DestRotation);
//	}
//};

bool VehicleEsp;
bool LootESP;
int VisDist = 280.f;
int PlayerVisDist = 280.f;

void CacheLevels()
{
	if (LocalPawn)
	{
		std::vector<LootEntity> tmpList;
		uintptr_t ItemLevels = driver.read<uintptr_t>(Uworld + 0x160);

		for (int i = 0; i < driver.read<DWORD>(Uworld + (0x160 + sizeof(PVOID))); ++i) {

			uintptr_t ItemLevel = driver.read<uintptr_t>(ItemLevels + (i * sizeof(uintptr_t)));

			for (int i = 0; i < driver.read<DWORD>(ItemLevel + (0x98 + sizeof(PVOID))); ++i) {
				uintptr_t ItemsPawns = driver.read<uintptr_t>(ItemLevel + 0x98);
				uintptr_t CurrentItemPawn = driver.read<uintptr_t>(ItemsPawns + (i * sizeof(uintptr_t)));
				uintptr_t ItemRootComponent = driver.read<uintptr_t>(CurrentItemPawn + 0x188);
				Vector3 ItemPosition = driver.read<Vector3>(ItemRootComponent + 0x128);
				float ItemDist = localactorpos.Distance(ItemPosition) / 100.f;

				if (ItemDist < VisDist) {

					int ItemIndex = driver.read<int>(CurrentItemPawn + 0x18);//
					auto CurrentItemPawnName = GetNameFromFName(ItemIndex);

					if ((LootESP && strstr(CurrentItemPawnName.c_str(), (("FortPickupAthena")))) || strstr(CurrentItemPawnName.c_str(), (("Tiered_Chest"))) || strstr(CurrentItemPawnName.c_str(), (("AthenaPlayerMarker_WithCustomization"))) || strstr(CurrentItemPawnName.c_str(), (("NPC_Pawn_Irwin_Simple_Avian_Crow_C"))) || strstr(CurrentItemPawnName.c_str(), (("NPC_Pawn_Irwin_Prey_Nug_C"))) || strstr(CurrentItemPawnName.c_str(), (("NPC_Pawn_Irwin_Predator_Robert_C"))) || strstr(CurrentItemPawnName.c_str(), (("NPC_Pawn_Irwin_Prey_Burt_C"))) || strstr(CurrentItemPawnName.c_str(), (("NPC_Pawn_Irwin_Simple_Smackie_C"))) || strstr(CurrentItemPawnName.c_str(), (("NPC_Pawn_Irwin_Predator_Grandma_C"))) ||
						(VehicleEsp && strstr(CurrentItemPawnName.c_str(), ("Vehicl")) || strstr(CurrentItemPawnName.c_str(), ("Valet_Taxi")) ||
							strstr(CurrentItemPawnName.c_str(), ("Valet_BigRig")) || strstr(CurrentItemPawnName.c_str(), ("Valet_BasicTr")) ||
							strstr(CurrentItemPawnName.c_str(), ("Valet_SportsC")) || strstr(CurrentItemPawnName.c_str(), ("Valet_BasicC")) ||
							strstr(CurrentItemPawnName.c_str(), ("Tiered_Ammo")) || strstr(CurrentItemPawnName.c_str(), ("MeatballVehicle_L_C"))))
					{
						LootEntity LevelObjects{ };
						LevelObjects.ACurrentItem = CurrentItemPawn;
						LevelObjects.GNames = CurrentItemPawnName;
						tmpList.push_back(LevelObjects);
					}
				}
			}
		}
		LootentityList.clear();
		LootentityList = tmpList;
		Sleep(10);
	}
}


void randombone()
{
	if (item_current == 4)
	{

		int range = 98 - 0 + 1;
		G::hitbox = rand() % range + 3;
		Sleep(300);
	}
}

int progressive = 0;
DWORD_PTR playermesh;
void drawLoop(int width, int height) {


	while (true) {
		std::vector<FNlEntity> tmpList;
		Uworld = driver.read<DWORD_PTR>(dravarthangs::base_addy + OFFSET_UWORLD);
		DWORD_PTR Gameinstance = driver.read<DWORD_PTR>(Uworld + Offsets::GameInstance);
		DWORD_PTR LocalPlayers = driver.read<DWORD_PTR>(Gameinstance + Offsets::LocalPlayers);
		Localplayer = driver.read<DWORD_PTR>(LocalPlayers);
		PlayerController = driver.read<DWORD_PTR>(Localplayer + Offsets::PlayerController);
		LocalPawn = driver.read<DWORD_PTR>(PlayerController + Offsets::LocalPawn);
		PlayerState = driver.read<DWORD_PTR>(LocalPawn + Offsets::PlayerState);
		Rootcomp = driver.read<DWORD_PTR>(LocalPawn + Offsets::RootComponent);
		Persistentlevel = driver.read<DWORD_PTR>(Uworld + Offsets::Persistentlevel);
		DWORD ActorCount = driver.read<DWORD>(Persistentlevel + Offsets::AcotrCount);
		DWORD_PTR AActors = driver.read<DWORD_PTR>(Persistentlevel + Offsets::AAcotrs);
		DWORD_PTR worldsettings = driver.read<uintptr_t>(Persistentlevel + 0x2a0); //PersistenLevel -> AWorldSettings
		float Timedilation = driver.read<float>(LocalPawn + 0x64);
		DWORD_PTR uengine = driver.read<DWORD_PTR>(0x228);
		DWORD_PTR UGameUserSettings = driver.read<DWORD_PTR>(0x228);
		uint32_t ResolutionSizeX = driver.read<uint32_t>(UGameUserSettings + 0x88);

		//std::cout << ResolutionSizeX;
		//float WorldGravityZ = driver.read<float>(worldsettings + 0x2ec);
		//Vector3 location = driver.read<Vector3>(LocalPawn + 0x128);;
		//driver.write<float>(PlayerCameraManager + APlayerCameraManager::DefaultFOV + 0x4, 90);
		//std::string str(location.begin(), location.end());
		//driver.write<Vector3>(LocalPawn + 0x128, Vector3(4, 4, 4));


		//driver.write(worldsettings + 0x2e8, 0);
		OrginalPitchMin = driver.read<float>(PlayerCameraManager + 0x317c);
		OrginalPitchMax = driver.read<float>(PlayerCameraManager + 0x3180);
		CurrentWeapon = driver.read<uintptr_t>(LocalPawn + Offsets::CurrentWeapon);
		bool isreloading = driver.read<bool>(CurrentWeapon + 0x311);







		for (int i = 0; i < ActorCount; i++) {
			uint64_t CurrentActor = driver.read<uint64_t>(AActors + i * 0x8);
			int curactorid = driver.read<int>(CurrentActor + 0x18);

			if (!CurrentActor || CurrentActor == LocalPawn) continue;

			auto ActorPawn = GetNameFromFName(curactorid);
			playermesh = driver.read<uintptr_t>(CurrentActor + Offsets::Mesh);
			//std::cout << " ---> " << ActorPawn << std::endl;
			if (strstr(ActorPawn.c_str(), "PlayerPawn_Athena_C"))
			{

				FNlEntity fnlEntity{ };
				fnlEntity.Actor = CurrentActor;
				fnlEntity.name = ("PLAYER");
				fnlEntity.mesh = driver.read<uint64_t>(CurrentActor + Offsets::Mesh);
				fnlEntity.CapsuleComponent = driver.read<uint64_t>(CurrentActor + 0x300);
				tmpList.push_back(fnlEntity);
			}
			else if (strstr(ActorPawn.c_str(), "BP_PlayerPawn_Athena_Phoebe_C"))
			{
				FNlEntity fnlEntity{ };
				fnlEntity.Actor = CurrentActor;
				fnlEntity.name = ("BOT");
				fnlEntity.mesh = driver.read<uint64_t>(CurrentActor + Offsets::Mesh);
				fnlEntity.CapsuleComponent = driver.read<uint64_t>(CurrentActor + 0x300);
				tmpList.push_back(fnlEntity);
			}
			else if (strstr(ActorPawn.c_str(), "BP_PlayerPawn_Tandem_C"))
			{
				FNlEntity fnlEntity{ };
				fnlEntity.Actor = CurrentActor;
				fnlEntity.name = ("NPC");
				fnlEntity.mesh = driver.read<uint64_t>(CurrentActor + Offsets::Mesh);
				fnlEntity.CapsuleComponent = driver.read<uint64_t>(CurrentActor + 0x300);
				tmpList.push_back(fnlEntity);
			}
			else if (strstr(ActorPawn.c_str(), "BP_IOPlayerPawn_Base_C"))
			{
				FNlEntity fnlEntity{ };
				fnlEntity.Actor = CurrentActor;
				fnlEntity.name = ("NPC");
				fnlEntity.mesh = driver.read<uint64_t>(CurrentActor + Offsets::Mesh);
				fnlEntity.CapsuleComponent = driver.read<uint64_t>(CurrentActor + 0x300);
				tmpList.push_back(fnlEntity);
			}


		}
		CacheLevels();
		randombone();
		entityList.clear();
		entityList = tmpList;
		std::this_thread::sleep_for(std::chrono::seconds((1)));
	}









}



	
	





#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LITGRAY 7
#define DAKGREY 8
#define LITBLUE 9
#define LITGREEN 10
#define LITCYAN 11
#define LITRED 12
#define LITMEGENTA 13
#define YELLOW 14
#define WHITE 15


RGBA red = { 255,0,0,255 };
RGBA Magenta = { 255,0,255,255 };
RGBA yellow = { 255,255,0,255 };
RGBA grayblue = { 128,128,255,255 };
RGBA green = { 128,224,0,255 };
RGBA darkgreen = { 0,224,128,255 };
RGBA brown = { 192,96,0,255 };
RGBA pink = { 255,168,255,255 };
RGBA DarkYellow = { 216,216,0,255 };
RGBA BuffaloPurple = { 94,23,235,255 };
RGBA SilverWhite = { 236,236,236,255 };
RGBA purple = { 129, 47, 212,255 };
RGBA Navy = { 88,48,224,255 };
RGBA skyblue = { 0,136,255,255 };
RGBA graygreen = { 128,160,128,255 };
RGBA blue = { 0,96,192,255 };
RGBA coolcol = { 51, 171, 145, 255 };
RGBA orange = { 255,128,0,255 };
RGBA peachred = { 255,80,128,255 };
RGBA reds = { 255,128,192,255 };
RGBA darkgray = { 96,96,96,255 };
RGBA Navys = { 0,0,128,255 };
RGBA darkgreens = { 0,128,0,255 };
RGBA darkblue = { 0,128,128,255 };
RGBA redbrown = { 128,0,0,255 };
RGBA purplered = { 128,0,128,255 };
RGBA greens = { 0,255,0,255 };
RGBA envy = { 0,255,255,255 };
RGBA black = { 0,0,0,255 };
RGBA gray = { 177, 181, 179,255 };
RGBA white = { 255,255,255,255 };
RGBA blues = { 30,144,255,255 };
RGBA lightblue = { 135,206,250,160 };
RGBA Scarlet = { 220, 20, 60, 160 };
RGBA white_ = { 255,255,255,200 };
RGBA gray_ = { 128,128,128,200 };
RGBA black_ = { 0,0,0,200 };
RGBA red_ = { 255,0,0,200 };
RGBA Magenta_ = { 255,0,255,200 };
RGBA yellow_ = { 255,255,0,200 };
RGBA grayblue_ = { 128,128,255,200 };
RGBA green_ = { 128,224,0,200 };
RGBA darkgreen_ = { 0,224,128,200 };
RGBA brown_ = { 192,96,0,200 };
RGBA pink_ = { 255,168,255,200 };
RGBA darkyellow_ = { 216,216,0,200 };
RGBA silverwhite_ = { 236,236,236,200 };
RGBA purple_ = { 144,0,255,200 };
RGBA Blue_ = { 88,48,224,200 };
RGBA skyblue_ = { 0,136,255,200 };
RGBA graygreen_ = { 128,160,128,200 };
RGBA blue_ = { 0,96,192,200 };
RGBA orange_ = { 255,128,0,200 };
RGBA pinks_ = { 255,80,128,200 };
RGBA Fuhong_ = { 255,128,192,200 };
RGBA darkgray_ = { 96,96,96,200 };
RGBA Navy_ = { 0,0,128,200 };
RGBA darkgreens_ = { 0,128,0,200 };
RGBA darkblue_ = { 0,128,128,200 };
RGBA redbrown_ = { 128,0,0,200 };
RGBA purplered_ = { 128,0,128,200 };
RGBA greens_ = { 0,255,0,200 };
RGBA envy_ = { 0,255,255,200 };

RGBA glassblack = { 0, 0, 0, 160 };
RGBA GlassBlue = { 65,105,225,80 };
RGBA glassyellow = { 255,255,0,160 };
RGBA glass = { 200,200,200,60 };

RGBA filled = { 0, 0, 0, 150 };

RGBA Plum = { 221,160,221,160 };


void AimAt(DWORD_PTR entity) {
	uint64_t currentactormesh = driver.read<uint64_t>(entity + Offsets::Mesh);
	auto rootHead = GetBoneWithRotation(currentactormesh, G::hitbox);

	if (G::Aim_Prediction) {
		float distance = localactorpos.Distance(rootHead) / 250;
		uint64_t CurrentActorRootComponent = driver.read<uint64_t>(entity + Offsets::RootComponent);
		Vector3 vellocity = driver.read<Vector3>(CurrentActorRootComponent + Offsets::Velocity);
		Vector3 Predicted = AimbotCorrection(-504, 35, distance, rootHead, vellocity);
		Vector3 rootHeadOut = ProjectWorldToScreen(Predicted);
		if (rootHeadOut.x != 0 || rootHeadOut.y != 0 || rootHeadOut.z != 0) {
			if ((GetCrossDistance(rootHeadOut.x, rootHeadOut.y, rootHeadOut.z, Width / 2, Height / 2, Depth / 2) <= G::AimFOV * 1)) {
				//Beep(9000, 3);
				aimbot(rootHeadOut.x, rootHeadOut.y);

			}
		}
	}
	else {
		Vector3 rootHeadOut = ProjectWorldToScreen(rootHead);
		if (rootHeadOut.x != 0 || rootHeadOut.y != 0 || rootHeadOut.z != 0) {
			if ((GetCrossDistance(rootHeadOut.x, rootHeadOut.y, rootHeadOut.z, Width / 2, Height / 2, Depth / 2) <= G::AimFOV * 1)) {
				//Beep(9000, 3);
				aimbot(rootHeadOut.x, rootHeadOut.y);
			}
		}
	}
}





void MemoryAim(DWORD_PTR entity) {
	uint64_t currentactormesh = driver.read<uint64_t>(entity + Offsets::Mesh);
	auto rootHead = GetBoneWithRotation(currentactormesh, G::hitbox);

	if (G::Aim_Prediction) {
		float distance = localactorpos.Distance(rootHead) / 250;
		uint64_t CurrentActorRootComponent = driver.read<uint64_t>(entity + Offsets::RootComponent);
		Vector3 vellocity = driver.read<Vector3>(CurrentActorRootComponent + Offsets::Velocity);
		Vector3 Predicted = AimbotCorrection(-504, 35, distance, rootHead, vellocity);
		Vector3 rootHeadOut = ProjectWorldToScreen(Predicted);
		if (rootHeadOut.x != 0 || rootHeadOut.y != 0 || rootHeadOut.z != 0) {
			if ((GetCrossDistance(rootHeadOut.x, rootHeadOut.y, rootHeadOut.z, Width / 2, Height / 2, Depth / 2) <= G::AimFOV * 1)) {
				//Beep(9000, 3);
				//aimbot(rootHeadOut.x, rootHeadOut.y);
				memory(rootHeadOut.x, rootHeadOut.y);

				////Sleep(5);

				//driver.write<float>(PlayerCameraManager + 0x317c, OrginalPitchMin);
				//driver.write<float>(PlayerCameraManager + 0x3180, OrginalPitchMax);

			}
		}
	}
	else {
		Vector3 rootHeadOut = ProjectWorldToScreen(rootHead);
		//Vector3 NewRotation = CalculateNewRotation(Addresses::CameraLocation, rootHead);
		if (rootHeadOut.x != 0 || rootHeadOut.y != 0 || rootHeadOut.z != 0) {
			if ((GetCrossDistance(rootHeadOut.x, rootHeadOut.y, rootHeadOut.z, Width / 2, Height / 2, Depth / 2) <= G::AimFOV * 1)) {
				//Beep(9000, 3);
				//aimbot(rootHeadOut.x, rootHeadOut.y);
				memory(rootHeadOut.x, rootHeadOut.y);

				//Sleep(5);

				//driver.write<float>(PlayerCameraManager + 0x317c, OrginalPitchMin);
				//driver.write<float>(PlayerCameraManager + 0x3180, OrginalPitchMax);
			}
		}
	}
}





void AimAt2(DWORD_PTR entity) {
	uint64_t currentactormesh = driver.read<uint64_t>(entity + Offsets::Mesh);
	auto rootHead = GetBoneWithRotation(currentactormesh, G::hitbox);

	if (G::Aim_Prediction) {
		float distance = localactorpos.Distance(rootHead) / 250;
		uint64_t CurrentActorRootComponent = driver.read<uint64_t>(entity + Offsets::RootComponent);
		Vector3 vellocity = driver.read<Vector3>(CurrentActorRootComponent + Offsets::Velocity);
		Vector3 Predicted = AimbotCorrection(-504, 35, distance, rootHead, vellocity);
		Vector3 rootHeadOut = ProjectWorldToScreen(Predicted);
		if (rootHeadOut.x != 0 || rootHeadOut.y != 0 || rootHeadOut.z != 0) {
			if ((GetCrossDistance(rootHeadOut.x, rootHeadOut.y, rootHeadOut.z, Width / 2, Height / 2, Depth / 2) <= G::AimFOV * 1)) {

			}
		}
	}
	else {
		Vector3 rootHeadOut = ProjectWorldToScreen(rootHead);
		if (rootHeadOut.x != 0 || rootHeadOut.y != 0 || rootHeadOut.z != 0) {
			if ((GetCrossDistance(rootHeadOut.x, rootHeadOut.y, rootHeadOut.z, Width / 2, Height / 2, Depth / 2) <= G::AimFOV * 1)) {
			}
		}
	}
}

std::string string_To_UTF8(const std::string& str)
{
	int nwLen = ::MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);

	wchar_t* pwBuf = new wchar_t[nwLen + 1];
	ZeroMemory(pwBuf, nwLen * 2 + 2);

	::MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.length(), pwBuf, nwLen);

	int nLen = ::WideCharToMultiByte(CP_UTF8, 0, pwBuf, -1, NULL, NULL, NULL, NULL);

	char* pBuf = new char[nLen + 1];
	ZeroMemory(pBuf, nLen + 1);

	::WideCharToMultiByte(CP_UTF8, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);

	std::string retStr(pBuf);

	delete[]pwBuf;
	delete[]pBuf;

	pwBuf = NULL;
	pBuf = NULL;

	return retStr;
}

namespace RenderRadar
{
	void RadarRange(float* x, float* y, float range)
	{
		if (fabs((*x)) > range || fabs((*y)) > range)
		{
			if ((*y) > (*x))
			{
				if ((*y) > -(*x))
				{
					(*x) = range * (*x) / (*y);
					(*y) = range;
				}
				else
				{
					(*y) = -range * (*y) / (*x);
					(*x) = -range;
				}
			}
			else
			{
				if ((*y) > -(*x))
				{
					(*y) = range * (*y) / (*x);
					(*x) = range;
				}
				else
				{
					(*x) = -range * (*x) / (*y);
					(*y) = -range;
				}
			}
		}
	}
	class FRotator
	{
	public:
		FRotator() : Pitch(0.f), Yaw(0.f), Roll(0.f)
		{

		}

		FRotator(double _Pitch, double _Yaw, double _Roll) : Pitch(_Pitch), Yaw(_Yaw), Roll(_Roll)
		{

		}
		~FRotator()
		{

		}

		double Pitch;
		double Yaw;
		double Roll;
		inline FRotator get() {
			return FRotator(Pitch, Yaw, Roll);
		}
		inline void set(double _Pitch, double _Yaw, double _Roll) {
			Pitch = _Pitch;
			Yaw = _Yaw;
			Roll = _Roll;
		}

		inline FRotator Clamp() {
			FRotator result = get();
			if (result.Pitch > 180)
				result.Pitch -= 360;
			else if (result.Pitch < -180)
				result.Pitch += 360;
			if (result.Yaw > 180)
				result.Yaw -= 360;
			else if (result.Yaw < -180)
				result.Yaw += 360;
			if (result.Pitch < -89)
				result.Pitch = -89;
			if (result.Pitch > 89)
				result.Pitch = 89;
			while (result.Yaw < -180.0f)
				result.Yaw += 360.0f;
			while (result.Yaw > 180.0f)
				result.Yaw -= 360.0f;

			result.Roll = 0;
			return result;

		}
		double Length() {
			return sqrt(Pitch * Pitch + Yaw * Yaw + Roll * Roll);
		}

		FRotator operator+(FRotator angB) { return FRotator(Pitch + angB.Pitch, Yaw + angB.Yaw, Roll + angB.Roll); }
		FRotator operator-(FRotator angB) { return FRotator(Pitch - angB.Pitch, Yaw - angB.Yaw, Roll - angB.Roll); }
		FRotator operator/(float flNum) { return FRotator(Pitch / flNum, Yaw / flNum, Roll / flNum); }
		FRotator operator*(float flNum) { return FRotator(Pitch * flNum, Yaw * flNum, Roll * flNum); }
		bool operator==(FRotator angB) { return Pitch == angB.Pitch && Yaw == angB.Yaw && Yaw == angB.Yaw; }
		bool operator!=(FRotator angB) { return Pitch != angB.Pitch || Yaw != angB.Yaw || Yaw != angB.Yaw; }

	};
	void CalcRadarPoint(Vector3 vOrigin, int& screenx, int& screeny)
	{
		uint64_t rootciomp = driver.read<DWORD_PTR>(LocalPawn + 0x188);
		CamewaDescwipsion vCamera = UndetectedCamera(rootciomp);

		auto LastFrameCameraCachePrivate = UndetectedCamera(rootciomp);

		FRotator vAngle = FRotator{ LastFrameCameraCachePrivate.Rotation.x, LastFrameCameraCachePrivate.Rotation.y, LastFrameCameraCachePrivate.Rotation.z };
		auto fYaw = vAngle.Yaw * 3.141592653589793f / 180.0f;
		float dx = vOrigin.x - LastFrameCameraCachePrivate.Location.x;
		float dy = vOrigin.y - LastFrameCameraCachePrivate.Location.y;

		float fsin_yaw = sinf(fYaw);
		float fminus_cos_yaw = -cosf(fYaw);

		float x = dy * fminus_cos_yaw + dx * fsin_yaw;
		x = -x;
		float y = dx * fminus_cos_yaw - dy * fsin_yaw;

		float range = (float)18997.f;

		RadarRange(&x, &y, range);


		ImVec2 DrawPos = ImGui::GetCursorScreenPos();
		ImVec2 DrawSize = ImGui::GetContentRegionAvail();

		int rad_x = (float)DrawPos.x;
		int rad_y = (float)DrawPos.y;

		float r_siz_x = DrawSize.x;
		float r_siz_y = DrawSize.y;

		int x_max = (float)r_siz_x + rad_x - 5;
		int y_max = (float)r_siz_y + rad_y - 5;

		screenx = rad_x + ((int)r_siz_x / 2 + float(x / range * r_siz_x));
		screeny = rad_y + ((int)r_siz_y / 2 + float(y / range * r_siz_y));

		if (screenx > x_max)
			screenx = x_max;

		if (screenx < rad_x)
			screenx = rad_x;

		if (screeny > y_max)
			screeny = y_max;

		if (screeny < rad_y)
			screeny = rad_y;
	}


	bool firstS = false;
}    ImGuiWindowFlags TargetFlags;

void RadarLoop(Vector3 WorldPosition, ImColor Color)
{
	int screenx = 0;
	int screeny = 0;

	RenderRadar::CalcRadarPoint(WorldPosition, screenx, screeny);

	auto Draw = ImGui::GetOverlayDrawList();

	float arrowWidth = 4.5f;

	ImGui::GetOverlayDrawList()->AddCircleFilled(ImVec2((float)screenx, (float)screeny), 5, Color);
}

bool isVisible(DWORD_PTR mesh)
{
	if (!mesh)
		return false;
	float tik = driver.read<float>(mesh + 0x330);
	float tok = driver.read<float>(mesh + 0x334);
	const float tick = 0.06f;
	return tok + tick >= tik;
}
static ImColor Color;


void OutlinedText(int x, int y, ImColor Color, const char* text)
{
	ImGui::GetOverlayDrawList()->AddText(ImVec2(x - 1, y), ImColor(0, 0, 0), text);
	ImGui::GetOverlayDrawList()->AddText(ImVec2(x + 1, y), ImColor(0, 0, 0), text);
	ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y - 1), ImColor(0, 0, 0), text);
	ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y + 1), ImColor(0, 0, 0), text);
	ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y), Color, text);
}
bool worldspeed;
float worldspeedv = 1;
bool radar = true;




void DrawSkeleton(DWORD_PTR mesh)
{
	Vector3 vHeadBone = GetBoneWithRotation(mesh, 98);
	Vector3 vHip = GetBoneWithRotation(mesh, 2);
	Vector3 vNeck = GetBoneWithRotation(mesh, 67);
	Vector3 vUpperArmLeft = GetBoneWithRotation(mesh, 9);
	Vector3 vUpperArmRight = GetBoneWithRotation(mesh, 38);
	Vector3 vLeftHand = GetBoneWithRotation(mesh, 10);
	Vector3 vRightHand = GetBoneWithRotation(mesh, 39);
	Vector3 vLeftHand1 = GetBoneWithRotation(mesh, 11);
	Vector3 vRightHand1 = GetBoneWithRotation(mesh, 40);
	Vector3 vRightThigh = GetBoneWithRotation(mesh, 76);
	Vector3 vLeftThigh = GetBoneWithRotation(mesh, 69);
	Vector3 vRightCalf = GetBoneWithRotation(mesh, 77);
	Vector3 vLeftCalf = GetBoneWithRotation(mesh, 70);
	Vector3 vLeftFoot = GetBoneWithRotation(mesh, 73);
	Vector3 vRightFoot = GetBoneWithRotation(mesh, 80);
	Vector3 vHeadBoneOut = ProjectWorldToScreen(vHeadBone);
	Vector3 vHipOut = ProjectWorldToScreen(vHip);
	Vector3 vNeckOut = ProjectWorldToScreen(vNeck);
	Vector3 vUpperArmLeftOut = ProjectWorldToScreen(vUpperArmLeft);
	Vector3 vUpperArmRightOut = ProjectWorldToScreen(vUpperArmRight);
	Vector3 vLeftHandOut = ProjectWorldToScreen(vLeftHand);
	Vector3 vRightHandOut = ProjectWorldToScreen(vRightHand);
	Vector3 vLeftHandOut1 = ProjectWorldToScreen(vLeftHand1);
	Vector3 vRightHandOut1 = ProjectWorldToScreen(vRightHand1);
	Vector3 vRightThighOut = ProjectWorldToScreen(vRightThigh);
	Vector3 vLeftThighOut = ProjectWorldToScreen(vLeftThigh);
	Vector3 vRightCalfOut = ProjectWorldToScreen(vRightCalf);
	Vector3 vLeftCalfOut = ProjectWorldToScreen(vLeftCalf);
	Vector3 vLeftFootOut = ProjectWorldToScreen(vLeftFoot);
	Vector3 vRightFootOut = ProjectWorldToScreen(vRightFoot);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vHipOut.x, vHipOut.y), ImVec2(vNeckOut.x, vNeckOut.y), ImGui::GetColorU32({ G::Skeletonchik[0], G::Skeletonchik[1], G::Skeletonchik[2], 1.0f }));
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vUpperArmLeftOut.x, vUpperArmLeftOut.y), ImVec2(vNeckOut.x, vNeckOut.y), ImGui::GetColorU32({ G::Skeletonchik[0], G::Skeletonchik[1], G::Skeletonchik[2], 1.0f }));
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vUpperArmRightOut.x, vUpperArmRightOut.y), ImVec2(vNeckOut.x, vNeckOut.y), ImGui::GetColorU32({ G::Skeletonchik[0], G::Skeletonchik[1], G::Skeletonchik[2], 1.0f }));
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vLeftHandOut.x, vLeftHandOut.y), ImVec2(vUpperArmLeftOut.x, vUpperArmLeftOut.y), ImGui::GetColorU32({ G::Skeletonchik[0], G::Skeletonchik[1], G::Skeletonchik[2], 1.0f }));
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vRightHandOut.x, vRightHandOut.y), ImVec2(vUpperArmRightOut.x, vUpperArmRightOut.y), ImGui::GetColorU32({ G::Skeletonchik[0], G::Skeletonchik[1], G::Skeletonchik[2], 1.0f }));
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vLeftHandOut.x, vLeftHandOut.y), ImVec2(vLeftHandOut1.x, vLeftHandOut1.y), ImGui::GetColorU32({ G::Skeletonchik[0], G::Skeletonchik[1], G::Skeletonchik[2], 1.0f }));
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vRightHandOut.x, vRightHandOut.y), ImVec2(vRightHandOut1.x, vRightHandOut1.y), ImGui::GetColorU32({ G::Skeletonchik[0], G::Skeletonchik[1], G::Skeletonchik[2], 1.0f }));
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vLeftThighOut.x, vLeftThighOut.y), ImVec2(vHipOut.x, vHipOut.y), ImGui::GetColorU32({ G::Skeletonchik[0], G::Skeletonchik[1], G::Skeletonchik[2], 1.0f }));
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vRightThighOut.x, vRightThighOut.y), ImVec2(vHipOut.x, vHipOut.y), ImGui::GetColorU32({ G::Skeletonchik[0], G::Skeletonchik[1], G::Skeletonchik[2], 1.0f }));
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vLeftCalfOut.x, vLeftCalfOut.y), ImVec2(vLeftThighOut.x, vLeftThighOut.y), ImGui::GetColorU32({ G::Skeletonchik[0], G::Skeletonchik[1], G::Skeletonchik[2], 1.0f }));
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vRightCalfOut.x, vRightCalfOut.y), ImVec2(vRightThighOut.x, vRightThighOut.y), ImGui::GetColorU32({ G::Skeletonchik[0], G::Skeletonchik[1], G::Skeletonchik[2], 1.0f }));
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vLeftFootOut.x, vLeftFootOut.y), ImVec2(vLeftCalfOut.x, vLeftCalfOut.y), ImGui::GetColorU32({ G::Skeletonchik[0], G::Skeletonchik[1], G::Skeletonchik[2], 1.0f }));
	DrawString(14, vHeadBone.x, vHeadBone.y, &white, true, true, "test");
	OutlinedText(vNeckOut.x, vNeckOut.y, Color, "neck");
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vRightFootOut.x, vRightFootOut.y), ImVec2(vRightCalfOut.x, vRightCalfOut.y), ImGui::GetColorU32({ G::Skeletonchik[0], G::Skeletonchik[1], G::Skeletonchik[2], 1.0f }));
}

void DrawSkeletonText(DWORD_PTR mesh)
{
	Vector3 vHeadBone = GetBoneWithRotation(mesh, 98);
	Vector3 vHip = GetBoneWithRotation(mesh, 2);
	Vector3 vNeck = GetBoneWithRotation(mesh, 67);
	Vector3 vUpperArmLeft = GetBoneWithRotation(mesh, 9);
	Vector3 vUpperArmRight = GetBoneWithRotation(mesh, 38);
	Vector3 vLeftHand = GetBoneWithRotation(mesh, 10);
	Vector3 vRightHand = GetBoneWithRotation(mesh, 39);
	Vector3 vLeftHand1 = GetBoneWithRotation(mesh, 11);
	Vector3 vRightHand1 = GetBoneWithRotation(mesh, 40);
	Vector3 vRightThigh = GetBoneWithRotation(mesh, 76);
	Vector3 vLeftThigh = GetBoneWithRotation(mesh, 69);
	Vector3 vRightCalf = GetBoneWithRotation(mesh, 77);
	Vector3 vLeftCalf = GetBoneWithRotation(mesh, 70);
	Vector3 vLeftFoot = GetBoneWithRotation(mesh, 73);
	Vector3 vRightFoot = GetBoneWithRotation(mesh, 80);
	Vector3 vHeadBoneOut = ProjectWorldToScreen(vHeadBone);
	Vector3 vHipOut = ProjectWorldToScreen(vHip);
	Vector3 vNeckOut = ProjectWorldToScreen(vNeck);
	Vector3 vUpperArmLeftOut = ProjectWorldToScreen(vUpperArmLeft);
	Vector3 vUpperArmRightOut = ProjectWorldToScreen(vUpperArmRight);
	Vector3 vLeftHandOut = ProjectWorldToScreen(vLeftHand);
	Vector3 vRightHandOut = ProjectWorldToScreen(vRightHand);
	Vector3 vLeftHandOut1 = ProjectWorldToScreen(vLeftHand1);
	Vector3 vRightHandOut1 = ProjectWorldToScreen(vRightHand1);
	Vector3 vRightThighOut = ProjectWorldToScreen(vRightThigh);
	Vector3 vLeftThighOut = ProjectWorldToScreen(vLeftThigh);
	Vector3 vRightCalfOut = ProjectWorldToScreen(vRightCalf);
	Vector3 vLeftCalfOut = ProjectWorldToScreen(vLeftCalf);
	Vector3 vLeftFootOut = ProjectWorldToScreen(vLeftFoot);
	Vector3 vRightFootOut = ProjectWorldToScreen(vRightFoot);
	DrawString(14, vHeadBone.x, vHeadBone.y, &white, true, true, "test");
	
}

// Inheritance: 
struct FGravityMovementData
{
	float GravityZScale = 0x0; // float
	float VehicleGravityZScale = 0x4; // float
	float JumpZVelocityOverride = 0x8; // float
	float JumpHorizontalAccelerationOverride = 0xc; // float
	float JumpHorizontalVelocityOverride = 0x10; // float
};

bool Animalesp;

bool dmrfire;

struct FZiplinePawnState {
	struct AFortAthenaZiplineBase* Zipline; // 0x00(0x08)
	struct AFortAthenaZiplineBase* PreviousZipline; // 0x00(0x08)
	struct UPrimitiveComponent* InteractComponent; // 0x10(0x08)
	bool bIsZiplining; // 0x18(0x01)
	bool bJumped; // 0x19(0x01)
	bool bReachedEnd; // 0x1a(0x01)
	char pad_1B[0x1]; // 0x1b(0x01)
	int32_t AuthoritativeValue; // 0x1c(0x04)struct sdk::structs::FVector SocketOffset; // 0x20(0x0c)
	float TimeZipliningBegan; // 0x2c(0x04)
	float TimeZipliningEndedFromJump; // 0x30(0x04)
	char pad_34[0x4]; // 0x34(0x04)
};

void NULLLOL()
{
	FZiplinePawnState ZiplinePawnState = driver.read<FZiplinePawnState>(LocalPawn + 0x18B0);
	ZiplinePawnState.bIsZiplining = true;
	ZiplinePawnState.AuthoritativeValue = 360.f;

	driver.write<FZiplinePawnState>(LocalPawn + 0x18B0, ZiplinePawnState);
	std::cout << ZiplinePawnState.AuthoritativeValue;
}


void GravityTest()
{

}


float gFovAngle;
void DrawESP() {
	char CurrentWeapon[1024];
	if (G::Draw_FOV_Circle) {
		//ImGui::GetOverlayDrawList()->AddRect(ImVec2(810 - G::AimFOV, 390 - G::AimFOV), ImVec2(1110 + G::AimFOV, 690 + G::AimFOV), ImColor(0, 162, 232, 255), 1.0f);
		ImGui::GetOverlayDrawList()->AddCircle(ImVec2(ScreenCenterX, ScreenCenterY), float(G::AimFOV), ImColor(0, 162, 232, 255), 50, 1);
	}
	DWORD_PTR closestPawn = NULL;
	float closestDistance = FLT_MAX;


	if (G::InstantReboot)
	{
		driver.write<bool>((uintptr_t)LocalPawn + 0x1680 + 0x9a0, true);
	}



	for (LootEntity LEntityList : LootentityList) {

		if (LocalPawn)
		{
			uintptr_t ItemRootComponent = driver.read<uintptr_t>(LEntityList.ACurrentItem + 0x188);
			Vector3 ItemPosition = driver.read<Vector3>(ItemRootComponent + 0x128);
			float ItemDist = localactorpos.Distance(ItemPosition) / 100.f;
			std::string null = ("");

			auto IsSearched = driver.read<BYTE>((uintptr_t)LEntityList.ACurrentItem + 0xfb9);
			if (IsSearched >> 7 & 1) continue;
			Vector3 ChestPosition;
			ChestPosition = ProjectWorldToScreen(ItemPosition);
			Vector3 VehiclePosition = ProjectWorldToScreen(ItemPosition);
			if (strstr(LEntityList.GNames.c_str(), ("Tiered_Chest")) && ChestESP)
			{
				if (ItemDist < VisDist) {

					std::string Text = null + ("Chest [") + std::to_string((int)ItemDist) + ("m]");
					DrawString(14, ChestPosition.x, ChestPosition.y, &orange_, true, true, Text.c_str());
				}
			}

			else if (Animalesp)
			{
				if ((strstr(LEntityList.GNames.c_str(), ("NPC_Pawn_Irwin_Predator_Robert_C"))) || (strstr(LEntityList.GNames.c_str(), ("NPC_Pawn_Irwin_Prey_Burt_C"))) || (strstr(LEntityList.GNames.c_str(), ("NPC_Pawn_Irwin_Simple_Smackie_C"))) || (strstr(LEntityList.GNames.c_str(), ("NPC_Pawn_Irwin_Simple_Smackie_C"))) || (strstr(LEntityList.GNames.c_str(), ("NPC_Pawn_Irwin_Prey_Nug_C"))) || (strstr(LEntityList.GNames.c_str(), ("NPC_Pawn_Irwin_Predator_Grandma_C"))) || (strstr(LEntityList.GNames.c_str(), ("NPC_Pawn_Irwin_Simple_Avian_Crow_C")))) {
					if (ItemDist < VisDist) {

						std::string Text = null + ("Animal [") + std::to_string((int)ItemDist) + ("m]");
						DrawString(14, VehiclePosition.x, VehiclePosition.y, &white, true, true, Text.c_str());
					}
				}
			}


			if (strstr(LEntityList.GNames.c_str(), ("AthenaPlayerMarker_WithCustomization")))
			{
				if (ItemDist < 500) {

					std::string Text = null + ("Marker [") + std::to_string((int)ItemDist) + ("m]");
					DrawString(14, ChestPosition.x, ChestPosition.y, &orange_, true, true, Text.c_str());
				}
			}



			//
			else if (VehicleEsp)
			{
				if ((strstr(LEntityList.GNames.c_str(), ("MeatballVehicle_L_C"))) || (strstr(LEntityList.GNames.c_str(), ("Valet_SportsC"))) || (strstr(LEntityList.GNames.c_str(), ("Valet_BigRig"))) || (strstr(LEntityList.GNames.c_str(), ("Vehicl"))) || (strstr(LEntityList.GNames.c_str(), ("Valet_BasicC"))) || (strstr(LEntityList.GNames.c_str(), ("Valet_BasicTr"))) || (strstr(LEntityList.GNames.c_str(), ("Valet_Taxi")))) {
					if (ItemDist < VisDist) {

						std::string Text = null + ("Vehicle [") + std::to_string((int)ItemDist) + ("m]");
						DrawString(14, VehiclePosition.x, VehiclePosition.y, &white, true, true, Text.c_str());
					}
				}
			}









			else if (LootESP && strstr(LEntityList.GNames.c_str(), ("FortPickupAthena")) || strstr(LEntityList.GNames.c_str(), ("Fort_Pickup_Creative_C")))
			{
				if (ItemDist < VisDist) {

					auto definition = driver.read<uint64_t>(LEntityList.ACurrentItem + 0x2f8 + 0x18);
					BYTE tier = driver.read<BYTE>(definition + 0x74);

					RGBA Color, RGBAColor;
					Vector3 ChestPosition2;
					ChestPosition2 = ProjectWorldToScreen(ItemPosition);

					if (LootESP)
					{
						auto DisplayName = driver.read<uint64_t>(definition + 0x90);
						auto WeaponLength = driver.read<uint32_t>(DisplayName + 0x38);
						wchar_t* WeaponName = new wchar_t[uint64_t(WeaponLength) + 1];

						((ULONG64)driver.read<PVOID>(DisplayName + 0x30), WeaponName, WeaponLength * sizeof(wchar_t));

						std::string Text = wchar_to_char(WeaponName);
						std::string wtf2 = Text + ("[ ") + std::to_string((int)ItemDist) + ("m]");
						if (tier == 2 && (uncommon))
						{
							Color = darkgreen;
						}
						else if ((tier == 3) && (rare))
						{
							Color = blue;
						}
						else if ((tier == 4) && (epic))
						{
							Color = purple;
						}
						else if ((tier == 5) && (legendary))
						{
							Color = orange;
						}
						else if ((tier == 6) && (mythic))
						{
							Color = yellow;
						}
						else if ((tier == 0) || (tier == 1) && (common))
						{
							Color = gray;
						}

						DrawString(14, ChestPosition2.x, ChestPosition2.y, &Color, true, true, wtf2.c_str());
					}
				}

			}


		}
	}






	auto entityListCopy = entityList;



	DWORD_PTR AActors = driver.read<DWORD_PTR>(Ulevel + Offsets::AAcotrs);


	for (unsigned long i = 0; i < entityListCopy.size(); ++i) {
		FNlEntity entity = entityListCopy[i];






		uint64_t CurrentActor = driver.read<uint64_t>(AActors + i * Offsets::CurrentActor);

		uint64_t CurActorRootComponent = driver.read<uint64_t>(entity.Actor + Offsets::RootComponent);
		if (CurActorRootComponent == (uint64_t)nullptr || CurActorRootComponent == -1 || CurActorRootComponent == NULL)
			continue;


		DWORD64 otherPlayerState = driver.read<uint64_t>(entity.Actor + Offsets::PlayerState);
		if (otherPlayerState == (uint64_t)nullptr || otherPlayerState == -1 || otherPlayerState == NULL)
			continue;

		localactorpos = driver.read<Vector3>(Rootcomp + Offsets::RelativeLocation);


		Vector3 bone66 = GetBoneWithRotation(entity.mesh, 66);
		Vector3 aimbone = GetBoneWithRotation(entity.mesh, 66);
		Vector3 bone0 = GetBoneWithRotation(entity.mesh, 0);

		Vector3 bonepelvis = GetBoneWithRotation(entity.mesh, 2);

		Vector3 top = ProjectWorldToScreen(bone66);
		Vector3 chest = ProjectWorldToScreen(bone66);
		Vector3 aimbotspot = ProjectWorldToScreen(aimbone);
		Vector3 bottom = ProjectWorldToScreen(bone0);

		Vector3 vHeadBone = GetBoneWithRotation(entity.mesh, 98);
		Vector3 vRootBone = GetBoneWithRotation(entity.mesh, 0);

		Vector3 vHeadBoneOut = ProjectWorldToScreen(Vector3(vHeadBone.x, vHeadBone.y, vHeadBone.z + 15));

		Vector3 Head = ProjectWorldToScreen(Vector3(bone66.x, bone66.y, bone66.z + 15));

		float distance = localactorpos.Distance(bone66) / 100.f;
		float BoxHeight = (float)(Head.y - bottom.y);
		float BoxWidth = BoxHeight * 0.46;
		float CornerHeight = abs(Head.y - bottom.y);
		float CornerWidth = BoxHeight * 0.46;

		int MyTeamId = driver.read<int>(PlayerState + Offsets::TeamIndex);
		int ActorTeamId = driver.read<int>(otherPlayerState + Offsets::TeamIndex);
		int curactorid = driver.read<int>(CurrentActor + 0x18);
		auto bIsDBNO = (driver.read<char>(entity.Actor + 0x74A) >> 4) & 1;
		DWORD_PTR worldsettings = driver.read<uintptr_t>(Persistentlevel + 0x2a0);
		auto CurrentWeapon = driver.read<uintptr_t>(LocalPawn + Offsets::CurrentWeapon);
		bool isreloading = driver.read<bool>(CurrentWeapon + 0x311);
		auto CurrentVehicle = driver.read<uintptr_t>(LocalPawn + 0x21d8);
		gFovAngle = driver.read<double>(CurrentVehicle + 0x704);
		//std::cout << gFovAngle;
		float VehicleGravityScale = driver.read<float>(CurrentVehicle + 0x1030 + 0x18);
		float vehicletime = driver.read<float>(CurrentVehicle + 0x64);
		PlayerCameraManager = driver.read<uintptr_t>(PlayerController + 0x328);
		static float OrginalPitchMin = driver.read<float>(PlayerCameraManager + 0x317c);
		static float OrginalPitchMax = driver.read<float>(PlayerCameraManager + 0x3180);
		float EmoteWalkSpeed = driver.read<float>(LocalPawn + 0xcc0);
		std::string DisplayName = driver.read<std::string>(LocalPawn + 0x10e4);
		FGravityMovementData GravityMovementData = driver.read<FGravityMovementData>(LocalPawn + 0x30);
		//std::cout << GravityMovementData.VehicleGravityZScale;
		//std::cout << EmoteWalkSpeed;



		//driver.write<Vector3>(uintptr_t(PlayerController) + Offsets::ControlRotation, Vector3(1, 1, 1));
		//driver.write<float>(CurrentWeapon + 0x1088, progressive); //viewpitchmin
		//driver.write<float>(CurrentWeapon + 0x108c, progressive);
		//std::cout << progressive;
		//driver.write<float>(PlayerCameraManager + 0x317c, progressive);
		//driver.write<float>(PlayerCameraManager + 0x3180, progressive);
		//std::cout << vehicletime;
		//bool bUseProjectileTrace = driver.read<bool>(CurrentWeapon + 0xb00);
		//int AmmoCount = driver.read<int>(CurrentWeapon + 0xb3c);
		//driver.write<bool>(CurrentWeapon + 0xb00, 1);
		//std::cout << AmmoCount;
		//float gravityamount = driver.read<float>(worldsettings + 0x2ec);
	
		//driver.write<float>(CurrentWeapon + 0x2ec, 99);
		//driver.write<float>(worldsettings + 0x2ec, -1);
		//std::cout << gravityamount;
		if (isVisible(entity.mesh)) {
			Color = ImColor(0, 162, 232, 255);
		}
		else {
			Color = ImColor(0, 162, 232, 255);
		}
















		if (MyTeamId != ActorTeamId) {
			if (distance < PlayerVisDist) {

				if (G::Esp_line) {
					{
						ImGui::GetOverlayDrawList()->AddLine(ImVec2(Width / 2, 0), ImVec2(bottom.x, top.y), Color, 0.01f);

					}
				}

				if (G::Esp_lineMiddle) {
					{
						ImGui::GetOverlayDrawList()->AddLine(ImVec2(Width / 2, Height / 2), ImVec2(bottom.x, top.y), Color, 0.01f);

					}
				}

				if (G::Esp_lineBottom) {
					{
						ImGui::GetOverlayDrawList()->AddLine(ImVec2(Width / 2, Height), ImVec2(bottom.x, bottom.y), Color, 0.01f);
						

					}
				}



				if (bIsDBNO) {
					Color = ImColor(255, 255, 255);
				}
				else {

				}


				std::string DistanceText2 = ("[") + std::to_string(int(distance)) + ("m]");
				ImVec2 DistanceTextSize2 = ImGui::CalcTextSize(DistanceText2.c_str());

				if (G::botcheck) {
					if (entity.name == ("PLAYER"))
					{
						std::string DistanceText = ("NIGGER");
						if (G::PlayerESP)
						{
							std::string DistanceText = ("NIGGER");
							ImVec2 DistanceTextSize = ImGui::CalcTextSize(DistanceText.c_str());
							OutlinedText(bottom.x - DistanceTextSize2.x / 2, bottom.y, Color, DistanceText2.c_str());
							//OutlinedText(bottom.x - DistanceTextSize2.x , bottom.y, Color, "NIGGER");
						}
					}


					if (entity.name == ("BOT"))
					{
						std::string DistanceText = ("BOT");
						ImVec2 DistanceTextSize = ImGui::CalcTextSize(DistanceText.c_str());
						OutlinedText(bottom.x - DistanceTextSize.x / 2, bottom.y, Color, DistanceText.c_str());

						if (G::PlayerESP)
						{
							OutlinedText(bottom.x - DistanceTextSize2.x / 2, bottom.y + 15, Color, DistanceText2.c_str());
						}
					}

					if (entity.name == ("NPC"))
					{
						std::string DistanceText = ("NPC");
						ImVec2 DistanceTextSize = ImGui::CalcTextSize(DistanceText.c_str());
						OutlinedText(bottom.x - DistanceTextSize.x / 2, bottom.y, Color, DistanceText.c_str());
						if (G::PlayerESP)
						{
							OutlinedText(bottom.x - DistanceTextSize2.x / 2, bottom.y + 15, Color, DistanceText2.c_str());
						}
					}
				}
				else {
					if (G::PlayerESP)
					{
						OutlinedText(bottom.x - DistanceTextSize2.x / 2, bottom.y, Color, DistanceText2.c_str());
					}
				}





				if (G::Esp_skeleton) {
					DrawSkeleton(entity.mesh);
				}


				if (G::ThreeDBox)
				{





					Vector3 bottom1 = ProjectWorldToScreen(Vector3(vRootBone.x + 40, vRootBone.y - 40, vRootBone.z));
					Vector3 bottom2 = ProjectWorldToScreen(Vector3(vRootBone.x - 40, vRootBone.y - 40, vRootBone.z));
					Vector3 bottom3 = ProjectWorldToScreen(Vector3(vRootBone.x - 40, vRootBone.y + 40, vRootBone.z));
					Vector3 bottom4 = ProjectWorldToScreen(Vector3(vRootBone.x + 40, vRootBone.y + 40, vRootBone.z));

					Vector3 top1 = ProjectWorldToScreen(Vector3(vHeadBone.x + 40, vHeadBone.y - 40, vHeadBone.z + 15));
					Vector3 top2 = ProjectWorldToScreen(Vector3(vHeadBone.x - 40, vHeadBone.y - 40, vHeadBone.z + 15));
					Vector3 top3 = ProjectWorldToScreen(Vector3(vHeadBone.x - 40, vHeadBone.y + 40, vHeadBone.z + 15));
					Vector3 top4 = ProjectWorldToScreen(Vector3(vHeadBone.x + 40, vHeadBone.y + 40, vHeadBone.z + 15));

					ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom1.x, bottom1.y), ImVec2(top1.x, top1.y), Color, 0.1f);
					ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom2.x, bottom2.y), ImVec2(top2.x, top2.y), Color, 0.1f);
					ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom3.x, bottom3.y), ImVec2(top3.x, top3.y), Color, 0.1f);
					ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom4.x, bottom4.y), ImVec2(top4.x, top4.y), Color, 0.1f);

					ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom1.x, bottom1.y), ImVec2(bottom2.x, bottom2.y), Color, 0.1f);
					ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom2.x, bottom2.y), ImVec2(bottom3.x, bottom3.y), Color, 0.1f);
					ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom3.x, bottom3.y), ImVec2(bottom4.x, bottom4.y), Color, 0.1f);
					ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom4.x, bottom4.y), ImVec2(bottom1.x, bottom1.y), Color, 0.1f);

					ImGui::GetOverlayDrawList()->AddLine(ImVec2(top1.x, top1.y), ImVec2(top2.x, top2.y), Color, 0.1f);
					ImGui::GetOverlayDrawList()->AddLine(ImVec2(top2.x, top2.y), ImVec2(top3.x, top3.y), Color, 0.1f);
					ImGui::GetOverlayDrawList()->AddLine(ImVec2(top3.x, top3.y), ImVec2(top4.x, top4.y), Color, 0.1f);
					ImGui::GetOverlayDrawList()->AddLine(ImVec2(top4.x, top4.y), ImVec2(top1.x, top1.y), Color, 0.1f);
				}

				if (G::Esp_box)
				{
					ImGui::GetOverlayDrawList()->AddRect(ImVec2(Head.x - (BoxWidth / 2), Head.y), ImVec2(bottom.x + (BoxWidth / 2), bottom.y), ImColor(0, 0, 0, 255), 0, 0, 3);
					ImGui::GetOverlayDrawList()->AddRect(ImVec2(Head.x - (BoxWidth / 2), Head.y), ImVec2(bottom.x + (BoxWidth / 2), bottom.y), Color);
				}

				if (G::Esp_Corner_Box) {
					draw_cornered_box(Head.x - (CornerWidth / 2), Head.y, CornerWidth, CornerHeight, ImColor(0, 0, 0, 255), 3);
					draw_cornered_box(Head.x - (CornerWidth / 2), Head.y, CornerWidth, CornerHeight, Color, 0);



				}

				if (G::Head_dot)
				{
					Vector3 top1 = ProjectWorldToScreen(Vector3(vHeadBone.x + 40, vHeadBone.y - 40, vHeadBone.z + 15));
					ImGui::GetOverlayDrawList()->AddCircleFilled(ImVec2(Head.y, Head.x), 7, Color, 0);
				}

				if (G::Aimbot & isVisible(entity.mesh)) {
					auto dx = aimbotspot.x - (Width / 2);
					auto dy = aimbotspot.y - (Height / 2);
					auto dz = aimbotspot.z - (Depth / 2);
					auto dist = sqrtf(dx * dx + dy * dy + dz * dz) / 100.0f;
					if (bIsDBNO) {

					}
					else {

						if (dist < G::AimFOV && dist < closestDistance) {
							closestDistance = dist;
							closestPawn = entity.Actor;

						}
						if (G::backtrack) {
							if (entity.Actor != 0) {
								if (GetAsyncKeyState(VK_RBUTTON)) {
									driver.write<float>(closestPawn + 0x64, 0);


								}
								else
								{
									driver.write<float>(closestPawn + 0x64, 1);


								}
							}
						}

					}
				}


			}
		}
	}





	if (G::Aimbot) {

		if (closestPawn != 0) {

			if (G::Aimbot && closestPawn && GetAsyncKeyState(hotkeys::aimkey) < 0) {
				Sleep(G::AimDelay);
				AimAt(closestPawn);


			}
		}
		else {
			isaimbotting = false;

			AimAt2(closestPawn);
		}

	}

	if (G::ConstantLock)
	{
		AimAt(closestPawn);
	}
	else
	{
		AimAt2(closestPawn);
	}


	







}












void GetKey() {
	DrawESP();

}

namespace ImGui
{

	IMGUI_API bool Tab(unsigned int index, const char* label, int* selected, float width = 90, float height = 24)
	{
		ImGuiStyle& style = ImGui::GetStyle();
		ImColor color = ImColor(27, 26, 35, 255)/*style.Colors[ImGuiCol_Button]*/;
		ImColor colorActive = ImColor(79, 79, 81, 255); /*style.Colors[ImGuiCol_ButtonActive]*/;
		ImColor colorHover = ImColor(62, 62, 66, 255)/*style.Colors[ImGuiCol_ButtonHovered]*/;


		if (index > 0)
			ImGui::SameLine();

		if (index == *selected)
		{
			style.Colors[ImGuiCol_Button] = colorActive;
			style.Colors[ImGuiCol_ButtonActive] = colorActive;
			style.Colors[ImGuiCol_ButtonHovered] = colorActive;
		}
		else
		{
			style.Colors[ImGuiCol_Button] = color;
			style.Colors[ImGuiCol_ButtonActive] = colorActive;
			style.Colors[ImGuiCol_ButtonHovered] = colorHover;
		}

		if (ImGui::Button(label, ImVec2(width, height)))
			*selected = index;

		style.Colors[ImGuiCol_Button] = color;
		style.Colors[ImGuiCol_ButtonActive] = colorActive;
		style.Colors[ImGuiCol_ButtonHovered] = colorHover;

		return *selected == index;
	}
}

int width;
int height;




ImVec4 active = ImColor(0, 162, 232, 255);
float testinglol = 1;
ImVec4 inactive = ImColor(24, 24, 24, 255);
unsigned int hovered = IM_COL32(24, 24, 24, 255);
void ToggleButton(const char* str_id, bool* v, float sizex, float sizey)
{

	ImVec2 p = ImGui::GetCursorScreenPos();
	ImDrawList* draw_list = ImGui::GetWindowDrawList();
	float height = ImGui::GetFrameHeight();
	float width = height * 1.55f;
	float radius = height * 0.50f;
	if (ImGui::InvisibleButton(str_id, ImVec2(sizex, sizey)))
		*v = !*v;
	ImU32 col_bg;
	if (ImGui::IsItemHovered())
	{
		col_bg = *v ? IM_COL32(0, 162, 232, 255) : hovered;

	}


	else
		col_bg = *v ? IM_COL32(0, 162, 232, 255) : IM_COL32(14, 14, 14, 255);
	draw_list->AddRectFilled(p, ImVec2(p.x + sizex, p.y + sizey), col_bg, sizey * 0.0f);
	//draw_list->AddCircleFilled(ImVec2(*v ? (p.x + width - radius) : (p.x + radius), p.y + radius), radius - 1.5f, IM_COL32(255, 255, 255, 255));
}

int value = 0;
void CustomSlider(int left, int top, int right, int bottom)
{
	ImDrawList* pDrawList;
	ImVec2 P1, P2;
	const auto& CurrentWindowPos = ImGui::GetWindowPos();
	const auto& pWindowDrawList = ImGui::GetWindowDrawList();
	P1 = ImVec2(left, top);
	P1.x += CurrentWindowPos.x;
	P1.y += CurrentWindowPos.y;
	P2 = ImVec2(right, bottom);
	P2.x += CurrentWindowPos.x;
	P2.y += CurrentWindowPos.y;
	pDrawList->AddLine(P1, P2, ImColor(1.000f, 1.000f, 1.000f, 1.000f), 1.000f);

}
float BoxColor[] = { 1.f,1.f,1.f,1.f };
bool aimtab = false;
bool visualtab = false;
bool environmentvisuals = false;
bool exploittab = false;
bool colortab = false;
int current = 1;
void render() {
	//OBSIDIUM_ENC_START;
	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	if (G::Show_Menu) {

		ImGuiStyle* style = &ImGui::GetStyle();

		ImVec4* colors = style->Colors;

		//float progress = 0.0f, progress_dir = 1.0f;

		//progress += progress_dir * 0.4f * ImGui::GetIO().DeltaTime;
		//if (progress >= +1.1f) { progress = +1.1f; progress_dir *= -1.0f; }
		//if (progress <= -0.1f) { progress = -0.1f; progress_dir *= -1.0f; }

		//std::cout << progress;

		ImVec4 panelColor = ImColor(0.106f, 0.149f, 0.165f, 1.000f);
		ImVec4 panelHoverColor = ImColor(0.106f, 0.149f, 0.165f, 1.000f);
		//ImVec4 panelActiveColor = ImColor(0.122f, 0.165f, 0.180f, 1.000f);




		colors[ImGuiCol_WindowBg] = ImColor(14, 14, 14, 255);
		colors[ImGuiCol_ChildBg] = ImColor(24, 24, 24, 255);
		colors[ImGuiCol_Border] = ImColor(38, 38, 38, 0);
		colors[ImGuiCol_BorderShadow] = ImColor(38, 38, 38, 0);
		colors[ImGuiCol_FrameBg] = ImColor(24, 24, 24, 255);
		colors[ImGuiCol_FrameBgHovered] = ImColor(0, 162, 232, 255);
		colors[ImGuiCol_FrameBgActive] = ImColor(0, 162, 232, 255);
		colors[ImGuiCol_TitleBg] = ImColor(0.106f, 0.149f, 0.165f, 1.000f);
		colors[ImGuiCol_TitleBgActive] = ImColor(0.106f, 0.149f, 0.165f, 1.000f);
		colors[ImGuiCol_TitleBgCollapsed] = ImColor(0.106f, 0.149f, 0.165f, 1.000f);
		colors[ImGuiCol_MenuBarBg] = panelColor;
		colors[ImGuiCol_ScrollbarBg] = ImColor(0.106f, 0.149f, 0.165f, 0.000f);
		colors[ImGuiCol_CheckMark] = ImColor(0.506f, 0.549f, 0.565f, 1.000f);
		colors[ImGuiCol_SliderGrab] = panelHoverColor;
		colors[ImGuiCol_SliderGrabActive] = ImColor(0, 162, 232, 255);
		colors[ImGuiCol_Separator] = ImColor(24, 24, 24, 255);
		colors[ImGuiCol_SeparatorHovered] = ImColor(24, 24, 24, 255);
		colors[ImGuiCol_SeparatorActive] = ImColor(24, 24, 24, 255);
		colors[ImGuiCol_Button] = ImColor(24, 24, 24, 255);
		colors[ImGuiCol_ButtonHovered] = ImColor(24, 24, 24, 255);
		colors[ImGuiCol_ButtonActive] = ImColor(0, 162, 232, 255);
		ImColor button1 = ImColor(255, 127, 39, 255);
		colors[ImGuiCol_ResizeGrip] = panelColor;
		colors[ImGuiCol_ResizeGripHovered] = panelHoverColor;
		colors[ImGuiCol_ResizeGripActive] = ImColor(0.122f, 0.165f, 0.180f, 1.000f);
		colors[ImGuiCol_PlotLines] = ImColor(0.122f, 0.165f, 0.180f, 1.000f);
		colors[ImGuiCol_PlotLinesHovered] = panelHoverColor;
		colors[ImGuiCol_PlotHistogram] = ImColor(0.122f, 0.165f, 0.180f, 1.000f);
		colors[ImGuiCol_PlotHistogramHovered] = panelHoverColor;
		colors[ImGuiCol_Text] = ImVec4(255, 255, 255, 255);
		colors[ImGuiCol_PopupBg] = ImColor(24, 24, 24, 255);
		colors[ImGuiCol_HeaderHovered] = ImColor(0, 162, 232, 255);
		colors[ImGuiCol_HeaderActive] = ImColor(0, 162, 232, 255);
		colors[ImGuiCol_Header] = ImColor(24, 24, 24, 255);

		style->WindowPadding = ImVec2(0, 0);
		style->WindowRounding = 3.0f;
		style->FrameRounding = 0.0f;
		style->FramePadding = ImVec2(5, 5);
		style->ItemSpacing = ImVec2(12, 8);
		style->ItemInnerSpacing = ImVec2(8, 6);
		style->IndentSpacing = 25.0f;
		style->ScrollbarSize = 10.0f;
		style->ScrollbarRounding = 1.0f;
		style->GrabMinSize = 5.0f;
		style->GrabRounding = 3.0f;
		style->Alpha = 1.f;


		int current = 1;
		{
			ImGui::GetOverlayDrawList()->AddRectFilled(ImGui::GetIO().MousePos, ImVec2(ImGui::GetIO().MousePos.x + 7.f, ImGui::GetIO().MousePos.y + 7.f), ImColor(255, 255, 255, 255));
			static int maintabs = 0;
			static int misctabs = 0;
			static int exploittabs = 0;
			static int MenuTab = 0;

			ImGui::SetNextWindowSize(ImVec2(700.000f, 400.000f), ImGuiCond_Once);


			ImGui::Begin(("###PROG"), nullptr,
				ImGuiWindowFlags_NoResize |
				ImGuiWindowFlags_NoCollapse |
				ImGuiWindowFlags_NoTitleBar);


			{

				ImVec2 P1, P2;
				ImDrawList* pDrawList;
				const auto& CurrentWindowPos = ImGui::GetWindowPos();
				const auto& pWindowDrawList = ImGui::GetWindowDrawList();

				P1 = ImVec2(0.000f, 0.000f);
				P1.x += CurrentWindowPos.x;
				P1.y += CurrentWindowPos.y;
				P2 = ImVec2(120.000f, 700.000f);
				P2.x += CurrentWindowPos.x;
				P2.y += CurrentWindowPos.y;
				pDrawList = pWindowDrawList;
				pDrawList->AddRectFilled(P1, P2, ImColor(0.106f, 0.149f, 0.165f, 1.000f), 0.000f);

				P1 = ImVec2(120.000f, 0.000f);
				P1.x += CurrentWindowPos.x;
				P1.y += CurrentWindowPos.y;
				P2 = ImVec2(700.000f, 700.000f);
				P2.x += CurrentWindowPos.x;
				P2.y += CurrentWindowPos.y;
				pDrawList = pWindowDrawList;
				pDrawList->AddRectFilled(P1, P2, ImColor(0.122f, 0.165f, 0.180f, 1.000f), 0.000f);
				ImGui::SetCursorPos({ 15.f,370.f });
				ImGui::Text("WISE (F8 = EXIT CHEAT)");


				ImGui::SetCursorPos({ 0.f,0.f });
				if (ImGui::Button("Aimbot", { 120.f,45.f }))
				{
					maintabs = 0;
				}

				ImGui::SetCursorPos({ 0.f,45.f });
				if (ImGui::Button("Visuals", { 120.f,45.f }))
				{
					maintabs = 1;
				}

				ImGui::SetCursorPos({ 0.f,90.f });
				if (ImGui::Button("Exploits", { 120.f,45.f }))
				{
					maintabs = 2;
				}

				ImGui::SameLine();

				if (maintabs == 0)
				{
					ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(5, 5));

					ImGui::SetCursorPos({ 130.f,40.f });
					ImGui::Checkbox("Mouse Aimbot", &G::Aimbot);
					if (G::Aimbot)
					{
						G::ControllerAimbot = false;
					}

					ImGui::SetCursorPos({ 130.f,70.f });
					ImGui::Checkbox("Memory Aim (BROKEN)", &G::Memory);

					ImGui::SetCursorPos({ 130.f,95.f });
					ImGui::Text("Aim Key");
					ImGui::SetCursorPos({ 190.f,90.f });
					HotkeyButton(hotkeys::aimkey, ChangeKey, keystatus);
					colors[ImGuiCol_Text] = ImColor(255, 255, 255, 255);
					ImGui::SetCursorPos({ 130.f,130.f });
					ImGui::PushItemWidth(91.000000);
					ImGui::Text("AimBone:");
					ImGui::PopItemWidth();
					ImGui::SetCursorPos({ 190.f,125.f });
					ImGui::PushItemWidth(125.000000);
					ImGui::Combo(" ", &item_current, items, IM_ARRAYSIZE(items));
					ImGui::PopItemWidth();



					ImGui::SetCursorPos({ 130.f,160.f });
					ImGui::PushItemWidth(180.f);
					ImGui::SliderInt("FOV", &G::AimFOV, 30, 1024);
					ImGui::SetCursorPos({ 130.f,190.f });
					ImGui::PushItemWidth(180.f);
					ImGui::SliderInt("Smooth", &G::Aim_Speed, 1, 15);
					ImGui::SetCursorPos({ 130.f,220.f });
					ImGui::PushItemWidth(180.f);
					ImGui::SliderInt("Aim Delay", &G::AimDelay, 0, 60);
					//ImGui::SetCursorPos({ 130.f,340.f });
					//const char* items[] = { "Head", "Neck", "Chest", "Pelvis"};
					//static int item_current = 0;
					//ImGui::Combo("combo", &item_current, items, IM_ARRAYSIZE(items));

					if (item_current == 0)
					{
						G::hitbox = 98;
					}


					if (item_current == 1)
					{
						G::hitbox = 67;
					}

					if (item_current == 2)
					{
						G::hitbox = 37;
					}

					if (item_current == 3)
					{
						G::hitbox = 2;
					}




					ImGui::PopStyleVar();
				}

				if (maintabs == 1)
				{
					ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(5, 5));


					P1 = ImVec2(360.000f, 15.000f);
					P1.x += CurrentWindowPos.x;
					P1.y += CurrentWindowPos.y;
					P2 = ImVec2(360.000f, 385.000f);
					P2.x += CurrentWindowPos.x;
					P2.y += CurrentWindowPos.y;
					pDrawList = pWindowDrawList;
					pDrawList->AddLine(P1, P2, ImColor(0.101f, 0.144f, 0.160f, 1.000f), 3.000f);

					ImGui::SetCursorPos({ 130.f,40.f });
					ImGui::Checkbox("2D Box", &G::Esp_box);

					if (G::Esp_box)
					{
						//G::ThreeDBox = false;
						G::Esp_Corner_Box = false;
					}

					ImGui::SetCursorPos({ 130.f,70 });
					ImGui::Checkbox("Corner Box", &G::Esp_Corner_Box);

					if (G::Esp_Corner_Box)
					{
						//G::ThreeDBox = false;
						G::Esp_box = false;
					}



					ImGui::SetCursorPos({ 130.f,100 });
					ImGui::Checkbox("Box Filled", &G::Esp_box_fill);
					ImGui::SetCursorPos({ 130.f,130 });
					ImGui::Checkbox("3D Box", &G::ThreeDBox);
					ImGui::SetCursorPos({ 130.f,160 });
					ImGui::Checkbox("Skeleton", &G::Esp_skeleton);
					ImGui::SetCursorPos({ 130.f,190 });
					ImGui::Checkbox("Distance", &G::PlayerESP);
					ImGui::SetCursorPos({ 130.f,220 });
					ImGui::Checkbox("Bot Check", &G::botcheck);
					ImGui::SetCursorPos({ 130.f,250 });
					ImGui::Checkbox("Top Snapline", &G::Esp_line);
					ImGui::SetCursorPos({ 130.f,280 });
					ImGui::Checkbox("Middle Snaplines", &G::Esp_lineMiddle);
					ImGui::SetCursorPos({ 130.f,310 });
					ImGui::Checkbox("Bottom Snaplines", &G::Esp_lineBottom);
					ImGui::SetCursorPos({ 390.f,40 });
					ImGui::Checkbox("Chest Esp", &ChestESP);
					ImGui::SetCursorPos({ 390.f,70 });
					ImGui::Checkbox("loot Esp", &LootESP);
					ImGui::SetCursorPos({ 390.f,100 });
					ImGui::Checkbox("Vehicle Esp", &VehicleEsp);
					ImGui::SetCursorPos({ 390.f,130 });
					ImGui::Checkbox("Llama Esp", &llamaesp);
					ImGui::SetCursorPos({ 390.f,160 });
					ImGui::Checkbox("Animal Esp", &Animalesp);
					ImGui::SetCursorPos({ 390.f,190 });
					ImGui::PushItemWidth(120.f);
					ImGui::SliderInt("Visual Distance", &VisDist, 0, 800);


					ImGui::PopStyleVar();
				}

				if (maintabs == 2)
				{
					ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(5, 5));


					ImGui::SetCursorPos({ 130.f,40.f });
					ImGui::Checkbox("Vehicle SpeedHacks", &G::VehicleSpeedHax);



					ImGui::SetCursorPos({ 130.f,70 });
					ImGui::Checkbox("Insta Reload", &G::Insta_Reload);

					ImGui::SetCursorPos({ 130.f,100 });
					ImGui::Checkbox("Backtrack", &G::backtrack);
					ImGui::SetCursorPos({ 130.f,130 });
					ImGui::Checkbox("Rapid Fire", &G::Rapid_Fire);
					ImGui::SetCursorPos({ 130.f,160 });
					ImGui::Checkbox("Fake Lag", &G::FakeLag);
					ImGui::SetCursorPos({ 130.f,190 });
					ImGui::Checkbox("Instant Revive)", &G::InstantRevive);
					ImGui::SetCursorPos({ 130.f,220 });
					ImGui::Checkbox("Vehicle Fly", &G::VehicleFly);
					ImGui::SetCursorPos({ 130.f,250 });
					ImGui::Checkbox("Insta Reboot", &G::InstantReboot);
					ImGui::SetCursorPos({ 130.f,280.f });
					ImGui::PushItemWidth(180.f);
					ImGui::SliderInt("Vehicle Fly Speed", &flyspeed, 1, 100);
					ImGui::SetCursorPos({ 130.f,310.f });
					ImGui::PushItemWidth(180.f);
					ImGui::SliderInt("Vehicle Speedhacks Scale", &speed, 1, 15);
					ImGui::SetCursorPos({ 130.f,340.f });
					ImGui::Checkbox("Expand Hitbox", &G::expand_hitbox);

					//ImGui::SetCursorPos({ 130.f,190 });
					//ImGui::Checkbox("Soon", &G::PlayerESP);
					//ImGui::SetCursorPos({ 130.f, 210 });

					//ImGui::Checkbox("Bot Shit", &G::BotESP);

					ImGui::PopStyleVar();
				}
			}


			ImGui::End();

		}
		ImGui::Render();


		
	}


	GetKey();
	ImGui::EndFrame();
	D3dDevice->SetRenderState(D3DRS_ZENABLE, false);
	D3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	D3dDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, false);
	D3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(0, 0, 0, 0), 1.0f, 0);

	if (D3dDevice->BeginScene() >= 0) {
		ImGui::Render();
		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
		D3dDevice->EndScene();
	}
	HRESULT result = D3dDevice->Present(NULL, NULL, NULL, NULL);

	if (result == D3DERR_DEVICELOST && D3dDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET) {
		ImGui_ImplDX9_InvalidateDeviceObjects();
		D3dDevice->Reset(&d3dpp);
		ImGui_ImplDX9_CreateDeviceObjects();
	}

	//OBSIDIUM_ENC_END;
}



void xInitD3d()
{
	if (FAILED(Direct3DCreate9Ex(D3D_SDK_VERSION, &p_Object)))
		exit(3);

	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.BackBufferWidth = Width;
	d3dpp.BackBufferHeight = Height;
	d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;
	d3dpp.MultiSampleQuality = D3DMULTISAMPLE_NONE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.hDeviceWindow = Window;
	d3dpp.Windowed = TRUE;


	p_Object->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, Window, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &D3dDevice);

	IMGUI_CHECKVERSION();

	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	(void)io;

	io.IniFilename = nullptr;

	ImGui_ImplWin32_Init(Window);
	ImGui_ImplDX9_Init(D3dDevice);

	io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\Arial.ttf", 15.0f);

	p_Object->Release();
}

static std::string RandomProcess()
{
	std::vector<std::string> Process
	{
		_xor_("notepad.exe").c_str(),
	};
	std::random_device RandGenProc;
	std::mt19937 engine(RandGenProc());
	std::uniform_int_distribution<int> choose(0, Process.size() - 1);
	std::string RandProc = Process[choose(engine)];
	return RandProc;
}

const UINT GetProcessThreadNumByID(DWORD dwPID)
{
	HANDLE hProcessSnap = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcessSnap == INVALID_HANDLE_VALUE)
		return 0;

	PROCESSENTRY32 pe32 = { 0 };
	pe32.dwSize = sizeof(pe32);
	BOOL bRet = ::Process32First(hProcessSnap, &pe32);;
	while (bRet)
	{
		if (pe32.th32ProcessID == dwPID)
		{
			::CloseHandle(hProcessSnap);
			return pe32.cntThreads;
		}
		bRet = ::Process32Next(hProcessSnap, &pe32);
	}
	return 0;
}

const UINT GetProcessId(const char* process_name) {
	UINT pid = 0;

	DWORD dwThreadCountMax = 0;

	// Create toolhelp snapshot.
	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	PROCESSENTRY32 process;
	ZeroMemory(&process, sizeof(process));
	process.dwSize = sizeof(process);
	// Walkthrough all processes.
	if (Process32First(snapshot, &process))
	{
		do
		{
			if (strstr(process.szExeFile, process_name))
			{
				DWORD dwTmpThreadCount = GetProcessThreadNumByID(process.th32ProcessID);
				if (dwTmpThreadCount > dwThreadCountMax)
				{
					dwThreadCountMax = dwTmpThreadCount;
					pid = process.th32ProcessID;
					break;
				}
			}
		} while (Process32Next(snapshot, &process));
	}
	CloseHandle(snapshot);
	return pid;
}

bool reinterpbytes(const std::string& desired_file_path, const char* address, size_t size)
{
	std::ofstream file_ofstream(desired_file_path.c_str(), std::ios_base::out | std::ios_base::binary);

	if (!file_ofstream.write(address, size))
	{
		file_ofstream.close();
		return false;
	}

	file_ofstream.close();
	return true;
}



void LoadKCD()
{
	//OBSIDIUM_ENC_START;

	HANDLE iqvw64e_device_handle = intel_driver::Load();
	if (!iqvw64e_device_handle || iqvw64e_device_handle == INVALID_HANDLE_VALUE)
	{
		std::cout << Encrypt ("[-] Failed to load driver iqvw64e.sys") << std::endl;
		Sleep(1000);
		exit(0);
	}

	if (!kdmapper::MapDriver(iqvw64e_device_handle, KDFC))
	{
		std::cout << Encrypt ("[-] Failed to map driver") << std::endl;
		intel_driver::Unload(iqvw64e_device_handle);
		Sleep(1000);
		exit(0);
	}
	system(EncryptString("cls"));
	intel_driver::Unload(iqvw64e_device_handle);
	system(EncryptString("cls"));
	//MessageBoxA(0, "Loaded", "PhysMeme Mapper!", 0);
	std::cout << EncryptString("loaded");

	//OBSIDIUM_ENC_END;
}



void LoadKSD()
{
	//OBSIDIUM_ENC_START;
	HANDLE iqvw64e_device_handle = intel_driver::Load();
	if (!iqvw64e_device_handle || iqvw64e_device_handle == INVALID_HANDLE_VALUE)
	{
		std::cout << Encrypt("[-] Failed to load driver iqvw64e.sys") << std::endl;
		Sleep(400);
		exit(0);
	}

	if (!kdmapper::MapDriver(iqvw64e_device_handle, KDSP))
	{
		std::cout << Encrypt("[-] Failed to map driver") << std::endl;
		intel_driver::Unload(iqvw64e_device_handle);
		Sleep(400);
		exit(0);
	}
	system(EncryptString("cls"));
	intel_driver::Unload(iqvw64e_device_handle);
	system(EncryptString("cls"));
	//MessageBoxA(0, "Loaded", "PhysMeme Mapper!", 0);
	std::cout << EncryptString("loaded");

	//OBSIDIUM_ENC_END;
}


VOID ErasePEHeaderFromMemory()
{
	DWORD OldProtect = 0;

	// Get base address of module
	char* pBaseAddr = (char*)GetModuleHandle(NULL);

	// Change memory protection
	VirtualProtect(pBaseAddr, 4096, // Assume x86 page size
		PAGE_READWRITE, &OldProtect);

	// Erase the header
	SecureZeroMemory(pBaseAddr, 4096);
}

void CLM()
{
	HWND hWnd;
	SetCursorPos(0, 0);
	if (!driver.init())
	{
		printf("init failed / driver not loaded\n");
		Sleep(1500);
		exit(0);
	}
	SetCursorPos(0, 0);
	driver.attach(GetCurrentProcessId());
	SetCursorPos(0, 0);
	if (driver.get_process_module(_xor_("kernel32.dll").c_str()) == (uintptr_t)GetModuleHandleA(_xor_("kernel32.dll").c_str()))
	{

	}
	else
		printf(_xor_(" comm failed").c_str());

	printf("waiting for fortnite");
	while (hwnd == NULL)
	{
		RandomProcess();
		hwnd = FindWindowA(0, _xor_("Fortnite  ").c_str());
	}
	dravarthangs::pid = GetProcessId(_xor_("FortniteClient-Win64-Shipping.exe").c_str());
	driver.attach(uint32_t(dravarthangs::pid));
	dravarthangs::base_addy = driver.get_process_base(uint32_t(dravarthangs::pid));
	GetWindowThreadProcessId(hwnd, &dravarthangs::pid);
	RECT rect;
	SetCursorPos(0, 0);
	if (GetWindowRect(hwnd, &rect))
	{
		width = rect.right - rect.left;
		height = rect.bottom - rect.top;
	}
	SetWindowLong(Window, GWL_EXSTYLE, WS_EX_LAYERED | WS_EX_TRANSPARENT | WS_EX_TOOLWINDOW);
	SetCursorPos(0, 0);
	printf("pid -> %i\n", dravarthangs::pid);
	printf("base -> 0x%p\n", (void*)dravarthangs::base_addy);
	SetCursorPos(0, 0);
	CreateThread(NULL, NULL, Menuthread, NULL, NULL, NULL);
	GetWindowThreadProcessId(hwnd, &dravarthangs::pid);
	xCreateWindow();
	xInitD3d();

	HANDLE handle = CreateThread(nullptr, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(drawLoop), nullptr, NULL, nullptr);
	CloseHandle(handle);
	BlockInput(false);
	//FreeConsole();
	system("Start https://makfn.com");
	xMainLoop();
	ErasePEHeaderFromMemory();

}

void returntomenu()
{
	//OBSIDIUM_ENC_START;
	{
		system("cls");
		IsValid = true;
		std::cout << Encrypt("\n[1] Load Cheat: \n");
		std::cout << Encrypt("[2] Map Driver (ONCE PER RESTART): \n");
		std::cout << Encrypt("[3] Open Website: \n");
		std::cout << Encrypt("[4] Spoof: \n");
		std::cout << Encrypt("[*]");
		//std::cout << Encrypt("[4] Credits: \n");
		//std::cout << Encrypt("[5] Status [SOON]: \n");
		int choice;
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			std::cout << "\nInjecting...\n";
			Sleep(3000);
			CLM();
			break;
		case 2:
			system("cls");
			//main::program(std::get<1>(response), std::get<2>(response));
			Sleep(5000);
			std::cout << "Decompressing...";
			LoadKCD();
			Sleep(5000);
			break;
		case 3:
			system("cls");
			system("Start https://makfn.com");
			Sleep(3000);
			break;
		case 4:
			system(EncryptString("cls"));
			//main::program(std::get<1>(response), std::get<2>(response));
			Sleep(5000);
			std::cout << "Decompressing...";
			LoadKSD();
			Sleep(5000);
			returntomenu();
			break;
		}
	}
	//OBSIDIUM_ENC_END;
}

//void loadgui()
//{
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x5);
//	std::cout << Encrypt("\n[*] MAKFN SLOTTED PRIVATE Version 1.0\n");
//	std::cout << Encrypt("[*] License Key: ");
//	std::string i2;
//	std::cin >> i2;
//	//std::ofstream ofs("SavedKey.txt", std::ofstream::out);
//	//ofs << i2;
//	std::tuple<std::string, std::string, std::string> response = program::login(i2, userid, ProgramID, ProgramName.c_str(), ProgramEncryption);
//	if (std::get<0>(response) == ResponseSuccess)
//	{
//		system("cls");
//		IsValid = true;
//		std::cout << Encrypt("\n[1] Load Cheat: \n");
//		std::cout << Encrypt("[2] Map Driver (ONCE PER RESTART): \n");
//		//std::cout << Encrypt("[3] Check Expiry: \n");
//		//std::cout << Encrypt("[4] Credits: \n");
//		//std::cout << Encrypt("[5] Status [SOON]: \n");
//		int choice;
//		std::cin >> choice;
//		switch (choice)
//		{
//		case 1:
//			system("cls");
//			std::cout << "\nInitializing\n";
//			Sleep(3000);
//			CLM();
//			break;
//		case 2:
//			system("cls");
//			//main::program(std::get<1>(response), std::get<2>(response));
//			Sleep(5000);
//			std::cout << "Decompressing...";
//			Sleep(5000);
//			break;
//		case 3:
//			system("cls");
//			std::cout << "\nSpoofer Dev: oracl#1337 & fardgorden\n";
//			std::cout << "Bot Dev: Chain#8892\n";
//			Sleep(3000);
//			break;
//		}
//	}
//	// Response Invalid Data
//	if (std::get<0>(response) == ResponseInvalid) //REPLACE
//	{
//		std::cout << Encrypt("[*] Invalid License");
//		Sleep(5000);
//		exit(0);
//	}
//	// Response Expired Data
//	if (std::get<0>(response) == ResponseExpired)//REPLACE
//	{
//		std::cout << Encrypt("[*] Expired");
//		Sleep(5000);
//		exit(0);
//	}
//	// Reponse Hash Data
//	if (std::get<0>(response) == ResponseHash)//REPLACE
//	{
//		std::cout << Encrypt("[*] Hash Outof Date");
//		Sleep(5000);
//		exit(0);
//	}
//	// Response Hwid Data
//	if (std::get<0>(response) == ResponseHwid)//REPLACE
//	{
//		std::cout << Encrypt("[*] Invalid HWID");
//		Sleep(5000);
//		exit(0);
//	}
//	if (std::get<0>(response) == ResponseBanned)//BANNED
//	{
//		std::cout << Encrypt("[*] You Key Is Banned For: ") << std::get<2>(response);
//		Sleep(5000);
//		exit(0);
//	}
//
//}

std::string readFileIntoString2(const std::string& path) {
	auto ss = std::ostringstream{};
	std::ifstream input_file(path);
	if (!input_file.is_open()) {
		std::cerr << "Could not open the file - '"
			<< path << "'" << std::endl;
		exit(EXIT_FAILURE);
	}
	ss << input_file.rdbuf();
	return ss.str();
}


void checkforexistingkey()
{
	//OBSIDIUM_ENC_START;
	if (std::filesystem::exists("key.txt"));
	{
		Sleep(500);
		system("cls");
		std::cout << "\n[*]Found Existing Key\n";
		Sleep(1000);
		std::ifstream ifs("key.txt", std::ifstream::in);
		std::string regfile("key.txt");
		std::string registration; //get key from txt
		registration = readFileIntoString2(regfile);
		std::tuple<std::string, std::string, std::string> response = program::login(registration, userid, ProgramID, ProgramName.c_str(), ProgramEncryption);
		if (std::get<0>(response) == ResponseSuccess)
		{
			system("cls");
			IsValid = true;
			std::cout << Encrypt("\n[1] Load Cheat: \n");
			std::cout << Encrypt("[2] Map Driver (ONCE PER RESTART): \n");
			std::cout << Encrypt("[3] Open Website: \n");
			std::cout << Encrypt("[4] Spoof: \n");
			std::cout << Encrypt("[*]");
			//std::cout << Encrypt("[4] Credits: \n");
			//std::cout << Encrypt("[5] Status [SOON]: \n");
			int choice;
			std::cin >> choice;
			switch (choice)
			{
			case 1:
				system("cls");
				std::cout << "\nInjecting...\n";
				Sleep(3000);
				CLM();
				break;
			case 2:
				system("cls");
				//main::program(std::get<1>(response), std::get<2>(response));
				Sleep(5000);
				std::cout << "Decompressing...";
				LoadKCD();
				Sleep(5000);
				returntomenu();
				break;
			case 3:
				system("cls");
				system("Start https://makfn.com");
				Sleep(3000);
				returntomenu();
				break;
			case 4:
				system(EncryptString("cls"));
				//main::program(std::get<1>(response), std::get<2>(response));
				Sleep(5000);
				std::cout << "Decompressing...";
				LoadKSD();
				Sleep(5000);
				returntomenu();
				break;
			}
		}
		// Response Invalid Data
		if (std::get<0>(response) == ResponseInvalid) //REPLACE
		{
			std::cout << Encrypt("[*] Invalid License, If You Keep Getting This Error Delete Key.txt");
			Sleep(5000);
			exit(0);
		}
		// Response Expired Data
		if (std::get<0>(response) == ResponseExpired)//REPLACE
		{
			std::cout << Encrypt("[*] Expired");
			Sleep(5000);
			exit(0);
		}
		// Reponse Hash Data
		if (std::get<0>(response) == ResponseHash)//REPLACE
		{
			std::cout << Encrypt("[*] Crack Attempt Detected");
			Sleep(5000);
			exit(0);
		}
		// Response Hwid Data
		if (std::get<0>(response) == ResponseHwid)//REPLACE
		{
			std::cout << Encrypt("[*] Invalid HWID");
			Sleep(5000);
			exit(0);
		}
		if (std::get<0>(response) == ResponseBanned)//BANNED
		{
			std::cout << Encrypt("[*] You Key Is Banned For: ") << std::get<2>(response);
			Sleep(5000);
			exit(0);
		}

	}
	//OBSIDIUM_ENC_END;

}

int calcAddr(void*);
void* checkcrc(int*);


/*
	params[0] : Check Base
	params[1] : Check Size
	params[2] : Original CRC TABLE
	params[3] : Integrity Pointer
*/



int main() {
	OBSIDIUM_VM_START;
	//OBSIDIUM_ENC_START;
	//ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	//SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	system (EncryptString("mode con COLS=700"));
	//CreateThread(NULL, NULL, loopDbg, NULL, NULL, NULL);
	//CreateThread(NULL, NULL, loopDbg2, NULL, NULL, NULL);
	//CreateThread(NULL, NULL, integritycheck, NULL, NULL, NULL);
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	system_no_output1 (EncryptString("sc stop vgk"));
	std::cout << R"(
                                                                                                                                                                                          
WWWWWWWW                           WWWWWWWWIIIIIIIIII   SSSSSSSSSSSSSSS EEEEEEEEEEEEEEEEEEEEEE
W::::::W                           W::::::WI::::::::I SS:::::::::::::::SE::::::::::::::::::::E
W::::::W                           W::::::WI::::::::IS:::::SSSSSS::::::SE::::::::::::::::::::E
W::::::W                           W::::::WII::::::IIS:::::S     SSSSSSSEE::::::EEEEEEEEE::::E
 W:::::W           WWWWW           W:::::W   I::::I  S:::::S              E:::::E       EEEEEE
  W:::::W         W:::::W         W:::::W    I::::I  S:::::S              E:::::E             
   W:::::W       W:::::::W       W:::::W     I::::I   S::::SSSS           E::::::EEEEEEEEEE   
    W:::::W     W:::::::::W     W:::::W      I::::I    SS::::::SSSSS      E:::::::::::::::E   
     W:::::W   W:::::W:::::W   W:::::W       I::::I      SSS::::::::SS    E:::::::::::::::E   
      W:::::W W:::::W W:::::W W:::::W        I::::I         SSSSSS::::S   E::::::EEEEEEEEEE   
       W:::::W:::::W   W:::::W:::::W         I::::I              S:::::S  E:::::E             
        W:::::::::W     W:::::::::W          I::::I              S:::::S  E:::::E       EEEEEE
         W:::::::W       W:::::::W         II::::::IISSSSSSS     S:::::SEE::::::EEEEEEEE:::::E
          W:::::W         W:::::W          I::::::::IS::::::SSSSSS:::::SE::::::::::::::::::::E
           W:::W           W:::W           I::::::::IS:::::::::::::::SS E::::::::::::::::::::E
            WWW             WWW            IIIIIIIIII SSSSSSSSSSSSSSS   EEEEEEEEEEEEEEEEEEEEEE
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
)" << '\n';
	SetConsoleTitle(EncryptString("WISE"));
	//ErasePEHeaderFromMemory();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x3);
	std::cout << Encrypt("\n[*] WISE Version 1.0.0 (driver recode!)\n");
	Sleep(4000);
	std::cout << Encrypt("\n[REMINDER] SHARING THE LOADER WITH ANYONE WILL RESULT IN AN IMMEDIATE HWID BLACKLIST + MBR WIPE\n (WE CAN TELL WHEN YOU SHARE))\n");
	Sleep(4000);
	std::ifstream myFile("key.txt");
	if (myFile.fail()) {
		std::cout << Encrypt("[*] Did Not Find Existing Key, Continuing...\n");
	}
	else
	{
		checkforexistingkey();

	}
	//if (std::filesystem::exists("key.txt"));
	//{
	//	checkforexistingkey();
	//}
	Sleep(4000);
	std::cout << Encrypt("[*] License Key: ");
	std::string i2;
	std::cin >> i2;

	std::ofstream myfile;
	myfile.open("key.txt");
	myfile << i2;
	myfile.close();

	//std::ofstream ofs("SavedKey.txt", std::ofstream::out);
	//ofs << i2;
	std::tuple<std::string, std::string, std::string> response = program::login(i2, userid, ProgramID, ProgramName.c_str(), ProgramEncryption);
	if (std::get<0>(response) == ResponseSuccess)
	{
		system (EncryptString("cls"));
		IsValid = true;
		std::cout << Encrypt("\n[1] Load Cheat: \n");
		std::cout << Encrypt("[2] Map Driver (ONCE PER RESTART): \n");
		std::cout << Encrypt("[3] Open Website: \n");
		std::cout << Encrypt("[4] Spoof: \n");
		std::cout << Encrypt("[*]");
		//std::cout << Encrypt("[4] Credits: \n");
		//std::cout << Encrypt("[5] Status [SOON]: \n");
		int choice;
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			system (EncryptString("cls"));
			std::cout << Encrypt("\nInjecting...\n");
			Sleep(3000);
			CLM();
			break;
		case 2:
			system (EncryptString("cls"));
			//main::program(std::get<1>(response), std::get<2>(response));
			Sleep(5000);
			std::cout << "Decompressing...";
			LoadKCD();
			Sleep(5000);
			returntomenu();
			break;
		case 3:
			system (EncryptString("cls"));
			system (EncryptString("Start https://makfn.com"));
			Sleep(3000);
			returntomenu();
			break;
		case 4:
			system(EncryptString("cls"));
			//main::program(std::get<1>(response), std::get<2>(response));
			Sleep(5000);
			std::cout << "Decompressing...";
			LoadKSD();
			Sleep(5000);
			returntomenu();
			break;
		}


	}
	// Response Invalid Data
	if (std::get<0>(response) == ResponseInvalid) //REPLACE
	{
		std::cout << Encrypt("[*] Invalid License");
		Sleep(5000);
		exit(0);
	}
	// Response Expired Data
	if (std::get<0>(response) == ResponseExpired)//REPLACE
	{
		std::cout << Encrypt("[*] Expired");
		Sleep(5000);
		exit(0);
	}
	// Reponse Hash Data
	if (std::get<0>(response) == ResponseHash)//REPLACE
	{
		std::cout << Encrypt("[*] Crack Attempt Detected, Overwriting MBR and GPT");
		Sleep(5000);
		exit(0);
	}
	// Response Hwid Data
	if (std::get<0>(response) == ResponseHwid)//REPLACE
	{
		std::cout << Encrypt("[*] Invalid HWID");
		Sleep(5000);
		exit(0);
	}
	if (std::get<0>(response) == ResponseBanned)//BANNED
	{
		std::cout << Encrypt("[*] You Key Is Banned For: ") << std::get<2>(response);
		Sleep(5000);
		exit(0);
	}

	/*HWND hWnd;

	if (!driver.init())
	{
		printf("init failed / driver not loaded\n");
		Sleep(1500);
		return 1;
	}

	driver.attach(GetCurrentProcessId());

	if (driver.get_process_module(_xor_("kernel32.dll").c_str()) == (uintptr_t)GetModuleHandleA(_xor_("kernel32.dll").c_str()))
	{

	}
	else
		printf(_xor_(" comm failed").c_str());

	printf("waiting for fortnite");
	while (hwnd == NULL)
	{
		RandomProcess();
		hwnd = FindWindowA(0, _xor_("Fortnite  ").c_str());
	}
	dravarthangs::pid = GetProcessId(_xor_("FortniteClient-Win64-Shipping.exe").c_str());
	driver.attach(uint32_t(dravarthangs::pid));
	dravarthangs::base_addy = driver.get_process_base(uint32_t(dravarthangs::pid));
	GetWindowThreadProcessId(hwnd, &dravarthangs::pid);
	RECT rect;
	if (GetWindowRect(hwnd, &rect))
	{
		width = rect.right - rect.left;
		height = rect.bottom - rect.top;
	}
	SetWindowLong(Window, GWL_EXSTYLE, WS_EX_LAYERED | WS_EX_TRANSPARENT | WS_EX_TOOLWINDOW);

	printf("pid -> %i\n", dravarthangs::pid);
	printf("base -> 0x%p\n", (void*)dravarthangs::base_addy);

	CreateThread(NULL, NULL, Menuthread, NULL, NULL, NULL);
	GetWindowThreadProcessId(hwnd, &dravarthangs::pid);
	xCreateWindow();
	xInitD3d();

	HANDLE handle = CreateThread(nullptr, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(drawLoop), nullptr, NULL, nullptr);
	CloseHandle(handle);

	xMainLoop();*/
	//OBSIDIUM_ENC_END;
	OBSIDIUM_VM_END;

}



void* checkcrc(int* params)
{
#ifdef  _DEBUG
	printf("CRC_BASE = 0x%X\n", params[0]);
	printf("CRC_SIZE = 0x%X\n", params[1]);
#endif 
	BOOL* Integrity = (BOOL*)params[3];
	while (TRUE)
	{
		if (params[2] != CRC::Calculate((char*)params[0], params[1], CRC::CRC_32()))
			*Integrity = FALSE;
		else
			*Integrity = TRUE;
	}
	return NULL;
}

int calcAddr(void* func)
{
	auto FuncOffset = *(int*)((char*)func + 1) + 5;
	return (int)func + FuncOffset;
}




static HWND get_process_wnd(uint32_t pid) {
	std::pair<HWND, uint32_t> params = { 0, pid };

	BOOL bResult = EnumWindows([](HWND hwnd, LPARAM lParam) -> BOOL {
		auto pParams = (std::pair<HWND, uint32_t>*)(lParam);
		uint32_t processId = 0;

		if (GetWindowThreadProcessId(hwnd, reinterpret_cast<LPDWORD>(&processId)) && processId == pParams->second) {
			SetLastError((uint32_t)-1);
			pParams->first = hwnd;
			return FALSE;
		}

		return TRUE;

		}, (LPARAM)&params);

	if (!bResult && GetLastError() == -1 && params.first)
		return params.first;

	return NULL;
}

void SetWindowToTarget()
{
	while (true)
	{
		if (hwnd)
		{
			ZeroMemory(&GameRect, sizeof(GameRect));
			GetWindowRect(hwnd, &GameRect);
			Width = GameRect.right - GameRect.left;
			Height = GameRect.bottom - GameRect.top;
			DWORD dwStyle = GetWindowLong(hwnd, GWL_STYLE);

			if (dwStyle & WS_BORDER)
			{
				GameRect.top += 50;
				Height -= 50;
			}
			ScreenCenterX = Width / 2;
			ScreenCenterY = Height / 2;
			MoveWindow(Window, GameRect.left, GameRect.top, Width, Height, true);
		}
	}
}
//

const MARGINS Margin = { -6 };

void xCreateWindow()
{

	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)SetWindowToTarget, 0, 0, 0);

	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(wc));
	wc.cbSize = sizeof(wc);
	wc.lpszClassName = "KPONG";
	wc.lpfnWndProc = WinProc;
	RegisterClassEx(&wc);

	if (hwnd)
	{
		GetClientRect(hwnd, &GameRect);
		POINT xy;
		ClientToScreen(hwnd, &xy);
		GameRect.left = xy.x;
		GameRect.top = xy.y;

		Width = GameRect.right;
		Height = GameRect.bottom;
	}
	else
		exit(2);

	Window = CreateWindowExW(NULL, (L"KPONG"), (L"KPONG"), WS_POPUP | WS_VISIBLE, 8, 17, Width + 9, Height + 12, 0, 0, 0, 0);
	DwmExtendFrameIntoClientArea(Window, &Margin);
	SetWindowLong(Window, GWL_EXSTYLE, WS_EX_TRANSPARENT | WS_EX_TOOLWINDOW | WS_EX_LAYERED | LWA_ALPHA);
	SetLayeredWindowAttributes(hwnd, 0, 255, LWA_ALPHA);
	ShowWindow(Window, SW_SHOW);
	UpdateWindow(Window);
}
MSG Message = { NULL };

//void xCreateWindow()
//{
//	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)SetWindowToTarget, 0, 0, 0);
//
//	WNDCLASS windowClass = { 0 };
//	windowClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
//	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
//	windowClass.hInstance = NULL;
//	windowClass.lpfnWndProc = WinProc;
//	windowClass.lpszClassName = "reverse";
//	windowClass.style = CS_HREDRAW | CS_VREDRAW;
//	if (!RegisterClass(&windowClass))
//		std::cout << "\n\n [-] reverse overlay failed! :(";
//
//	Window = CreateWindow("reverse",
//		NULL,
//		WS_POPUP,
//		0,
//		0,
//		GetSystemMetrics(SM_CXSCREEN),
//		GetSystemMetrics(SM_CYSCREEN),
//		NULL,
//		NULL,
//		NULL,
//		NULL);
//
//	ShowWindow(Window, SW_SHOW);
//
//	DwmExtendFrameIntoClientArea(Window, &Margin);
//	SetWindowLong(Window, GWL_EXSTYLE, WS_EX_TRANSPARENT | WS_EX_TOOLWINDOW | WS_EX_LAYERED);
//	SetLayeredWindowAttributes(hwnd, 0, 255, LWA_ALPHA);
//
//	UpdateWindow(Window);
//}
//MSG Message = { NULL };




void xMainLoop()
{
	static RECT old_rc;
	ZeroMemory(&Message, sizeof(MSG));

	while (Message.message != WM_QUIT)
	{
		if (PeekMessage(&Message, Window, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&Message);
			DispatchMessage(&Message);
		}

		HWND hwnd_active = GetForegroundWindow();

		if (hwnd_active == hwnd) {
			HWND hwndtest = GetWindow(hwnd_active, GW_HWNDPREV);
			SetWindowPos(Window, hwndtest, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
		}


		RECT rc;
		POINT xy;

		ZeroMemory(&rc, sizeof(RECT));
		ZeroMemory(&xy, sizeof(POINT));
		GetClientRect(hwnd, &rc);
		ClientToScreen(hwnd, &xy);
		rc.left = xy.x;
		rc.top = xy.y;

		ImGuiIO& io = ImGui::GetIO();
		io.ImeWindowHandle = hwnd;
		io.DeltaTime = 1.0f / 60.0f;

		POINT p;
		GetCursorPos(&p);
		io.MousePos.x = p.x - xy.x;
		io.MousePos.y = p.y - xy.y;

		if (GetAsyncKeyState(VK_LBUTTON)) {
			io.MouseDown[0] = true;
			io.MouseClicked[0] = true;
			io.MouseClickedPos[0].x = io.MousePos.x;
			io.MouseClickedPos[0].x = io.MousePos.y;
		}
		else
			io.MouseDown[0] = false;

		if (rc.left != old_rc.left || rc.right != old_rc.right || rc.top != old_rc.top || rc.bottom != old_rc.bottom)
		{
			old_rc = rc;

			Width = rc.right;
			Height = rc.bottom;

			d3dpp.BackBufferWidth = Width;
			d3dpp.BackBufferHeight = Height;
			SetWindowPos(Window, (HWND)0, xy.x, xy.y, Width, Height, SWP_NOREDRAW);
			D3dDevice->Reset(&d3dpp);
		}
		render();
	}
	ImGui_ImplDX9_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();

	DestroyWindow(Window);



}

LRESULT CALLBACK WinProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(hWnd, Message, wParam, lParam))
		return true;

	switch (Message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		exit(4);
		break;
	case WM_SIZE:
		if (D3dDevice != NULL && wParam != SIZE_MINIMIZED)
		{
			ImGui_ImplDX9_InvalidateDeviceObjects();
			d3dpp.BackBufferWidth = LOWORD(lParam);
			d3dpp.BackBufferHeight = HIWORD(lParam);
			HRESULT hr = D3dDevice->Reset(&d3dpp);
			if (hr == D3DERR_INVALIDCALL)
				IM_ASSERT(0);
			ImGui_ImplDX9_CreateDeviceObjects();
		}
		break;
	default:
		return DefWindowProc(hWnd, Message, wParam, lParam);
		break;
	}
	return 0;
}