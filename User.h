#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User
{
    int id;
    string name;
    string secondName;
    string login;
    string password;

public:
    int getId();
    string getName();
    string getSecondName();
    string getPassword();
    string getLogin();

    void setId(int);
    void setName(string);
    void setSecondName(string);
    void setPassword(string);
    void setLogin(string);
};

#endif
