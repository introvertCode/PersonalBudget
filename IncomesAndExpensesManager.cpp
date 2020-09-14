#include "IncomesAndExpensesManager.h"

void IncomeAndExpenseManager::addNew()
{
    Date date;
    char choice = {0};
    char confirmation = {0};
    string category = "";
    int Date = 0;
    long double amount = 0.00;
    int operationDate = 0;

    cout << "Category: ";
    cin >> category;

    amount = getAmount();

    cout << "With Today's date? (y/n) ";

    choice = getch();
    if (choice == 'y' || choice == 'Y')
    {
       operationDate = date.getTodaysDateAsOneInt();
    }
    else operationDate = date.addDate();

    cout << endl << "Confirm with y key OR abort with any key: ";
    confirmation = getch();

    if (confirmation == 'y' || confirmation == 'Y')
    {
        addToVectorAndFile(operationDate, amount, category);
        cout << endl <<"added successfully!" << endl;
        system("pause");
        return;
    }
    else
    {
        cout << endl << "Adding aborted." << endl;
        system("pause");
        return;
    }
}

long double IncomeAndExpenseManager::getAmount()
{
    long double amount;
    string userTypedAmount = "";
    bool isDataCorrect = true;
    int amountOfCommasOrDots = 0;

    do
    {
        isDataCorrect = true;
        userTypedAmount = "";
        amountOfCommasOrDots = 0;

        cout << "Amount: ";
        cin.sync();
        getline(cin,userTypedAmount);

        for (int i = 0; i < userTypedAmount.length(); i++)
        {


            if(userTypedAmount[0] == ',' || userTypedAmount[0] == '.')
            {
                cout << "wrong value, try again" << endl << endl;
                isDataCorrect = false;
                break;
            }

            if(userTypedAmount[userTypedAmount.length()-1] == ',' || userTypedAmount[userTypedAmount.length()-1] == '.')
            {
                cout << "wrong value, try again" << endl << endl;
                isDataCorrect = false;
                break;
            }

            if(userTypedAmount[i] == ',' || userTypedAmount[i] == '.')
            {
                userTypedAmount[i] = '.';
                amountOfCommasOrDots++;
            }

            if((userTypedAmount[i] > '9' || userTypedAmount[i] < '0') && userTypedAmount[i] != '.')
            {
                cout << "wrong value, try again" << endl << endl;
                isDataCorrect = false;
                break;
            }

            if (amountOfCommasOrDots > 1)
            {
                cout << "wrong value, try again" << endl << endl;
                isDataCorrect = false;
                break;
            }
            if (userTypedAmount[i] == '.')
            {
                if(userTypedAmount.length() > (i + 3))
                {
                cout << "wrong value, try again" << endl << endl;
                isDataCorrect = false;
                break;
                }
            }
        }
    }
    while(isDataCorrect == false);

    amount = atof(userTypedAmount.c_str());
    return amount;
}
