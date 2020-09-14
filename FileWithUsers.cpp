#include "FileWithUsers.h"

void FileWithUsers::addUserToFile(User user)
{
    CMarkup xmlFile;
    bool ifExists = xmlFile.Load(FILE_PATH);
    if (ifExists == false)
    {
        xmlFile.AddElem("Users");
        xmlFile.IntoElem();
        //cout << "File was created!" << endl;
    }
    xmlFile.FindElem();
    xmlFile.IntoElem();
    xmlFile.AddElem("User");
    xmlFile.IntoElem();
    xmlFile.AddElem("ID", user.getId());
    xmlFile.AddElem("name", user.getName());
    xmlFile.AddElem("second name", user.getSecondName());
    xmlFile.AddElem("login", user.getLogin());
    xmlFile.AddElem("password", user.getPassword());
    xmlFile.Save("G:\\kod c++\\personalBudgetApp\\users.xml");
}

vector<User> FileWithUsers::loadUsersFromFile()
{
    vector<User> users;
    CMarkup xmlFile;
    bool ifFileExists = xmlFile.Load(FILE_PATH);
    if (ifFileExists == false)
    {
     return users;
    }
    xmlFile.ResetPos();

    xmlFile.FindElem();
    xmlFile.IntoElem();

    while(xmlFile.FindElem("User"))
    {
        //cout << "iteracja" << endl;
        User user;
        xmlFile.IntoElem();
        xmlFile.FindElem("ID");
        user.setId(stoi(xmlFile.GetData()));
        xmlFile.FindElem("name");
        user.setName(xmlFile.GetData());
        xmlFile.FindElem("second name");
        user.setSecondName(xmlFile.GetData());
        xmlFile.FindElem("login");
        user.setLogin(xmlFile.GetData());
        xmlFile.FindElem("password");
        user.setPassword(xmlFile.GetData());
        users.push_back(user);
        xmlFile.OutOfElem();
    }

    return users;
}

void FileWithUsers::changeUserPasswordInFile(string newPassword, int loggedUserId)
{
    CMarkup xmlFile;

    system("pause");
    bool ifExists = xmlFile.Load(FILE_PATH);


    if (ifExists == false)
    {
        cout << "Failed to load file!" << endl;
        system("pause");
        return;
    }
     xmlFile.FindElem();
     xmlFile.IntoElem();
     while(xmlFile.FindElem("User"))
     {
         xmlFile.IntoElem();
         xmlFile.FindElem("ID");
         if (loggedUserId == stoi(xmlFile.GetData()))
             {
                 xmlFile.FindElem("password");
                 xmlFile.RemoveElem();
                 xmlFile.AddElem("password", newPassword);
                 xmlFile.Save("G:\\kod c++\\personalBudgetApp\\users.xml");
                 return;
             }
     }

}
