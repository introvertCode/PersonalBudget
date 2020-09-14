#include "UserManager.h"

void UserManager::loadFromFile()
{
    FileWithUsers fileWithUsers;
    users.clear();
    users = fileWithUsers.loadUsersFromFile();
    idOfLoggedUser = 0;
}

void UserManager::userRegister()
{
    User user = setNewUserData();
    FileWithUsers fileWithUsers;

    char choice = 'n';
    cout << "Add new user? (y/n)" << endl;
    cin >> choice;
    if (choice == 'y')
    {
        users.push_back(user);
        cout << "User added, you can log in now" << endl;
        fileWithUsers.addUserToFile(user);
        return;
    }
    cout << "User not added!" << endl;
    return;
}

User UserManager::setNewUserData()
{
    string name, secondName, login, password;
    User user;

    cout << "..::USER REGISTRATION::.." << endl;
    cout << "Your name: ";
    cin >> name;
    user.setName(name);
    cout << "Your surname: ";
    cin >> secondName;
    user.setSecondName(secondName);
    do
    {
        cout << "Login: ";
        cin >> login;

    }
    while(!isLoginFreeToUse(login));
    user.setLogin(login);
    cout << "Password: ";
    cin >> password;
    user.setPassword(password);
    user.setId(setUserId());

    return user;
}

bool UserManager::isLoginFreeToUse(string newLogin)
{
    vector<User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == newLogin)
        {
            cout << "This login already exists!" << endl;
            return false;
        }
        else
            itr++;
    }
    return true;
}

int UserManager::setUserId()
{
    if(users.empty() == true)
    {
        return 1;
    }
    else return users.back().getId()+1;
}

void UserManager::showAllUsers()
{
    for (int i = 0; i<users.size(); i++)
    {
        cout << users[i].getName() << endl;
    }
}

int UserManager::userLogIn()
{
    string login = "", password = "";
    int counter = 3;
    idOfLoggedUser = 0;

    cout << ".:LOG IN:." << endl;
    cout << "login: ";
    cin >> login;
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            while (counter > 0)
            {
                cout << endl <<counter << " probes left." << endl ;
                cout << "password: ";
                cin >> password;
                if (users[i].getPassword() == password)
                {
                    idOfLoggedUser = users[i].getId();
                    return idOfLoggedUser;
                }
                else
                {
                    cout << "Wrong password!" << endl;
                    counter--;
                }
                if (counter == 0)
                {
                    cout << "access denied!" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "There is no such user" << endl;
    return 0;
}

bool UserManager::isUserLoggedIn()
{
    if (idOfLoggedUser == 0) return false;
    else return true;
}

void UserManager::changePassword()
{
    FileWithUsers fileWithUsers;
    string newPassword;
    cout << ".:Change Password:." << endl;
    cout << "Type new password: ";
    cin >> newPassword;

    for(int i = 0; i < users.size(); i++)
    {
        if (users[i].getId() == idOfLoggedUser)
        {
            users[i].setPassword(newPassword);
        }
    }
    fileWithUsers.changeUserPasswordInFile(newPassword, idOfLoggedUser);
}

int UserManager::getLoggedUserId()
{
    return idOfLoggedUser;
}

void UserManager::userLogOut()
{
    idOfLoggedUser = 0;
    return;
}
