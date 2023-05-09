#include "../include/upfile.h"

void upFILE(string str, vector<booker> list_booker)
{
    ofstream input_FILE;
    input_FILE.open(str);
    input_FILE << "Tai khoan"
               << " , "
               << "Mat khau"
               << " , "
               << "type" << endl;
    for (int i = 0; i < list_booker.size(); i++)
    {
        input_FILE << list_booker[i].get_account().tk_ << ","
                   << list_booker[i].get_account().mk_ << ","
                   << list_booker[i].type_ << endl;
    }
    input_FILE.close();
}

void readFIle(string str, vector<book> &list_book)
{
    string line;
    book book_ = book();
    fstream out_put;
    out_put.open(str);
    if (!out_put.is_open())
    {
        cout << "could not open the file" << endl;
        return;
    }
    while (getline(out_put, line))
    {
        stringProcessing(line, list_book);
    }
}

void stringProcessing(string str, vector<book> &list_book)
{
    book book_;
    while (str.size() > 0)
    {
        string input;
        book_ = book();
        int index = count(str) - 2;
        book_.book_name_ = str.substr(0, index);
        book_.id_ = str.substr(index + 4, str.size());

        list_book.push_back(book_);

        if (count(str) != -1)
        {
            return;
        }
    }
}

int count(string str)
{
    int result;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ',')
        {
            return i;
        }
    }
    return -1;
}

int convert(string str)
{
    stringstream str_num(str);
    int x = 0;
    str_num >> x;
    return x;
}

void clearFile(string str)
{
    ofstream input_FILE(str, ios::out);
    input_FILE.close();

    input_FILE.open(str, ios::out | ios::trunc);
    input_FILE.close();
}
