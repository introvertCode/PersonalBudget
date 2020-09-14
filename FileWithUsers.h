#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>

#include "Markup.h"
#include "User.h"

using namespace std;

class FileWithUsers{

    const string FILE_PATH;

public:
    FileWithUsers(string filePath = "users.xml"):FILE_PATH(filePath){
    }
    void addUserToFile(User);
    vector<User> loadUsersFromFile();
    void changeUserPasswordInFile(string, int);
};

#endif
