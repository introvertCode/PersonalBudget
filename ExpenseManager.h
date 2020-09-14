#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include "IncomesAndExpensesManager.h"
#include "FileWithExpenses.h"

class ExpenseManager : public IncomeAndExpenseManager
{
    vector<Expense> expenses;
    const int LOGGED_USER_ID;
    FileWithExpenses fileWithExpenses;

    void addToVectorAndFile(int, long double, string);

public:
    ExpenseManager(int loggedUserId):LOGGED_USER_ID(loggedUserId)
    {
        expenses = fileWithExpenses.template loadFromFile<Expense>(LOGGED_USER_ID);
        lastId = fileWithExpenses.getLastId();
    };
    void clearVector();
    long double showExpensesFromCurrentMonth();
    long double showExpensesFromLastMonth();
    long double showExpensesFromSelectedPeriod(int, int);
};

#endif
