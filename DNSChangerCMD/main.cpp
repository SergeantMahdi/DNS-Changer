#include <iostream>
#include "DNSAddresses.h"
#include <thread>
#include <chrono>
#include "conio.h"
#include "TextColor.h"


//All adresses of DNS has been created in DNSAddress.h
//Text color has been created to colorize the cmd text


//Change DNS by Shell
void change_DNS(LPCSTR primary, LPCSTR secondary) {
    TextColor color;

    //shell command
    LPCSTR application = "netsh";

    //shell executer for primary and secondary DNS
    HINSTANCE hInstance = ShellExecuteA(NULL, "runas", application, primary, NULL, SW_SHOWNORMAL);
    HINSTANCE hInstance2 = ShellExecuteA(NULL, "runas", application, secondary, NULL, SW_SHOWNORMAL);

    //Error handler of shell executer
    if (reinterpret_cast<uintptr_t>(hInstance) > 32) {
        color.success();
        std::cout << "Primary and Secondary DNS has changed successfully." << std::endl;
        color.reset();
    }
    else {
        color.error();
        DWORD errorCode = GetLastError();
        std::cerr << "Failed to change DNS. Error code: " << errorCode << std::endl;
        color.reset();
    }
    if (reinterpret_cast<uintptr_t>(hInstance2) > 32) {
        color.success();
        std::cout << "Seconday DNS has changed successfully." << std::endl;
        color.reset();
    }
    else {
        color.error();
        DWORD errorCode = GetLastError();
        std::cerr << "Failed to change Secondary. Error code: " << errorCode << std::endl;
        color.reset();
    }


}

void disable_DNS(LPCSTR disableDNS) {
    TextColor color;

    //shell command
    LPCSTR application = "netsh";

    // shell executer to disable DNS
    HINSTANCE hInstance = ShellExecuteA(NULL, "runas", application, disableDNS, NULL, SW_SHOWNORMAL);

    //Error handler of shell executer
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

//Select your  Network adapter 
//(Will be automated in the future)
int chooseNetworkAdapter() {

    int selection;

    std::cout << "Choose your Network Connection:(1-2) \n";
    std::cout << "1.Ethernet\n";
    std::cout << "2.Wifi\n";
    std::cin >> selection;
    system("cls");
    return selection;
}

int main() {
    TextColor color;


    bool flag = true;

    //Select the network
    int selection = chooseNetworkAdapter();
     system("cls");

    while (flag) {
        //Print out all existing options
        int num;
        color.info();
        selection == 1 ? std::cout << "Your Network Connection: Ethernet\n" : std::cout << "Your Network Connection: Wi-Fi\n";
        color.reset();
        std::cout << "_______________________________\n";
        std::cout << "1. Google:    | 8.8.8.8 / 8.8.4.4\n";
        std::cout << "2. Electro:   | 78.157.42.101 / 78.157.42.100\n";
        std::cout << "3. Shecan:    | 178.22.122.100 / 185.51.200.2\n";
        std::cout << "4. Cloudflare:| 1.1.1.1 / 1.0.0.1\n";
        std::cout << "5. Disable DNS\n";
        std::cout << "6. Change Network Connection\n";
        std::cout << "0. Exit\n";

        std::cin >> num;

        //check the network if it's Wifi or Ethernet
        if (selection == 1)
        {//Ethernet

            DNS_Ethernet dns;

            switch (num) {
            case 1: 
                change_DNS(dns.primaryGoogle, dns.secondaryGoogle);
                  break;
            
            case 2: 
                change_DNS(dns.primaryElectro, dns.secondaryElectro);
                break;
  
            case 3:
                change_DNS(dns.primaryShecan, dns.secondaryShecan);
                break;
            
            case 4: 
                change_DNS(dns.primaryCloudFlare, dns.secondaryCloudFlare);
                  break;

            case 5:
                disable_DNS(dns.disableDNS);
                break;
            case 6:
            {
                system("cls");
                selection = chooseNetworkAdapter();
            }
            continue;

            case 0:
                flag = false;
                continue;

            default:
                std::cout << "Invalid number\n";
            }

        }
        else { //WiFi

            DNS_WiFi dns;

            switch (num) {
            case 1:
                change_DNS(dns.primaryGoogle, dns.secondaryGoogle);
                break;

            case 2:
                change_DNS(dns.primaryElectro, dns.secondaryElectro);
                break;

            case 3:
                change_DNS(dns.primaryShecan, dns.secondaryShecan);
                break;

            case 4:
                change_DNS(dns.primaryCloudFlare, dns.secondaryCloudFlare);
                break;

            case 5:
                disable_DNS(dns.disableDNS);
                break;

            case 6:
            {
                system("cls");
                selection = chooseNetworkAdapter();
            }
            continue;

            case 0:
                flag = false;
                continue;

            default:
                std::cout << "Invalid number\n";
            }
        }

        //Delay 3 second to avoid scam
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        system("cls");
    }

}