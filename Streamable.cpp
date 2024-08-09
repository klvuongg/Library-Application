/* Citation and Sources...
Final Project Milestone 5
Module: Streamable
Filename: Streamable.cpp
Version 1.0
Author	Kaitlyn Vuong
Revision History
-----------------------------------------------------------
Name               Date                 Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Streamable.h"
using namespace std;
namespace seneca {
	std::ostream& operator<<(std::ostream& os, const Streamable& str) {
		return str.write(os);
	}

	std::istream& operator>>(std::istream& istr, Streamable& str) {
		return str.read(istr);
	}
}