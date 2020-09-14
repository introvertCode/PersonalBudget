#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include <cstdlib>
#include "UserManager.h"
#include "IncomeManager.h"
#include "ExpenseManager.h"

using namespace std;

class PersonalBudget
{
    UserManager userManager;
    IncomeManager *incomeManager;
    ExpenseManager *expenseManager;

    void showSumOfIncomesAndExpensesAndBalance(long double, long double);

public:
    PersonalBudget (){
        userManager.loadFromFile();
        expenseManager = NULL;
        incomeManager = NULL;};

    ~PersonalBudget (){
    delete expenseManager;
    delete incomeManager;
    expenseManager = NULL;
    incomeManager = NULL;
    }

    void registerNewUser();
    void logIn();
    void showMainMenu();
    char getCharacter();
    void showUserMenu();
    void addIncome();
    void currentMonthBalance();
    void previousMonthBalance();
    void selectedPeriodBalance();
    void changeUserPassword();
    void logOut();
    void addExpense();
    int getIdOfLoggedUser();
};



#endif
