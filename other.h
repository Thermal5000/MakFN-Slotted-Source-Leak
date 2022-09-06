#include <Windows.h>
#include "utils.h"

DWORD_PTR Uworld;
DWORD_PTR LocalPawn;
DWORD_PTR PlayerState;
DWORD_PTR Localplayer;
DWORD_PTR HealthState;
DWORD_PTR Rootcomp;
DWORD_PTR PlayerController;
DWORD_PTR Persistentlevel;
DWORD_PTR Ulevel;


RGBA ESPSkeleton;

ImFont* infoF;

Vector3 localactorpos;

uint64_t TargetPawn;
int localplayerID;

RECT GameRect = { NULL };
D3DPRESENT_PARAMETERS d3dpp;

DWORD ScreenCenterX;
DWORD ScreenCenterY;
DWORD ScreenCenterZ;

int FovTypeInt = 1;

bool isaimbotting = false;

int AimboneInt = 0;

bool common{ true };
bool uncommon{ true };
bool rare{ true };
bool epic{ true };
bool legendary{ true };
bool mythic{ true };

int enemyID = 0;
int CloseRangeenemyID = 0;

namespace dravarthangs {
	DWORD pid;
	DWORD64 base_addy;
}

auto pStartupInfo = new STARTUPINFOA();
auto remoteProcessInfo = new PROCESS_INFORMATION();


static const char* FovTypeItems[]{
	"   Square",
	"   Circle",
};

static const char* AimboneItems[]{
	"   Head",
	"   Chest",
	"   Neck",
	"   Bottom",
};

static const char* AimKey_TypeItems[]{
	"   RMB",
	"   LMB",
	"   SHIFT",
	"   CAPS"
};

char* wchar_to_char(const wchar_t* pwchar)
{
	int currentCharIndex = 0;
	char currentChar = pwchar[currentCharIndex];

	while (currentChar != '\0')
	{
		currentCharIndex++;
		currentChar = pwchar[currentCharIndex];
	}

	const int charCount = currentCharIndex + 1;

	char* filePathC = (char*)malloc(sizeof(char) * charCount);

	for (int i = 0; i < charCount; i++)
	{
		char character = pwchar[i];

		*filePathC = character;

		filePathC += sizeof(char);

	}
	filePathC += '\0';

	filePathC -= (sizeof(char) * charCount);

	return filePathC;
}


class EAC_VirtualFunctions
{
public:
	virtual void RegisterInitCallbacks(void* clbk0, void* clbk1, void* p_g_hEAC) = 0;
	virtual void Unload(void) = 0;
	virtual void Initialize(void) = 0;
	virtual bool DoSomeChecks(void* ptr1, void* ptr2) = 0;
	virtual void UnkVirtFunc_0x20(void* unk1, int unk2) = 0; //not sure with return type
	virtual void RegisterUnkCallback(void* clbk, int unk_Flags, void* unk_pObject) = 0;
	virtual void UnkVirtFunc_0x30() = 0;
	virtual void UnkVirtFunc_0x38() = 0;
	virtual void UnkVirtFunc_0x40() = 0;
	virtual void UnkVirtFunc_0x48() = 0;
	virtual void UnkVirtFunc_0x50(int unk1, int unk2) = 0;
};

class EAC_Interface : public EAC_VirtualFunctions
{
public:
	void RegisterInitCallbacks(void* clbk0, void* clbk1, void* p_g_hEAC)
	{
		return; //clbk0 = xor eax,eax; ret; & clbk1 = ret; so really does not matter if we call them or not
	}
	void Unload(void)
	{
		return;
	}
	void Initialize(void)
	{
		return;
	}
	bool DoSomeChecks(void* ptr1, void* ptr2)
	{
		return false; //if returned false then called only once, otherwise called in a loop until returned false
	}
	void UnkVirtFunc_0x20(void* unk1, int unk2)
	{
		return;
	}
	void RegisterUnkCallback(void* clbk, int unk_Flags, void* unk_pObject)
	{
		return; //clbk directly calls some virt func, lets better not call it
	}
	void UnkVirtFunc_0x30()
	{
		return;
	}
	void UnkVirtFunc_0x38()
	{
		return;
	}
	void UnkVirtFunc_0x40()
	{
		return;
	}
	void UnkVirtFunc_0x48()
	{
		return;
	}
	void UnkVirtFunc_0x50(int unk1, int unk2)
	{
		return;
	}
};

void* CreateGameClient(char* szInterfaceNameWithVersion)
{
	return (new EAC_Interface);
}

typedef HMODULE(*fnLoadLibraryExW)(LPCWSTR, HANDLE, DWORD);
fnLoadLibraryExW oLoadLibraryExW;

typedef LPVOID(*fnGetProcAddress)(HMODULE, LPCSTR);
fnGetProcAddress oGetProcAddress;

HMODULE g_hModule;

HMODULE hkLoadLibraryExW(LPCWSTR lpLibFileName, HANDLE hFile, DWORD dwFlags)
{
	if (wcsstr(lpLibFileName, L"easyanticheat_x64.dll"))
		return g_hModule;

	return oLoadLibraryExW(lpLibFileName, hFile, dwFlags);
}

LPVOID hkGetProcAddress(HMODULE hModule, LPCSTR lpProcName)
{
	if (strstr(lpProcName, "CreateGameClient"))
		return CreateGameClient;

	return oGetProcAddress(hModule, lpProcName);
}
