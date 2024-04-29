#include "DNS_OP.h"
#include <regex>
#include <utility>
#include <thread>
#include <chrono>

//Operation of changing DNS
void DNS_OPERATION::change_DNS(LPCSTR primary, LPCSTR secondary)
{
    TextColor color;
    LPCSTR application = "netsh";

    HINSTANCE hInstance = ShellExecuteA(NULL, "runas", application, primary, NULL, SW_SHOWNORMAL);
    HINSTANCE hInstance2 = ShellExecuteA(NULL, "runas", application, secondary, NULL, SW_SHOWNORMAL);
    //USE createProcess();


    //Error handler of shell executer
    if (reinterpret_cast<uintptr_t>(hInstance) > 32) {
        color.success();
        std::cout << "Primary DNS has changed successfully." << std::endl;
        color.reset();
    }
    else {
        color.error();
        DWORD errorCode = GetLastError();
        std::cerr << "Failed to change Primary DNS. Error code: " << errorCode << std::endl;
        color.reset();
    }
    if (reinterpret_cast<uintptr_t>(hInstance2) > 32) {
        color.success();
        std::cout << "Secondary DNS has changed successfully." << std::endl;
        color.reset();
    }
    else {
        color.error();
        DWORD errorCode = GetLastError();
        std::cerr << "Failed to change Secondary DNS. Error code: " << errorCode << std::endl;
        color.reset();
    }
}

//Disabling the DNS
void DNS_OPERATION::disable_DNS(LPCSTR disableDNS)
{
    TextColor color;


    LPCSTR application = "netsh";


    HINSTANCE hInstance = ShellExecuteA(NULL, "runas", application, disableDNS, NULL, SW_SHOWNORMAL);

    if (reinterpret_cast<uintptr_t>(hInstance) > 32) {
        color.success();
        std::cout << "DNS disabled successfully." << std::endl;
        color.reset();
    }
    else {
        color.error();
        DWORD errorCode = GetLastError();
        std::cerr << "Failed to disable DNS. Error code: " << errorCode << std::endl;
        color.reset();
    }
}

//Choosing Network Adapter
int DNS_OPERATION::chooseNetworkAdapter()
{

    int selection;

    std::cout << "Choose your Network Connection:(1-2) \n";
    std::cout << "1.Ethernet\n";
    std::cout << "2.Wifi\n";
    std::cin >> selection;
    system("cls");
    return selection;
}

//CMD Command Executer
std::string DNS_OPERATION::exec(std::string command)
{

    char buffer[128];
    std::string result = "";

    FILE* pipe = _popen(command.c_str(), "r");
    if (!pipe) {
        return "popen failed!";
    }

    while (!feof(pipe)) {

        if (fgets(buffer, 128, pipe) != NULL)
            result += buffer;
    }

    _pclose(pipe);
    return result;
}

//finding your current DNS
std::pair<std::string, std::string> DNS_OPERATION::findDNS(int num)
{
    std::string input;
    if (num == 1) {
        input = exec("netsh interface ip show dns \"Ethernet\"");
    }
    else if (num == 2)
    {
        input = exec("netsh interface ip show dns \"Wi-Fi\"");
    }
    // Regular expression pattern to match IPv4 addresses

    std::regex pattern(R"(\b(?:\d{1,3}\.){3}\d{1,3}\b)");
    // Iterator for searching DNS matches
    std::sregex_iterator iter(input.begin(), input.end(), pattern);
    std::sregex_iterator end;

    std::string dns1, dns2;
    int count = 0;
    // Iterate through matches and print them
    while (iter != end) {
        std::smatch match = *iter;
        if (count == 0) {
            dns1 = match.str();
        }
        else if (count == 1) {
            dns2 += match.str();
        }

        ++iter;
        count++;
    }

    return std::make_pair(dns1, dns2);
}


//Test Ping
void DNS_OPERATION::testPing(int num)
{
    TextColor color;
    color.success();
    if (num == 1) {
        std::cout << exec("ping " + findDNS(1).first);
        std::cout << "\n------------\n";
        std::cout << exec("ping " + findDNS(1).second);
    }
    else {
        std::cout << exec("ping " + findDNS(2).first);
        std::cout << "\n------------\n";
        std::cout << exec("ping " + findDNS(2).second);
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    color.reset();
}

