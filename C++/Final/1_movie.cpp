// Create a class representing a `Movie` with attributes like `title`, `genre`, and `releasedYear`.
  // Demonstrate the instantiation of objects using array and accessing their attributes.
  
#include <iostream>
#include <string>
using namespace std;

class Movie
{
public:
    string title;
    string genre;
    int releasedYear;
};

int main()
{
    Movie m[3];

    // Input movie details
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter Movie Title: ";
        getline(cin, m[i].title);

        cout << "Enter Genre: ";
        getline(cin, m[i].genre);

        cout << "Enter Released Year: ";
        cin >> m[i].releasedYear;
        cin.ignore();
    }

    // Display movie details
    cout << "\n--- Movie Details ---";

    for (int i = 0; i < 3; i++)
    {
        cout << "\nMovie " << i + 1 << endl;
        cout << "Title: " << m[i].title << endl;
        cout << "Genre: " << m[i].genre << endl;
        cout << "Released Year: " << m[i].releasedYear << endl;
    }

    return 0;
}




