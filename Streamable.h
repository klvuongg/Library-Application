/* Citation and Sources...
Final Project Milestone 5
Module: Streamable
Filename: Streamable.h
Version 1.0
Author	Kaitlyn Vuong
Revision History
-----------------------------------------------------------
Name               Date                 Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SENECA_STREAMABLE_H
#define SENECA_STREAMABLE_H
#include <iostream>
namespace seneca {
    class Streamable {
    public:
        virtual std::ostream& write(std::ostream& os) const = 0;
        virtual std::istream& read(std::istream& istr) = 0;
        virtual bool conIO(std::ios& io) const = 0;
        virtual operator bool() const = 0;
        virtual ~Streamable() {};
    };
    std::ostream& operator<<(std::ostream& os, const Streamable& str);
    std::istream& operator>>(std::istream& istr, Streamable& str);
}
#endif // !SENECA_STREAMABLE_H
