#include <iostream>
#include<string>

using namespace std;

const int COLLS = 3;
const int ROWS = 100;

string books[ROWS][COLLS];
int bookCount = 0;


void userInterface();

void _addNewBook();
void displayShelf_();

int main(){

    userInterface();

    // Code by Fishy, on falcon using Arch, btw.
    return 0;
}

void userInterface(){

    cout << "=====Digital Bookshelf=====" << "\n";
    cout << "1. Add new book." << "\n";
    cout << "2. List all books." << "\n";
    cout << "3. Search for a book by it's title." << "\n";
    cout << "4. Delete a book by it's number." << "\n";
    cout << "5. Count of books for an Author." << "\n";
    cout << "6. Quit!" << "\n";
    cout << "=====Jeffry Dahemr's Refrigerator Production=====" << "\n";

    int choice;
    cout << "Make your choice: ";
    cin >> choice;
    cin.ignore();

    switch (choice)
    {
        case 1: 
            _addNewBook();
            break;

        case 2: 
            displayShelf_(); 
            break;

        case 3: 
            cout << "book found!"; 
            break;

        case 4: 
            cout << "book deleted!"; 
            break;

        case 5: 
            cout << "you have X books"; 
            break;

        case 6:
            cout << "GG Commander!";
            return;
            break;

        default: 
            break;
    }

}

void _addNewBook(){

    cout << "\n---- Add a New Book ----\n";

    cout << "Title: "; 
    getline(cin, books[bookCount][0]);

    cout << "Author: "; 
    getline(cin, books[bookCount][1]);

    cout << "Year of publish: "; 
    getline(cin, books[bookCount][2]);

    bookCount ++;
    cout << "---- Book Added Successfully ----\n";

    displayShelf_();
}

void displayShelf_(){

    if (bookCount == 0){
        cout << "\n ohh.. The Refrigerator is empty!" << endl;
        return; // For now!
    }

    cout << "\n---- The Refrigerator ----\n";

    for (int i = 0; i < bookCount; ++i){

        cout << (i + 1) << ". ";

        for (int j = 0; j < COLLS; ++j){
            cout << books[i][j] << "\t";
        }

        cout << "\n";
    }

    cout << "---- Eat Well Commander ----\n";
}