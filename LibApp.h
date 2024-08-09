/* Citation and Sources...
Final Project Milestone 5
Module: LibApp
Filename: LibApp.h
Version 2.0
Author	Kaitlyn Vuong
Revision History
---------------------------------------------------------------------------------------------------------------
Name                           Date                                   Reason
Added new member data,      2024/09/08         Update member data and functions so that they work for MS5
updated old functions 
and added a new function
---------------------------------------------------------------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------------------------------------------------------------*/

#ifndef SENECA_LIBAPP_H
#define SENECA_LIBAPP_H
#include "Menu.h"
#include "Publication.h"
#include "Lib.h"
namespace seneca {
	class LibApp {
		bool m_changed;
		Menu m_mainMenu;
		Menu m_exitMenu;
		char m_fileName[256];
		Publication* pub_pointer[SENECA_LIBRARY_CAPACITY];
		int num_pub;
		int last_libRef;
		Menu m_pubTypeMenu;
		bool confirm(const char* message);
		void load();
		void save();
		int search(int mode);
		void returnPub();
		void newPublication();
		void removePublication();
		void checkOutPub();
	public:
		LibApp(const char* filename);
		void run();
		Publication* getPub(int libRef);
		~LibApp();
	};
}
#endif // !SENECA_LIBAPP_H
