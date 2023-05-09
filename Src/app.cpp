#include "../include/app.h"

app::app(/* args */)
{
}

app::~app()
{
}

void app::Run()
{
    loading("../Database/book.csv");
    menu_.menu_Run_app();
}

void app::loading(string str)
{
    menu_.menu_loading(str);
}