#include "../include/menu.h"

menu::menu(/* args */)
{
}

menu::~menu()
{
}

// khởi chạy chương trình

void menu::menu_Run_app()
{
     system("cls");

     admin *admin_ = new admin();
     admin_->type_ = "admin";
     admin_->set_account("admin", "admin");
     list_admin_.push_back(*admin_);
     delete admin_;
     int select = 0;

     cout << endl
          << "Book_Management_System" << endl
          << endl;

     cout << "1.Logn In:" << endl
          << endl;
     cout << "2.sign Up:" << endl
          << endl;
     cout << "0.thoát:" << endl
          << endl;

     cout << "select: ";
     cin >> select;
     cin.ignore();
     if (select < 0 || select > 2)
     {
          cout << endl
               << "lựa chọn không hợp lệ, vui lòng chọn lại";
          Sleep(850);
          system("cls");
          return menu_Run_app();
     }
     else if (select >= 0 && select <= 2)
     {
          switch (select)
          {
          case 1:
               system("cls");
               return menu_log_in();
          case 2:
               system("cls");
               return menu_sign_up();
          case 0:
               clearFile("../Database/account.csv");
               exit(0);
          default:
               break;
          }
     }
}

void menu::menu_log_in()
{
     system("cls");

     cout << endl
          << "LOG IN" << endl
          << endl;

     string tk;
     string mk;

     cout << "user name: ";
     getline(cin, tk);
     cout << "password:  ";
     getline(cin, mk);

     if (tk.compare(list_admin_[0].get_account().tk_) == 0)
     {
          if (mk.compare(list_admin_[0].get_account().mk_) == 0)
          {
               cout << endl
                    << "đăng nhập thành công!";
               Sleep(800);
               system("cls");
               return menu_of_admin(&list_admin_[0]);
          }
     }

     for (int i = 0; i < list_booker_.size(); i++)
     {
          if (tk.compare(list_booker_[i].get_account().tk_) == 0)
          {
               if (mk.compare(list_booker_[i].get_account().mk_) == 0)
               {
                    cout << endl
                         << "đăng nhập thành công!";
                    Sleep(800);
                    system("cls");
                    return menu_of_user(&list_booker_[i]);
               }
          }
     }

     cout << endl
          << "tài khoản hoặc mật khẩu không hợp lệ!" << endl
          << "      vui lòng đăng nhập lại!";

     Sleep(900);
     system("cls");
     return menu_Run_app();
}

void menu::menu_sign_up()
{
     booker *booker_ = new booker();

     cout << endl
          << "SIGN UP " << endl
          << endl;

     booker_->type_ = "user";
     cout << "user name: ";
     getline(cin, booker_->name_);

     string password;
     cout << "password:  ";
     getline(cin, password);
     booker_->set_account(booker_->name_, password);

     cout << endl
          << "tạo tài khoản thành công!";

     list_booker_.push_back(*booker_);

     string file_path = "../Database/account.csv";
     upFILE(file_path, list_booker_);

     Sleep(900);
     system("cls");

     delete booker_;

     menu_Run_app();
}

void menu::menu_loading(string str)
{
     readFIle(str, list_book_);
}

// giao diện người dùng

void menu::menu_muon_Sach(booker *booker_)
{
     system("cls");
     cout << "THƯ VIỆN SÁCH" << endl
          << endl;
     for (int i = 0; i < list_book_.size(); ++i)
     {
          cout << "ID: " << list_book_[i].id_ << endl;
          cout << "TÊN SÁCH: " << list_book_[i].book_name_ << endl
               << endl;
     }

     int select;
     cout << endl
          << "nhập id để mua hoặc nhập 0 để thoát: ";
     cin >> select;
     cin.ignore();
     if (select == 0)
     {
          return;
     }
     else
     {
          book *result;
          for (int i = 0; i < list_book_.size(); ++i)
          {
               if (select - convert(list_book_[i].id_) == 0)
               {
                    result = &list_book_[i];
                    if (booker_->getBook_().size() == 0)
                    {
                         cout << endl
                              << "MƯỢN THÀNH CÔNG!";
                         Sleep(900);
                         return booker_->muonsach(result);
                    }
                    else if (booker_->getBook_().size() > 0)
                    {
                         for (int i = 0; i < booker_->getBook_().size(); ++i)
                         {
                              if (result->book_name_.compare(booker_->getBook_()[i].book_name_) == 0)
                              {
                                   cout << endl
                                        << "SÁCH ĐÃ ĐƯỢC MƯỢN TRƯỚC ĐÓ!";
                                   Sleep(900);
                                   return menu_muon_Sach(booker_);
                              }
                              else
                              {
                                   cout << endl
                                        << "MƯỢN THÀNH CÔNG!";
                                   Sleep(1000);
                                   return booker_->muonsach(result);
                              }
                         }
                    }
               }
          }
          cout << "LỰA CHỌN KHÔNG HỢP LỆ! " << endl;
          Sleep(900);
          return menu_muon_Sach(booker_);
     }
}

void menu::menu_tra_sach(booker *booker_)
{
     if (booker_->getBook_().size() > 0)
     {
          system("cls");
          int result;
          cout << "DANH SÁCH CÁC SÁCH ĐÃ MƯỢN" << endl
               << endl;
          for (int i = 0; i < booker_->getBook_().size(); i++)
          {
               cout << "ID: " << booker_->getBook_()[i].id_ << endl;
               cout << "TÊN SÁCH: " << booker_->getBook_()[i].book_name_ << endl
                    << endl;
          }

          int select = 0;
          cout << "nhập id: ";
          cin >> select;
          cin.ignore();

          for (int j = 0; j < list_book_.size(); ++j)
          {
               if (select - convert(booker_->getBook_()[j].id_) == 0)
               {
                    result = j;
                    cout << endl
                         << "TRẢ THÀNH CÔNG!";
                    Sleep(900);
                    vector<book> list_get_book_ = booker_->get_getBook_();

                    list_get_book_.push_back(booker_->getBook_()[j]);
                    booker_->Set_get_book(list_get_book_);

                    return booker_->trasach(&result);
               }
          }
          cout << "LỰA CHỌN KHÔNG HỢP LỆ! " << endl;
          Sleep(900);
          return menu_tra_sach(booker_);
     }
     else
     {
          cout << "DANH SÁCH MƯỢN TRỐNG!";
          Sleep(900);
          return menu_of_user(booker_);
     }
}

void menu::menu_mua_sach(booker *booker_)
{
     system("cls");
     cout << "THƯ VIỆN SÁCH ĐĂNG BÁN" << endl
          << endl;

     cout << "số dư tài khoản: " << booker_->Get_monney() << endl
          << endl;

     for (int i = 0; i < list_book_sell.size(); ++i)
     {
          if (list_book_sell[i].sell_nameBooker_.compare(booker_->name_) != 0)
          {
               cout << "ID: " << i + 1 << endl;
               cout << "TÊN SÁCH: " << list_book_sell[i].book_name_ << endl;
               cout << "Giá Tiền: " << list_book_sell[i].monney_ << endl;
               cout << "Người Bán: " << list_book_sell[i].sell_nameBooker_ << endl
                    << endl;
          }
          else
          {
               continue;
          }
     }

     int select;
     cout << endl
          << "nhập id: ";
     cin >> select;
     cin.ignore();

     book *result;
     for (int i = 0; i < list_book_sell.size(); ++i)
     {
          list_book_sell[i].id_ = "1";
          if (select - convert(list_book_sell[i].id_) + i == 0)
          {
               if (booker_->Get_monney() >= convert(list_book_sell[i].monney_))
               {
                    result = new book(list_book_sell[i].book_name_);
                    int monney = convert(list_book_sell[i].monney_);

                    vector<book> list_result_puy = booker_->get_puyBook_();

                    list_result_puy.push_back(*result);
                    booker_->Set_puy_book(list_result_puy);

                    cout << endl
                         << "MUA THÀNH CÔNG!";

                    list_book_sell.erase(list_book_sell.begin() + i);

                    booker_->muasach(&monney);

                    for (int j = 0; j < list_booker_.size(); ++j)
                    {
                         if (list_book_sell[i].sell_nameBooker_.compare(list_booker_[j].name_) == 0)
                         {
                              list_booker_[j].bansach(&monney);
                              break;
                         }
                    }

                    Sleep(900);
                    delete result;
               }
               else
               {
                    system("cls");
                    cout << "TÀI KHOẢN KHÔNG ĐỦ!" << endl
                         << endl;
                    cout << "1: nạp tiền:" << endl;
                    cout << "0: thoát:" << endl
                         << endl;

                    int select;
                    cout << "chọn: ";
                    cin >> select;
                    cin.ignore();
                    switch (select)
                    {
                    case 1:
                         menu_nap_tien(booker_);
                         return menu_mua_sach(booker_);
                    case 0:
                         return menu_of_user(booker_);
                    default:
                         break;
                    }
               }
          }
     }

     Sleep(900);
}

void menu::menu_ban_sach(booker *booker_)
{
     system("cls");

     sell_book *sell_book_ = new sell_book();

     cout << "THÊM SÁCH MUỐN BÁN: ";
     getline(cin, sell_book_->book_name_);
     cout << "ĐỊNH GIÁ: ";
     getline(cin, sell_book_->monney_);

     sell_book_->sell_nameBooker_ = booker_->name_;
     list_book_sell.push_back(*sell_book_);

     vector<sell_book> list_result_sell = booker_->get_sellBook_();

     list_result_sell.push_back(*sell_book_);
     booker_->Set_sell_book(list_result_sell);

     delete sell_book_;

     cout << endl
          << "ĐĂNG BÁN THÀNH CÔNG! ";
     Sleep(900);
}

void menu::menu_xem_thong_tin(booker *booker_)
{
     system("cls");
     int select;
     cout << "thông tin người dùng" << endl
          << endl;
     cout << *booker_;

     cout << "nhấn 0 để thoát: ";
     cin >> select;
     cin.ignore();
     if (select == 0)
     {
          return menu_of_user(booker_);
     }
}

void menu::menu_thay_doi_mk(booker *booker)
{
     system("cls");
     cout << "THAY ĐỔI MẬT KHẨU" << endl
          << endl;
     string mk_;
     cout << "nhập mật khẩu hiện tại: ";
     getline(cin, mk_);

     for (int i = 0; i < list_booker_.size(); i++)
     {
          if (mk_.compare(list_booker_[i].get_account().mk_) == 0)
          {
               cout << "nhập mật khẩu mới: ";
               getline(cin, mk_);
               string mk_again;
               cout << "nhập lại mật khẩu mới: ";
               getline(cin, mk_again);

               if (mk_.compare(mk_again) == 0)
               {
                    list_booker_[i].set_account(booker->name_, mk_again);
                    string file_path = "../Database/account.csv";
                    upFILE(file_path, list_booker_);
                    cout << endl
                         << "thay đổi mật khẩu thành công!";
                    Sleep(900);
                    break;
               }
          }
     }
}

void menu::menu_danh_sach(booker *booker)
{
     system("cls");
     cout << endl
          << "DANH SÁCH" << endl
          << endl;

     cout << "1.sách mượn:" << endl;
     cout << "2.sách trả:" << endl;
     cout << "3.sách mua:" << endl;
     cout << "4.sách bán:" << endl;
     cout << "0.thoát:" << endl
          << endl;

     int numberFunction_;
     cout << "chọn: ";
     cin >> numberFunction_;
     cin.ignore();
     cout << endl;

     switch (numberFunction_)
     {
     case 1:
          cout << "danh sách sách mượn:" << endl
               << endl;
          list_muon(booker);
     case 2:
          cout << "danh sách sách trả:" << endl
               << endl;
          list_tra(booker);
     case 3:
          cout << "danh sách sách mua:" << endl
               << endl;
          list_mua(booker);
     case 4:
          cout << "danh sách sách bán:" << endl
               << endl;
          list_ban(booker);
     case 0:
          return menu_of_user(booker);

     default:
          break;
     }
}

// giao diện hỗ trợ

void menu::menu_nap_tien(booker *booker_)
{
     system("cls");
     cout << "NẠP TIỀN" << endl
          << endl;

     int monney_;
     cout << "nhập số tiền muốn nạp: ";
     cin >> monney_;
     cin.ignore();

     cout << "nhập mật khẩu: ";
     string password;
     getline(cin, password);

     for (int i = 0; i < list_booker_.size(); ++i)
     {
          if (password.compare(list_booker_[i].get_account().mk_) == 0)
          {
               int monney = booker_->Get_monney();
               monney = monney + monney_;
               booker_->Set_monney(monney);
               cout << endl
                    << "nạp thành công!";
               Sleep(900);
               break;
          }
     }
}

void menu::list_muon(booker *booker_)
{
     if (booker_->getBook_().size() > 0)
     {
          for (int i = 0; i < booker_->getBook_().size(); ++i)
          {
               cout << i << ". " << booker_->getBook_()[i].book_name_ << endl
                    << endl;
          }
     }
     else
     {
          cout << endl
               << "DANH SÁCH MƯỢN TRỐNG!" << endl
               << endl;
     }
     int select;
     cout << endl
          << "nhập 0 để thoát: ";
     cin >> select;
     cin.ignore();
     if (select == 0)
     {
          return menu_danh_sach(booker_);
     }
}

void menu::list_tra(booker *booker_)
{
     if (booker_->get_getBook_().size() > 0)
     {
          for (int i = 0; i < booker_->get_getBook_().size(); ++i)
          {
               cout << i << ". " << booker_->get_getBook_()[i].book_name_ << endl
                    << endl;
          }
     }
     else
     {
          cout << endl
               << "DANH SÁCH TRẢ TRỐNG!" << endl
               << endl;
     }
     int select;
     cout << endl
          << "nhập 0 để thoát: ";
     cin >> select;
     cin.ignore();
     if (select == 0)
     {
          return menu_danh_sach(booker_);
     }
}

void menu::list_mua(booker *booker_)
{
     if (booker_->get_puyBook_().size() > 0)
     {
          for (int i = 0; i < booker_->get_puyBook_().size(); i++)
          {
               cout << i << ". " << booker_->get_puyBook_()[i].book_name_ << endl
                    << endl;
          }
     }
     else
     {
          cout << endl
               << "DANH SÁCH MUA TRỐNG!" << endl
               << endl;
     }
     int select;
     cout << endl
          << "nhập 0 để thoát: ";
     cin >> select;
     cin.ignore();
     if (select == 0)
     {
          return menu_danh_sach(booker_);
     }
}

void menu::list_ban(booker *booker_)
{
     if (booker_->get_sellBook_().size() > 0)
     {
          for (int i = 0; i < booker_->get_sellBook_().size(); i++)
          {
               cout << i << ". " << booker_->get_sellBook_()[i].book_name_ << endl;
               cout << "Giá bán: " << booker_->get_sellBook_()[i].monney_ << endl
                    << endl;
          }
     }
     else
     {
          cout << endl
               << "DANH SÁCH BÁN TRỐNG!" << endl
               << endl;
     }
     int select;
     cout << endl
          << "nhập 0 để thoát: ";
     cin >> select;
     cin.ignore();
     if (select == 0)
     {
          return menu_danh_sach(booker_);
     }
}

// giao diện chính

void menu::menu_of_user(booker *booker_)
{
     if (booker_ != NULL)
     {
          system("cls");
          bool input = true;
          cout << endl
               << "GIAO DIỆN NGƯỜI DÙNG" << endl
               << endl;
          while (input == true)
          {
               cout << "1.mượn sách: " << endl;
               cout << "2.trả sách: " << endl;
               cout << "3.mua sách: " << endl;
               cout << "4.bán sách: " << endl;
               cout << "5.xem danh sách: " << endl;
               cout << "6.thay đổi mật khẩu: " << endl;
               cout << "7.xem thông tin: " << endl;
               cout << "0.thoát " << endl
                    << endl;

               int numberFunction_;
               cout << "chọn: ";
               cin >> numberFunction_;
               cin.ignore();
               cout << endl;

               if (numberFunction_ > 7 || numberFunction_ < 0)
               {
                    cout << "không hợp lệ!" << endl
                         << endl;
               }
               else
               {
                    switch (numberFunction_)
                    {
                    case 1:
                         cout << "MƯỢN SÁCH:" << endl
                              << endl;
                         menu_muon_Sach(booker_);
                         return menu_of_user(booker_);
                    case 2:
                         cout << "trả sách:" << endl
                              << endl;
                         menu_tra_sach(booker_);
                         return menu_of_user(booker_);
                    case 3:
                         cout << "mua sách:" << endl
                              << endl;
                         menu_mua_sach(booker_);
                         return menu_of_user(booker_);
                    case 4:
                         cout << "bán sách:" << endl
                              << endl;
                         menu_ban_sach(booker_);
                         return menu_of_user(booker_);
                    case 5:
                         cout << "xem danh sách:" << endl
                              << endl;
                         menu_danh_sach(booker_);
                         return menu_of_user(booker_);
                    case 6:
                         cout << "thay đổi mật khẩu:" << endl
                              << endl;
                         menu_thay_doi_mk(booker_);
                         return menu_log_in();
                    case 7:
                         cout << "xem thông tin:" << endl
                              << endl;
                         menu_xem_thong_tin(booker_);
                         return menu_of_user(booker_);
                    case 0:
                         input = false;
                         return menu_Run_app();

                    default:
                         break;
                    }
               }
          }
     }
     else
     {
          cout << "ptr is null" << endl;
          return;
     }
}

void menu::menu_of_admin(admin *admin_)
{
     if (admin_ != NULL)
     {
          bool input = true;
          cout << endl
               << "GIAO DIỆN QUẢN TRỊ VIÊN" << endl
               << endl;
          while (input == true)
          {
               cout << "1.mượn sách: " << endl;
               cout << "2.trả sách: " << endl;
               cout << "3.mua sách: " << endl;
               cout << "4.bán sách: " << endl;
               cout << "5.xem thông tin: " << endl;
               cout << "6.thay đổi mật khẩu: " << endl;
               cout << "0.thoát " << endl
                    << endl;

               int numberFunction_;
               cout << "chọn: ";
               cin >> numberFunction_;
               cin.ignore();
               cout << endl;

               if (numberFunction_ > 6 || numberFunction_ < 0)
               {
                    cout << "không hợp lệ!" << endl
                         << endl;
               }
               else
               {
                    switch (numberFunction_)
                    {
                    case 1:
                         cout << "mượn sách:" << endl
                              << endl;
                         break;
                    case 2:
                         cout << "trả sách:" << endl
                              << endl;
                         break;
                    case 3:
                         cout << "mua sách:" << endl
                              << endl;
                         break;
                    case 4:
                         cout << "bán sách:" << endl
                              << endl;
                         break;
                    case 5:
                         cout << "xem thông tin:" << endl
                              << endl;
                         break;
                    case 6:
                         cout << "thay đổi mật khẩu:" << endl
                              << endl;
                         break;
                    case 0:
                         input = false;
                         return menu_Run_app();

                    default:
                         break;
                    }
               }
          }
     }
     else
     {
          cout << "ptr is null" << endl;
          return;
     }
}
