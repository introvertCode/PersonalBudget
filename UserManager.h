#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>

#include "User.h"
#include "FileWithUsers.h"

using namespace std;

class UserManager
{
    vector<User> users;
    int idOfLoggedUser;

    bool isLoginFreeToUse(string);
    User setNewUserData();
    int setUserId();
    string loadLine();

public:
    void userRegister();
    void loadFromFile();
    void showAllUsers();
    int userLogIn();
    bool isUserLoggedIn();
    void changePassword();
    int getLoggedUserId();
    void userLogOut();
};

#endif
