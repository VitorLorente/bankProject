#ifndef MENU_HPP
#define MENU_HPP

#include <stdexcept>
#include <string>

enum class MenuOption : int {
    RegisterPerson = 1,
    SearchPerson = 2,
    OpenAccount = 3,
    Deposit = 4,
    Withdraw = 5,
    CheckBalance = 6,
    ViewStatement = 7,
    Exit = 0
};

inline std::string menuOptionLabel(MenuOption option) {
    switch (option) {
        case MenuOption::RegisterPerson:
            return "Cadastrar pessoa";
        case MenuOption::SearchPerson:
            return "Consultar pessoa";
        case MenuOption::OpenAccount:
            return "Abrir conta";
        case MenuOption::Deposit:
            return "Realizar depósito";
        case MenuOption::Withdraw:
            return "Realizar saque";
        case MenuOption::CheckBalance:
            return "Consultar saldo";
        case MenuOption::ViewStatement:
            return "Consultar extrato";
        case MenuOption::Exit:
            return "Sair";
    }

    throw std::invalid_argument("Opcao de menu invalida");
}

class Menu {
    public:
        Menu();
        ~Menu();

        void displayMainMenu();
        void displayAddPersonMenu();
        void displaySearchPersonInfosMenu();
        void displayOpenAccountMenu();
        void readMenuOption();
        void resolveMenuOption(int option);

};
#endif // MENU_HPP