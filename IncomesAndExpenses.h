#ifndef INCOMESANDEXPENSES_H
#define INCOMESANDEXPENSES_H

#include <iostream>

using namespace std;

class IncomesAndExpenses
{
    int userId;
    int id;
    int date;
    long double amount;
    string type;

public:
    int getUserId();
    int getId();
    int getDate()const;
    long double getAmount();
    string getType();

    void setUserId(int);
    void setId(int);
    void setDate(int);
    void setAmount(long double);
    void setType(string);

};

#endif
