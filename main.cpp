#include <iostream>
#include <string>
using namespace std;

const int ROWS = 100;
const int COLLS = 3;
const int TITLE_COL = 0;
const int AUTHOR_COL = 1;
const int YEAR_COL = 2;

string books[ROWS][COLLS];
int counter = 0;

// Function
void addNewBook();
void displayBookList();
void deleteBook();
void searchByTitle();
void countByAuthor();

// UI Functions
void clearScreen();
void showMenu();
void handleUserChoice();

int main()
{
    while (true)
    {
        showMenu();
    }

    // Code By Fishy @falcon, on Arch, btw.
    return 0;
}

void showMenu()
{
    cout << "==== The Book Refrigerator ====\n"
         << "1. Add New Book\n"
         << "2. Display All Books\n"
         << "3. Delete a Book\n"
         << "4. Search by Title\n"
         << "5. Count Books by Author\n"
         << "6. Exit\n"
         << "==== Jeffry Dahmer's Refrigerator Productions ====\n";

    handleUserChoice();
}

void handleUserChoice()
{
    int choice;
    cout << "\nEnter your choice: ";
    cin >> choice;
    cin.ignore();

    switch (choice)
    {
    case 1:
        addNewBook();
        break;
    case 2:
        displayBookList();
        break;
    case 3:
        deleteBook();
        break;
    case 4:
        searchByTitle();
        break;
    case 5:
        countByAuthor();
        break;
    case 6:
        clearScreen();
        cout << "Goodbye, Commander!\n";
        exit(0);
    default:
        cout << "Invalid choice!\n";
        break;
    }
}

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void addNewBook()
{
    clearScreen();
    cout << "\n--- Add New Book ---\n";

    cout << "Title: ";
    getline(cin, books[counter][TITLE_COL]);

    cout << "Author: ";
    getline(cin, books[counter][AUTHOR_COL]);

    cout << "Year: ";
    getline(cin, books[counter][YEAR_COL]);

    counter++;
    cout << "\nBook added successfully!\n"
         << "\n";
}

void displayBookList()
{
    clearScreen();
    cout << "\n---------------- The Refrigerator ---------------\n";
    cout << "No.  Title               Author              Year\n";
    cout << "-------------------------------------------------\n";

    if (counter == 0)
    {
        cout << "The Refrigerator is empty.\n"
             << "-------------------------------------------------\n";
        return;
    }

    for (int i = 0; i < counter; i++)
    {
        if (books[i][TITLE_COL].empty())
            continue;

        cout << (i + 1) << ".   ";

        // The Output With Padding So It Will Look Cool...
        cout << books[i][TITLE_COL];
        int titleSpaces = 20 - books[i][TITLE_COL].length();
        if (titleSpaces > 0)
            cout << string(titleSpaces, ' ');

        cout << books[i][AUTHOR_COL];
        int authorSpaces = 20 - books[i][AUTHOR_COL].length();
        if (authorSpaces > 0)
            cout << string(authorSpaces, ' ');

        cout << books[i][YEAR_COL] << "\n";
    }
    cout << "-------------------------------------------------\n"
         << "\n";
}

void deleteBook()
{
    displayBookList();
    if (counter == 0)
    {
        cout << "Press Enter to continue...";
        cin.ignore();
        return;
    }

    int bookNum;
    cout << "\nEnter book number to delete: ";
    cin >> bookNum;
    cin.ignore();

    if (bookNum < 1 || bookNum > counter)
    {
        cout << "Invalid book number!\n";
        cout << "Press Enter to continue...";
        cin.ignore();
        return;
    }

    for (int i = bookNum - 1; i < counter - 1; i++)
    {
        books[i][TITLE_COL] = books[i + 1][TITLE_COL];
        books[i][AUTHOR_COL] = books[i + 1][AUTHOR_COL];
        books[i][YEAR_COL] = books[i + 1][YEAR_COL];
    }

    counter--;
    cout << "\nBook deleted successfully!\n";
    cout << "Press Enter to continue...";
    cin.ignore();
}

void searchByTitle()
{
    clearScreen();
    string title;
    cout << "\nEnter book title: ";
    getline(cin, title);

    bool found = false;
    for (int i = 0; i < counter; i++)
    {
        if (books[i][TITLE_COL] == title)
        {
            found = true;
            cout << "\nFound: "
                 << books[i][TITLE_COL] << " | "
                 << books[i][AUTHOR_COL] << " | "
                 << books[i][YEAR_COL] << "\n";
            break;
        }
    }

    if (!found)
    {
        cout << "\nBook not found!\n";
    }
    cout << "Press Enter to continue...";
    cin.ignore();
}

void countByAuthor()
{
    clearScreen();
    string author;
    cout << "\nEnter author name: ";
    getline(cin, author);

    int count = 0;
    cout << "\nBooks by " << author << ":\n";
    for (int i = 0; i < counter; i++)
    {
        if (books[i][AUTHOR_COL] == author)
        {
            count++;
            cout << count << ". "
                 << books[i][TITLE_COL] << " ("
                 << books[i][YEAR_COL] << ")\n";
        }
    }

    if (count == 0)
    {
        cout << "No books found for this author.\n";
    }
    else
    {
        cout << "\nTotal: " << count << " book(s)\n";
    }
    cout << "Press Enter to continue...";
    cin.ignore();
}