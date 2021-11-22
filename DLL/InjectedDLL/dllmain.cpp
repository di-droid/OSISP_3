#include "../DLL/lib.h"

#define SEARCH_STR "Hello, MOTHERFUCKERS"
#define REPLACEMENT_STR "Hello, bro"

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fwdReson, LPVOID lpReserved)
{
	DWORD pid = GetCurrentProcessId();

	switch (fwdReson)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
		ReplaceData(pid, SEARCH_STR, sizeof(SEARCH_STR), REPLACEMENT_STR, sizeof(REPLACEMENT_STR));
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}