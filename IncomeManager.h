#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include "IncomesAndExpensesManager.h"
#include "FileWithIncomes.h"

class IncomeManager : public IncomeAndExpenseManager
{
    vector<Income> incomes;
    const int LOGGED_USER_ID;
    FileWithIncomes fileWithIncomes;

    void addToVectorAndFile(int, long double, string);

public:
    IncomeManager(int loggedUserId):LOGGED_USER_ID(loggedUserId)
    {
        incomes = fileWithIncomes.template loadFromFile<Income>(LOGGED_USER_ID);
        lastId = fileWithIncomes.getLastId();
    }

    void clearVector();
    long double showIncomesFromLastMonth();
    long double showIncomesFromCurrentMonth();
    long double showIncomesFromSelectedPeriod(int, int);



};




#endif
