/* Citation and Sources...
Final Project Milestone 5
Module: Book
Filename: Book.h
Version 1.0
Author	Kaitlyn Vuong
Revision History
-----------------------------------------------------------
Name               Date                 Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H
#include <iostream>
#include "Publication.h"
namespace seneca {
    class Book : public Publication {
        char* author_name;
    public:
        Book();
        Book(const Book& b);
        Book& operator=(const Book& b);
        ~Book();
        char type() const;
        std::ostream& write(std::ostream& os) const;
        std::istream& read(std::istream& istr);
        void set(int member_id);
        operator bool() const;
    };
}
#endif // !SENECA_BOOK_H
