#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <windows.h>

#define LOG(mes) out_buffer += std::to_string(GetTickCount()) + mes

int main() {

    std::srand(std::time(nullptr));
    const char mapping_name[] = "mapping";
    std::string out_buffer;
    out_buffer.reserve(500);

    HANDLE f = OpenSemaphore(SYNCHRONIZE | SEMAPHORE_MODIFY_STATE, FALSE, "f"),
            e = OpenSemaphore(SYNCHRONIZE | SEMAPHORE_MODIFY_STATE, FALSE, "e"),
            mutex = OpenMutex(MUTEX_ALL_ACCESS, FALSE, "file"),
            output = GetStdHandle(STD_OUTPUT_HANDLE),
            mapping = OpenFileMapping(FILE_MAP_READ | FILE_MAP_WRITE, FALSE, mapping_name);

    if (mapping) {
        for(unsigned i = 0; i < 3; ++i) {
            WaitForSingleObject(f, INFINITE);
            LOG("|TAKE|SEMAPHORE\n");

            WaitForSingleObject(mutex, INFINITE);
            LOG("|TAKE|MUTEX\n");

            LOG("|START|WRITE\n");
            Sleep(std::rand() % 1000 + 500);
            LOG("|END|WRITE\n");

            if(ReleaseMutex(mutex)) LOG("|RELEASE|MUTEX\n");
            else LOG("|ERROR|RELEASE MUTEX CODE:" + std::to_string(GetLastError())) + "\n";

            if(ReleaseSemaphore(e, 1, nullptr)) {
                LOG("|RELEASE|SEMAPHORE\n");
                LOG("|PAGE|NUMBER="+std::to_string(i)+"\n");
            }
            else LOG("|ERROR|RELEASE SEMAPHORE CODE:" + std::to_string(GetLastError())) + "\n";
        }
    }
    else LOG("ERROR|MAPPING CREATION" + std::to_string(GetLastError())) + "\n";
    WriteFile(output, out_buffer.data(), out_buffer.size(), nullptr, nullptr);
    CloseHandle(output);
    return 0;
}
