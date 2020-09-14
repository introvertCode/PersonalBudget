#include "ExpenseManager.h"

void ExpenseManager::addToVectorAndFile(int date, long double amount, string type)
{
    Expense expense;

    expense.setUserId(LOGGED_USER_ID);
    expense.setId(lastId + 1);
    expense.setAmount(amount);
    expense.setDate(date);
    expense.setType(type);

    expenses.push_back(expense);
    fileWithExpenses.addToFile(expense);
    lastId++;

    return;
}

long double ExpenseManager::showExpensesFromCurrentMonth()
{
    long double sum = 0.00;
    sum = showBalanceFromCurrentMonth(sortVector(expenses));
    return sum;
}

long double ExpenseManager::showExpensesFromLastMonth()
{
    long double sum = 0.00;
    sum = showBalanceFromLastMonth(sortVector(expenses));
    return sum;
}

long double ExpenseManager::showExpensesFromSelectedPeriod(int firstUserDate, int secondUserDate)
{
    long double sum = 0.00;
    sum = showBalanceFromSelectedPeriod(sortVector(expenses), firstUserDate, secondUserDate);
    return sum;
}

void ExpenseManager::clearVector()
{
    expenses.clear();
    return;
}

