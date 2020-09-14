#include "XmlFile.h"

void XmlFile::addToFile(IncomesAndExpenses incomeAndExpense)
{
    CMarkup xmlFile;
    Date date;
    string header = ELEMENT + "s";
    bool ifExists = xmlFile.Load(FILE_PATH);
    if (!ifExists)
    {
        xmlFile.AddElem(header);
        xmlFile.IntoElem();
        //cout << endl << "File was created!" << endl;
    }
    xmlFile.FindElem();
    xmlFile.IntoElem();
    xmlFile.AddElem(ELEMENT);
    xmlFile.IntoElem();
    xmlFile.AddElem("userId", incomeAndExpense.getUserId());
    xmlFile.AddElem("Id", incomeAndExpense.getId());
    xmlFile.AddElem("date", date.getDateFormattedAsString(incomeAndExpense.getDate()));
    xmlFile.AddElem("amount", to_string(incomeAndExpense.getAmount()));
    xmlFile.AddElem("type", incomeAndExpense.getType());
    xmlFile.Save(FILE_PATH);

    return;
}

int XmlFile::getLastId()
{
    return lastId;
}
