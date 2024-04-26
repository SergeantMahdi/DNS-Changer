#pragma once
#include <windows.h>

class TextColor {
private:
	enum
	{
		Error = 9,
		Success = 10,
		Warning = 11,
		Info = 3,
		Reset = 15
	};
public:
	void error() {
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, Error);
	}

	void success() {
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, Success);
	}

	void info() {
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, Info);
	}

	void warning() {
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, Warning);
	}

	void reset() {
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, Reset);
	}
 
};