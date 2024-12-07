//
// Created by jagfoljersolen on 25/11/24.
//

#ifndef CONTACT_H
#define CONTACT_H
#include <ostream>
#include <string>
using namespace std;


class Contact {
public:
    string name;
    string surname;
    int age;
    string telephone;
    string street;

    friend ostream& operator<<(ostream& os, const Contact& contact) {
        os << contact.name << " " << contact.surname << " "  << contact.age << " " << contact.telephone << " " << contact.street << endl;
        return os;
    }


};



#endif //CONTACT_H
