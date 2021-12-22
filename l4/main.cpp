#include <iostream>
#include <string>
#include <windows.h>
//TODO fix time if necessary
int main()
{
    SYSTEM_INFO info;
    GetSystemInfo(&info);

    const DWORD dwPageSize = info.dwPageSize;
    const unsigned uPageCount = 21,
                    size = (uPageCount-1)*dwPageSize;
    const char mapping_name[] = "mapping";

    HANDLE eSemaphore = CreateSemaphore(nullptr, uPageCount-1, uPageCount-1, "f"),
           fSemaphore = CreateSemaphore(nullptr, 0, uPageCount-1, "e"),
           mutex = CreateMutex(nullptr, false, "file"),
           file = CreateFile("E:\\l4",  GENERIC_READ | GENERIC_WRITE,
                             FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr),
           map = CreateFileMapping(file, nullptr, PAGE_READWRITE, 0, 0, mapping_name),
           processes[uPageCount];

    auto mapping = MapViewOfFile(map, FILE_MAP_ALL_ACCESS, 0, 0, size);
    VirtualLock(mapping, size);

    std::string savePreset = "E:\\l4LOGS\\w_",
                appName = "E:\\Stud\\5 sem\\os\\l4_1_W\\cmake-build-debug\\l4_1_W.exe";
    int offset = 1;
    for(int i = 0; i < uPageCount + (uPageCount%2?1:0); ++i) {
        if(i == (uPageCount / 2) + (uPageCount%2?1:0)) {
            savePreset = "E:\\l4LOGS\\r_";
            appName = "E:\\Stud\\5 sem\\os\\l4_1_R\\cmake-build-debug\\l4_1_R.exe";
            offset = -i+1;
        }
        STARTUPINFO sys;
        PROCESS_INFORMATION proc;
        SECURITY_ATTRIBUTES secureAttr = { sizeof(SECURITY_ATTRIBUTES), nullptr, TRUE };
        ZeroMemory(&sys, sizeof(sys));
        auto saveto = (savePreset + std::to_string((i + offset))) + ".txt";
        HANDLE outHandle = CreateFile(saveto.data(), GENERIC_WRITE, FILE_SHARE_WRITE, &secureAttr,
                                      OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
        sys.cb = sizeof(sys);
        sys.hStdOutput = outHandle;
        sys.hStdError = nullptr;
        sys.hStdInput = nullptr;
        sys.dwFlags |= STARTF_USESTDHANDLES;

        ZeroMemory(&proc, sizeof(proc));

        if (int process = CreateProcess(appName.data(), nullptr, nullptr, nullptr, TRUE,
                                        0, nullptr, nullptr, &sys, &proc);
            process)
            processes[i] = proc.hProcess;
    }
    WaitForMultipleObjects(uPageCount, processes, true, INFINITE);

    for (auto & p : processes)
        CloseHandle(p);

    CloseHandle(map);
    UnmapViewOfFile(mapping);
    CloseHandle(file);
    CloseHandle(mutex);
    CloseHandle(eSemaphore);
    CloseHandle(fSemaphore);
    return 0;
}