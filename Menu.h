/* Citation and Sources...
Final Project Milestone 5
Module: Menu
Filename: Menu.h
Version 1.0
Author	Kaitlyn Vuong
Revision History
-----------------------------------------------------------
Name               Date                 Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SENECA_MENU_H__
#define SENECA_MENU_H__
#include <iostream>
namespace seneca {
	const unsigned int MAX_MENU_ITEMS = 20;
	class Menu;

	class MenuItem {
		char* content;
		friend class Menu;
		void setEmpty();
		bool isEmpty() const;
		MenuItem(const char* name);
		MenuItem(const MenuItem& copy) = delete;
		MenuItem& operator=(const MenuItem& copy) = delete;
		~MenuItem();
		operator bool() const;
		operator const char* () const;
		void display(std::ostream& os) const;
	};

	class Menu {
		MenuItem* title;
		MenuItem* item[MAX_MENU_ITEMS];
		unsigned int count;
		Menu(const Menu& copy) = delete;
		Menu& operator=(const Menu& copy) = delete;
		void setEmpty();
	public:
		Menu(const char* title = nullptr);
		~Menu();
		void displayTitle(std::ostream& out, bool withContent) const;
		void display(std::ostream& out) const;
		unsigned int run() const;
		unsigned int operator~() const;
		Menu& operator<<(const char* menuitemContent);
		operator int() const;
		operator unsigned int() const;
		operator bool() const;
		const char* operator[](unsigned int index) const;
	};
	std::ostream& operator<<(std::ostream& os, const Menu& menu);
}
#endif
