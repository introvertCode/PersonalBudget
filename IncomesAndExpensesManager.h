#ifndef INCOMEANDEXPENSEMANAGER_H
#define INCOMEANDEXPENSEMANAGER_H

#include <iostream>
#include <vector>
#include "Income.h"
#include "Expense.h"
#include "Date.h"
#include <cstdlib>
#include <conio.h>
#include <stdlib.h>
#include <algorithm>
#include <iomanip>

using namespace std;

class IncomeAndExpenseManager
{
    long double getAmount();
    virtual void addToVectorAndFile(int, long double, string) = 0;
    template <class T> void showRecords(T);

    protected:
    int lastId;
    template <class T> long double showBalanceFromCurrentMonth(vector<T>);
    template <class T> vector<T> sortVector(vector<T>);
    template <class T> long double showBalanceFromLastMonth(vector<T>);
    template <class T> long double showBalanceFromSelectedPeriod(vector<T>, int, int);

    public:
    IncomeAndExpenseManager(){};
    void addNew();
    long double showIncomesFromCurrentMonth();
    long double showIncomesFromSelectedPeriod();
    virtual ~IncomeAndExpenseManager(){};
};



template <class T> vector<T> IncomeAndExpenseManager::sortVector(vector<T> notSortedVector)
{
    vector<T> sortedVector = notSortedVector;
    sort(sortedVector.begin(), sortedVector.end(), [](const T &lhs, const T &rhs)
    {
        return lhs.getDate() > rhs.getDate();
    });
    return sortedVector;
}

template <class T> long double IncomeAndExpenseManager::showBalanceFromCurrentMonth(vector<T> sortedVector)
{
    Date date;
    T incomeOrExpense;
    long double sum = 0.00;
    int firstDayOfMonth = date.getFirstDayOfCurrentMonth();

    for (int i = 0; i < sortedVector.size(); i++)
    {

        if(sortedVector[i].getDate() >= firstDayOfMonth)
        {
            incomeOrExpense = sortedVector[i];
            showRecords(incomeOrExpense);
            sum += sortedVector[i].getAmount();
        }
    }
    return sum;
}

template <class T> long double IncomeAndExpenseManager::showBalanceFromLastMonth(vector<T> sortedVector)
{
    Date date;
    T incomeOrExpense;
    long double sum = 0.00;
    int beginDate = date.getFirstDayOfLastMonth();
    int endDate = date.getLastDayOfLastMonth();

    for (int i = 0; i < sortedVector.size(); i++)
    {

        if(sortedVector[i].getDate() >= beginDate && sortedVector[i].getDate() <= endDate)
        {
            incomeOrExpense = sortedVector[i];
            showRecords(incomeOrExpense);
            sum += sortedVector[i].getAmount();
        }
    }
    return sum;
}

template <class T> long double IncomeAndExpenseManager::showBalanceFromSelectedPeriod(vector<T> sortedVector, int firstUserDate, int secondUserDate)
{
    T incomeOrExpense;
    long double sum = 0.00;

    for (int i = 0; i < sortedVector.size(); i++)
    {
        if(sortedVector[i].getDate() >= firstUserDate && sortedVector[i].getDate() <= secondUserDate)
        {
            incomeOrExpense = sortedVector[i];
            showRecords(incomeOrExpense);
            sum += sortedVector[i].getAmount();
        }
    }
    return sum;
}

 template <class T> void IncomeAndExpenseManager::showRecords(T incomeOrExpense)
 {
     Date date;
     cout.precision(2);
     cout << setw(15) << left << date.getDateFormattedAsString(incomeOrExpense.getDate()) << setw(10) << left << incomeOrExpense.getType() << setw(10) << right << fixed << incomeOrExpense.getAmount() << endl;
 }


#endif
