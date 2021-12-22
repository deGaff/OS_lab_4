#include <iostream>
#include <windows.h>
#include "menu.h"

void pipe_connect();
void send_mes();
void pipe_disconnect();

OVERLAPPED over = OVERLAPPED(),
        sync = OVERLAPPED();
HANDLE callback = CreateEvent(nullptr, FALSE, FALSE, "callback"),
        pipe = CreateNamedPipe(R"(\\.\pipe\lab)", PIPE_ACCESS_OUTBOUND,
                               PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
                               1, 512, 512, 0, nullptr);
bool connected = false;

int main() {

    if(callback == INVALID_HANDLE_VALUE) {
        std::cout << "Event was not created\n";
        if(pipe!=INVALID_HANDLE_VALUE) CloseHandle(pipe);
        return 1;
    }
    if(pipe == INVALID_HANDLE_VALUE) {
        std::cout << "Pipe was not created\n";
        CloseHandle(callback);
        return 1;
    }

    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    view_menu main_menu("MAIN MENU", menu({
                                                  std::make_shared<action_menu>("Connect to pipe", pipe_connect),
                                                  std::make_shared<action_menu>("Send message", send_mes),
                                                  std::make_shared<action_menu>("Disconnect from the pipe", pipe_disconnect)
                                          }));
    main_menu.execute();

    if(callback != INVALID_HANDLE_VALUE) CloseHandle(callback);
    if(pipe != INVALID_HANDLE_VALUE) CloseHandle(pipe);

    return 0;
}

void pipe_connect() {
    sync.hEvent = callback;
    connected = ConnectNamedPipe(pipe, &sync);
    WaitForSingleObject(callback, 20000);
    if(connected) std::cout << "CONNECTED TO PIPE SUCCESSFULLY\n";
    else std::cout << "CONNECTION TO PIPE FAILED\n";
}

void send_mes() {
    std::string data;
    if(!connected) {
        std::cout << "NEED TO CONNECT FIRST\n";
        return;
    }

    std::cout << "Enter data\n";
    std::getline(std::cin, data);

    over.hEvent = callback;
    connected = WriteFile(pipe, data.data(), 512, nullptr, &over);

    if(WaitForSingleObject(callback, INFINITE) == WAIT_OBJECT_0 && connected)
        std::cout << "MESSAGE SENT SUCCESSFULLY\n";
    else
        std::cout << "MESSAGE WAS NOT SENT\n";
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