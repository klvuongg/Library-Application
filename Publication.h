/* Citation and Sources...
Final Project Milestone 5
Module: Publication
Filename: Publication.h
Version 1.0
Author	Kaitlyn Vuong
Revision History
-----------------------------------------------------------
Name               Date                 Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SENECA_PUBLICATION_H
#define SENECA_PUBLICATION_H
#include <iostream>
#include "Streamable.h"
#include "Date.h"
namespace seneca {
    class Publication : public Streamable {
        char* m_title;
        char m_shelfId[5];
        int m_membership;
        int m_libRef;
        Date m_date;
    public:
        Publication();
        virtual void set(int member_id); // Sets the membership attribute to either zero or a five-digit integer.
        void setRef(int value); // Sets the **libRef** attribute value
        void resetDate(); // Sets the date to the current date of the system.
        virtual char type() const; //Returns the character 'P' to identify this object as a "Publication object"
        bool onLoan() const; //Returns true is the publication is checkout (membership is non-zero)
        Date checkoutDate() const; //Returns the date attribute
        bool operator==(const char* title) const; //Returns true if the argument title appears anywhere in the title of the publication. 
        //Otherwise, it returns false; (use strstr() function in <cstring>)
        operator const char* () const; //Returns the title attribute
        int getRef() const; //Returns the libRef attirbute. 

        bool conIO(std::ios& io) const;
        virtual std::ostream& write(std::ostream& os) const;
        virtual std::istream& read(std::istream& istr);
        virtual operator bool() const;

        Publication(const Publication& pub);
        Publication& operator=(const Publication& pub);
        ~Publication();
    };
}
#endif // !SENECA_PUBLICATION_H
