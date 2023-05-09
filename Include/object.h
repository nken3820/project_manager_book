#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class book
{
public:
    string book_name_;
    string id_;

public:
    book();
    book(string str);
    ~book();
};

class sell_book : public book
{
public:
    string monney_;
    string sell_nameBooker_;

public:
    sell_book(/* args */);
    ~sell_book();
};

struct account
{
    string tk_;
    string mk_;
};

class user
{
protected:
    account account_;

public:
    string name_;
    string type_;

public:
    void set_account(string tk, string mk)
    {
        this->account_.tk_ = tk;
        this->account_.mk_ = mk;
    }
    account get_account()
    {
        return this->account_;
    }

public:
    user(/* args */);
    ~user();
};

class booker : public user
{
private:
    vector<book> list_book_;
    vector<book> list_book_get;
    vector<sell_book> list_sell_book_;
    vector<book> list_book_puy_;
    int monney_;

public:
    vector<book> getBook_()
    {
        return this->list_book_;
    }
    void Set_book(vector<book> list_book)
    {
        this->list_book_ = list_book;
    }

    vector<book> get_getBook_()
    {
        return this->list_book_get;
    }
    void Set_get_book(vector<book> list_book)
    {
        this->list_book_get = list_book;
    }

    vector<sell_book> get_sellBook_()
    {
        return this->list_sell_book_;
    }
    void Set_sell_book(vector<sell_book> list_book)
    {
        this->list_sell_book_ = list_book;
    }

    vector<book> get_puyBook_()
    {
        return this->list_book_puy_;
    }
    void Set_puy_book(vector<book> list_book)
    {
        this->list_book_puy_ = list_book;
    }

    int Get_monney()
    {
        return this->monney_;
    }
    void Set_monney(int monney)
    {
        this->monney_ = monney;
    }

public:
    friend ostream &operator<<(ostream &os, booker &booker_)
    {
        os << "tên người dùng: " << booker_.name_ << endl;
        os << "tên đăng nhập: " << booker_.get_account().tk_ << endl;
        os << "mật khẩu: " << booker_.get_account().mk_ << endl;
        os << "số dư khả dụng: " << booker_.Get_monney() << endl
           << endl;
        return os;
    }

public:
    void muonsach(book *book_);
    void trasach(int *index);
    void muasach(int *monney);
    void bansach(int *monney);

public:
    booker(/* args */);
    ~booker();
};

class admin : public user
{
private:
    /* data */
public:
    admin(/* args */);
    ~admin();
};

#endif