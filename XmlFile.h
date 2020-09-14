#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>
#include <vector>
#include "Markup.h"
#include "IncomesAndExpenses.h"
#include "Date.h"
#include "Expense.h"
#include "Income.h"

using namespace std;

class XmlFile
{
    int lastId;
    string const FILE_PATH;
    string const ELEMENT;

public:
     XmlFile(string filePath, string element):FILE_PATH(filePath), ELEMENT(element){
     }
     template <class T> vector<T> loadFromFile(const int&);
     void addToFile(IncomesAndExpenses);
     int getLastId();
};

template <class T> vector<T> XmlFile::loadFromFile(const int &loggedUserId)
{
    vector<T> vectorWithIncomesOrExpenses;
    CMarkup xmlFile;
    Date date;
    lastId = 0;

    bool ifFileExists = xmlFile.Load(FILE_PATH);

    if (ifFileExists == false)
    {
     return vectorWithIncomesOrExpenses;
    }

    xmlFile.ResetPos();
    xmlFile.FindElem();
    xmlFile.IntoElem();

    while(xmlFile.FindElem(ELEMENT))
    {
        T incomeOrExpense;

        xmlFile.IntoElem();
        xmlFile.FindElem("userId");
        incomeOrExpense.setUserId(stoi(xmlFile.GetData()));
        xmlFile.FindElem("Id");
        incomeOrExpense.setId(stoi(xmlFile.GetData()));
        lastId = incomeOrExpense.getId();
        xmlFile.FindElem("date");
        incomeOrExpense.setDate(date.convertStringDateToInt(xmlFile.GetData()));
        xmlFile.FindElem("amount");
        incomeOrExpense.setAmount(atof(xmlFile.GetData().c_str()));
        xmlFile.FindElem("type");
        incomeOrExpense.setType(xmlFile.GetData());

        if ( incomeOrExpense.getUserId() == loggedUserId)
        {
            vectorWithIncomesOrExpenses.push_back(incomeOrExpense);
        }
        xmlFile.OutOfElem();
    }

    return vectorWithIncomesOrExpenses;
}

#endif
