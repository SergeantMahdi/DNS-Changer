#pragma once
#include <Windows.h>

//(This File will be saved in a database with more DNS in the future)

//Ethernet DNS command
class DNS_Ethernet {
public:
    LPCSTR primaryGoogle = "interface ipv4 set dnsservers \"Ethernet\" static 8.8.8.8 primary";
    LPCSTR secondaryGoogle = "interface ipv4 add dnsservers \"Ethernet\" 8.8.4.4 index=2";

    LPCSTR primaryElectro = "interface ipv4 set dnsservers \"Ethernet\" static 78.157.42.101 primary";
    LPCSTR secondaryElectro = "interface ipv4 add dnsservers \"Ethernet\" 78.157.42.100 index=2";

    LPCSTR primaryShecan = "interface ipv4 set dnsservers \"Ethernet\" static 178.22.122.100 primary";
    LPCSTR secondaryShecan = "interface ipv4 add dnsservers \"Ethernet\" 185.51.200.2 index=2";

    LPCSTR primaryCloudFlare = "interface ipv4 set dnsservers \"Ethernet\" static 1.1.1.1 primary";
    LPCSTR secondaryCloudFlare = " interface ipv4 add dnsservers \"Ethernet\" 1.0.0.1 index=2";

    LPCSTR disableDNS = "interface ip set dnsserver \"Ethernet\" static none validate=no";

};

//Wifi DNS command
class DNS_WiFi {
public:
    LPCSTR primaryGoogle = "interface ipv4 set dnsservers \"Wi-Fi\" static 8.8.8.8 primary";
    LPCSTR secondaryGoogle = "interface ipv4 add dnsservers \"Wi-Fi\" 8.8.4.4 index=2";

    LPCSTR primaryElectro = "interface ipv4 set dnsservers \"Wi-Fi\" static 78.157.42.101 primary";
    LPCSTR secondaryElectro = "interface ipv4 add dnsservers \"Wi-Fi\" 78.157.42.100 index=2";

    LPCSTR primaryShecan = "interface ipv4 set dnsservers \"Wi-Fi\" static 178.22.122.100 primary";
    LPCSTR secondaryShecan = "interface ipv4 add dnsservers \"Wi-Fi\" 185.51.200.2 index=2";

    LPCSTR primaryCloudFlare = "interface ipv4 set dnsservers \"Wi-Fi\" static 1.1.1.1 primary";
    LPCSTR secondaryCloudFlare = " interface ipv4 add dnsservers \"Wi-Fi\" 1.0.0.1 index=2";

    LPCSTR disableDNS = "interface ip set dnsserver \"Wi-Fi\" static none validate=no";

};