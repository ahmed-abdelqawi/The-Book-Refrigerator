#include <iostream>
using namespace std;

const int ROWS = 100;
const int COLLS = 3;

string books[ROWS][COLLS];
int counter = 0;

// Functions Area
void _addNewBook();
void displayTheList_();
void delBook();
void searchTitle();
void countAuthor();

// UI Area
void userCommands_();
void menu_();
void clearTerminal();

int main()
{
    while (true)
    {
        menu_();
    }

    // Code by Fishy @falcon.
    return 0;
}

void menu_()
{
    cout << "==== The Book Refrigerator ====" << "\n";
    cout << "1. Add New Book." << "\n";
    cout << "2. Display The Book List." << "\n";
    cout << "3. Delete A Book." << "\n";
    cout << "4. Search For A Book By Its Title." << "\n";
    cout << "5. Count Books By Author." << "\n";
    cout << "6. Exit" << "\n";
    cout << "==== Jeffry Dahmer's Refrigerator Productions ====" << "\n";

    userCommands_();
}

void userCommands_()
{
    int choice;
    cout << "\n--Make Your Choice: ";
    cin >> choice;
    cin.ignore();

    switch (choice)
    {
    case 1:
        _addNewBook();
        break;
    case 2:
        displayTheList_();
        break;
    case 3:
        displayTheList_();
        delBook();
        break;
    case 4:
        searchTitle();
        break;
    case 5:
        countAuthor();
        break;
    case 6:
        cout << "\nGG Commander!\n";
        exit(0);
    default:
        cout << "Invalid choice!\n";
        break;
    }
}

void clearTerminal()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Functions Area
void _addNewBook()
{
    clearTerminal();

    cout << "\n------ Adding A New Book ------\n";
    cout << "\n";

    cout << "Title: ";
    getline(cin, books[counter][0]);

    cout << "Author: ";
    getline(cin, books[counter][1]);

    cout << "Year: ";
    getline(cin, books[counter][2]);

    counter++;

    cout << "\n------ Book Added Successfully ------\n";
    cout << "\n";
}

void displayTheList_()
{
    clearTerminal();

    cout << "\n------ The Refrigerator ------\n";
    cout << "\n";

    if (counter == 0)
    {
        cout << "The List is Empty!\n";
    }

    int displayRowNum = 1;

    for (int i = 0; i < counter; ++i)
    {
        if (books[i][1] == "")
        {
            continue;
        }

        cout << displayRowNum++ << ". ";
        for (int j = 0; j < COLLS; ++j)
        {
            cout << books[i][j] << "  ";
        }
        cout << "\n";
    }

    cout << "\n------ The End ------\n";
    cout << "\n";
}

void delBook()
{
    int _exe;
    cout << "Choose a book number: ";
    cin >> _exe;
    cin.ignore();

    if (_exe <= 0 || _exe > counter)
    {
        cout << "Invalid book number!\n";
        return;
    }

    for (int i = _exe - 1; i < counter - 1; i++)
    {
        books[i][0] = books[i + 1][0];
        books[i][1] = books[i + 1][1];
        books[i][2] = books[i + 1][2];
    }

    counter--;

    cout << "\n------ Book Terminated! ------\n";
    cout << "\n";
}

void searchTitle()
{
    clearTerminal();

    string target;
    cout << "\nEnter the Book Title: ";
    getline(cin, target);

    bool found = false;
    for (int i = 0; i < counter; ++i)
    {
        if (books[i][0] == target)
        {
            found = true;
        }

        if (found)
        {
            for (int j = 0; j < COLLS; ++j)
            {
                if (found)
                {
                    cout << books[i][j] << "  ";
                }
            }
            cout << "\n";
            break;
        }
    }

    if (!found || counter == 0)
    {
        cout << "Book Not Found!\n";
    }
}

void countAuthor()
{
    clearTerminal();

    string target;
    cout << "Enter The Author Name: ";
    getline(cin, target);
    cout << "\n";

    int num = 1;

    bool found = false, r = false;
    for (int i = 0; i < counter; ++i)
    {
        if (books[i][1] == target)
        {
            found = true;
        }
        else if (books[i][1] != target)
        {
            found = false;
        }

        if (found)
        {
            r = true;
            cout << num++ << ". ";

            for (int j = 0; j < COLLS; ++j)
            {
                cout << books[i][j] << "  ";
            }
            cout << "\n";
        }
    }
    cout << "\n";

    if (!r)
    {
        cout << "\nAuthor Not Found!\n";
    }
}