/* Citation and Sources...
Final Project Milestone 5
Module: Menu
Filename: Menu.cpp
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
#include <iomanip>
#include <iostream>
#include <ctime>
#include <cstring>

#include "Menu.h"
#include "Utils.h"
using namespace std;
namespace seneca {
	void MenuItem::setEmpty() {
		content = nullptr;
	}

	bool MenuItem::isEmpty() const {
		return content[0] == '\0';
	}

	MenuItem::MenuItem(const char* name) {
		if (name && name[0] != '\0') {
			content = new char[strlen(name) + 1];
			strcpy(content, name);
		}
		else {
			setEmpty();
		}
	}

	MenuItem::~MenuItem() {
		delete[] content;
	}

	MenuItem::operator bool() const {
		if (isEmpty()) {
			return false;
		}
		else {
			return true;
		}
	}

	MenuItem::operator const char* () const {
		return content;
	}

	void MenuItem::display(std::ostream& os) const {
		if (!isEmpty()) {
			os << content;
		}
	}

	void Menu::setEmpty() {
		unsigned int i;
		title = nullptr;
		for (i = 0; i < MAX_MENU_ITEMS; i++) {
			item[i] = nullptr;
		}
		count = 0;
	}

	Menu::Menu(const char* title) {
		setEmpty();
		if (title) {
			this->title = new MenuItem(title);
		}
	}

	Menu::~Menu() {
		unsigned int i;
		delete title;
		for (i = 0; i < count; i++) {
			delete item[i];
		}
	}

	void Menu::displayTitle(std::ostream& out, bool withContent) const {
		if (title) {
			out << title->content;
			if (withContent) {
				out << endl;
			}
		}
	}

	void Menu::display(std::ostream& out) const {
		unsigned int i;
		displayTitle(out, true);
		for (i = 0; i < count; i++) {
			out.width(2);
			out.setf(ios::right);
			out << i + 1 << "- ";
			item[i]->display(out);
			out << endl;
		}
		out << " 0- Exit" << endl;
		out << "> ";
	}

	unsigned int Menu::run() const {
		display(std::cout);
		return foolproof(count, 0, "", "Invalid Selection, try again: ");
	}

	unsigned int Menu::operator~() const {
		return run();
	}

	Menu& Menu::operator<<(const char* menuitemContent) {
		if (menuitemContent && menuitemContent[0] != '\0' && count < MAX_MENU_ITEMS) {
			item[count] = new MenuItem(menuitemContent);
			count++;
		}
		return *this;
	}

	Menu::operator int() const {
		return (int)count;
	}

	Menu::operator unsigned int() const {
		return count;
	}

	Menu::operator bool() const {
		if (count > 0) {
			return true;
		}
		else {
			return false;
		}
	}

	std::ostream& operator<<(std::ostream& os, const Menu& menu) {
		menu.displayTitle(os, false);
		return os;
	}

	const char* Menu::operator[](unsigned int index) const {
		if (count == 0) {
			return nullptr;
		}
		return (const char*)(*item[index % count]);
	}
}