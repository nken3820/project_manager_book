#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <fstream>
#include "../include/upfile.h"

using namespace std;

class menu
{
private:
    vector<booker> list_booker_;
    vector<admin> list_admin_;
    vector<book> list_book_;
    vector<sell_book> list_book_sell;

public:
    void menu_Run_app();
    void menu_log_in();
    void menu_sign_up();
    void menu_loading(string str);

public:
    void menu_muon_Sach(booker *booker_);
    void menu_tra_sach(booker *booker_);
    void menu_mua_sach(booker *booker_);
    void menu_ban_sach(booker *booker_);

public:
    void menu_xem_thong_tin(booker *booker_);
    void menu_thay_doi_mk(booker *booker);
    void menu_danh_sach(booker *booker);
    void menu_nap_tien(booker *booker_);
    void list_muon(booker *booker_);
    void list_tra(booker *booker_);
    void list_mua(booker *booker_);
    void list_ban(booker *booker_);

public:
    void menu_of_user(booker *booker_);
    void menu_of_admin(admin *admin_);

public:
    menu(/* args */);
    ~menu();
};

#endif