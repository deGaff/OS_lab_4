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

    HANDLE  mutex = OpenMutex(MUTEX_ALL_ACCESS, FALSE, "file"),
            output = GetStdHandle(STD_OUTPUT_HANDLE),
            mapping = OpenFileMapping(FILE_MAP_READ | FILE_MAP_WRITE, FALSE, mapping_name);

    HANDLE eSemaphore[21],
            fSemaphore[21];

    for(size_t i = 0; i < 21; ++i) {
        eSemaphore[i] = OpenSemaphore(SYNCHRONIZE | SEMAPHORE_MODIFY_STATE, false, ("e" + std::to_string(i)).c_str());
        fSemaphore[i] = OpenSemaphore(SYNCHRONIZE | SEMAPHORE_MODIFY_STATE, false, ("f" + std::to_string(i)).c_str());
    }

    if (mapping) {
        for(unsigned i = 0; i < 3; ++i) {
            size_t page = WaitForMultipleObjects(21, fSemaphore, false, INFINITE);
            LOG("|TAKE|SEMAPHORE\n");

            WaitForSingleObject(mutex, INFINITE);
            LOG("|TAKE|MUTEX\n");

            LOG("|START|WRITE\n");
            Sleep(std::rand() % 1000 + 500);
            LOG("|END|WRITE\n");

            if(ReleaseMutex(mutex)) LOG("|RELEASE|MUTEX\n");
            else LOG("|ERROR|RELEASE MUTEX CODE:" + std::to_string(GetLastError())) + "\n";

            if(ReleaseSemaphore(eSemaphore[page], 1, nullptr)) {
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
