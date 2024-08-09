/* Citation and Sources...
Final Project Milestone 5
Module: Publication
Filename: Publication.cpp
Version 3.0
Author	Kaitlyn Vuong
Revision History
---------------------------------------------------------------------
Name                         Date                 Reason
write function updated    2024/03/08     updated write function so
										 that the book title can fit
read function updated     2024/03/08     updated read function so
										 that the book title can be
										 read into a bigger buffer
write function updated    2024/09/08     updated write function so 
                                         that the newline character 
										 is added correctly according 
										 to the type
---------------------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Publication.h"
#include "Lib.h"
using namespace std;
namespace seneca {
	Publication::Publication() {
		m_title = nullptr;
		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
		m_date = Date();
	}

	void Publication::set(int member_id) {
		if (member_id >= 10000 && member_id <= 99999) {
			m_membership = member_id;
		}
		else {
			m_membership = 0;
		}
	}

	void Publication::setRef(int value) {
		m_libRef = value;
	}

	void Publication::resetDate() {
		m_date = Date();
	}

	char Publication::type() const {
		return 'P';
	}

	bool Publication::onLoan() const {
		if (m_membership != 0) {
			return true;
		}
		return false;
	}

	Date Publication::checkoutDate() const {
		return m_date;
	}

	bool Publication::operator==(const char* title) const {
		if (strstr(m_title, title) != nullptr) {
			return true;
		}
		return false;
	}

	Publication::operator const char* () const {
		return m_title;
	}

	int Publication::getRef() const {
		return m_libRef;
	}

	bool Publication::conIO(std::ios& io) const {
		return &io == &std::cin || &io == &std::cout;
	}

	std::ostream& Publication::write(std::ostream& os) const {
		if (conIO(os)) {
			if (*this) {
				os << "| " << setw(SENECA_SHELF_ID_LEN) << setfill(' ') << m_shelfId << " | ";
				if (strlen(m_title) > SENECA_TITLE_WIDTH) {
					os.write(m_title, SENECA_TITLE_WIDTH);
				}
				else {
					os << left << setw(SENECA_TITLE_WIDTH) << setfill('.') << (m_title ? m_title : "");
				}
				os << " | ";
				if (m_membership != 0) {
					os << setw(5) << setfill(' ') << m_membership;
				}
				else {
					os << " N/A ";
				}
				os << " | " << setfill(' ') << m_date << " |";
			}
		}
		else {
			if (*this) {
				os << type() << '\t' << m_libRef << '\t' << m_shelfId << '\t'
					<< (m_title ? m_title : "") << '\t' << m_membership << '\t' << m_date << '\t';
				if (type() == 'P') {
					os << "\n";
				}
			}
		}
		return os;
	}

	std::istream& Publication::read(std::istream& istr) {
		delete[] m_title;
		m_title = nullptr;
		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
		m_date = Date();
		char shelfId[SENECA_SHELF_ID_LEN + 1];
		char title[256];
		int membership = 0;
		int libRef = -1;
		Date date;

		if (conIO(istr)) {
			cout << "Shelf No: ";
			istr.ignore();
			istr.getline(shelfId, SENECA_SHELF_ID_LEN + 1);
			if (strlen(shelfId) != SENECA_SHELF_ID_LEN) {
				istr.setstate(ios::failbit);
				return istr;
			}
			cout << "Title: ";
			istr.getline(title, 256);
			cout << "Date: ";
			istr >> date;
		}
		else {
			istr >> libRef;
			istr.ignore();
			istr.getline(shelfId, SENECA_SHELF_ID_LEN + 1, '\t');
			istr.getline(title, 256, '\t');
			istr >> membership;
			istr.ignore();
			istr >> date;
		}

		if (strcmp(date.dateStatus(), "No Error") != 0) {
			istr.setstate(ios::failbit);
			return istr;
		}

		if (istr) {
			m_title = new char[strlen(title) + 1];
			strcpy(m_title, title);
			strcpy(m_shelfId, shelfId);
			m_membership = membership;
			m_date = date;
			m_libRef = libRef;
		}
		else {
			delete[] m_title;
			m_title = nullptr;
		}

		return istr;
	}

	Publication::operator bool() const {
		if (m_title != nullptr && m_shelfId[0] != '\0') {
			return true;
		}
		return false;
	}

	Publication::Publication(const Publication& pub) {
		m_membership = pub.m_membership;
		m_libRef = pub.m_libRef;
		m_date = pub.m_date;
		strcpy(m_shelfId, pub.m_shelfId);

		if (pub.m_title) {
			m_title = new char[strlen(pub.m_title) + 1];
			strcpy(m_title, pub.m_title);
		}
	}

	Publication& Publication::operator=(const Publication& pub) {
		if (this != &pub) {
			delete[] m_title;
			m_membership = pub.m_membership;
			m_libRef = pub.m_libRef;
			m_date = pub.m_date;
			strcpy(m_shelfId, pub.m_shelfId);

			if (pub.m_title) {
				m_title = new char[strlen(pub.m_title) + 1];
				strcpy(m_title, pub.m_title);
			}
			else {
				m_title = nullptr;
			}
		}
		return *this;
	}

	Publication::~Publication() {
		delete[] m_title;
	}
}