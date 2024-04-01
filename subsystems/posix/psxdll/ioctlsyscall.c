/*
    psxdll syscall dispatcher to lxcore.sys
*/

#define NDK_MODE_USER 1

static HANDLE g_hCoreFile = INVALID_HANDLE_FILE;

static void CloseManagerFile(void)
{
    if (g_hCoreFile != INVALID_HANDLE_FILE)
    {
        CloseHandle(g_hCoreFile);
        g_hCoreFile = INVALID_HANDLE_FILE;
    }
}

static BOOL OpenManagerFile(void)
{
    g_hCoreFile = CreateFileW(IOCTL_SYSCALL_LINK, GENERIC_WRITE | GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    if (g_hCoreFile == INVALID_HANDLE_FILE)
    {
        DPRINT1("psxdll: open ioctl failed %x\n", GetLastError());
        return FALSE;
    }

    return TRUE;
}

static BOOL Perform()
{
    DWORD br;
    if (!DeviceIOControl(g_hCoreFile, IOCTL_PERFORM_SYSCALL, in, insize, out, outsize, &br, NULL))
    {
        DPRINT1("pdxdll: ioctl syscall failed %x\n", GetLastError());
        return FALSE;
    }

    return TRUE;
}

BOOL WINAPI DllMain(_In_ HINSTANCE lpDll, _In_ DWORD fdwReason, _In_ LPVOID lpReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            return OpenManagerFile();
        case DLL_PROCESS_DETACH:
            CloseManagerFile();
            break;
        default:
            break;
    }

    return TRUE;
}
