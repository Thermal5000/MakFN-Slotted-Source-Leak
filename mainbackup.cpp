//#include "Offsets.h"
//#include <string.h>
//#include <string>
//#include <xstring>
//#include "utils.h"
//#include <dwmapi.h>
//#include "Definitions.h"
//#include <sstream>
//#include <stdio.h>
//#include <stdio.h>
//#include <stdio.h>
//#include <stdio.h>
//#include <string>
//#include <algorithm>
//#include <list>
//#include <sstream>
//#include "xorstr.hpp"
//#include <iostream>
//#include <tlhelp32.h>
//#include <fstream>
//#include <filesystem>
//#include <Windows.h>
//#include <winioctl.h>
//#include <lmcons.h>
//#include <random>
//#include "other.h"
//#include <thread>
//#include "driver.h"
//#pragma comment (lib, "urlmon.lib")
//float FOV = 90.0f;
//kernel::driver driver;
//
//struct ESettingType {
//	struct ESettingType* MouseSensitivityYaw;// 0x00;
//	struct ESettingType* MouseSensitivityPitch;// 0x00(0x4)
//
//};
//
//
//std::string random_string(std::size_t length)
//{
//
//	const std::string CHARACTERS = _xor_("abdail").c_str();
//
//	std::random_device random_device;
//	std::mt19937 generator(random_device());
//	std::uniform_int_distribution<> distribution(0, CHARACTERS.size() - 1);
//
//	std::string random_string;
//
//	for (std::size_t i = 0; i < length; ++i)
//	{
//		random_string += CHARACTERS[distribution(generator)];
//	}
//
//	return random_string;
//}
//
//std::string GetNameByID(int id) {
//	uint32_t ChunkOffset = (uint32_t)((int)(id) >> 16);
//	uint16_t NameOffset = (uint16_t)id;
//
//	uint64_t NamePoolChunk = driver.read<uint64_t>((uint64_t)dravarthangs::base_addy + 0xCC282C0 + (8 * ChunkOffset) + 16) + (unsigned int)(4 * NameOffset);
//	uint16_t nameEntry = driver.read<uint64_t>(NamePoolChunk);
//
//	int nameLength = nameEntry >> 6;
//	char buff[1024];
//	if ((uint32_t)nameLength)
//	{
//		for (int x = 0; x < nameLength; ++x)
//		{
//			buff[x] = driver.read<char>(NamePoolChunk + 4 + x);
//		}
//
//		char* v2 = buff;
//		signed int v4 = nameLength;
//		uint64_t result;
//		uint64_t v7;
//		unsigned int v8;
//		signed int v5;
//
//		result = 30;
//		v5 = 0;
//
//		if (v4)
//		{
//			do
//			{
//				v7 = (uint16_t)(v5 | result);
//				++v2;
//				++v5;
//				v8 = (char)~(char)v7;
//				result = (uint8_t)(2 * v7);
//				*(v2 - 1) ^= v8;
//			} while (v5 < v4);
//		}
//		buff[nameLength] = '\0';
//		return std::string(buff);
//	}
//	return "";
//}
//
//
//static std::string GetNameFromFName(int key)
//{
//	uint64_t NamePoolChunk = driver.read<uint64_t>(dravarthangs::base_addy + 0xCC282C0 + (8 * (uint32_t)((int)(key) >> 16)) + 16) + (unsigned int)(4 * (uint16_t)key);
//
//	if (driver.read<uint16_t>(NamePoolChunk) < 64)
//	{
//		auto a1 = driver.read<DWORD>(NamePoolChunk + 4);
//		return GetNameByID(a1);
//	}
//
//	else
//	{
//		return GetNameByID(key);
//	}
//}
//
//static void xCreateWindow();
//static void xInitD3d();
//static void xMainLoop();
//static LRESULT CALLBACK WinProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam);
//extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
//
//static HWND Window = NULL;
//IDirect3D9Ex* p_Object = NULL;
//static LPDIRECT3DDEVICE9 D3dDevice = NULL;
//static LPDIRECT3DVERTEXBUFFER9 TriBuf = NULL;
//
//FTransform GetBoneIndex(DWORD_PTR mesh, int index) {
//	DWORD_PTR bonearray = driver.read<DWORD_PTR>(mesh + Offsets::BoneArray);
//	if (bonearray == NULL) {
//		bonearray = driver.read<DWORD_PTR>(mesh + Offsets::BoneArray + 0x10);
//	}
//	return driver.read<FTransform>(bonearray + (index * 0x60));
//}
//
//Vector3 GetBoneWithRotation(DWORD_PTR mesh, int id) {
//	FTransform bone = GetBoneIndex(mesh, id);
//	FTransform ComponentToWorld = driver.read<FTransform>(mesh + 0x240);
//	D3DMATRIX Matrix;
//	Matrix = MatrixMultiplication(bone.ToMatrixWithScale(), ComponentToWorld.ToMatrixWithScale());
//	return Vector3(Matrix._41, Matrix._42, Matrix._43);
//}
//
//D3DMATRIX Matrix(Vector3 rot, Vector3 origin = Vector3(0, 0, 0)) {
//	double radPitch = (rot.x * double(M_PI) / 180.f);
//	double radYaw = (rot.y * double(M_PI) / 180.f);
//	double radRoll = (rot.z * double(M_PI) / 180.f);
//
//	double SP = sinf(radPitch);
//	double CP = cosf(radPitch);
//	double SY = sinf(radYaw);
//	double CY = cosf(radYaw);
//	double SR = sinf(radRoll);
//	double CR = cosf(radRoll);
//
//	D3DMATRIX matrix;
//	matrix.m[0][0] = CP * CY;
//	matrix.m[0][1] = CP * SY;
//	matrix.m[0][2] = SP;
//	matrix.m[0][3] = 0.f;
//
//	matrix.m[1][0] = SR * SP * CY - CR * SY;
//	matrix.m[1][1] = SR * SP * SY + CR * CY;
//	matrix.m[1][2] = -SR * CP;
//	matrix.m[1][3] = 0.f;
//
//	matrix.m[2][0] = -(CR * SP * CY + SR * SY);
//	matrix.m[2][1] = CY * SR - CR * SP * SY;
//	matrix.m[2][2] = CR * CP;
//	matrix.m[2][3] = 0.f;
//
//	matrix.m[3][0] = origin.x;
//	matrix.m[3][1] = origin.y;
//	matrix.m[3][2] = origin.z;
//	matrix.m[3][3] = 1.f;
//
//	return matrix;
//}
//
//struct CamewaDescwipsion
//{
//	float FieldOfView;
//	Vector3 Rotation;
//	Vector3 Location;
//};
//
//struct CameraInfo {
//	double X, Y, Z;
//	double Pitch, Yaw;
//};
//
//
//CamewaDescwipsion UndetectedCamera(__int64 a1)
//{
//	CamewaDescwipsion VirtualCamera;
//	__int64 v1;
//	__int64 v6;
//	__int64 v7;
//	__int64 v8;
//
//	v1 = driver.read<__int64>(Localplayer + 0xC8);
//	__int64 v9 = driver.read<__int64>(v1 + 8);
//
//	VirtualCamera.FieldOfView = 80.f / (driver.read<double>(v9 + 0x690) / 1.19f);
//
//	VirtualCamera.Rotation.x = driver.read<double>(v9 + 0x7E0);
//	VirtualCamera.Rotation.y = driver.read<double>(a1 + 0x148);
//
//	v6 = driver.read<__int64>(Localplayer + 0x70);
//	v7 = driver.read<__int64>(v6 + 0x98);
//	v8 = driver.read<__int64>(v7 + 0xF8);
//
//	VirtualCamera.Location = driver.read<Vector3>(v8 + 0x20);
//	return VirtualCamera;
//}
//
//Vector3 ProjectWorldToScreen(Vector3 WorldLocation)
//{
//	CamewaDescwipsion vCamera = UndetectedCamera(Rootcomp);
//	vCamera.Rotation.x = (asin(vCamera.Rotation.x)) * (180.0 / M_PI);
//
//	D3DMATRIX tempMatrix = Matrix(vCamera.Rotation);
//
//	Vector3 vAxisX = Vector3(tempMatrix.m[0][0], tempMatrix.m[0][1], tempMatrix.m[0][2]);
//	Vector3 vAxisY = Vector3(tempMatrix.m[1][0], tempMatrix.m[1][1], tempMatrix.m[1][2]);
//	Vector3 vAxisZ = Vector3(tempMatrix.m[2][0], tempMatrix.m[2][1], tempMatrix.m[2][2]);
//
//	Vector3 vDelta = WorldLocation - vCamera.Location;
//	Vector3 vTransformed = Vector3(vDelta.Dot(vAxisY), vDelta.Dot(vAxisZ), vDelta.Dot(vAxisX));
//
//	if (vTransformed.z < 1.f)
//		vTransformed.z = 1.f;
//
//	return Vector3((Width / 2.0f) + vTransformed.x * (((Width / 2.0f) / tanf(vCamera.FieldOfView * (float)M_PI / 360.f))) / vTransformed.z, (Height / 2.0f) - vTransformed.y * (((Width / 2.0f) / tanf(vCamera.FieldOfView * (float)M_PI / 360.f))) / vTransformed.z, 0);
//}
//
//DWORD Menuthread(LPVOID in) {
//	while (1) {
//		if (GetAsyncKeyState(VK_INSERT) & 1) {
//			G::Show_Menu = !G::Show_Menu;
//		}
//		Sleep(2);
//	}
//}
//
//
//Vector3 AimbotCorrection(float bulletVelocity, float bulletGravity, float targetDistance, Vector3 targetPosition, Vector3 targetVelocity) {
//	Vector3 recalculated = targetPosition;
//	float gravity = fabs(bulletGravity);
//	float time = targetDistance / fabs(bulletVelocity);
//	return recalculated;
//}
//
//
//void SetMouseAbsPosition(DWORD x, DWORD y)
//{
//	INPUT input = { 0 };
//	input.type = INPUT_MOUSE;
//	input.mi.dwFlags = MOUSEEVENTF_MOVE;
//	input.mi.dx = x;
//	input.mi.dy = y;
//	SendInput(1, &input, sizeof(input));
//}
//static auto aimbot(float x, float y) -> void {
//	float center_x = (ImGui::GetIO().DisplaySize.x / 2);
//	float center_y = (ImGui::GetIO().DisplaySize.y / 2);
//
//	int AimSpeed = G::Aim_Speed;
//	float target_x = 0;
//	float target_y = 0;
//
//	//if (isVisible)
//	{
//		if (x != 0.f)
//		{
//			if (x > center_x)
//			{
//				target_x = -(center_x - x);
//				target_x /= G::Aim_Speed;
//				if (target_x + center_x > center_x * 2.f) target_x = 0.f;
//			}
//
//			if (x < center_x)
//			{
//				target_x = x - center_x;
//				target_x /= G::Aim_Speed;
//				if (target_x + center_x < 0.f) target_x = 0.f;
//			}
//		}
//
//		if (y != 0.f)
//		{
//			if (y > center_y)
//			{
//				target_y = -(center_y - y);
//				target_y /= G::Aim_Speed;
//				if (target_y + center_y > center_y * 2.f) target_y = 0.f;
//			}
//
//			if (y < center_y)
//			{
//				target_y = y - center_y;
//				target_y /= G::Aim_Speed;
//				if (target_y + center_y < 0.f) target_y = 0.f;
//			}
//		}
//
//		SetMouseAbsPosition(static_cast<DWORD>(target_x), static_cast<DWORD>(target_y));
//	}
//}
//
//double GetCrossDistance(double x1, double y1, double z1, double x2, double y2, double z2) {
//	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
//}
//
//typedef struct _FNlEntity {
//	uint64_t Actor;
//	int ID;
//	uint64_t mesh;
//}FNlEntity;
//
//std::vector<FNlEntity> entityList;
//
//void FilledRect(int x, int y, int w, int h, ImColor color)
//{
//	ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color)), 0, 0);
//}
//
//void draw_cornered_box(int x, int y, int w, int h, ImColor color, int thickness) {
//	float line_w = (w / 3);
//	float line_h = (h / 3);
//	ImGui::GetOverlayDrawList()->AddLine(ImVec2(x, y), ImVec2(x, y + line_h), color, thickness);
//	ImGui::GetOverlayDrawList()->AddLine(ImVec2(x, y), ImVec2(x + line_w, y), color, thickness);
//	ImGui::GetOverlayDrawList()->AddLine(ImVec2(x + w - line_w, y), ImVec2(x + w, y), color, thickness);
//	ImGui::GetOverlayDrawList()->AddLine(ImVec2(x + w, y), ImVec2(x + w, y + line_h), color, thickness);
//	ImGui::GetOverlayDrawList()->AddLine(ImVec2(x, y + h - line_h), ImVec2(x, y + h), color, thickness);
//	ImGui::GetOverlayDrawList()->AddLine(ImVec2(x, y + h), ImVec2(x + line_w, y + h), color, thickness);
//	ImGui::GetOverlayDrawList()->AddLine(ImVec2(x + w - line_w, y + h), ImVec2(x + w, y + h), color, thickness);
//	ImGui::GetOverlayDrawList()->AddLine(ImVec2(x + w, y + h - line_h), ImVec2(x + w, y + h), color, thickness);
//}
//
//
//void DrawLine(int x1, int y1, int x2, int y2, const ImU32& color, int thickness)
//{
//	ImGui::GetOverlayDrawList()->AddLine(ImVec2(x1, y1), ImVec2(x2, y2), ImGui::GetColorU32(color), thickness);
//}
//
//void DrawRect(int x, int y, int w, int h, RGBA* color, int thickness)
//{
//	ImGui::GetOverlayDrawList()->AddRect(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), 0, 0, thickness);
//}
//
//void DrawLine2(int x1, int y1, int x2, int y2, RGBA* color, int thickness)
//{
//	ImGui::GetOverlayDrawList()->AddLine(ImVec2(x1, y1), ImVec2(x2, y2), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 153.0, color->B / 51.0, color->A / 255.0)), thickness);
//}
//
//std::string WStringToUTF8(const wchar_t* lpwcszWString)
//{
//	char* pElementText;
//	int iTextLen = ::WideCharToMultiByte(CP_UTF8, 0, (LPWSTR)lpwcszWString, -1, NULL, 0, NULL, NULL);
//	pElementText = new char[iTextLen + 1];
//	memset((void*)pElementText, 0, (iTextLen + 1) * sizeof(char));
//	::WideCharToMultiByte(CP_UTF8, 0, (LPWSTR)lpwcszWString, -1, pElementText, iTextLen, NULL, NULL);
//	std::string strReturn(pElementText);
//	delete[] pElementText;
//	return strReturn;
//}
//
//std::wstring MBytesToWString(const char* lpcszString)
//{
//	int len = strlen(lpcszString);
//	int unicodeLen = ::MultiByteToWideChar(CP_ACP, 0, lpcszString, -1, NULL, 0);
//	wchar_t* pUnicode = new wchar_t[unicodeLen + 1];
//	memset(pUnicode, 0, (unicodeLen + 1) * sizeof(wchar_t));
//	::MultiByteToWideChar(CP_ACP, 0, lpcszString, -1, (LPWSTR)pUnicode, unicodeLen);
//	std::wstring wString = (wchar_t*)pUnicode;
//	delete[] pUnicode;
//	return wString;
//}
//
//void DrawString(float fontSize, int x, int y, RGBA* color, bool bCenter, bool stroke, const char* pText, ...)
//{
//	va_list va_alist;
//	char buf[1024] = { 0 };
//	va_start(va_alist, pText);
//	_vsnprintf_s(buf, sizeof(buf), pText, va_alist);
//	va_end(va_alist);
//	std::string text = WStringToUTF8(MBytesToWString(buf).c_str());
//	if (bCenter)
//	{
//		ImVec2 textSize = ImGui::CalcTextSize(text.c_str());
//		x = x - textSize.x / 2;
//		y = y - textSize.y;
//	}
//	if (stroke)
//	{
//		ImGui::GetOverlayDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x + 1, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
//		ImGui::GetOverlayDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x - 1, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
//		ImGui::GetOverlayDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x + 1, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
//		ImGui::GetOverlayDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x - 1, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
//	}
//	ImGui::GetOverlayDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), text.c_str());
//}
//
//int FVector
//(
//	float InX,
//	float InY,
//	float InZ
//);
//
//
//
//
//namespace APlayerCameraManager
//{
//	DWORD DefaultFOV = 0x284;
//};
//
//typedef struct _LootEntity {
//	std::string GNames;
//	uintptr_t ACurrentItem;
//}LootEntity;
//
//static std::vector<LootEntity> LootentityList;
//
//void CacheLevels()
//{
//	if (LocalPawn)
//	{
//		std::vector<LootEntity> tmpList;
//		uintptr_t ItemLevels = driver.read<uintptr_t>(Uworld + 0x160);
//
//		for (int i = 0; i < driver.read<DWORD>(Uworld + (0x160 + sizeof(PVOID))); ++i) {
//
//			uintptr_t ItemLevel = driver.read<uintptr_t>(ItemLevels + (i * sizeof(uintptr_t)));
//
//			for (int i = 0; i < driver.read<DWORD>(ItemLevel + (0x98 + sizeof(PVOID))); ++i) {
//				uintptr_t ItemsPawns = driver.read<uintptr_t>(ItemLevel + 0x98);
//				uintptr_t CurrentItemPawn = driver.read<uintptr_t>(ItemsPawns + (i * sizeof(uintptr_t)));
//				uintptr_t ItemRootComponent = driver.read<uintptr_t>(CurrentItemPawn + 0x188);
//				Vector3 ItemPosition = driver.read<Vector3>(ItemRootComponent + 0x128);
//				float ItemDist = localactorpos.Distance(ItemPosition) / 100.f;
//
//				if (ItemDist < G::VisDist) {
//
//					int ItemIndex = driver.read<int>(CurrentItemPawn + 0x18);//
//					auto CurrentItemPawnName = GetNameFromFName(ItemIndex);
//
//					if ((G::LootESP && strstr(CurrentItemPawnName.c_str(), (("FortPickupAthena")))) || strstr(CurrentItemPawnName.c_str(), (("Tiered_Chest"))) || strstr(CurrentItemPawnName.c_str(), (("AthenaPlayerMarker_WithCustomization"))) || strstr(CurrentItemPawnName.c_str(), (("NPC_Pawn_Irwin_Simple_Avian_Crow_C"))) || strstr(CurrentItemPawnName.c_str(), (("NPC_Pawn_Irwin_Prey_Nug_C"))) || strstr(CurrentItemPawnName.c_str(), (("NPC_Pawn_Irwin_Predator_Robert_C"))) || strstr(CurrentItemPawnName.c_str(), (("NPC_Pawn_Irwin_Prey_Burt_C"))) || strstr(CurrentItemPawnName.c_str(), (("NPC_Pawn_Irwin_Simple_Smackie_C"))) || strstr(CurrentItemPawnName.c_str(), (("NPC_Pawn_Irwin_Predator_Grandma_C"))) ||
//						(G::VehicleEsp && strstr(CurrentItemPawnName.c_str(), ("Vehicl")) || strstr(CurrentItemPawnName.c_str(), ("Valet_Taxi")) ||
//							strstr(CurrentItemPawnName.c_str(), ("Valet_BigRig")) || strstr(CurrentItemPawnName.c_str(), ("Valet_BasicTr")) ||
//							strstr(CurrentItemPawnName.c_str(), ("Valet_SportsC")) || strstr(CurrentItemPawnName.c_str(), ("Valet_BasicC")) ||
//							strstr(CurrentItemPawnName.c_str(), ("Tiered_Ammo")) || strstr(CurrentItemPawnName.c_str(), ("MeatballVehicle_L_C"))))
//					{
//						LootEntity LevelObjects{ };
//						LevelObjects.ACurrentItem = CurrentItemPawn;
//						LevelObjects.GNames = CurrentItemPawnName;
//						tmpList.push_back(LevelObjects);
//					}
//				}
//			}
//		}
//		LootentityList.clear();
//		LootentityList = tmpList;
//		Sleep(1);
//	}
//}
//
//
//
//
//void drawLoop(int width, int height) {
//
//
//	while (true) {
//		std::vector<FNlEntity> tmpList;
//
//		Uworld = driver.read<DWORD_PTR>(dravarthangs::base_addy + OFFSET_UWORLD);
//		DWORD_PTR Gameinstance = driver.read<DWORD_PTR>(Uworld + Offsets::GameInstance);
//		DWORD_PTR LocalPlayers = driver.read<DWORD_PTR>(Gameinstance + Offsets::LocalPlayers);
//		Localplayer = driver.read<DWORD_PTR>(LocalPlayers);
//		PlayerController = driver.read<DWORD_PTR>(Localplayer + Offsets::PlayerController);
//		LocalPawn = driver.read<DWORD_PTR>(PlayerController + Offsets::LocalPawn);
//		PlayerState = driver.read<DWORD_PTR>(LocalPawn + Offsets::PlayerState);
//		Rootcomp = driver.read<DWORD_PTR>(LocalPawn + Offsets::RootComponent);
//		Persistentlevel = driver.read<DWORD_PTR>(Uworld + Offsets::Persistentlevel);
//		DWORD ActorCount = driver.read<DWORD>(Persistentlevel + Offsets::AcotrCount);
//		DWORD_PTR AActors = driver.read<DWORD_PTR>(Persistentlevel + Offsets::AAcotrs);
//		uintptr_t PlayerCameraManager = driver.read<uintptr_t >(PlayerController + 0x328);
//		static auto Pdefaultxmin = driver.read<float>(PlayerCameraManager + 0x3174); //ViewPitchMin
//		static auto Pdefaultxmax = driver.read<float>(PlayerCameraManager + 0x3178); //ViewPitchMax
//		static auto Ydefaultxmin = driver.read<float>(PlayerCameraManager + 0x317C); //ViewYawMin
//		static auto Ydefaultxmax = driver.read<float>(PlayerCameraManager + 0x3180); //ViewYawMax
//		static auto DefaultAspectRatio = driver.read<float>(PlayerCameraManager + 0x294); //ViewYawMax
//		DWORD DefaultFOV = driver.read<float>(PlayerCameraManager + 0x284); //ViewYawMax
//		DWORD_PTR worldsettings = driver.read<uintptr_t>(Persistentlevel + 0x2a0); //PersistenLevel -> AWorldSettings
//		float Timedilation = driver.read<float>(LocalPawn + 0x64);
//		float WorldGravityZ = driver.read<float>(worldsettings + 0x2ec);
//		Vector3 location = driver.read<Vector3>(LocalPawn + 0x128);
//		//std::string str(location.begin(), location.end());
//		//driver.write<Vector3>(LocalPawn + 0x128, Vector3(4, 4, 4));
//
//
//		//driver.write(worldsettings + 0x2e8, 0);
//
//		//uintptr_t CurrentWeapon = driver.read<uintptr_t>(LocalPawn + Offsets::CurrentWeapon);
//		//bool isreloading = driver.read<bool>(CurrentWeapon + 0x311);
//		//DWORD_PTR worldsettings = driver.read<uintptr_t>(Persistentlevel + 0x2a0); //PersistenLevel -> AWorldSettings
//		//std::cout << isreloading;
//		//if (isreloading == true)
//		//{
//		//	driver.write(worldsettings + 0x390, 5.f);
//		//}
//		//else {
//		//	driver.write(worldsettings + 0x390, 1.f);
//		//}
//		//driver.write<float>(PlayerCameraManager + APlayerCameraManager::DefaultFOV + 0x4, FOV); //fov changer
//
//		//driver.write<float>(PlayerCameraManager + 0x284, 120); //ViewYawMax
//		//std::cout << DefaultAspectRatio;
//		//std::cout << "\nratio^^^\n";
//		//std::cout << DefaultFOV;
//		//std::cout << "\nfov^^^\n";
//		//system("pause");
//		//driver.write<float>(PlayerCameraManager + 0x294, 10); //DefaultAspectRatio
//		//driver.write<float>(PlayerCameraManager + 0x3178, 100); //ViewPitchMax
//		//driver.write<float>(PlayerCameraManager + 0x317C, 100); //ViewYawMin
//		//driver.write<float>(PlayerCameraManager + 0x3180, 100); //ViewYawMax
//		//std::cout << Pdefaultxmin;
//		//std::cout << "\nPitch_Min^^\n";
//		//std::cout << Pdefaultxmax;
//		//std::cout << "\nPitch_Max^^\n";
//		//std::cout << Ydefaultxmin;
//		//std::cout << "\nYaw_Min^^\n";
//		//std::cout << Ydefaultxmin;
//		//std::cout << "\nYaw_Max^^\n";
//		//system("pause");
//
//
//
//
//		for (int i = 0; i < ActorCount; i++) {
//			uint64_t CurrentActor = driver.read<uint64_t>(AActors + i * 0x8);
//
//			int curactorid = driver.read<int>(CurrentActor + 0x18);
//
//			if (!CurrentActor || CurrentActor == LocalPawn) continue;
//
//			auto ActorPawn = GetNameFromFName(curactorid);
//
//			if (strstr(ActorPawn.c_str(), _xor_("PlayerPawn").c_str()))
//			{
//				FNlEntity fnlEntity{ };
//				fnlEntity.Actor = CurrentActor;
//				fnlEntity.mesh = driver.read<uint64_t>(CurrentActor + Offsets::Mesh);
//				tmpList.push_back(fnlEntity);
//			}
//		}
//		entityList = tmpList;
//		std::this_thread::sleep_for(std::chrono::seconds((1)));
//	}
//
//
//}
//
//
//void AimAt(DWORD_PTR entity) {
//	uint64_t currentactormesh = driver.read<uint64_t>(entity + Offsets::Mesh);
//	auto rootHead = GetBoneWithRotation(currentactormesh, G::hitbox);
//
//	if (G::Aim_Prediction) {
//		float distance = localactorpos.Distance(rootHead) / 250;
//		uint64_t CurrentActorRootComponent = driver.read<uint64_t>(entity + Offsets::RootComponent);
//		Vector3 vellocity = driver.read<Vector3>(CurrentActorRootComponent + Offsets::Velocity);
//		Vector3 Predicted = AimbotCorrection(-504, 35, distance, rootHead, vellocity);
//		Vector3 rootHeadOut = ProjectWorldToScreen(Predicted);
//		if (rootHeadOut.x != 0 || rootHeadOut.y != 0 || rootHeadOut.z != 0) {
//			if ((GetCrossDistance(rootHeadOut.x, rootHeadOut.y, rootHeadOut.z, Width / 2, Height / 2, Depth / 2) <= G::AimFOV * 1)) {
//				//Beep(9000, 3);
//				aimbot(rootHeadOut.x, rootHeadOut.y);
//
//			}
//		}
//	}
//	else {
//		Vector3 rootHeadOut = ProjectWorldToScreen(rootHead);
//		if (rootHeadOut.x != 0 || rootHeadOut.y != 0 || rootHeadOut.z != 0) {
//			if ((GetCrossDistance(rootHeadOut.x, rootHeadOut.y, rootHeadOut.z, Width / 2, Height / 2, Depth / 2) <= G::AimFOV * 1)) {
//				//Beep(9000, 3);
//				aimbot(rootHeadOut.x, rootHeadOut.y);
//			}
//		}
//	}
//}
//
//void AimAt2(DWORD_PTR entity) {
//	uint64_t currentactormesh = driver.read<uint64_t>(entity + Offsets::Mesh);
//	auto rootHead = GetBoneWithRotation(currentactormesh, G::hitbox);
//
//	if (G::Aim_Prediction) {
//		float distance = localactorpos.Distance(rootHead) / 250;
//		uint64_t CurrentActorRootComponent = driver.read<uint64_t>(entity + Offsets::RootComponent);
//		Vector3 vellocity = driver.read<Vector3>(CurrentActorRootComponent + Offsets::Velocity);
//		Vector3 Predicted = AimbotCorrection(-504, 35, distance, rootHead, vellocity);
//		Vector3 rootHeadOut = ProjectWorldToScreen(Predicted);
//		if (rootHeadOut.x != 0 || rootHeadOut.y != 0 || rootHeadOut.z != 0) {
//			if ((GetCrossDistance(rootHeadOut.x, rootHeadOut.y, rootHeadOut.z, Width / 2, Height / 2, Depth / 2) <= G::AimFOV * 1)) {
//
//			}
//		}
//	}
//	else {
//		Vector3 rootHeadOut = ProjectWorldToScreen(rootHead);
//		if (rootHeadOut.x != 0 || rootHeadOut.y != 0 || rootHeadOut.z != 0) {
//			if ((GetCrossDistance(rootHeadOut.x, rootHeadOut.y, rootHeadOut.z, Width / 2, Height / 2, Depth / 2) <= G::AimFOV * 1)) {
//			}
//		}
//	}
//}
//
//std::string string_To_UTF8(const std::string& str)
//{
//	int nwLen = ::MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);
//
//	wchar_t* pwBuf = new wchar_t[nwLen + 1];
//	ZeroMemory(pwBuf, nwLen * 2 + 2);
//
//	::MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.length(), pwBuf, nwLen);
//
//	int nLen = ::WideCharToMultiByte(CP_UTF8, 0, pwBuf, -1, NULL, NULL, NULL, NULL);
//
//	char* pBuf = new char[nLen + 1];
//	ZeroMemory(pBuf, nLen + 1);
//
//	::WideCharToMultiByte(CP_UTF8, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);
//
//	std::string retStr(pBuf);
//
//	delete[]pwBuf;
//	delete[]pBuf;
//
//	pwBuf = NULL;
//	pBuf = NULL;
//
//	return retStr;
//}
//
//
//void DrawSkeleton(DWORD_PTR mesh)
//{
//	Vector3 vHeadBone = GetBoneWithRotation(mesh, 98);
//	Vector3 vHip = GetBoneWithRotation(mesh, 2);
//	Vector3 vNeck = GetBoneWithRotation(mesh, 67);
//	Vector3 vUpperArmLeft = GetBoneWithRotation(mesh, 9);
//	Vector3 vUpperArmRight = GetBoneWithRotation(mesh, 38);
//	Vector3 vLeftHand = GetBoneWithRotation(mesh, 10);
//	Vector3 vRightHand = GetBoneWithRotation(mesh, 39);
//	Vector3 vLeftHand1 = GetBoneWithRotation(mesh, 11);
//	Vector3 vRightHand1 = GetBoneWithRotation(mesh, 40);
//	Vector3 vRightThigh = GetBoneWithRotation(mesh, 76);
//	Vector3 vLeftThigh = GetBoneWithRotation(mesh, 69);
//	Vector3 vRightCalf = GetBoneWithRotation(mesh, 77);
//	Vector3 vLeftCalf = GetBoneWithRotation(mesh, 70);
//	Vector3 vLeftFoot = GetBoneWithRotation(mesh, 73);
//	Vector3 vRightFoot = GetBoneWithRotation(mesh, 80);
//	Vector3 vHeadBoneOut = ProjectWorldToScreen(vHeadBone);
//	Vector3 vHipOut = ProjectWorldToScreen(vHip);
//	Vector3 vNeckOut = ProjectWorldToScreen(vNeck);
//	Vector3 vUpperArmLeftOut = ProjectWorldToScreen(vUpperArmLeft);
//	Vector3 vUpperArmRightOut = ProjectWorldToScreen(vUpperArmRight);
//	Vector3 vLeftHandOut = ProjectWorldToScreen(vLeftHand);
//	Vector3 vRightHandOut = ProjectWorldToScreen(vRightHand);
//	Vector3 vLeftHandOut1 = ProjectWorldToScreen(vLeftHand1);
//	Vector3 vRightHandOut1 = ProjectWorldToScreen(vRightHand1);
//	Vector3 vRightThighOut = ProjectWorldToScreen(vRightThigh);
//	Vector3 vLeftThighOut = ProjectWorldToScreen(vLeftThigh);
//	Vector3 vRightCalfOut = ProjectWorldToScreen(vRightCalf);
//	Vector3 vLeftCalfOut = ProjectWorldToScreen(vLeftCalf);
//	Vector3 vLeftFootOut = ProjectWorldToScreen(vLeftFoot);
//	Vector3 vRightFootOut = ProjectWorldToScreen(vRightFoot);
//	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vHipOut.x, vHipOut.y), ImVec2(vNeckOut.x, vNeckOut.y), ImGui::GetColorU32({ G::Skeletonchik[0], G::Skeletonchik[1], G::Skeletonchik[2], 1.0f }));
//	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vUpperArmLeftOut.x, vUpperArmLeftOut.y), ImVec2(vNeckOut.x, vNeckOut.y), ImGui::GetColorU32({ G::Skeletonchik[0], G::Skeletonchik[1], G::Skeletonchik[2], 1.0f }));
//	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vUpperArmRightOut.x, vUpperArmRightOut.y), ImVec2(vNeckOut.x, vNeckOut.y), ImGui::GetColorU32({ G::Skeletonchik[0], G::Skeletonchik[1], G::Skeletonchik[2], 1.0f }));
//	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vLeftHandOut.x, vLeftHandOut.y), ImVec2(vUpperArmLeftOut.x, vUpperArmLeftOut.y), ImGui::GetColorU32({ G::Skeletonchik[0], G::Skeletonchik[1], G::Skeletonchik[2], 1.0f }));
//	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vRightHandOut.x, vRightHandOut.y), ImVec2(vUpperArmRightOut.x, vUpperArmRightOut.y), ImGui::GetColorU32({ G::Skeletonchik[0], G::Skeletonchik[1], G::Skeletonchik[2], 1.0f }));
//	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vLeftHandOut.x, vLeftHandOut.y), ImVec2(vLeftHandOut1.x, vLeftHandOut1.y), ImGui::GetColorU32({ G::Skeletonchik[0], G::Skeletonchik[1], G::Skeletonchik[2], 1.0f }));
//	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vRightHandOut.x, vRightHandOut.y), ImVec2(vRightHandOut1.x, vRightHandOut1.y), ImGui::GetColorU32({ G::Skeletonchik[0], G::Skeletonchik[1], G::Skeletonchik[2], 1.0f }));
//	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vLeftThighOut.x, vLeftThighOut.y), ImVec2(vHipOut.x, vHipOut.y), ImGui::GetColorU32({ G::Skeletonchik[0], G::Skeletonchik[1], G::Skeletonchik[2], 1.0f }));
//	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vRightThighOut.x, vRightThighOut.y), ImVec2(vHipOut.x, vHipOut.y), ImGui::GetColorU32({ G::Skeletonchik[0], G::Skeletonchik[1], G::Skeletonchik[2], 1.0f }));
//	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vLeftCalfOut.x, vLeftCalfOut.y), ImVec2(vLeftThighOut.x, vLeftThighOut.y), ImGui::GetColorU32({ G::Skeletonchik[0], G::Skeletonchik[1], G::Skeletonchik[2], 1.0f }));
//	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vRightCalfOut.x, vRightCalfOut.y), ImVec2(vRightThighOut.x, vRightThighOut.y), ImGui::GetColorU32({ G::Skeletonchik[0], G::Skeletonchik[1], G::Skeletonchik[2], 1.0f }));
//	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vLeftFootOut.x, vLeftFootOut.y), ImVec2(vLeftCalfOut.x, vLeftCalfOut.y), ImGui::GetColorU32({ G::Skeletonchik[0], G::Skeletonchik[1], G::Skeletonchik[2], 1.0f }));
//	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vRightFootOut.x, vRightFootOut.y), ImVec2(vRightCalfOut.x, vRightCalfOut.y), ImGui::GetColorU32({ G::Skeletonchik[0], G::Skeletonchik[1], G::Skeletonchik[2], 1.0f }));
//}
//
//bool isVisible(DWORD_PTR mesh)
//{
//	if (!mesh)
//		return false;
//	float tik = driver.read<float>(mesh + 0x330);
//	float tok = driver.read<float>(mesh + 0x334);
//	const float tick = 0.06f;
//	return tok + tick >= tik;
//}
//static ImColor Color;
//
////auto SetGlobalTimeDilationForLevels(float NewTimeDilation, bool bReset)
////{
////	auto WorldContext = this->GetReference();
////	if (!WorldContext) return;
////
////	static auto OldTimeDilation = 0.0f;
////
////	for (auto LevelIndex = 0; LevelIndex < read<int>(WorldContext + (0x160 + sizeof(uintptr_t))); ++LevelIndex)
////	{
////		auto Levels = read<uintptr_t*>(WorldContext + 0x160);
////		if (!Levels) break;
////
////		auto CurrentLevel = Levels[LevelIndex];
////		if (!CurrentLevel) continue;
////
////		auto WorldSettings = read<uintptr_t>(CurrentLevel + 0x298);
////		if (!WorldSettings) continue;
////
////		// Save old TimeDilation.
////		if (!OldTimeDilation) OldTimeDilation = read<float>(WorldSettings + 0x390);
////
////		// Reset the TimeDilation to the original cached value.
////		if (bReset) write<float>(WorldSettings + 0x390, OldTimeDilation), OldTimeDilation = 0.0f;
////
////		// Set the TimeDilation to the new value.
////		if (NewTimeDilation) write<float>(WorldSettings + 0x390, NewTimeDilation);
////	}
////}
//
//
////int delay(long seconds)
////{
////	time_t t1;
////	t1 = time(0) + seconds;
////	while (time(0) < t1);
////}
//
//void DrawESP() {
//
//	if (G::Draw_FOV_Circle) {
//		ImGui::GetOverlayDrawList()->AddCircle(ImVec2(ScreenCenterX, ScreenCenterY), float(G::AimFOV), ImColor(255, 0, 0, 255), 50, 1);
//	}
//
//	auto entityListCopy = entityList;
//	float closestDistance = FLT_MAX;
//	DWORD_PTR closestPawn = NULL;
//
//	DWORD_PTR AActors = driver.read<DWORD_PTR>(Ulevel + Offsets::AAcotrs);
//
//	int ActorTeamId = driver.read<int>(Offsets::TeamIndex);
//
//	for (unsigned long i = 0; i < entityListCopy.size(); ++i) {
//		FNlEntity entity = entityListCopy[i];
//
//		auto isDBNO = (driver.read<char>(entity.Actor + 0x74a) >> 4) & 1;
//
//		uint64_t CurrentActor = driver.read<uint64_t>(AActors + i * Offsets::CurrentActor);
//
//		uint64_t CurActorRootComponent = driver.read<uint64_t>(entity.Actor + Offsets::RootComponent);
//		if (CurActorRootComponent == (uint64_t)nullptr || CurActorRootComponent == -1 || CurActorRootComponent == NULL)
//			continue;
//
//		Vector3 RelativeLocation = driver.read<Vector3>(CurActorRootComponent + Offsets::RelativeLocation);
//		Vector3 RelativeLocationW2s = ProjectWorldToScreen(RelativeLocation);
//
//		DWORD64 otherPlayerState = driver.read<uint64_t>(entity.Actor + Offsets::PlayerState);
//		if (otherPlayerState == (uint64_t)nullptr || otherPlayerState == -1 || otherPlayerState == NULL)
//			continue;
//
//		localactorpos = driver.read<Vector3>(Rootcomp + Offsets::RelativeLocation);
//		uintptr_t PlayerCameraManager = driver.read<uintptr_t >(PlayerController + 0x328);
//		DWORD_PTR worldsettings = driver.read<uintptr_t>(Persistentlevel + 0x2a0); //PersistenLevel -> AWorldSettings
//		float DemoPlayTimeDilation = driver.read<uintptr_t>(worldsettings + 0x398);
//		static auto OldTimeDilation = driver.read<float>(worldsettings + 0x390); // AWorldSettings -> TimeDilation
//		//std::cout << OldTimeDilation;
//		//driver.write(worldsettings + 0x390, 1.f);
//		//std::cout << OldTimeDilation;
//
//
//
//		//static auto Pdefaultxmin = driver.read<float>(PlayerCameraManager + 0x3174); //ViewPitchMin
//		//static auto Pdefaultxmax = driver.read<float>(PlayerCameraManager + 0x3178); //ViewPitchMax
//		//static auto Ydefaultxmin = driver.read<float>(PlayerCameraManager + 0x317C); //ViewYawMin
//		//static auto Ydefaultxmax = driver.read<float>(PlayerCameraManager + 0x3180); //ViewYawMax
//		//std::cout << Pdefaultxmin;
//		//std::cout << "\nPitch_Min^^\n";
//		//std::cout << Pdefaultxmax;
//		//std::cout << "\nPitch_Max^^\n";
//		//std::cout << Ydefaultxmin;
//		//std::cout << "\nYaw_Min^^\n";
//		//std::cout << Ydefaultxmin;
//		//std::cout << "\nYaw_Max^^\n";
//
//
//		Vector3 bone66 = GetBoneWithRotation(entity.mesh, 66);
//		Vector3 aimbone = GetBoneWithRotation(entity.mesh, 66);
//		Vector3 bone0 = GetBoneWithRotation(entity.mesh, 0);
//
//		Vector3 bonepelvis = GetBoneWithRotation(entity.mesh, 2);
//
//		Vector3 top = ProjectWorldToScreen(bone66);
//		Vector3 chest = ProjectWorldToScreen(bone66);
//		Vector3 aimbotspot = ProjectWorldToScreen(aimbone);
//		Vector3 bottom = ProjectWorldToScreen(bone0);
//
//		Vector3 vHeadBone = GetBoneWithRotation(entity.mesh, 98);
//		Vector3 vRootBone = GetBoneWithRotation(entity.mesh, 0);
//
//		Vector3 vHeadBoneOut = ProjectWorldToScreen(Vector3(vHeadBone.x, vHeadBone.y, vHeadBone.z + 15));
//		Vector3 vRootBoneOut = ProjectWorldToScreen(vRootBone);
//
//		Vector3 Head = ProjectWorldToScreen(Vector3(bone66.x, bone66.y, bone66.z + 15));
//
//		float distance = localactorpos.Distance(bone66) / 100.f;
//		float BoxHeight = (float)(Head.y - bottom.y);
//		float BoxWidth = BoxHeight * 0.46;
//		float CornerHeight = abs(Head.y - bottom.y);
//		float CornerWidth = BoxHeight * 0.46;
//
//		int MyTeamId = driver.read<int>(PlayerState + Offsets::TeamIndex);
//		int ActorTeamId = driver.read<int>(otherPlayerState + Offsets::TeamIndex);
//		int curactorid = driver.read<int>(CurrentActor + 0x18);
//		uintptr_t CurrentWeapon = driver.read<uintptr_t>(LocalPawn + Offsets::CurrentWeapon);
//		bool isreloading = driver.read<bool>(CurrentWeapon + 0x311);
//
//		if (isVisible(entity.mesh)) {
//			Color = ImColor(0, 255, 0);
//		}
//		else {
//			Color = ImColor(255, 0, 0);
//		}
//
//		if (G::FakeLag == true)
//		{
//			driver.write<float>(LocalPawn + 0x64, 0);
//			driver.write<float>(LocalPawn + 0x64, 1);
//
//		}
//		else {
//			driver.write<float>(LocalPawn + 0x64, 1);
//		}
//
//
//		if (G::VehicleSpeedHax == true)
//		{
//			if (GetAsyncKeyState(VK_XBUTTON2))
//			{
//				driver.write(worldsettings + 0x390, 5.f);
//
//			}
//			else {
//				driver.write(worldsettings + 0x390, 1.f);
//			}
//		}
//
//
//		if (G::Insta_Reload == true)
//		{
//			if (isreloading == true)
//			{
//				driver.write(worldsettings + 0x390, 5.f);
//
//			}
//			else {
//				driver.write(worldsettings + 0x390, 1.f);
//			}
//		}
//
//		if (G::Rapid_Fire == true)
//		{
//			if (CurrentWeapon) {
//				if (CurrentWeapon + 0x30) {
//					driver.write<float>(CurrentWeapon + 0x64, 800);
//				}
//			}
//		}
//
//
//
//		//if (G::Rapid_Fire == true)
//		//{
//		//	if (CurrentWeapon) {
//		//		if (CurrentWeapon + 0x30) {
//		//			if (GetAsyncKeyState(VK_LBUTTON)) {
//		//				mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
//		//				mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
//		//				mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
//		//			}
//		//		}
//		//	}
//		//}
//
//
//
//		if (MyTeamId != ActorTeamId) {
//			if (distance < G::VisDist) {
//
//				if (G::Esp_line) {
//					{
//						ImGui::GetOverlayDrawList()->AddLine(ImVec2(Width / 2, Height), ImVec2(Head.x, Head.y), Color, 0.01f);
//					}
//				}
//#include <stdio.h>
//
//				if (G::Esp_box)
//				{
//					ImGui::GetOverlayDrawList()->AddRect(ImVec2(Head.x - (BoxWidth / 2), Head.y), ImVec2(bottom.x + (BoxWidth / 2), bottom.y), ImColor(0, 0, 0, 255), 0, 0, 3);
//					ImGui::GetOverlayDrawList()->AddRect(ImVec2(Head.x - (BoxWidth / 2), Head.y), ImVec2(bottom.x + (BoxWidth / 2), bottom.y), Color);
//				}
//
//				if (G::Esp_Corner_Box) {
//					draw_cornered_box(Head.x - (CornerWidth / 2), Head.y, CornerWidth, CornerHeight, ImColor(0, 0, 0, 255), 3);
//					draw_cornered_box(Head.x - (CornerWidth / 2), Head.y, CornerWidth, CornerHeight, Color, 0);
//				}
//
//				if (G::Esp_skeleton) {
//					DrawSkeleton(entity.mesh);
//				}
//
//				if (G::Aimbot & isVisible(entity.mesh)) {
//					auto dx = aimbotspot.x - (Width / 2);
//					auto dy = aimbotspot.y - (Height / 2);
//					auto dz = aimbotspot.z - (Depth / 2);
//					auto dist = sqrtf(dx * dx + dy * dy + dz * dz) / 100.0f;
//					if (dist < G::AimFOV && dist < closestDistance) {
//						closestDistance = dist;
//						closestPawn = entity.Actor;
//						//driver.write<float>(PlayerCameraManager + 0x3174, -89.9); //ViewPitchMin
//						//driver.write<float>(PlayerCameraManager + 0x3178, 89.9); //ViewPitchMax
//						//driver.write<float>(PlayerCameraManager + 0x317C, 0); //ViewYawMin
//						//driver.write<float>(PlayerCameraManager + 0x3180, 0); //ViewYawMax
//					}
//				}
//
//
//				if (G::backtrack) {
//					if (entity.Actor != 0) {
//						if (GetAsyncKeyState(VK_RBUTTON)) {
//							driver.write<float>(closestPawn + 0x64, 0.1);
//
//						}
//						else
//						{
//							driver.write<float>(closestPawn + 0x64, 1);
//
//
//						}
//					}
//				}
//
//
//			}
//		}
//	}
//
//	if (G::Aimbot) {
//
//		if (closestPawn != 0) {
//			if (G::Aimbot && closestPawn && GetAsyncKeyState(VK_RBUTTON) < 0) {
//
//				AimAt(closestPawn);
//
//
//			}
//		}
//		else {
//			isaimbotting = false;
//
//			AimAt2(closestPawn);
//		}
//
//	}
//}
//
//
//
//void GetKey() {
//
//	DrawESP();
//
//}
//
//namespace ImGui
//{
//
//	IMGUI_API bool Tab(unsigned int index, const char* label, int* selected, float width = 90, float height = 24)
//	{
//		ImGuiStyle& style = ImGui::GetStyle();
//		ImColor color = ImColor(27, 26, 35, 255)/*style.Colors[ImGuiCol_Button]*/;
//		ImColor colorActive = ImColor(79, 79, 81, 255); /*style.Colors[ImGuiCol_ButtonActive]*/;
//		ImColor colorHover = ImColor(62, 62, 66, 255)/*style.Colors[ImGuiCol_ButtonHovered]*/;
//
//
//		if (index > 0)
//			ImGui::SameLine();
//
//		if (index == *selected)
//		{
//			style.Colors[ImGuiCol_Button] = colorActive;
//			style.Colors[ImGuiCol_ButtonActive] = colorActive;
//			style.Colors[ImGuiCol_ButtonHovered] = colorActive;
//		}
//		else
//		{
//			style.Colors[ImGuiCol_Button] = color;
//			style.Colors[ImGuiCol_ButtonActive] = colorActive;
//			style.Colors[ImGuiCol_ButtonHovered] = colorHover;
//		}
//
//		if (ImGui::Button(label, ImVec2(width, height)))
//			*selected = index;
//
//		style.Colors[ImGuiCol_Button] = color;
//		style.Colors[ImGuiCol_ButtonActive] = colorActive;
//		style.Colors[ImGuiCol_ButtonHovered] = colorHover;
//
//		return *selected == index;
//	}
//}
//
//int width;
//int height;
//
//int current = 1;
//void render() {
//
//	ImGui_ImplDX9_NewFrame();
//	ImGui_ImplWin32_NewFrame();
//	ImGui::NewFrame();
//
//	if (G::Show_Menu) {
//
//		ImGuiStyle* style = &ImGui::GetStyle();
//
//		ImVec4* colors = style->Colors;
//
//
//
//		ImVec4 panelColor = ImColor(0.106f, 0.149f, 0.165f, 1.000f);
//		ImVec4 panelHoverColor = ImColor(0.106f, 0.149f, 0.165f, 1.000f);
//		ImVec4 panelActiveColor = ImColor(0.506f, 0.549f, 0.565f, 1.000f);
//
//
//
//
//		colors[ImGuiCol_WindowBg] = ImColor(14, 14, 14, 0);
//		colors[ImGuiCol_ChildBg] = ImColor(14, 14, 14, 255);
//		colors[ImGuiCol_Border] = ImColor(38, 38, 38, 0);
//		colors[ImGuiCol_BorderShadow] = ImColor(38, 38, 38, 0);
//		colors[ImGuiCol_FrameBg] = ImColor(0.106f, 0.149f, 0.165f, 1.000f);
//		colors[ImGuiCol_FrameBgHovered] = ImColor(0.106f, 0.149f, 0.165f, 1.000f);
//		colors[ImGuiCol_FrameBgActive] = ImColor(0.606f, 0.649f, 0.665f, 1.000f);
//		colors[ImGuiCol_TitleBg] = panelActiveColor;
//		colors[ImGuiCol_TitleBgActive] = panelActiveColor;
//		colors[ImGuiCol_TitleBgCollapsed] = panelActiveColor;
//		colors[ImGuiCol_MenuBarBg] = panelColor;
//		colors[ImGuiCol_ScrollbarBg] = panelColor;
//		colors[ImGuiCol_CheckMark] = panelActiveColor;
//		colors[ImGuiCol_SliderGrab] = panelHoverColor;
//		colors[ImGuiCol_SliderGrabActive] = panelActiveColor;
//		colors[ImGuiCol_Button] = ImColor(0.106f, 0.149f, 0.165f, 1.000f);
//		colors[ImGuiCol_ButtonHovered] = ImColor(0.106f, 0.149f, 0.165f, 1.000f);
//		colors[ImGuiCol_ButtonActive] = ImColor(0.106f, 0.149f, 0.165f, 1.000f);
//		colors[ImGuiCol_Separator] = panelActiveColor;
//		colors[ImGuiCol_SeparatorHovered] = panelActiveColor;
//		colors[ImGuiCol_SeparatorActive] = panelActiveColor;
//		colors[ImGuiCol_ButtonHovered] = panelActiveColor;
//		colors[ImGuiCol_ButtonActive] = panelHoverColor;
//		colors[ImGuiCol_ResizeGrip] = panelColor;
//		colors[ImGuiCol_ResizeGripHovered] = panelHoverColor;
//		colors[ImGuiCol_ResizeGripActive] = panelActiveColor;
//		colors[ImGuiCol_PlotLines] = panelActiveColor;
//		colors[ImGuiCol_PlotLinesHovered] = panelHoverColor;
//		colors[ImGuiCol_PlotHistogram] = panelActiveColor;
//		colors[ImGuiCol_PlotHistogramHovered] = panelHoverColor;
//		colors[ImGuiCol_Text] = ImColor(255, 255, 255, 255);
//
//
//		style->WindowPadding = ImVec2(15, 15);
//		style->WindowRounding = 8.0f;
//		style->FrameRounding = 0.0f;
//		style->FramePadding = ImVec2(5, 5);
//		style->ItemSpacing = ImVec2(12, 8);
//		style->ItemInnerSpacing = ImVec2(8, 6);
//		style->IndentSpacing = 25.0f;
//		style->ScrollbarSize = 0.0f;
//		style->ScrollbarRounding = 1.0f;
//		style->GrabMinSize = 5.0f;
//		style->GrabRounding = 3.0f;
//		style->Alpha = 1.f;
//
//
//		int current = 1;
//		{
//			ImGui::GetOverlayDrawList()->AddRectFilled(ImGui::GetIO().MousePos, ImVec2(ImGui::GetIO().MousePos.x + 7.f, ImGui::GetIO().MousePos.y + 7.f), ImColor(255, 255, 255, 255));
//			static int maintabs = 0;
//			static int misctabs = 0;
//			static int exploittabs = 0;
//			static int MenuTab = 0;
//
//			ImGui::SetNextWindowSize(ImVec2(700.000f, 400.000f), ImGuiCond_Once);
//
//
//			ImGui::Begin(("###PROG"), nullptr,
//				ImGuiWindowFlags_NoResize |
//				ImGuiWindowFlags_NoCollapse |
//				ImGuiWindowFlags_NoTitleBar);
//
//
//			{
//
//				ImVec2 P1, P2;
//				ImDrawList* pDrawList;
//				const auto& CurrentWindowPos = ImGui::GetWindowPos();
//				const auto& pWindowDrawList = ImGui::GetWindowDrawList();
//
//				P1 = ImVec2(0.000f, 0.000f);
//				P1.x += CurrentWindowPos.x;
//				P1.y += CurrentWindowPos.y;
//				P2 = ImVec2(120.000f, 700.000f);
//				P2.x += CurrentWindowPos.x;
//				P2.y += CurrentWindowPos.y;
//				pDrawList = pWindowDrawList;
//				pDrawList->AddRectFilled(P1, P2, ImColor(0.106f, 0.149f, 0.165f, 1.000f), 0.000f);
//
//				P1 = ImVec2(120.000f, 0.000f);
//				P1.x += CurrentWindowPos.x;
//				P1.y += CurrentWindowPos.y;
//				P2 = ImVec2(700.000f, 700.000f);
//				P2.x += CurrentWindowPos.x;
//				P2.y += CurrentWindowPos.y;
//				pDrawList = pWindowDrawList;
//				pDrawList->AddRectFilled(P1, P2, ImColor(0.122f, 0.165f, 0.180f, 1.000f), 0.000f);
//
//
//
//				ImGui::SetCursorPos({ 0.f,0.f });
//				if (ImGui::Button("Aimbot", { 120.f,45.f }))
//				{
//					maintabs = 0;
//				}
//
//				ImGui::SetCursorPos({ 0.f,45.f });
//				if (ImGui::Button("Visuals", { 120.f,45.f }))
//				{
//					maintabs = 1;
//				}
//
//				ImGui::SetCursorPos({ 0.f,90.f });
//				if (ImGui::Button("Exploits", { 120.f,45.f }))
//				{
//					maintabs = 2;
//				}
//
//				ImGui::SameLine();
//
//				if (maintabs == 0)
//				{
//					ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(5, 5));
//
//					ImGui::SetCursorPos({ 130.f,40.f });
//					ImGui::Checkbox("Enable Aimbot", &G::Aimbot);
//					if (G::Aimbot)
//					{
//						G::ControllerAimbot = false;
//					}
//
//					ImGui::SetCursorPos({ 130.f,70.f });
//					ImGui::Text("Aim Key");
//					//ImGui::SetCursorPos({ 70.f,96.f });
//					//if (ImGui::Button("RMBUTTON", { 80.f,25.f }))
//					//{
//					//	G::aimkey = VK_RBUTTON;
//					//}
//					//ImGui::SetCursorPos({ 160.f,96.f });
//					//if (ImGui::Button("LMBUTTON", { 80.f,25.f }))
//					//{
//					//	G::aimkey = VK_LBUTTON;
//					//}
//					//ImGui::SetCursorPos({ 250.f,96.f });
//					//if (ImGui::Button("SHIFT", { 80.f,25.f }))
//					//{
//					//	G::aimkey = VK_SHIFT;
//					//}
//
//					//ImGui::SetCursorPos({ 11.f,132.f });
//					//ImGui::Text("Current Aim Key:   ");
//					//if (G::aimkey == VK_RBUTTON)
//					//{
//					//	ImGui::SetCursorPos({ 125.f,132.f });
//					//	colors[ImGuiCol_Text] = ImColor(255, 0, 11, 255);
//					//	ImGui::Text("RIGHT MOUSE BUTTON");
//					//}
//					//if (G::aimkey == VK_LBUTTON)
//					//{
//					//	ImGui::SetCursorPos({ 125.f,132.f });
//					//	colors[ImGuiCol_Text] = ImColor(255, 0, 11, 255);
//					//	ImGui::Text("LEFT MOUSE BUTTON");
//					//}
//					//if (G::aimkey == VK_SHIFT)
//					//{
//					//	ImGui::SetCursorPos({ 125.f,132.f });
//					//	colors[ImGuiCol_Text] = ImColor(255, 0, 11, 255);
//					//	ImGui::Text("SHIFT");
//					//}
//					colors[ImGuiCol_Text] = ImColor(255, 255, 255, 255);
//					ImGui::SetCursorPos({ 130.f,100.f });
//					ImGui::PushItemWidth(91.000000);
//					ImGui::Text("Aimbot bones:");
//					ImGui::PopItemWidth();
//
//					ImGui::SetCursorPos({ 130.f,130.f });
//					ImGui::Checkbox("Head", &G::Head);
//					if (G::Head)
//					{
//						G::hitbox = 98;
//						G::Chest = false;
//						G::Pelvis = false;
//						G::Toes = false;
//					}
//
//					ImGui::SetCursorPos({ 130.f,160.f });
//					ImGui::Checkbox("Chest", &G::Chest);
//					if (G::Chest)
//					{
//						G::hitbox = 37;
//						G::Head = false;
//						G::Pelvis = false;
//						G::Toes = false;
//					}
//
//					ImGui::SetCursorPos({ 130.f,190.f });
//					ImGui::Checkbox("Pelvis", &G::Pelvis);
//					if (G::Pelvis)
//					{
//						G::hitbox = 37;
//						G::Head = false;
//						G::Chest = false;
//						G::Toes = false;
//					}
//
//					ImGui::SetCursorPos({ 130.f,220.f });
//					ImGui::Checkbox("Bottom", &G::Toes);
//					if (G::Toes)
//					{
//						G::hitbox = 37;
//						G::Head = false;
//						G::Pelvis = false;
//						G::Chest = false;
//					}
//
//					ImGui::SetCursorPos({ 130.f,250.f });
//					ImGui::PushItemWidth(180.f);
//					ImGui::SliderFloat("FOV", &G::AimFOV, 30, 300);
//					ImGui::SetCursorPos({ 130.f,330.f });
//					ImGui::PushItemWidth(180.f);
//					ImGui::SliderFloat("Smooth", &G::Aim_Speed, 1, 15);
//
//					ImGui::PopStyleVar();
//				}
//
//				if (maintabs == 1)
//				{
//					ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(5, 5));
//
//					ImGui::SetCursorPos({ 130.f,40.f });
//					ImGui::Checkbox("2D Box", &G::Esp_box);
//
//					if (G::Esp_box)
//					{
//						G::Esp_Corner_Box = false;
//					}
//
//					ImGui::SetCursorPos({ 130.f,70 });
//					ImGui::Checkbox("Corner Box", &G::Esp_Corner_Box);
//
//					if (G::Esp_Corner_Box)
//					{
//						G::Esp_box = false;
//					}
//
//					ImGui::SetCursorPos({ 130.f,100 });
//					ImGui::Checkbox("Box Filled", &G::Esp_box_fill);
//					ImGui::SetCursorPos({ 130.f,130 });
//					ImGui::Checkbox("Skeleton", &G::Esp_skeleton);
//					ImGui::SetCursorPos({ 130.f,160 });
//					ImGui::Checkbox("Snaplines", &G::Esp_line);
//
//					ImGui::SetCursorPos({ 130.f,190 });
//					ImGui::Checkbox("Distance", &G::PlayerESP);
//					//ImGui::SetCursorPos({ 130.f, 210 });
//
//					//ImGui::Checkbox("Bot Shit", &G::BotESP);
//
//					ImGui::PopStyleVar();
//				}
//
//				if (maintabs == 2)
//				{
//					ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(5, 5));
//
//
//					ImGui::SetCursorPos({ 130.f,40.f });
//					ImGui::Checkbox("Vehicle SpeedHacks", &G::VehicleSpeedHax);
//
//
//
//					ImGui::SetCursorPos({ 130.f,70 });
//					ImGui::Checkbox("Insta Reload", &G::Insta_Reload);
//
//					ImGui::SetCursorPos({ 130.f,100 });
//					ImGui::Checkbox("Backtrack", &G::backtrack);
//					ImGui::SetCursorPos({ 130.f,130 });
//					ImGui::Checkbox("Rapid Fire", &G::Rapid_Fire);
//					ImGui::SetCursorPos({ 130.f,160 });
//					ImGui::Checkbox("Fake Lag", &G::FakeLag);
//
//					//ImGui::SetCursorPos({ 130.f,190 });
//					//ImGui::Checkbox("Soon", &G::PlayerESP);
//					//ImGui::SetCursorPos({ 130.f, 210 });
//
//					//ImGui::Checkbox("Bot Shit", &G::BotESP);
//
//					ImGui::PopStyleVar();
//				}
//			}
//			ImGui::End();
//		}
//		ImGui::Render();
//	}
//
//	GetKey();
//	ImGui::EndFrame();
//	D3dDevice->SetRenderState(D3DRS_ZENABLE, false);
//	D3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
//	D3dDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, false);
//	D3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(0, 0, 0, 0), 1.0f, 0);
//
//	if (D3dDevice->BeginScene() >= 0) {
//		ImGui::Render();
//		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
//		D3dDevice->EndScene();
//	}
//	HRESULT result = D3dDevice->Present(NULL, NULL, NULL, NULL);
//
//	if (result == D3DERR_DEVICELOST && D3dDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET) {
//		ImGui_ImplDX9_InvalidateDeviceObjects();
//		D3dDevice->Reset(&d3dpp);
//		ImGui_ImplDX9_CreateDeviceObjects();
//	}
//}
//
//void xInitD3d()
//{
//	if (FAILED(Direct3DCreate9Ex(D3D_SDK_VERSION, &p_Object)))
//		exit(3);
//
//	ZeroMemory(&d3dpp, sizeof(d3dpp));
//	d3dpp.BackBufferWidth = Width;
//	d3dpp.BackBufferHeight = Height;
//	d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;
//	d3dpp.MultiSampleQuality = D3DMULTISAMPLE_NONE;
//	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
//	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
//	d3dpp.EnableAutoDepthStencil = TRUE;
//	d3dpp.hDeviceWindow = Window;
//	d3dpp.Windowed = TRUE;
//
//	p_Object->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, Window, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &D3dDevice);
//
//	IMGUI_CHECKVERSION();
//
//	ImGui::CreateContext();
//	ImGuiIO& io = ImGui::GetIO();
//	(void)io;
//
//	io.IniFilename = nullptr;
//
//	ImGui_ImplWin32_Init(Window);
//	ImGui_ImplDX9_Init(D3dDevice);
//
//	io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\Arial.ttf", 14.0f);
//
//	p_Object->Release();
//}
//
//static std::string RandomProcess()
//{
//	std::vector<std::string> Process
//	{
//		_xor_("Taskmgr.exe").c_str(),
//	};
//	std::random_device RandGenProc;
//	std::mt19937 engine(RandGenProc());
//	std::uniform_int_distribution<int> choose(0, Process.size() - 1);
//	std::string RandProc = Process[choose(engine)];
//	return RandProc;
//}
//
//const UINT GetProcessThreadNumByID(DWORD dwPID)
//{
//	HANDLE hProcessSnap = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
//	if (hProcessSnap == INVALID_HANDLE_VALUE)
//		return 0;
//
//	PROCESSENTRY32 pe32 = { 0 };
//	pe32.dwSize = sizeof(pe32);
//	BOOL bRet = ::Process32First(hProcessSnap, &pe32);;
//	while (bRet)
//	{
//		if (pe32.th32ProcessID == dwPID)
//		{
//			::CloseHandle(hProcessSnap);
//			return pe32.cntThreads;
//		}
//		bRet = ::Process32Next(hProcessSnap, &pe32);
//	}
//	return 0;
//}
//
//const UINT GetProcessId(const char* process_name) {
//	UINT pid = 0;
//
//	DWORD dwThreadCountMax = 0;
//
//	// Create toolhelp snapshot.
//	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
//	PROCESSENTRY32 process;
//	ZeroMemory(&process, sizeof(process));
//	process.dwSize = sizeof(process);
//	// Walkthrough all processes.
//	if (Process32First(snapshot, &process))
//	{
//		do
//		{
//			if (strstr(process.szExeFile, process_name))
//			{
//				DWORD dwTmpThreadCount = GetProcessThreadNumByID(process.th32ProcessID);
//				if (dwTmpThreadCount > dwThreadCountMax)
//				{
//					dwThreadCountMax = dwTmpThreadCount;
//					pid = process.th32ProcessID;
//					break;
//				}
//			}
//		} while (Process32Next(snapshot, &process));
//	}
//	CloseHandle(snapshot);
//	return pid;
//}
//
//int main() {
//
//	HWND hWnd;
//	//SystemParametersInfo(
//	//	SPI_SETMOUSESPEED,
//	//	0,
//	//	(LPVOID)10,
//	//	SPIF_UPDATEINIFILE | SPIF_SENDCHANGE | SPIF_SENDWININICHANGE
//	//);
//	if (!driver.init())
//	{
//		printf("init failed / driver not loaded\n");
//		Sleep(1500);
//		return 1;
//	}
//
//	driver.attach(GetCurrentProcessId());
//
//	if (driver.get_process_module(_xor_("kernel32.dll").c_str()) == (uintptr_t)GetModuleHandleA(_xor_("kernel32.dll").c_str()))
//	{
//
//	}
//	else
//		printf(_xor_(" comm failed").c_str());
//
//
//	while (hwnd == NULL)
//	{
//		RandomProcess();
//		hwnd = FindWindowA(0, _xor_("Fortnite  ").c_str());
//	}
//	dravarthangs::pid = GetProcessId(_xor_("FortniteClient-Win64-Shipping.exe").c_str());
//	driver.attach(uint32_t(dravarthangs::pid));
//	dravarthangs::base_addy = driver.get_process_base(uint32_t(dravarthangs::pid));
//	GetWindowThreadProcessId(hwnd, &dravarthangs::pid);
//	RECT rect;
//	if (GetWindowRect(hwnd, &rect))
//	{
//		width = rect.right - rect.left;
//		height = rect.bottom - rect.top;
//	}
//	SetWindowLong(Window, GWL_EXSTYLE, WS_EX_LAYERED | WS_EX_TRANSPARENT | WS_EX_TOOLWINDOW);
//
//	printf("pid -> %i\n", dravarthangs::pid);
//	printf("base -> 0x%p\n", (void*)dravarthangs::base_addy);
//
//	CreateThread(NULL, NULL, Menuthread, NULL, NULL, NULL);
//	GetWindowThreadProcessId(hwnd, &dravarthangs::pid);
//
//	xCreateWindow();
//	xInitD3d();
//
//	HANDLE handle = CreateThread(nullptr, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(drawLoop), nullptr, NULL, nullptr);
//	CloseHandle(handle);
//
//	xMainLoop();
//}
//
//void SetWindowToTarget()
//{
//	while (true)
//	{
//		if (hwnd)
//		{
//			ZeroMemory(&GameRect, sizeof(GameRect));
//			GetWindowRect(hwnd, &GameRect);
//			Width = GameRect.right - GameRect.left;
//			Height = GameRect.bottom - GameRect.top;
//			DWORD dwStyle = GetWindowLong(hwnd, GWL_STYLE);
//
//			if (dwStyle & WS_BORDER)
//			{
//				GameRect.top += 50;
//				Height -= 50;
//			}
//			ScreenCenterX = Width / 2;
//			ScreenCenterY = Height / 2;
//			MoveWindow(Window, GameRect.left, GameRect.top, Width, Height, true);
//		}
//		else
//		{
//			exit(0);
//		}
//	}
//}
//
//const MARGINS Margin = { -6 };
//
//void xCreateWindow()
//{
//
//	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)SetWindowToTarget, 0, 0, 0);
//
//	WNDCLASSEX wc;
//	ZeroMemory(&wc, sizeof(wc));
//	wc.cbSize = sizeof(wc);
//	wc.lpszClassName = "mspaint";
//	wc.lpfnWndProc = WinProc;
//	RegisterClassEx(&wc);
//
//	if (hwnd)
//	{
//		GetClientRect(hwnd, &GameRect);
//		POINT xy;
//		ClientToScreen(hwnd, &xy);
//		GameRect.left = xy.x;
//		GameRect.top = xy.y;
//
//		Width = GameRect.right;
//		Height = GameRect.bottom;
//	}
//	else
//		exit(2);
//
//	Window = CreateWindowEx(NULL, "mspaint", "mspaint", WS_POPUP | WS_VISIBLE, 0, 0, Width, Height, 0, 0, 0, 0);
//
//	DwmExtendFrameIntoClientArea(Window, &Margin);
//	SetWindowLong(Window, GWL_EXSTYLE, WS_EX_TRANSPARENT | WS_EX_TOOLWINDOW | WS_EX_LAYERED);
//	ShowWindow(Window, SW_SHOW);
//	UpdateWindow(Window);
//}
//
//MSG Message = { NULL };
//
//void xMainLoop()
//{
//	static RECT old_rc;
//	ZeroMemory(&Message, sizeof(MSG));
//
//	while (Message.message != WM_QUIT)
//	{
//		if (PeekMessage(&Message, Window, 0, 0, PM_REMOVE))
//		{
//			TranslateMessage(&Message);
//			DispatchMessage(&Message);
//		}
//
//		HWND hwnd_active = GetForegroundWindow();
//
//		if (hwnd_active == hwnd) {
//			HWND hwndtest = GetWindow(hwnd_active, GW_HWNDPREV);
//			SetWindowPos(Window, hwndtest, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
//		}
//
//		if (GetAsyncKeyState(0x23) & 1)
//			exit(8);
//
//		RECT rc;
//		POINT xy;
//
//		ZeroMemory(&rc, sizeof(RECT));
//		ZeroMemory(&xy, sizeof(POINT));
//		GetClientRect(hwnd, &rc);
//		ClientToScreen(hwnd, &xy);
//		rc.left = xy.x;
//		rc.top = xy.y;
//
//		ImGuiIO& io = ImGui::GetIO();
//		io.ImeWindowHandle = hwnd;
//		io.DeltaTime = 1.0f / 60.0f;
//
//		POINT p;
//		GetCursorPos(&p);
//		io.MousePos.x = p.x - xy.x;
//		io.MousePos.y = p.y - xy.y;
//
//		if (GetAsyncKeyState(VK_LBUTTON)) {
//			io.MouseDown[0] = true;
//			io.MouseClicked[0] = true;
//			io.MouseClickedPos[0].x = io.MousePos.x;
//			io.MouseClickedPos[0].x = io.MousePos.y;
//		}
//		else
//			io.MouseDown[0] = false;
//
//		if (rc.left != old_rc.left || rc.right != old_rc.right || rc.top != old_rc.top || rc.bottom != old_rc.bottom)
//		{
//			old_rc = rc;
//
//			Width = rc.right;
//			Height = rc.bottom;
//
//			d3dpp.BackBufferWidth = Width;
//			d3dpp.BackBufferHeight = Height;
//			SetWindowPos(Window, (HWND)0, xy.x, xy.y, Width, Height, SWP_NOREDRAW);
//			D3dDevice->Reset(&d3dpp);
//		}
//		render();
//	}
//	ImGui_ImplDX9_Shutdown();
//	ImGui_ImplWin32_Shutdown();
//	ImGui::DestroyContext();
//
//	DestroyWindow(Window);
//}
//
//LRESULT CALLBACK WinProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)
//{
//	if (ImGui_ImplWin32_WndProcHandler(hWnd, Message, wParam, lParam))
//		return true;
//
//	switch (Message)
//	{
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		exit(4);
//		break;
//	case WM_SIZE:
//		if (D3dDevice != NULL && wParam != SIZE_MINIMIZED)
//		{
//			ImGui_ImplDX9_InvalidateDeviceObjects();
//			d3dpp.BackBufferWidth = LOWORD(lParam);
//			d3dpp.BackBufferHeight = HIWORD(lParam);
//			HRESULT hr = D3dDevice->Reset(&d3dpp);
//			if (hr == D3DERR_INVALIDCALL)
//				IM_ASSERT(0);
//			ImGui_ImplDX9_CreateDeviceObjects();
//		}
//		break;
//	default:
//		return DefWindowProc(hWnd, Message, wParam, lParam);
//		break;
//	}
//	return 0;
//}