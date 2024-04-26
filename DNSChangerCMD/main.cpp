#include <iostream>
#include <thread>
#include <chrono>
#include "conio.h"
#include "DNSAddresses.h"
#include "dnsOperatins.h"
#include "TextColor.h"



int main() {
    TextColor color;
    DNS_OPERATION op;

    bool flag = true;

    //Select the network
    int selection = op.chooseNetworkAdapter();
    
     system("cls");

    while (flag) {
        //Print out all existing options

        color.info();

        selection == 1 ? std::cout << "Your Network Connection: Ethernet\n" : std::cout << "Your Network Connection: Wi-Fi\n";
        std::cout << "-------------\n";
        auto DNS = op.findDNS(selection);
        std::cout << "Your Current DNS: " << DNS.first << "/" << DNS.second;

        color.reset();

        int num;

        std::cout << "\n_______________________________\n";
        std::cout << "1. Google:    | 8.8.8.8 / 8.8.4.4\n";
        std::cout << "2. Electro:   | 78.157.42.101 / 78.157.42.100\n";
        std::cout << "3. Shecan:    | 178.22.122.100 / 185.51.200.2\n";
        std::cout << "4. Cloudflare:| 1.1.1.1 / 1.0.0.1\n";
        std::cout << "5. Disable DNS\n";
        std::cout << "6. Change Network Connection\n";
        std::cout << "7. Test Your Ping\n";
        std::cout << "0. Exit\n";

        std::cin >> num;

        //check the network if it's Wifi or Ethernet
        if (selection == 1)
        {//Ethernet

            DNS_Ethernet dns;

            switch (num) {
            case 1: 
                op.change_DNS(dns.primaryGoogle, dns.secondaryGoogle);
                  break;
            
            case 2:
                op.change_DNS(dns.primaryElectro, dns.secondaryElectro);
                break;
  
            case 3:
                op.change_DNS(dns.primaryShecan, dns.secondaryShecan);
                break;
            
            case 4: 
                op.change_DNS(dns.primaryCloudFlare, dns.secondaryCloudFlare);
                  break;

            case 5:
                op.disable_DNS(dns.disableDNS);
                break;
            case 6:
            {
                system("cls");
                selection = op.chooseNetworkAdapter();
            continue;
            }
            case 7:
            {
                system("cls");
                op.testPing(num);
                break;
            }

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
                op.change_DNS(dns.primaryGoogle, dns.secondaryGoogle);
                break;

            case 2:
                op.change_DNS(dns.primaryElectro, dns.secondaryElectro);
                break;

            case 3:
                op.change_DNS(dns.primaryShecan, dns.secondaryShecan);
                break;

            case 4:
                op.change_DNS(dns.primaryCloudFlare, dns.secondaryCloudFlare);
                break;

            case 5:
                op.disable_DNS(dns.disableDNS);
                break;

            case 6:
            {
                system("cls");
                selection = op.chooseNetworkAdapter();
                continue;
            }
            case 7:
            {
                system("cls");
                op.testPing(num);
                break;
            }

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