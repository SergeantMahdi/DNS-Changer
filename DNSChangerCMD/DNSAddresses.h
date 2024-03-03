#pragma once
#include <Windows.h>

//(This File will be saved in a database with more DNS in the future)

//Ethernet DNS command
class DNS_Ethernet {
public:
    LPCSTR primaryGoogle = "interface ip set dns name = \"Ethernet\" source=\"static\" address=\"8.8.8.8\" validate=no";
    LPCSTR secondaryGoogle = "interface ip add  dns name=\"Ethernet\" address=\"8.8.4.4\" index=2 validate=no";

    LPCSTR primaryElectro = "interface ip set dns name=\"Ethernet\" source=\"static\" address=\"78.157.42.101\" validate=no";
    LPCSTR secondaryElectro = "interface ip add  dns name=\"Ethernet\" address=\"78.157.42.100\" index=2 validate=no ";

    LPCSTR primaryShecan = "interface ip set dns name=\"Ethernet\" source=\"static\" address=\"178.22.122.100\" validate=no";
    LPCSTR secondaryShecan = "interface ip add  dns name=\"Ethernet\" address=\"185.51.200.2\" index=2 validate=no ";

    LPCSTR primaryCloudFlare = "interface ip set dns name=\"Ethernet\" source=\"static\" address=\"1.1.1.1\" validate=no";
    LPCSTR secondaryCloudFlare = " interface ip add  dns name=\"Ethernet\" address=\"1.0.0.1\" index=2 validate=no ";

    LPCSTR disableDNS = "interface ip set dns name=\"Ethernet\" source=\"static\" address=\"none\" validate=no";

};

//Wifi DNS command
class DNS_WiFi {
public:
    LPCSTR primaryGoogle = "interface ip set dns name = \"wi-fi\" source=\"static\" address=\"8.8.8.8\" validate=no";
    LPCSTR secondaryGoogle = "interface ip add  dns name=\"wi-fi\" address=\"8.8.4.4\" index=2 validate=no";

    LPCSTR primaryElectro = "interface ip set dns name=\"wi-fi\" source=\"static\" address=\"78.157.42.101\" validate=no";
    LPCSTR secondaryElectro = "interface ip add  dns name=\"wi-fi\" address=\"78.157.42.100\" index=2 validate=no ";

    LPCSTR primaryShecan = "interface ip set dns name=\"wi-fi\" source=\"static\" address=\"178.22.122.100\" validate=no";
    LPCSTR secondaryShecan = "interface ip add  dns name=\"wi-fi\" address=\"185.51.200.2\" index=2 validate=no ";

    LPCSTR primaryCloudFlare = "interface ip set dns name=\"wi-fi\" source=\"static\" address=\"1.1.1.1\" validate=no";
    LPCSTR secondaryCloudFlare = " interface ip add  dns name=\"wi-fi\" address=\"1.0.0.1\" index=2 validate=no ";

    LPCSTR disableDNS = "interface ip set dns name=\"wi-fi\" source=\"static\" address=\"none\" validate=no";

};