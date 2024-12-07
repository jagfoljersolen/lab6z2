//
// Created by jagfoljersolen on 25/11/24.
//

#ifndef CONTACTS_H
#define CONTACTS_H
#include "Contact.h"
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/ordered_index.hpp>

using namespace boost::multi_index;

typedef multi_index_container<
        Contact,
        indexed_by<
                hashed_non_unique<member<Contact, string, &Contact::name>>,
                hashed_non_unique<member<Contact, string, &Contact::surname>>,
                ordered_non_unique<member<Contact, int, &Contact::age>>,
                hashed_unique<member<Contact, string, &Contact::telephone>>,
                hashed_non_unique<member<Contact, string, &Contact::street>>
    >
    > contact_multi;

typedef contact_multi::nth_index<0>::type name_type;
typedef contact_multi::nth_index<1>::type surname_type;
typedef contact_multi::nth_index<2>::type age_type;
typedef contact_multi::nth_index<3>::type telephone_type;
typedef contact_multi::nth_index<4>::type street_type;

class Contacts {
public:
    contact_multi contacts;
    void addContact(string name, string surname, int age, string tel, string street);
    void removeContact(string tel);

    void findNeighbors(string street) const;

    void findByAge(int min, int max) const;
    Contact findByTel(string tel) const;
    void updateStreet(Contact& contact, string& newStreet) ;
    void changeStreetname(string oldStreet, string newStreet);
    int countAdults() const;
    int countUniqueSurnames() const;
    void showContacts() const;



};



#endif //CONTACTS_H
