#ifndef APP_H
#define APP_H

#include <iostream>
#include <string>
#include "../include/menu.h"

using namespace std;

class app
{
private:
    menu menu_;
    vector<book> list_book_;

public:
    vector<book> get_list_book()
    {
        return list_book_;
    }

public:
    app(/* args */);
    ~app();

public:
    void Run();
    void loading(string str);
};

#endif