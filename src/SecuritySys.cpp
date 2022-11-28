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

extern AppUI UI;

using namespace std;

//this file is for Security (login) system
//create a username and password (will be decided by you)
//maximum of 3 tries ELSE terminates
//can change username and password
//should login first before changing the username and password
//username and password variables SHOULD be  private(can't be accessed outside class)
//create function to GET username
//assigned to : Darwin Alba, Ramil Rosal

void SecuritySys::Login()
{
    string user="test";
    string pass="testpass";
    string tmp_user, tmp_pass;
    int x=4;

    attempt:
    UI.Login();
    cout << "Username: ";
    cin >> tmp_user;
    cout << "Password: ";
    cin >> tmp_pass;

    if(tmp_user == user)
    {
        if(tmp_pass == pass) {
            cout << "Login successful: " << user << endl;
            sleep(2);
            UI.MainMenu();
        }
        else {
            x--;
            if(x==0) {
                cout << "Login failed!";
                sleep(2);
                exit(0);
            }
            else {
                cout << "Login failed you have " << x << " left";
                sleep(1);
                goto attempt;
            }
        }
    }
    else
    {
        cout << "User not found!" << endl;
        sleep(1);
        goto attempt;
    }
}
