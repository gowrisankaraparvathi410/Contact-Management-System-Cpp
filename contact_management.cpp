#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Contact {
    string name;
    string phone;
    string email;
};

void addContact() {
    Contact c;

    cin.ignore();

    cout << "\nEnter Name: ";
    getline(cin, c.name);

    cout << "Enter Phone: ";
    getline(cin, c.phone);

    cout << "Enter Email: ";
    getline(cin, c.email);

    ofstream file("contacts.txt", ios::app);

    file << c.name << endl;
    file << c.phone << endl;
    file << c.email << endl;

    file.close();

    cout << "\nContact Saved Successfully!\n";
}

void viewContacts() {

    Contact c;

    ifstream file("contacts.txt");

    cout << "\n====== CONTACT LIST ======\n";

    while (getline(file, c.name)) {

        getline(file, c.phone);
        getline(file, c.email);

        cout << "\nName  : " << c.name;
        cout << "\nPhone : " << c.phone;
        cout << "\nEmail : " << c.email;
        cout << "\n------------------------";
    }

    file.close();
}

void searchContact() {

    Contact c;
    string searchName;
    bool found = false;

    cin.ignore();

    cout << "\nEnter Name to Search: ";
    getline(cin, searchName);

    ifstream file("contacts.txt");

    while (getline(file, c.name)) {

        getline(file, c.phone);
        getline(file, c.email);

        if (c.name == searchName) {

            cout << "\nContact Found!\n";

            cout << "Name  : " << c.name << endl;
            cout << "Phone : " << c.phone << endl;
            cout << "Email : " << c.email << endl;

            found = true;
            break;
        }
    }

    if (!found)
        cout << "\nContact Not Found!\n";

    file.close();
}

void deleteContact() {

    Contact c;
    string deleteName;
    bool found = false;

    cin.ignore();

    cout << "\nEnter Name to Delete: ";
    getline(cin, deleteName);

    ifstream file("contacts.txt");
    ofstream temp("temp.txt");

    while (getline(file, c.name)) {

        getline(file, c.phone);
        getline(file, c.email);

        if (c.name != deleteName) {

            temp << c.name << endl;
            temp << c.phone << endl;
            temp << c.email << endl;
        }
        else {
            found = true;
        }
    }

    file.close();
    temp.close();

    remove("contacts.txt");
    rename("temp.txt", "contacts.txt");

    if (found)
        cout << "\nContact Deleted Successfully!\n";
    else
        cout << "\nContact Not Found!\n";
}

int main() {

    int choice;

    do {

        cout << "\n==============================";
        cout << "\n CONTACT MANAGEMENT SYSTEM";
        cout << "\n==============================";
        cout << "\n1. Add Contact";
        cout << "\n2. View All Contacts";
        cout << "\n3. Search Contact";
        cout << "\n4. Delete Contact";
        cout << "\n5. Exit";
        cout << "\n\nEnter Choice: ";

        cin >> choice;

        switch(choice) {

            case 1:
                addContact();
                break;

            case 2:
                viewContacts();
                break;

            case 3:
                searchContact();
                break;

            case 4:
                deleteContact();
                break;

            case 5:
                cout << "\nThank You!\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 5);

    return 0;
}