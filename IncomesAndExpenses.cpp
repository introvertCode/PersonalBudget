#include "IncomesAndExpenses.h"

int IncomesAndExpenses::getUserId()
{
    return userId;
}

int IncomesAndExpenses::getId()
{
    return id;
}

int IncomesAndExpenses::getDate() const
{
    return date;
}
long double IncomesAndExpenses::getAmount()
{
    return amount;
}

string IncomesAndExpenses::getType()
{
    return type;
}

void IncomesAndExpenses::setUserId(int newUserId)
{
    userId = newUserId;
}

void IncomesAndExpenses::setId(int newId)
{
    id = newId;
}

void IncomesAndExpenses::setDate(int newDate)
{
    date = newDate;
}

void IncomesAndExpenses::setAmount(long double newAmount)
{
    amount = newAmount;
}

void IncomesAndExpenses::setType(string newType)
{
    type = newType;
}
