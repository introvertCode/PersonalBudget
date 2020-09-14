#include "PersonalBudget.h"

void PersonalBudget::logIn()
{
    system("cls");
    userManager.userLogIn();
    if (userManager.isUserLoggedIn())
    {
        incomeManager = new IncomeManager(userManager.getLoggedUserId());
        expenseManager = new ExpenseManager(userManager.getLoggedUserId());
        return;
    }
    else return;
}

void PersonalBudget::registerNewUser()
{
    userManager.userRegister();
    return;
}

void PersonalBudget::showMainMenu()
{
    system("cls");
    cout <<".:Budget App Main Menu:."<< endl;
    cout << "1. Register new user" << endl;
    cout << "2. Log in" << endl;
    cout << "3. Exit" << endl;

    return;
}

char PersonalBudget::getCharacter()
{
    char choice = {0};

        string enteredText = "";
        cout << "Your choice: ";
        cin >> enteredText;

        if (enteredText.length() == 1)
        {
            choice = enteredText[0];
            system("cls");
            return choice;
        }

        else
            {
            system("cls");
            return choice;
    }

}

void PersonalBudget::showUserMenu()
{
    system("cls");
    cout << "    .:Menu:."<< endl;
    cout << "1. Add Income" << endl;
    cout << "2. Add Expense" << endl;
    cout << "3. Current month balance" << endl;
    cout << "4. Previous month balance" << endl;
    cout << "5. Balance from selected period" << endl;
    cout << "6. Change password" << endl;
    cout << "7. LogOut" << endl;


return;
}

void PersonalBudget::addIncome()
{
    cout << ".:Add Income" << endl;
    incomeManager -> addNew();
    return;
}

void PersonalBudget::currentMonthBalance()
{
    cout << ".:Current Month Balance:." << endl;
    long double sumOfIncomes = 0;
    long double sumOfExpenses = 0;

    cout << endl << "Incomes: " << endl;
    sumOfIncomes = incomeManager -> showIncomesFromCurrentMonth();
    cout << endl <<"Expenses: " << endl;
    sumOfExpenses = expenseManager -> showExpensesFromCurrentMonth();

    showSumOfIncomesAndExpensesAndBalance(sumOfIncomes, sumOfExpenses);
    return;
}

void PersonalBudget::previousMonthBalance()
{
    cout << ".:Previous Month Balance:." << endl;
    long double sumOfIncomes = 0;
    long double sumOfExpenses = 0;

    cout << endl << "Incomes: " << endl;
    sumOfIncomes = incomeManager -> showIncomesFromLastMonth();
    cout << endl <<"Expenses: " << endl;
    sumOfExpenses = expenseManager -> showExpensesFromLastMonth();

    showSumOfIncomesAndExpensesAndBalance(sumOfIncomes, sumOfExpenses);
    return;
}

void PersonalBudget::selectedPeriodBalance()
{
    cout << ".:Selected Period Balance:." << endl << endl;
    Date date;
    int firstUserDate = 0;
    int secondUserDate = 0;
    cout << "Write first date, than second." << endl;
    firstUserDate = date.addDate();
    secondUserDate = date.addDate();

    long double sumOfIncomes = 0;
    long double sumOfExpenses = 0;

    cout << endl << "Incomes: " << endl;
    sumOfIncomes = incomeManager -> showIncomesFromSelectedPeriod(firstUserDate, secondUserDate);
    cout << endl << "Expenses: " << endl;
    sumOfExpenses = expenseManager -> showExpensesFromSelectedPeriod(firstUserDate, secondUserDate);

    showSumOfIncomesAndExpensesAndBalance(sumOfIncomes, sumOfExpenses);
    return;
}

void PersonalBudget::changeUserPassword()
{
    userManager.changePassword();
    return;
}

void PersonalBudget::logOut()
{
    incomeManager -> clearVector();
    expenseManager -> clearVector();
    userManager.userLogOut();
    return;
}

void PersonalBudget::addExpense()
{
    system("cls");
    cout << ".:Add Expense:." << endl;
    expenseManager -> addNew();
    return;
}

int PersonalBudget::getIdOfLoggedUser()
{
    return userManager.getLoggedUserId();
}


void PersonalBudget::showSumOfIncomesAndExpensesAndBalance(long double sumOfIncomes, long double sumOfExpenses)
{
    cout.precision(2);
    long double balance = sumOfIncomes - sumOfExpenses;
    cout << endl << "Sum of incomes:  " << fixed << sumOfIncomes << endl;
    cout << "Sum of Expenses: " << fixed << sumOfExpenses << endl;
    cout << endl << "     balance: " << fixed << balance << endl << endl;
}
