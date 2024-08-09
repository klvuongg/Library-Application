/***********************************************************************
// OOP244 Utils Module
// File	Utils.cpp
// Version 1.0
// Date  July 14, 2024
// Author  Kaitlyn Vuong
// Description  I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include "Utils.h"
#include <cstdio>
using namespace std;
namespace seneca {
	void flushKey() {
		int c;
		while ((c = getchar()) != '\n' && c != EOF);
	}

	unsigned int foolproof(unsigned max, unsigned min, const char* prompt, const char* errorMessage) {
		unsigned int num;
		while (true) {
			cout << prompt;
			cin >> num;
			if (cin.fail() || num < min || num > max) {
				cin.clear();
				flushKey();
				cout << errorMessage;
			}
			else {
				return num;
			}
		}

	}
}