/* Citation and Sources...
Final Project Milestone 5
Module: Book
Filename: Book.cpp
Version 2.0
Author	Kaitlyn Vuong
Revision History
--------------------------------------------------------------------------
Name                         Date                 Reason
write function updated    2024/09/08     updated write function so that
										 the newline character is added
										 after the author's name and set
										 the author's name to the left
--------------------------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Lib.h"
#include "Book.h"
#include "Utils.h"
using namespace std;
namespace seneca {
	Book::Book() : Publication() {
		author_name = nullptr;
	}

	Book::Book(const Book& b) : Publication(b) {
		author_name = nullptr;
		if (b.author_name) {
			author_name = new char[strlen(b.author_name) + 1];
			strcpy(author_name, b.author_name);
		}
	}

	Book& Book::operator=(const Book& b) {
		if (this != &b) {
			(Publication&)*this = b;
			delete[] author_name;
			author_name = nullptr;
			if (b.author_name) {
				author_name = new char[strlen(b.author_name) + 1];
				strcpy(author_name, b.author_name);
			}
		}
		return *this;
	}

	Book::~Book() {
		delete[] author_name;
		author_name = nullptr;
	}

	char Book::type() const {
		return 'B';
	}

	std::ostream& Book::write(std::ostream& os) const {
		Publication::write(os);
		if (conIO(os)) {
			os << left;
			if (author_name) {
				os << " ";
				if (strlen(author_name) > SENECA_AUTHOR_WIDTH) {
					os.write(author_name, SENECA_AUTHOR_WIDTH);
				}
				else {
					os << setw(SENECA_AUTHOR_WIDTH) << author_name;
				}
				os << " |";
			}
		}
		else {
			os << author_name;
		}
		
		return os;
	}

	std::istream& Book::read(std::istream& istr) {
		char aName[256];
		Publication::read(istr);
		delete[] author_name;
		author_name = nullptr;
		if (conIO(istr)) {
			istr.ignore();
			cout << "Author: ";
			istr.get(aName, 256);
		}
		else {
			istr.ignore();
			istr.get(aName, 256);
		}

		if (istr) {
			author_name = new char[strlen(aName) + 1];
			strcpy(author_name, aName);
		}
		else {
			delete[] author_name;
			author_name = nullptr;
		}
		return istr;
	}

	void Book::set(int member_id) {
		Publication::set(member_id);
		resetDate();
	}

	Book::operator bool() const {
		return author_name && author_name[0] != '\0' && Publication::operator bool();
	}
}