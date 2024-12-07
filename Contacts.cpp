//
// Created by jagfoljersolen on 25/11/24.
//

#include "Contacts.h"

#include <iostream>
#include <unordered_set>

void Contacts::addContact(string name, string surname, int age, string tel, string street) {

    auto& telephone_index = contacts.get<3>();
    if (telephone_index.find(tel) != telephone_index.end()) {
        cout << "Kontakt o podanym numerze juz istnieje!" << endl;

    }else {
        contacts.insert(Contact{name, surname, age, tel, street});
        cout << "Kontakt dodany." << endl;
    }

}

void Contacts::removeContact(string tel) {

    auto& telephone_index = contacts.get<3>();
    auto it = telephone_index.find(tel);
    if (it != telephone_index.end()) {
        telephone_index.erase(it);
        cout << "Kontakt usuniety." << endl;
    } else {
        cout << "Nie znaleziono kontaktu o tym numerze." << endl;
    }
}

void Contacts::findNeighbors(string street) const {

    auto& street_index = contacts.get<4>();
    auto range = street_index.equal_range(street);
    for (auto it = range.first; it != range.second; it++) {
        cout << *it ;
    }
}

void Contacts::findByAge(int min, int max) const {

    auto& age_index = contacts.get<2>();

    auto from = age_index.lower_bound(min);
    auto to = age_index.upper_bound(max);

    for (auto it = from; it != to; it++) {
        cout << *it ;
    }

}

Contact Contacts::findByTel(string tel) const {

    auto& telephone_index = contacts.get<3>();
    auto it = telephone_index.find(tel);
    if (it != telephone_index.end()) {
        cout << "Znaleziono kontakt: " << endl;
        cout << *it ;
    }
    return *it;
}
void Contacts::updateStreet(Contact &contact, string &newStreet){
    contact.street = newStreet;
}

void Contacts::changeStreetname(string oldStreet, string newStreet) {

    auto& street_index = contacts.get<4>();
    vector<street_type> streets;
    for (auto it = street_index.begin(); it != street_index.end(); it++) {
    }
    for (int i=0; i<streets.size(); i++) {
        street_index.modify(streets[i], bind(updateStreet, placeholders::_1));
    }
}

int Contacts::countAdults() const {
    auto& age_index = contacts.get<2>();
    auto it = age_index.lower_bound(18);
    int count = 0;
    for (; it != age_index.end(); ++it) {
        ++count;
    }
    return count;
}

int Contacts::countUniqueSurnames() const {
    auto& surname_index = contacts.get<1>();
    unordered_set<string> unique_surnames;
    for (const auto& contact : surname_index) {
        unique_surnames.insert(contact.surname);
    }
    return unique_surnames.size();
}

void Contacts::showContacts() const {
    for (auto& contact : contacts) {
        cout << contact;
    }
}
