
#include <iostream>
#include <string>
#include <limits>
using namespace std;

const int MAX_ITEMS = 100;

// Abstract Base Class
class LibraryItem
{
private:
    string title;
    string author;
    string dueDate;

public:
    LibraryItem(string t, string a, string d)
    {
        title = t;
        author = a;
        dueDate = d;
    }

    virtual ~LibraryItem() {}

    // Getters
    string getTitle() const
    {
        return title;
    }

    string getAuthor() const
    {
        return author;
    }

    string getDueDate() const
    {
        return dueDate;
    }

    // Pure Virtual Functions
    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() const = 0;
};

// Derived Class: Book
class Book : public LibraryItem
{
private:
    string isbn;
    bool isIssued;

public:
    Book(string t, string a, string d, string i)
        : LibraryItem(t, a, d)
    {
        isbn = i;
        isIssued = false;
    }

    void checkOut()
    {
        if (isIssued)
            cout << "Book is already issued.\n";
        else
        {
            isIssued = true;
            cout << "Book checked out successfully.\n";
        }
    }

    void returnItem()
    {
        if (!isIssued)
            cout << "Book was not issued.\n";
        else
        {
            isIssued = false;
            cout << "Book returned successfully.\n";
        }
    }

    void displayDetails() const
    {
        cout << "\nType: Book";
        cout << "\nTitle: " << getTitle();
        cout << "\nAuthor: " << getAuthor();
        cout << "\nDue Date: " << getDueDate();
        cout << "\nISBN: " << isbn;
        cout << "\nStatus: "
             << (isIssued ? "Issued" : "Available");
        cout << "\n";
    }
};

// Derived Class: DVD
class DVD : public LibraryItem
{
private:
    int duration;
    bool isIssued;

public:
    DVD(string t, string a, string d, int dur)
        : LibraryItem(t, a, d)
    {
        duration = dur;
        isIssued = false;
    }

    void checkOut()
    {
        if (isIssued)
            cout << "DVD is already issued.\n";
        else
        {
            isIssued = true;
            cout << "DVD checked out successfully.\n";
        }
    }

    void returnItem()
    {
        if (!isIssued)
            cout << "DVD was not issued.\n";
        else
        {
            isIssued = false;
            cout << "DVD returned successfully.\n";
        }
    }

    void displayDetails() const
    {
        cout << "\nType: DVD";
        cout << "\nTitle: " << getTitle();
        cout << "\nAuthor: " << getAuthor();
        cout << "\nDue Date: " << getDueDate();
        cout << "\nDuration: " << duration << " minutes";
        cout << "\nStatus: "
             << (isIssued ? "Issued" : "Available");
        cout << "\n";
    }
};

// Derived Class: Magazine
class Magazine : public LibraryItem
{
private:
    int issueNumber;
    bool isIssued;

public:
    Magazine(string t, string a, string d, int issue)
        : LibraryItem(t, a, d)
    {
        issueNumber = issue;
        isIssued = false;
    }

    void checkOut()
    {
        if (isIssued)
            cout << "Magazine is already issued.\n";
        else
        {
            isIssued = true;
            cout << "Magazine checked out successfully.\n";
        }
    }

    void returnItem()
    {
        if (!isIssued)
            cout << "Magazine was not issued.\n";
        else
        {
            isIssued = false;
            cout << "Magazine returned successfully.\n";
        }
    }

    void displayDetails() const
    {
        cout << "\nType: Magazine";
        cout << "\nTitle: " << getTitle();
        cout << "\nAuthor: " << getAuthor();
        cout << "\nDue Date: " << getDueDate();
        cout << "\nIssue Number: " << issueNumber;
        cout << "\nStatus: "
             << (isIssued ? "Issued" : "Available");
        cout << "\n";
    }
};

// Main Function
int main()
{
    LibraryItem* libraryItems[MAX_ITEMS] = {NULL};
    int count = 0;
    int choice = 0;

    do
    {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. Add DVD\n";
        cout << "3. Add Magazine\n";
        cout << "4. Display All Items\n";
        cout << "5. Search Item\n";
        cout << "6. Check Out Item\n";
        cout << "7. Return Item\n";
        cout << "8. Remove Item\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cout << "Invalid input. Enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = 0;
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice >= 1 && choice <= 3)
        {
            if (count >= MAX_ITEMS)
            {
                cout << "Library catalog is full.\n";
                continue;
            }

            string title, author, dueDate;

            cout << "Enter title: ";
            getline(cin, title);

            cout << "Enter author: ";
            getline(cin, author);

            cout << "Enter due date (DD-MM-YYYY): ";
            getline(cin, dueDate);

            if (choice == 1)
            {
                string isbn;
                bool valid = true;

                cout << "Enter 13-digit ISBN: ";
                getline(cin, isbn);

                if (isbn.length() != 13)
                    valid = false;
                else
                {
                    for (int j = 0; j < 13; j++)
                    {
                        if (isbn[j] < '0' || isbn[j] > '9')
                        {
                            valid = false;
                            break;
                        }
                    }
                }

                if (!valid)
                {
                    cout << "Invalid ISBN. Enter 13 digits only.\n";
                    continue;
                }

                libraryItems[count] =
                    new Book(title, author, dueDate, isbn);

                cout << "Book added successfully.\n";
            }
            else if (choice == 2)
            {
                int duration;

                cout << "Enter duration in minutes: ";

                if (!(cin >> duration))
                {
                    cout << "Invalid duration.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (duration <= 0)
                {
                    cout << "Duration must be positive.\n";
                    continue;
                }

                libraryItems[count] =
                    new DVD(title, author, dueDate, duration);

                cout << "DVD added successfully.\n";
            }
            else
            {
                int issue;

                cout << "Enter issue number: ";

                if (!(cin >> issue))
                {
                    cout << "Invalid issue number.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (issue <= 0)
                {
                    cout << "Issue number must be positive.\n";
                    continue;
                }

                libraryItems[count] =
                    new Magazine(title, author, dueDate, issue);

                cout << "Magazine added successfully.\n";
            }

            count++;
        }
        else if (choice == 4)
        {
            if (count == 0)
                cout << "Library is empty.\n";

            for (int i = 0; i < count; i++)
            {
                cout << "\nItem Number: " << i + 1;
                libraryItems[i]->displayDetails();
            }
        }
        else if (choice == 5)
        {
            string searchTitle;
            bool found = false;

            cout << "Enter title to search: ";
            getline(cin, searchTitle);

            for (int i = 0; i < count; i++)
            {
                if (libraryItems[i]->getTitle() == searchTitle)
                {
                    libraryItems[i]->displayDetails();
                    found = true;
                }
            }

            if (!found)
                cout << "Item not found.\n";
        }
        else if (choice == 6 || choice == 7 || choice == 8)
        {
            if (count == 0)
            {
                cout << "Library is empty.\n";
                continue;
            }

            int index;

            cout << "Enter item number (1 to " << count << "): ";

            if (!(cin >> index))
            {
                cout << "Invalid item number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (index < 1 || index > count)
            {
                cout << "Invalid item number.\n";
                continue;
            }

            index--;

            if (choice == 6)
            {
                libraryItems[index]->checkOut();
            }
            else if (choice == 7)
            {
                libraryItems[index]->returnItem();
            }
            else
            {
                delete libraryItems[index];

                for (int i = index; i < count - 1; i++)
                {
                    libraryItems[i] = libraryItems[i + 1];
                }

                libraryItems[count - 1] = NULL;
                count--;

                cout << "Item removed successfully.\n";
            }
        }
        else if (choice == 9)
        {
            cout << "Exiting Library Management System.\n";
        }
        else
        {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 9);

    // Release memory
    for (int i = 0; i < count; i++)
    {
        delete libraryItems[i];
    }

    return 0;
}
