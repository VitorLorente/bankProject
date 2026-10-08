#include "menu.hpp"
#include "person.hpp"
#include "account.hpp"

#include <cstddef>
#include <iostream>


std::array<Person, 100> people{}; // Array to store Person objects
std::array<Account, 100> accounts{}; // Array to store Account objects

Menu::Menu() {
    // Constructor implementation
}

Menu::~Menu() {}

Person findPersonById(int id) {
    for (const auto& person : people) {
        if (person.getId() == id) {
            return person;
        }
    }
    return Person(); // Return an empty Person object if not found
}

Person findPersonByName(const std::string& name) {
    for (const auto& person : people) {
        if (person.getFirstName() == name || person.getLastName() == name) {
            return person;
        }
    }
    return Person(); // Return an empty Person object if not found
}

void Menu::displayMainMenu() {
    // Implementation for displaying the main menu
    for (
        int i = static_cast<int>(MenuOption::Exit);
        i <= static_cast<int>(MenuOption::ViewStatement);
        ++i
    ) {
        auto option = static_cast<MenuOption>(i);
        std::cout << i << " - " << menuOptionLabel(option) << std::endl;
    }

    std::cout << "------------------------" << std::endl;

    std::cout << "\nDigite a opção desejada: ";
    int choice;
    std::cin >> choice;
    resolveMenuOption(choice);
}


void Menu::displayAddPersonMenu() {
    // Implementation fo add Person
    std::cout << "\x1B[2J\x1B[H" << std::flush;
    std::cout << "Menu de cadastro de pessoa" << std::endl;
    std::cout << "------------------------" << std::endl;

    std::string first_name, last_name, phone1, phone2 = "";
    std::cout << "Digite o primeiro nome: ";
    std::cin >> first_name;
    std::cout << "Digite o sobrenome: ";
    std::cin >> last_name;
    std::cout << "Digite o telefone 1: ";
    std::cin >> phone1;
    std::cout << "Deseja adicionar um segundo telefone? (s/n): ";

    char choice;
    std::cin >> choice;
    if (choice == 's' || choice == 'S') {
        std::cout << "Digite o telefone 2: ";
        std::cin >> phone2;
    }

    Person newPerson(first_name, last_name, {phone1, phone2});
    // Store the new person in the array
    for (std::size_t i = 0; i < people.size(); ++i) {
        if (people[i].getFirstName().empty()) {
            people[i] = newPerson;
            people[i].setId(static_cast<int>(i + 1));
            std::cout << "Pessoa cadastrada com sucesso!" << std::endl;
            std::cout << people[i].returnPrettyId() << std::endl;
            std::cout << people[i].returnPrettyName() << std::endl;
            std::cout << people[i].returnPrettyPhoneNumbers() << std::endl;

            break;
        }
    }

    std::cout << "\n\n------------------------" << std::endl;
    std::cout << "Deseja cadastrar outra pessoa? (s/n): ";
    std::cin >> choice;
    if (choice == 's' || choice == 'S') {
        displayAddPersonMenu(); // Call the menu again for another registration
    } else {
        displayMainMenu(); // Return to the main menu
    }
}


void Menu::displaySearchPersonInfosMenu() {
    // Implementation for searching person information
    std::cout << "\n\nMenu de consulta de pessoa" << std::endl;
    std::cout << "------------------------\n" << std::endl;

    std::string searchName;
    std::cout << "Digite o nome ou o sobrenome da pessoa a ser consultada: ";
    std::cin >> searchName;

    Person foundPerson = findPersonByName(searchName);

    if (!foundPerson.getFirstName().empty() || !foundPerson.getLastName().empty()) {
        std::cout << "Pessoa encontrada!" << std::endl;
        std::cout << foundPerson.returnPrettyId() << std::endl;
        std::cout << foundPerson.returnPrettyName() << std::endl;
        std::cout << foundPerson.returnPrettyPhoneNumbers() << std::endl;
    } else {
        std::cout << "Pessoa não encontrada." << std::endl;
    }

    std::cout << "\n\n------------------------" << std::endl;
    
    char choice;
    std::cout << "Deseja consultar outra pessoa? (s/n): ";
    std::cin >> choice;
    if (choice == 's' || choice == 'S') {
        displaySearchPersonInfosMenu();
    } else {
        displayMainMenu();
    }
}


void Menu::displayOpenAccountMenu() {

    std::cout << "\n\nMenu de abertura de conta" << std::endl;
    std::cout << "------------------------\n" << std::endl;

    std::cout << "Você precisa pesquisar um pessoa pelo ID ou pelo nome para abrir uma conta." << std::endl;
    std::cout << "Você prefere pesquisar pelo ID (digite 1) ou pelo nome (digite 2)? ";

    int searchOption;
    std::cin >> searchOption;

    if (searchOption == 1) {
        int searchId;
        std::cout << "Digite o ID da pessoa: ";
        std::cin >> searchId;

        Person foundPerson = findPersonById(searchId);

        if ((!foundPerson.getFirstName().empty() || !foundPerson.getLastName().empty()) && foundPerson.getId() != 0) {
            std::cout << "Pessoa encontrada!" << std::endl;
            std::cout << foundPerson.returnPrettyId() << std::endl;
            std::cout << foundPerson.returnPrettyName() << std::endl;
            std::cout << foundPerson.returnPrettyPhoneNumbers() << std::endl;
            std::cout << "Deseja abrir uma conta para esta pessoa? (s/n): ";
            
            char openAccountChoice;
            std::cin >> openAccountChoice;
            if (openAccountChoice == 's' || openAccountChoice == 'S') { 
                // Proceed with account opening for the found person
                std::string agency, accountNumber;
                double initialBalance;

                std::cout << "Digite o número da agência: ";
                std::cin >> agency;
                std::cout << "Digite o número da conta: ";
                std::cin >> accountNumber;
                std::cout << "Digite o saldo inicial: ";
                std::cin >> initialBalance;

                Account newAccount(agency, accountNumber, initialBalance, foundPerson);
                // Store the new account in the array
                for (std::size_t i = 0; i < accounts.size(); ++i) {
                    if (accounts[i].getAgency().empty() && accounts[i].getAccountNumber().empty()) {
                        accounts[i] = newAccount;
                        std::cout << "Conta aberta com sucesso!" << std::endl;
                        displayMainMenu(); // Return to the main menu after opening the account
                    }
                }
            } else {
                displayMainMenu(); // Return to the main menu
            }
            // Proceed with account opening for the found person
        } else {
            std::cout << "Pessoa não encontrada." << std::endl;
            std::cout << "Deseja tentar novamente? (s/n): ";
            char retryChoice;
            std::cin >> retryChoice;
            if (retryChoice == 's' || retryChoice == 'S') {
                displayOpenAccountMenu(); // Call the menu again for another search
            } else {
                displayMainMenu(); // Return to the main menu
            }
        }

    } else if (searchOption == 2) {
        std::string searchName;
        std::cout << "Digite o nome ou o sobrenome da pessoa: ";
        std::cin >> searchName;

        Person foundPerson = findPersonByName(searchName);

        if (!foundPerson.getFirstName().empty() || !foundPerson.getLastName().empty()) {
            std::cout << "Pessoa encontrada!" << std::endl;
            std::cout << foundPerson.returnPrettyId() << std::endl;
            std::cout << foundPerson.returnPrettyName() << std::endl;
            std::cout << foundPerson.returnPrettyPhoneNumbers() << std::endl;
            std::cout << "Deseja abrir uma conta para esta pessoa? (s/n): ";

            char openAccountChoice;
            std::cin >> openAccountChoice;
            if (openAccountChoice == 's' || openAccountChoice == 'S') {
                // Proceed with account opening for the found person
                std::string agency, accountNumber;
                double initialBalance;

                std::cout << "Digite o número da agência: ";
                std::cin >> agency;
                std::cout << "Digite o número da conta: ";
                std::cin >> accountNumber;
                std::cout << "Digite o saldo inicial: ";
                std::cin >> initialBalance;

                Account newAccount(agency, accountNumber, initialBalance, foundPerson);
                // Store the new account in the array
                for (std::size_t i = 0; i < accounts.size(); ++i) {
                    if (accounts[i].getAgency().empty() && accounts[i].getAccountNumber().empty()) {
                        accounts[i] = newAccount;
                        std::cout << "Conta aberta com sucesso!" << std::endl;
                        displayMainMenu(); // Return to the main menu after opening the account
                    }
                }
                // Proceed with account opening for the found person
            } else {
                displayMainMenu(); // Return to the main menu
            }
        } else {
            std::cout << "Pessoa não encontrada." << std::endl;
            std::cout << "Deseja tentar novamente? (s/n): ";
            char retryChoice;
            std::cin >> retryChoice;
            if (retryChoice == 's' || retryChoice == 'S') {
                displayOpenAccountMenu(); // Call the menu again for another search
            } else {
                displayMainMenu(); // Return to the main menu
            }
        }
    } else {
        std::cout << "Opção inválida. Retornando ao menu principal." << std::endl;
    }
}


void Menu::resolveMenuOption(int option) {
    switch (static_cast<MenuOption>(option)) {
        case MenuOption::RegisterPerson:
            displayAddPersonMenu();
            break;
        case MenuOption::SearchPerson:
            displaySearchPersonInfosMenu();
            break;
        case MenuOption::OpenAccount:
            displayOpenAccountMenu();
            break;
        case MenuOption::Deposit:
            // Implement deposit functionality
            break;
        case MenuOption::Withdraw:
            // Implement withdraw functionality
            break;
        case MenuOption::CheckBalance:
            // Implement check balance functionality
            break;
        case MenuOption::ViewStatement:
            // Implement view statement functionality
            break;
        case MenuOption::Exit:
            std::cout << "Saindo do programa..." << std::endl;
            exit(0);
        default:
            std::cout << "Opção inválida. Tente novamente." << std::endl;
    }
}


void Menu::readMenuOption(){
    int option;
    std::cin >> option;
    resolveMenuOption(option);
}