// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"

// @see: https://docs.microsoft.com/en-us/windows/win32/dlls/dllmain
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
    /*
    The DLL is being loaded into the virtual address space of
    the current process as a result of the process starting up
    or as a result of a call to LoadLibrary. DLLs can use
    this opportunity to initialize any instance data or to use
    the TlsAlloc function to allocate a thread local storage (TLS) index.
    The lpReserved parameter indicates whether the DLL is being
    loaded statically or dynamically.
    */
	case DLL_PROCESS_ATTACH:
    /*
    The current process is creating a new thread. When this occurs,
    the system calls the entry-point function of all DLLs currently
    attached to the process. The call is made in the context of
    the new thread. DLLs can use this opportunity to initialize
    a TLS slot for the thread. A thread calling the DLL entry-point
    function with DLL_PROCESS_ATTACH does not call the DLL entry-point
    function with DLL_THREAD_ATTACH.
    Note that a DLL's entry-point function is called with this value
    only by threads created after the DLL is loaded by the process.
    When a DLL is loaded using LoadLibrary, existing threads do not
    call the entry-point function of the newly loaded DLL.
    */
	case DLL_THREAD_ATTACH:
    /*
    A thread is exiting cleanly.
    If the DLL has stored a pointer to allocated memory in a TLS slot,
    it should use this opportunity to free the memory.
    The system calls the entry-point function of all currently
    loaded DLLs with this value. The call is made in the context of
    the exiting thread.
    */
	case DLL_THREAD_DETACH:
    /*
    The DLL is being unloaded from the virtual address space of
    the calling process because it was loaded unsuccessfully or
    the reference count has reached zero (the processes has
    either terminated or called FreeLibrary one time for each time
    it called LoadLibrary).
    The lpReserved parameter indicates whether the DLL is being
    unloaded as a result of a FreeLibrary call, a failure to load,
    or process termination.
    The DLL can use this opportunity to call the TlsFree function
    to free any TLS indices allocated by using TlsAlloc and
    to free any thread local data.
    Note that the thread that receives the DLL_PROCESS_DETACH
    notification is not necessarily the same thread that received
    the DLL_PROCESS_ATTACH notification.
    */
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

