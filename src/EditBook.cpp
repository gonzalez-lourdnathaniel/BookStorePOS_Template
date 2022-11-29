#include <iostream>
#include <windows.h>
#include <iomanip>
#include <string>
#include <cstring>
#include <algorithm>
#include <unistd.h>
#include <stdio.h>
#include <limits>

#include "SecuritySys.h"
#include "AppUI.h"
#include "EditBook.h"

extern AppUI UI;

using namespace std;

void EditBook::AddBook()
{
    //variable declarations
    char bookTitle[255], bookAuthor[255], bookPubDate[255], bookPublisher[255];

    system("CLS");
    UI.AddBook();

    cout << "Title: ";
    getchar();
    cin.getline(bookTitle,sizeof(bookTitle));
    cout << "Author: ";
    cin.getline(bookAuthor,sizeof(bookAuthor));
    cout << "Publication Date: ";
    cin.getline(bookPubDate,sizeof(bookPubDate));
    cout << "Publisher: ";
    cin.getline(bookPublisher,sizeof(bookPublisher));

    //replace this code with function to add the book to database
    cout << "\n\nTitle: " << bookTitle
         << "\nAuthor: " << bookAuthor
         << "\nDate: " << bookPubDate
         << "\nPublisher: " << bookPublisher << endl << endl;
    system("pause");
    UI.MainMenu();
}

//sort alphabetically in ascending order
bool sortAsc(string a, string b)
{
    return a<b;
}

//sort alphabetically in descending order
bool sortDesc(string a, string b)
{
    return a>b;
}

//count the length of the ID of a book
//example: 20 will be counted as 2 digits
int countDigit(long long n)
{
    if (n == 0)
        return 1;
    int count = 0;
    while (n != 0) {
        n = n / 10;
        ++count;
    }
    return count;
}

void EditBook::ViewBooks()
{
    //variable declarations
    string bTitle[] = {"Harry Potter", "Lord of the Rings", "The Hobbit", "Hunger Games"};
    string bAuthor[] = {"J.K. Rowling", "J.R.R. Tolkien", "J.R.R. Tolkien", "Suzanne Collins"};
    string bPubDate[] = {"Jan 1, 2020", "Nov 20,2022", "Nov 14, 2022", "March 15, 2015"};
    string bPublisher[] = {"Bloomsbury", "Allen & Unwin", "Allen & Unwin", "Scholastic"};
    int bTitleSize = std::size(bTitle);

    UI.ViewBook();
    sort(bTitle, bTitle + bTitleSize, sortAsc);

    for (int x=0; x<bTitleSize; x++)
    {
        int TitleStrSize = bTitle[x].length(),
            AuthorStrSize = bAuthor[x].length(),
            PubDateStrSize = bPubDate[x].length(),
            PublisherStrSize = bPublisher[x].length();
        long long n = x;

        cout << " " << x << setw(15 - countDigit(n) - 1) << "|"
             << " " << bTitle[x] << setw(50 - TitleStrSize - 1) << "|"
             << " " << bAuthor[x] << setw(40 - AuthorStrSize - 1) << "|"
             << " " << bPubDate[x] << setw(20 - PubDateStrSize - 1) << "|"
             << " " << bPublisher[x] << endl;
    }
    cout << std::string(15 - 1, '-') << "+" << std::string(50 - 1, '-') << "+" << std::string(40 -1, '-') << "+" << std::string(20 - 1, '-') << "+" << std::string(30, '-') << endl;
    system("pause");
    UI.MainMenu();
}

void EditBook::DeleteBook()
{
    //variable declarations
    string bTitle[] = {"Harry Potter", "Lord of the Rings", "The Hobbit", "Hunger Games"};
    string bAuthor[] = {"J.K. Rowling", "J.R.R. Tolkien", "J.R.R. Tolkien", "Suzanne Collins"};
    string bPubDate[] = {"Jan 1, 2020", "Nov 20,2022", "Nov 14, 2022", "March 15, 2015"};
    string bPublisher[] = {"Bloomsbury", "Allen & Unwin", "Allen & Unwin", "Scholastic"};
    int bTitleSize = std::size(bTitle), bookID;

    UI.DeleteBook();
    sort(bTitle, bTitle + bTitleSize, sortAsc);

    for (int x=0; x<bTitleSize; x++)
    {
        int TitleStrSize = bTitle[x].length(),
            AuthorStrSize = bAuthor[x].length(),
            PubDateStrSize = bPubDate[x].length(),
            PublisherStrSize = bPublisher[x].length();
        long long n = x;

        cout << " " << x << setw(15 - countDigit(n) - 1) << "|"
             << " " << bTitle[x] << setw(50 - TitleStrSize - 1) << "|"
             << " " << bAuthor[x] << setw(40 - AuthorStrSize - 1) << "|"
             << " " << bPubDate[x] << setw(20 - PubDateStrSize - 1) << "|"
             << " " << bPublisher[x] << endl;
    }
    cout << std::string(15 - 1, '-') << "+" << std::string(50 - 1, '-') << "+" << std::string(40 -1, '-') << "+" << std::string(20 - 1, '-') << "+" << std::string(30, '-') << endl;

    cout << "\nEnter ID of book to be deleted: ";
    cin >> bookID;
    UI.MainMenu();
}

SearchByTitle(string searchTxt)
{
    cout << "Enter search by TITLE code here" << endl << endl;
    system("pause");
    UI.MainMenu();
}

SearchByAuthor(string searchTxt)
{
    cout << "Enter search by AUTHOR code here" << endl << endl;
    system("pause");
    UI.MainMenu();
}

SearchByPubDate(string searchTxt)
{
    cout << "Enter search by PUBLISHING DATE code here" << endl << endl;
    system("pause");
    UI.MainMenu();
}

SearchByPublisher(string searchTxt)
{
    cout << "Enter search by PUBLISHER code here" << endl << endl;
    system("pause");
    UI.MainMenu();
}

void EditBook::SearchBook()
{
    //variable declarations
    string Opt;
    char searchTxt[255];

    SearchStart:
    UI.SearchBook();
    cout << "Search books by:" << endl;
    cout << "1. Title" << endl;
    cout << "2. Author" << endl;
    cout << "3. Publication Date" << endl;
    cout << "4. Publisher" << endl;
    cout << "\n0. Go back to main menu" << endl;

    cout << "\nOption: ";
    cin >> Opt;

    if(Opt == "1")
    {
        UI.SearchBook();
        cout << "Enter title: ";
        cin.getline(searchTxt,sizeof(searchTxt));
        SearchByTitle(searchTxt);
    }
    else if(Opt == "2")
    {
        UI.SearchBook();
        cout << "Enter author name: ";
        cin.getline(searchTxt,sizeof(searchTxt));
        SearchByAuthor(searchTxt);
    }
    else if(Opt == "3")
    {
        UI.SearchBook();
        cout << "Enter publication date: ";
        cin.getline(searchTxt,sizeof(searchTxt));
        SearchByPubDate(searchTxt);
    }
    else if(Opt == "4")
    {
        UI.SearchBook();
        cout << "Enter publisher: ";
        cin.getline(searchTxt,sizeof(searchTxt));
        SearchByPublisher(searchTxt);
    }
    else if(Opt == "0")
    {
        UI.MainMenu();
    }
    else
    {
        cout << "Invalid option!";
        sleep(1);
        goto SearchStart;
    }
}
