# Book Refrigerator

This program is a simple command-line application to manage a list of books. It allows users to add new books, display the list of books, delete books, search for books by title, and count books by a specific author.

## Functions

Below is an explanation of each function used in this C++ program.

### `int main()`

```cpp
int main()
{
    while (true)
    {
        showMenu();
    }
    return 0;
}
```

The `main()` function is the entry point of any C++ program. When you run this program, the `main()` function is the first one to be executed.

In this specific program, the `main()` function has a `while (true)` loop. This creates an infinite loop, meaning the code inside it will keep running forever until the program is explicitly told to stop. Inside this loop, it continuously calls the `showMenu()` function. This is what keeps the menu displaying to the user repeatedly, allowing them to perform multiple actions (like adding a book, then displaying the list, etc.) without the program ending after just one action.

The `return 0;` statement at the end is a standard way to indicate that the program has finished successfully. However, in this particular code, because of the `while(true)` loop and the `exit(0)` call within the `handleUserChoice` function (when the user chooses to exit), this `return 0;` statement in `main()` will likely never be reached.

### `void showMenu()`

```cpp
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
```

The `showMenu()` function is responsible for displaying the main menu of the application to the user.

When called, it uses `cout` (which stands for "character output" and is C++'s way to print text to the console) to print several lines of text. These lines form a user-friendly menu with a title "==== The Book Refrigerator ====" and lists the available options, each numbered from 1 to 6:

1.  Add New Book
2.  Display All Books
3.  Delete a Book
4.  Search by Title
5.  Count Books by Author
6.  Exit

It also displays a footer "==== Jeffry Dahmer's Refrigerator Productions ====".

After displaying all these options, the `showMenu()` function then immediately calls another function: `handleUserChoice()`. This means that as soon as the menu is shown, the program will then proceed to get the user's input and act on it.

### `void handleUserChoice()`

```cpp
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
```

The `handleUserChoice()` function is called right after the menu is displayed by `showMenu()`. Its job is to get the user's selection from the menu and then perform the action the user wants.

First, it declares an integer variable named `choice`. Then, it prompts the user to "Enter your choice: " using `cout`. The program then waits for the user to type a number and press Enter. This input is read into the `choice` variable using `cin` (which stands for "character input"). The `cin.ignore()` line after `cin >> choice;` is important; it clears the input buffer. When you type a number and press Enter, the number is read by `cin >> choice`, but the Enter key press (which is a newline character) remains in the input buffer. If not cleared, it might be accidentally read by a later input command (especially `getline`), causing unexpected behavior. `cin.ignore()` helps prevent this.

Next, the function uses a `switch` statement. A `switch` statement is a way to select one of many code blocks to be executed based on the value of an expression (in this case, the `choice` variable).

- If `choice` is `1`, it calls the `addNewBook()` function.
- If `choice` is `2`, it calls the `displayBookList()` function.
- If `choice` is `3`, it calls the `deleteBook()` function.
- If `choice` is `4`, it calls the `searchByTitle()` function.
- If `choice` is `5`, it calls the `countByAuthor()` function.
- If `choice` is `6`, it first calls `clearScreen()` to clear the console, then prints "Goodbye, Commander!\n", and finally calls `exit(0)`. The `exit(0)` function immediately terminates the entire program. The `0` indicates a successful termination.
- If the `choice` is any other number not listed above (the `default` case), it prints "Invalid choice!\n" to the console, indicating the user entered an option that doesn't exist.

After the corresponding action is taken (or an invalid choice message is shown), this function finishes, and because `showMenu()` is in a `while(true)` loop in `main()`, the menu will be displayed again, ready for the user's next choice.

### `void clearScreen()`

```cpp
void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
```

The `clearScreen()` function is a utility function designed to clear the terminal or console window. This helps to keep the application's output tidy by removing previous text before displaying new information, like a new menu or the book list.

It uses preprocessor directives (`#ifdef`, `#else`, `#endif`) to provide cross-platform compatibility. This means it tries to use the correct command depending on the operating system the program is compiled on:

- `#ifdef _WIN32`: This checks if the program is being compiled on a Windows operating system (where `_WIN32` is a predefined macro).
  - If it is Windows, `system("cls");` is executed. The `system()` function allows the C++ program to run a command as if you typed it directly into the command prompt. The `cls` command is the standard command for clearing the screen in Windows Command Prompt.
- `#else`: If the program is not being compiled on Windows (e.g., it's on Linux or macOS).
  - `system("clear");` is executed. The `clear` command is the standard command for clearing the screen in Unix-like terminal emulators (like those found on Linux and macOS).
- `#endif`: This ends the conditional preprocessor block.

So, this function intelligently chooses the right command to clear the screen, making the user experience cleaner regardless of whether they are running the program on Windows or a Unix-based system.

### `void addNewBook()`

```cpp
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
```

The `addNewBook()` function allows the user to add a new book to the list.

Here's how it works step-by-step:

1.  `clearScreen();`: First, it calls the `clearScreen()` function to clear the console, providing a clean interface for adding a new book.
2.  `cout << "\n--- Add New Book ---\n";`: It then prints a title "--- Add New Book ---" to indicate what the user is currently doing.
3.  The program then prompts the user for the book's details one by one:
    - `cout << "Title: ";`: It asks for the "Title".
    - `getline(cin, books[counter][TITLE_COL]);`: It reads the entire line of text the user types for the title (including spaces) and stores it in the `books` array. The `books` array is a two-dimensional array that stores book information. `counter` is a global variable that keeps track of how many books are currently in the list. So, `books[counter]` refers to the next available slot for a new book, and `[TITLE_COL]` (which is a constant with value 0) specifies that this is the title column for that book.
    - Similarly, it prompts for and reads the "Author" (`getline(cin, books[counter][AUTHOR_COL]);`), storing it in the author column (`AUTHOR_COL` is 1).
    - And then it prompts for and reads the "Year" (`getline(cin, books[counter][YEAR_COL]);`), storing it in the year column (`YEAR_COL` is 2).
4.  `counter++;`: After all the information for the new book has been entered, the `counter` variable is incremented. This is crucial because it means the next time `addNewBook()` is called, it will store the new book in the next empty slot in the `books` array, and `counter` also accurately reflects the total number of books.
5.  `cout << "\nBook added successfully!\n" << "\n";`: Finally, it prints a confirmation message "Book added successfully!" to let the user know the operation was completed.

This function uses `getline(cin, ...)` to read the input. This is preferred over `cin >> ...` for strings because `getline` can read strings that include spaces, which is common for book titles and author names. The `cin.ignore()` that was present in `handleUserChoice` before calling functions that might use `getline` (like this one, if it were called directly after a `cin >> choice`) helps prevent issues with leftover newline characters in the input buffer.

### `void displayBookList()`

```cpp
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
```

The `displayBookList()` function is responsible for showing all the books currently stored in the application.

Here's a breakdown of its actions:

1.  `clearScreen();`: It starts by clearing the console screen for a neat display.
2.  `cout << ...;`: It then prints a header for the book list: "---------------- The Refrigerator ----------------", followed by column titles: "No. Title Author Year", and a separator line "-------------------------------------------------".
3.  `if (counter == 0)`: It checks if the `counter` (which tracks the number of books) is zero.
    - If `counter` is 0, it means there are no books to display. So, it prints "The Refrigerator is empty." and another separator line. Then, `return;` is called, which means the function stops executing here, as there's nothing more to display.
4.  `for (int i = 0; i < counter; i++)`: If there are books (i.e., `counter` is not 0), this `for` loop will run for each book. The loop variable `i` goes from `0` up to (but not including) `counter`.
    - `if (books[i][TITLE_COL].empty()) continue;`: Inside the loop, this line checks if the title of the current book (`books[i][TITLE_COL]`) is empty. This is a safeguard, perhaps for partially deleted entries, though the current `deleteBook` function shifts elements up. If the title is empty, `continue;` skips the rest of the current iteration and moves to the next book.
    - `cout << (i + 1) << ".   ";`: It prints the book number. Since array indices `i` start from 0, `i + 1` is used to display a 1-based numbering for the user (e.g., Book 1, Book 2, etc.).
    - The next few lines are for printing the Title, Author, and Year with some padding to make the columns align nicely:
      - `cout << books[i][TITLE_COL];`: Prints the book's title.
      - `int titleSpaces = 20 - books[i][TITLE_COL].length(); if (titleSpaces > 0) cout << string(titleSpaces, ' ');`: This calculates how many spaces are needed after the title to make the total width about 20 characters. If the title is shorter than 20 characters, it prints the required number of spaces. `string(titleSpaces, ' ')` creates a string consisting of `titleSpaces` space characters.
      - The same logic is applied for the Author column, also aiming for a width of 20 characters.
      - `cout << books[i][YEAR_COL] << "\n";`: Prints the year of the book, followed by `\n` which moves the cursor to the next line for the next book.
5.  After the loop finishes (meaning all books have been printed), it prints a final separator line "-------------------------------------------------" and an extra newline character for spacing.

This function provides a formatted and readable list of all the books that have been added to the system.

### `void deleteBook()`

```cpp
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
```

The `deleteBook()` function allows the user to remove a book from the list.

Here is how it operates:

1.  `displayBookList();`: First, it calls `displayBookList()` to show the current list of books with their numbers. This helps the user identify the number of the book they want to delete.
2.  `if (counter == 0)`: It checks if there are any books in the list.
    - If `counter` is 0 (the list is empty), it prints "Press Enter to continue...", waits for the user to press Enter (using `cin.ignore()` to consume the Enter key press), and then `return;` exits the function because there's nothing to delete.
3.  `int bookNum; cout << "\nEnter book number to delete: "; cin >> bookNum; cin.ignore();`: If there are books, it declares an integer variable `bookNum`. It then prompts the user to "Enter book number to delete: ". The program reads the number entered by the user into `bookNum`. `cin.ignore()` is used again to clear the newline character from the input buffer after reading the number, which is good practice before potentially using `getline` in other parts of the program or just to ensure clean input handling.
4.  `if (bookNum < 1 || bookNum > counter)`: This line validates the user's input. It checks if the entered `bookNum` is less than 1 (invalid) or greater than the current number of books (`counter`).
    - If the number is invalid, it prints "Invalid book number!", prompts the user to "Press Enter to continue...", waits for an Enter press, and then `return;` exits the function.
5.  `for (int i = bookNum - 1; i < counter - 1; i++)`: If the book number is valid, this `for` loop is executed to remove the book. The loop starts from the index of the book to be deleted (`bookNum - 1`, because users see 1-based numbers but arrays are 0-based). It goes up to one less than the current `counter - 1` (i.e., up to the second to last element).
    - Inside the loop: `books[i][TITLE_COL] = books[i + 1][TITLE_COL];` (and similarly for `AUTHOR_COL` and `YEAR_COL`). This line effectively shifts each subsequent book one position up in the array. For example, if book number 2 is deleted, book 3's data is copied into book 2's slot, book 4's data into book 3's slot, and so on. This overwrites the data of the book that was meant to be deleted.
6.  `counter--;`: After shifting all the elements, the `counter` is decremented. This reduces the total count of books, and the last (now duplicated) slot in the array will be ignored in future operations or overwritten when a new book is added.
7.  `cout << "\nBook deleted successfully!\n"; cout << "Press Enter to continue..."; cin.ignore();`: Finally, it prints a success message and waits for the user to press Enter before returning to the main menu.

This method of deletion (shifting elements) is common for array-based lists where you want to maintain a contiguous block of data without gaps.

### `void searchByTitle()`

```cpp
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
```

The `searchByTitle()` function enables the user to search for a specific book in the list by its title.

Here's a step-by-step explanation of its functionality:

1.  `clearScreen();`: It begins by clearing the console screen to provide a clean search interface.
2.  `string title; cout << "\nEnter book title: "; getline(cin, title);`: It declares a string variable named `title`. Then, it prompts the user to "Enter book title: " and reads the entire line of text entered by the user (including spaces) into the `title` variable using `getline(cin, title)`. This is important because book titles can often contain spaces.
3.  `bool found = false;`: A boolean variable `found` is initialized to `false`. This variable will be used to keep track of whether the searched book has been found in the list.
4.  `for (int i = 0; i < counter; i++)`: The code then enters a `for` loop that iterates through all the books currently stored in the `books` array. The loop runs from `i = 0` up to (but not including) `counter` (the total number of books).
    - `if (books[i][TITLE_COL] == title)`: Inside the loop, this `if` statement compares the title of the current book (`books[i][TITLE_COL]`) with the `title` entered by the user.
      - If a match is found:
        - `found = true;`: The `found` variable is set to `true` to indicate that the book has been located.
        - `cout << "\nFound: " << books[i][TITLE_COL] << " | " << books[i][AUTHOR_COL] << " | " << books[i][YEAR_COL] << "\n";`: The details of the found book (Title, Author, and Year) are printed to the console, formatted with " | " as a separator.
        - `break;`: Since the book has been found, there's no need to continue searching the rest of the list. The `break;` statement immediately exits the `for` loop.
5.  `if (!found)`: After the loop has finished (either because it completed all iterations or because `break;` was executed), this `if` statement checks the value of the `found` variable.
    - If `found` is still `false` (meaning the loop completed without finding a matching title), it prints "\nBook not found!\n" to the console.
6.  `cout << "Press Enter to continue..."; cin.ignore();`: Regardless of whether the book was found or not, the function then prompts the user to "Press Enter to continue..." and waits for an Enter key press (using `cin.ignore()` to consume it) before returning. This allows the user to see the search result before the menu is displayed again.

This function provides a simple way for users to quickly check if a book with a specific title exists in their collection and view its details if it does.

### `void countByAuthor()`

```cpp
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
```

The `countByAuthor()` function allows the user to search for all books written by a particular author and get a count of how many books by that author are in the list.

Here’s how it works:

1.  `clearScreen();`: As with other functions that display significant output, it starts by clearing the console screen.
2.  `string author; cout << "\nEnter author name: "; getline(cin, author);`: It declares a string variable `author`. Then, it prompts the user to "Enter author name: " and reads the full line of text (including spaces, which is common in author names) into the `author` variable using `getline(cin, author)`.
3.  `int count = 0;`: An integer variable `count` is initialized to `0`. This variable will be used to store the number of books found for the specified author.
4.  `cout << "\nBooks by " << author << ":\n";`: It prints a header indicating whose books are being listed, for example, "Books by Jane Austen:".
5.  `for (int i = 0; i < counter; i++)`: The code then enters a `for` loop that iterates through all the books currently in the `books` array (from index `0` up to `counter - 1`).
    - `if (books[i][AUTHOR_COL] == author)`: Inside the loop, this `if` statement compares the author of the current book (`books[i][AUTHOR_COL]`) with the `author` name entered by the user.
      - If the authors match:
        - `count++;`: The `count` variable is incremented.
        - `cout << count << ". " << books[i][TITLE_COL] << " (" << books[i][YEAR_COL] << ")\n";`: The title and year of the found book are printed, prefixed by the current `count` (to provide a numbered list of books by that author). For example: "1. Pride and Prejudice (1813)".
6.  After the loop finishes checking all the books:
    - `if (count == 0)`: It checks if the `count` is still `0`. If so, it means no books by that author were found, and it prints "No books found for this author.\n".
    - `else`: If `count` is greater than 0 (meaning at least one book was found), it prints the total number of books found, for example, "\nTotal: 2 book(s)\n".
7.  `cout << "Press Enter to continue..."; cin.ignore();`: Finally, it prompts the user to "Press Enter to continue..." and waits for an Enter key press before returning to the main menu. This allows the user to review the list and the count before the screen is cleared for the menu.

This function is useful for users who want to see all works by a specific author that they have cataloged or to simply find out how many books by that author are in their list.

# This Program Was Created By Ahmed Abdelqawi "Fishy.", Feel Free To Use It As You Prefer :D
