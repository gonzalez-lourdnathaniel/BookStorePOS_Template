#include <iostream>
#include <windows.h>
#include <iomanip>
#include <string>
#include <cstring>
#include <algorithm>
#include <unistd.h>
#include <stdio.h>

#include "OrderSys.h"
#include "AppUI.h"

using namespace std;

//this file is for POS or (Order/Sale) System

//create a blank database for the orders using linked list
//should have the following attributes: OrderID, CustomerName, [BooksOrdered, QtyOrder] , UnitPrice, AmountPrice, VAT, DiscountPrice, TotalSales
// ->>if the customer will pay by cash, add these attribute : Cash, Change
// ->>if the customer will pay by installment, add these attribute : 1stInstallment, 1stChange, 2ndInstallment, 2ndChange
//create your own OrderID format
//OrderId should be automated, every order should increment ID by 1, example Ord-01 -> Ord-02 -> Ord-03 ->...
//customer's first middle last name is NOT necessary, only the provided name, example Bryan Calulo, REYSAN, Luciano123, etc.
//customer CAN order 1 or more books
//BooksOrdered should linked to BookID in Book System
//BooksOrdered should be in 2D array together with the QtyOrder
//UnitPrice is 200.00
//AmountPrice is UnitPrice*TotalQtyOrder
//VAT is 12% of AmountPrice
//DiscountPrice is 5% of AmountPrice IF TotalQtyOrder is >= 3 ELSE 0
//TotalSales is AmountPrice + VAT - DiscountPrice
//Cash will be given by an imaginary customer
//Cash should decline IF Cash < TotalSales
//Change = Cash - TotalSales
//1stInstallment should be 60% of TotalSales ELSE decline
//2ndInstallment should be the the remaining balance ELSE decline
//assigned to : Vince Hernandez, Andrei Pascual


//create a CRUD system for the Order Database
//should create an Order Entry every transaction
//Customer paying with cash should differ from customer paying with installment
//ask if the customer will pay in cash or installment
//order should not complete IF QtyOrder > Quantity in Book System
//every order should decrement the Book quantity
//create function to display the customer with remaining balance
//create function to display the entire Order Database
//create function to read or access every attributes given

extern AppUI UI;

void OrderSys::OrderBook()
{
    //varaible declarations
    string bookTitle[] = {"Harry Potter", "Lord of the Rings", "The Hobbit", "Hunger Games"};
    int Opt, Qty[]={0}, bookID, OrderID[]={0};
    double bookPrice, VAT, Discount;

    OrderStart:
    UI.OrderBook();
    int orderCount = std::size(OrderID);

    for(int x=0; x<orderCount; x++)
    {
        cout << "| " << bookTitle[x] << setw((50-1) - bookTitle[x].length()) << "|" << Qty[x] << endl;
    }
    cout << "+" << std::string(70-1, '-') << "+" << endl;

    cout << "\n\n(1) Add to cart\t(2) Check Out\t(3) Remove from cart" << endl;
    cout << "Option: ";
    cin >> Opt;

    if(Opt == 1)
    {
        cout << "\n\nEnter book ID: ";
        cin >> bookID;
        UI.MainMenu();
    }
    if(Opt == 2)
    {
        sleep(1);
        UI.MainMenu();
    }
    if(Opt == 3)
    {
        sleep(1);
        UI.MainMenu();
    }
}
