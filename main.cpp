#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Contact {
    std::string name;
    std::string phone;
    std::string email;
};

void addContact(std::vector<Contact> &contacts) {
    Contact newContact;
    std::cout << "Enter name: ";
    std::cin >> newContact.name;
    std::cout << "Enter phone: ";
    std::cin >> newContact.phone;
    std::cout << "Enter email: ";
    std::cin >> newContact.email;
    contacts.push_back(newContact);
    std::cout << "Contact added." << std::endl;
}

void displayContacts(const std::vector<Contact> &contacts) {
    
    std::vector<std::string> contactNames;
    for (const auto &contact : contacts) {
        contactNames.push_back(contact.name);
    }

    std::sort(contactNames.begin(), contactNames.end());  // sorting in lexicographically

    for (const auto &name : contactNames) {
        for (const auto &contact : contacts) {
            if (contact.name == name) {
                std::cout << "Name: " << contact.name << ", Phone: " 
                          << contact.phone << ", Email: " << contact.email << std::endl;
                break;
            }
        }
    }
}

void searchContact(const std::vector<Contact> &contacts) {
    std::string searchTerm;
    std::cout << "Enter name to search: ";
    std::cin >> searchTerm;

    bool found = false;
    for (const auto &contact : contacts) {
        if (contact.name == searchTerm) {
            std::cout << "Name: " << contact.name << ", Phone: " 
                      << contact.phone << ", Email: " << contact.email << std::endl;
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Contact not found." << std::endl;
    }
}

void editContact(std::vector<Contact> &contacts) {
    std::string nameToEdit;
    std::cout << "Enter name of contact to edit: ";
    std::cin >> nameToEdit;

    auto it = std::find_if(contacts.begin(), contacts.end(), [&](const Contact &contact) {
        return contact.name == nameToEdit;
    });

    if (it != contacts.end()) {
        std::cout << "Enter new name (or press enter to keep current): ";
        std::string newName;
        std::cin >> newName;
        if (!newName.empty()) {
            it->name = newName;
        }

        std::cout << "Enter new phone (or press enter to keep current): ";
        std::string newPhone;
        std::cin >> newPhone;
        if (!newPhone.empty()) {
            it->phone = newPhone;
        }

        std::cout << "Enter new email (or press enter to keep current): ";
        std::string newEmail;
        std::cin >> newEmail;
        if (!newEmail.empty()) {
            it->email = newEmail;
        }

        std::cout << "Contact updated." << std::endl;
    } else {
        std::cout << "Contact not found." << std::endl;
    }
}

void deleteContact(std::vector<Contact> &contacts) {
    std::string nameToDelete;
    std::cout << "Enter name of contact to delete: ";
    std::cin >> nameToDelete;

    auto it = std::remove_if(contacts.begin(), contacts.end(), [&](const Contact &contact) {
        return contact.name == nameToDelete;
    });

    if (it!= contacts.end()) {
        contacts.erase(it, contacts.end());
        std::cout << "Contact deleted." << std::endl;
    } else {
        std::cout << "Contact not found." << std::endl;
    }
}

int main() {
    std::vector<Contact> contacts;
    int choice;

    do {
        std::cout << "\n1. Add Contact" << std::endl;
        std::cout << "2. Display Contacts" << std::endl;
        std::cout << "3. Search Contact" << std::endl;
        std::cout << "4. Edit Contact" << std::endl;
        std::cout << "5. Delete Contact" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            addContact(contacts);
            break;
        case 2:
            displayContacts(contacts);
            break;
        case 3:
            searchContact(contacts);
            break;
        case 4:
            editContact(contacts);
            break;
        case 5:
            deleteContact(contacts);
            break;
        case 6:
            break;
        default:
            std::cout << "Invalid choice." << std::endl;
        }
    } while (choice!= 6);

    return 0;
}
