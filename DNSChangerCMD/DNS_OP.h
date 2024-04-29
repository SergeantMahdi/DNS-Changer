#pragma once
#include <iostream>
#include <Windows.h>
#include "TextColor.h"
#include "string"

class DNS_OPERATION {
public:
    void change_DNS(LPCSTR , LPCSTR);

    void disable_DNS(LPCSTR);
    void testPing(int);
    int chooseNetworkAdapter();
    std::string exec(std::string);
    std::pair<std::string, std::string> findDNS(int);
};