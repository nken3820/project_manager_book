#include "../include/object.h"

user::user(/* args */)
{
    account_.tk_ = "";
    account_.mk_ = "";
    name_ = "";
    type_ = "";
}

user::~user()
{
}

book::book(/* args */)
{
    book_name_ = "";
    id_ = "";
}

book::book(string str)
{
    this->book_name_ = str;
}

book::~book()
{
}

sell_book::sell_book(/* args */)
{
    book();
    monney_ = "";
    sell_nameBooker_ = "";
}

sell_book::~sell_book()
{
}

booker::booker(/* args */)
{
    user();
    monney_ = 10000;
}

booker::~booker()
{
}

void booker::muonsach(book *book_)
{
    this->list_book_.push_back(*book_);
}

void booker::trasach(int *index)
{
    this->list_book_.erase(this->list_book_.begin() + *index);
}

void booker::muasach(int *monney)
{
    this->monney_ = monney_ - *monney;
}

void booker::bansach(int *monney)
{
    this->monney_ = monney_ + *monney;
}

admin::admin(/* args */)
{
    user();
}

admin::~admin()
{
}
