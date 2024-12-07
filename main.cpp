#include <iostream>

#include "Contacts.h"

int main()
{
    Contacts myContacts;
    myContacts.addContact("Bartosz", "Chudzik", 28, "777999333", "Pomaranczowa");
    myContacts.addContact("Anna", "Szysiak", 19, "666555444", "Morska");
    myContacts.addContact("Nikodem", "Skalski", 19, "444555888", "Morska");
    myContacts.addContact("Anna", "Wyrostkiewicz", 22, "777333222", "Makaronowa");
    myContacts.addContact("Jan", "Star", 22, "555777888", "Czesnikowska");
    myContacts.addContact("Gosia", "Star", 16, "777444999", "Cukierkowa");

    cout << "Lista kontaktow: " << endl;
    myContacts.showContacts();
    cout << endl;

    myContacts.removeContact("777333222");
    cout << "Lista kontaktow po usunieciu kontaktu o numerze 777333222: " << endl;
    myContacts.showContacts();
    cout << endl;
    myContacts.addContact("Anna", "Wyrostkiewicz", 22, "777333222", "Makaronowa");
    cout << endl;
    cout << "Lista mieszkancow ulicy Morskiej: "<<endl;
    myContacts.findNeighbors("Morska");
    cout << endl;
    cout << "Mieszkancy w wieku 19-24 lat: "<< endl;
    myContacts.findByAge(19,24);
    cout << endl;
    // cout << "Po zmianie nazwy ulicy Morskiej:" <<endl;
    // myContacts.changeStreetname("Morska","Nadmorska");
    // myContacts.findNeighbors("Nadmorska");
    // cout << endl;
    // myContacts.showContacts();
    cout << "Liczba doroslych: " << myContacts.countAdults() << endl;
    cout << "Liczba unikalnych nazwisk: " << myContacts.countUniqueSurnames() << endl;


    return 0;
}
