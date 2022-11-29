#include <iostream>
#include <windows.h>
#include <iomanip>
#include <string>
#include <cstring>
#include <algorithm>
#include <unistd.h>
#include <stdio.h>

#include "SecuritySys.h"
#include "AppUI.h"
#include "EditBook.h"
#include "OrderSys.h"

extern SecuritySys SecSysFunc;
extern EditBook BookFunc;
extern OrderSys OrderFunc;

using namespace std;

//this file is responsible for the designs or UI
//create functions or methods to easily design an output
//design a receipt
//design a security UI
//design an order database UI
//design an book database UI
//design an about us UI
//design a transaction UI
//be creative!
//assigned to: Michaela De Guzman

//lets you change the text color of line
void setTxtColor(int ColorValue)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, ColorValue);
}

//main header of app
void TitleHeader()
{
    string Title = "Book Store";
    system("CLS");
    setTxtColor(9);
    cout << std::string(155,'=') << endl;
    cout << setw((155/2) + (Title.length()/2)) << Title << endl;
    cout << std::string(155,'=') << endl << endl;
}

//title of the page
void PageTitle(string title)
{
    string PageTitle = "|    " + title + "    |";
    int PageTitleSize = PageTitle.length();
    cout << setw(((155/2) + PageTitleSize/2) - 1) << std::string(PageTitleSize - 2, '*') << endl;
    cout << setw((155/2) + (PageTitleSize/2)) << PageTitle << endl;
    cout << setw(((155/2) + PageTitleSize/2) - 1) << std::string(PageTitleSize - 2, '*') << endl << endl;
}

void AppUI::Login()
{
    TitleHeader();
    setTxtColor(10);
    PageTitle("Login");
}

void AppUI::MainMenu()
{
    //variable declarations
    MenuStart:
    string opt;


    system("CLS");
    TitleHeader();
    setTxtColor(10);
    PageTitle("Main Menu");
    string Menu[] = {"Add Books", "Search Books", "View Books", "Delete Book", "Exit"};
    cout << "1. Add Books" << endl;
    cout << "2. Search Books" << endl;
    cout << "3. View Books" << endl;
    cout << "4. Delete Books" << endl;
    cout << "5. Order Books" << endl << endl;
    cout << "0. Exit";

    cout << "\n\nEnter Option: ";
    cin >> opt;

    if(opt == "1")
    {
        BookFunc.AddBook();
    }
    else if(opt == "2")
    {
        BookFunc.SearchBook();
    }
    else if(opt == "3")
    {
        BookFunc.ViewBooks();
    }
    else if(opt == "4")
    {
        BookFunc.DeleteBook();
    }
    else if(opt == "5")
    {
        OrderFunc.OrderBook();
    }
    else if(opt == "0")
    {
        for (int j = 0; j < 3; j++) {
               cout << "\rLoging out, please wait   \rLoging out, please wait";
               for (int i = 0; i < 3; i++) {
                  cout << ".";
                  sleep(1);
               }
            }
        SecSysFunc.Login();
    }
    else
    {
        cout << "Invalid option!" << endl;
        sleep(1);
        goto MenuStart;
    }
}

void AppUI::AddBook()
{
    TitleHeader();
    setTxtColor(10);
    PageTitle("Add Book");
}

void AppUI::ViewBook()
{
    //variable declarations
    string h0 = "ID", h1= "Title", h2 = "Author", h3 = "Date Published", h4 = "Publishing Company";
    int hc0 = h0.length(), hc1 = h1.length(), hc2 = h2.length(), hc3 = h3.length(), hc4 = h4.length();

    system("CLS");
    TitleHeader();
    setTxtColor(10);
    PageTitle("Book List");
    cout << std::string(15 - 1, '-') << "+" << std::string(50 - 1, '-') << "+" << std::string(40 -1, '-') << "+" << std::string(20 - 1, '-') << "+" << std::string(30, '-') << endl;
    cout << " " + h0 << setw(15 - hc0 - 1) << "|" << setw((50/2) + (hc1/2)) << h1 << setw((50/2) - (hc1/2)) << "|"
         << setw((40/2) + (hc2/2)) << h2 << setw((40/2) - (hc2/2)) << "|"
         << setw((20/2) + (hc3/2)) << h3 << setw((20/2) - (hc3/2)) << "|"
         << setw((30/2) + (hc4/2)) << h4 << setw((30/2) - (hc4/2)) << endl;
    cout << std::string(15 - 1, '-') << "+" << std::string(50 - 1, '-') << "+" << std::string(40 -1, '-') << "+" << std::string(20 - 1, '-') << "+" << std::string(30, '-') << endl;
}

void AppUI::DeleteBook()
{
    //variable declarations
    string h0 = "ID", h1= "Title", h2 = "Author", h3 = "Date Published", h4 = "Publishing Company";
    int hc0 = h0.length(), hc1 = h1.length(), hc2 = h2.length(), hc3 = h3.length(), hc4 = h4.length();

    system("CLS");
    TitleHeader();
    setTxtColor(10);
    PageTitle("Delete Book");
    cout << std::string(15 - 1, '-') << "+" << std::string(50 - 1, '-') << "+" << std::string(40 -1, '-') << "+" << std::string(20 - 1, '-') << "+" << std::string(30, '-') << endl;
    cout << " " + h0 << setw(15 - hc0 - 1) << "|" << setw((50/2) + (hc1/2)) << h1 << setw((50/2) - (hc1/2)) << "|"
         << setw((40/2) + (hc2/2)) << h2 << setw((40/2) - (hc2/2)) << "|"
         << setw((20/2) + (hc3/2)) << h3 << setw((20/2) - (hc3/2)) << "|"
         << setw((30/2) + (hc4/2)) << h4 << setw((30/2) - (hc4/2)) << endl;
    cout << std::string(15 - 1, '-') << "+" << std::string(50 - 1, '-') << "+" << std::string(40 -1, '-') << "+" << std::string(20 - 1, '-') << "+" << std::string(30, '-') << endl;
}

void AppUI::SearchBook()
{
    system("CLS");
    TitleHeader();
    setTxtColor(10);
    PageTitle("Search Book");
}

void AppUI::OrderBook()
{
    //variable declarations
    string  h1 = "Book Title", h2 = "Quantity";
    system("CLS");
    TitleHeader();
    setTxtColor(10);
    PageTitle("Search Book");

    cout << "+" << std::string(70-1, '-') << "+" << endl;
    cout << "| " << h1 << setw((50 - 1) - h1.length()) << "|" << setw((20/2) + h2.length()/2) << h2 << setw((20/2) - h2.length()/2) << "|" << endl;
    cout << "+" << std::string(70-1, '-') << "+" << endl;
}
