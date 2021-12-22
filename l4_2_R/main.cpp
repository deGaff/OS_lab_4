#include <iostream>
#include <windows.h>
#include "menu.h"

void pipe_connect();
void receive_mes();
void pipe_disconnect();

OVERLAPPED over = OVERLAPPED();
HANDLE callback,
        pipe;
bool connected = false;

void WINAPI Callback(DWORD dwErrorCode, DWORD dwNumberOfBytesTransfered, LPOVERLAPPED lpOverlapped) {
    std::cout << "Message received\n";
}

int main() {

    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    view_menu main_menu("MAIN MENU", menu({
                                                  std::make_shared<action_menu>("Connect to pipe", pipe_connect),
                                                  std::make_shared<action_menu>("Receive message", receive_mes),
                                                  std::make_shared<action_menu>("Disconnect from the pipe", pipe_disconnect)
                                          }));
    main_menu.execute();

    if(callback != INVALID_HANDLE_VALUE) CloseHandle(callback);
    if(pipe != INVALID_HANDLE_VALUE) CloseHandle(pipe);

    return 0;
}

void pipe_connect() {

    callback = OpenEvent(EVENT_MODIFY_STATE, true, "callback");
    pipe = CreateFile(R"(\\.\pipe\lab)", GENERIC_READ, 0, nullptr, OPEN_EXISTING, FILE_FLAG_OVERLAPPED, nullptr);

    if(callback == INVALID_HANDLE_VALUE) {
        std::cout << "Event was not created\n";
        if(pipe!=INVALID_HANDLE_VALUE) CloseHandle(pipe);
        return;
    }
    if(pipe == INVALID_HANDLE_VALUE) {
        std::cout << "Pipe was not created\n";
        CloseHandle(callback);
        return;
    }
    connected = true;
    std::cout << "CONNECTED TO PIPE SUCCESSFULLY\n";
}

void receive_mes() {
    char data[512];
    if(!connected) {
        std::cout << "NEED TO CONNECT FIRST\n";
        return;
    }

    over.hEvent = callback;
    connected = ReadFileEx(pipe, data, 512, &over, Callback);
    if(connected) {
        SleepEx(INFINITE, true);
        std::cout << data;
    }
    else std::cout << "MESSAGE READING FAILED\n";
}

void pipe_disconnect() {
    if(!connected) {
        std::cout << "NOT CONNECTED\n";
        return;
    }
    if(CloseHandle(pipe)) {
        std::cout << "DISCONNECTED PIPE SUCCESSFULLY\n";
        connected = false;
        return;
    }
    std::cout << "DISCONNECTING FAILED\n";
}