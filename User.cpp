#include "User.h"

using namespace std;

int User::getId()
{
    return id;
}

string User::getLogin()
{
    return login;
}

string User::getPassword()
{
    return password;
}

string User::getSecondName()
{
    return secondName;
}

string User::getName()
{
    return name;
}

void User::setId(int newId)
{
    id = newId;
}

void User::setName(string newName)
{
    name = newName;
}

void User::setSecondName(string newSecondName)
{
    secondName = newSecondName;
}

void User::setPassword(string newPassword)
{
    password = newPassword;
}

void User::setLogin(string newLogin)
{
    login = newLogin;
}

