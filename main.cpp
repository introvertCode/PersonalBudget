#include <iostream>
#include "PersonalBudget.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget;
    char choice = {0};
    while(true)
    {
        while(personalBudget.getIdOfLoggedUser() == 0)
        {
            personalBudget.showMainMenu();
            choice = personalBudget.getCharacter();
            if (choice == '1')
            {
                personalBudget.registerNewUser();
            }
            else if (choice == '2')
            {
                personalBudget.logIn();
            }
            else if (choice == '3')
            {
                return 0;
            }
            else
            {
                cout << "there is no such option, try again" << endl << endl;
                system("pause");
            }
        }

        do
        {
            personalBudget.showUserMenu();
            choice = personalBudget.getCharacter();
            if (choice == '1')
            {
                personalBudget.addIncome();
            }
            else if (choice == '2')
            {
                personalBudget.addExpense();
            }
            else if (choice == '3')
            {
                personalBudget.currentMonthBalance();
                system("pause");
            }
            else if (choice == '4')
            {
                personalBudget.previousMonthBalance();
                system("pause");
            }
            else if (choice == '5')
            {
                personalBudget.selectedPeriodBalance();
                system("pause");
            }
            else if (choice == '6')
            {
               personalBudget.changeUserPassword();
            }
            else if (choice == '7')
            {
                personalBudget.logOut();
            }
        }
        while (personalBudget.getIdOfLoggedUser() != 0);

    }

}
