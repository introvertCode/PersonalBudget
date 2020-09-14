#include "IncomeManager.h"

void IncomeManager::addToVectorAndFile(int date, long double amount, string type)
{
    Income income;

    income.setUserId(LOGGED_USER_ID);
    income.setId(lastId + 1);
    income.setAmount(amount);
    income.setDate(date);
    income.setType(type);

    incomes.push_back(income);
    fileWithIncomes.addToFile(income);
    lastId++;

    return;
}

long double IncomeManager::showIncomesFromCurrentMonth()
{
    long double sum = 0.00;
    sum = showBalanceFromCurrentMonth(sortVector(incomes));
    return sum;
}

long double IncomeManager::showIncomesFromLastMonth()
{
    long double sum = 0.00;
    sum = showBalanceFromLastMonth(sortVector(incomes));
    return sum;
}

long double IncomeManager::showIncomesFromSelectedPeriod(int firstUserDate, int secondUserDate)
{
    long double sum = 0.00;
    sum = showBalanceFromSelectedPeriod(sortVector(incomes), firstUserDate, secondUserDate);
    return sum;
}

void IncomeManager::clearVector()
{
    incomes.clear();
    return;
}
