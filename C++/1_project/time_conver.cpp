// time converter
#include <iostream>
using namespace std;

class TimeConverter
{
public:

    // Convert seconds to HH:MM:SS
    void secondsToTime()
    {
        int totalSeconds, hours, minutes, seconds;

        cout << "Enter total seconds: ";
        cin >> totalSeconds;

        hours = totalSeconds / 3600;
        minutes = (totalSeconds % 3600) / 60;
        seconds = totalSeconds % 60;

        cout << "HH:MM:SS => "
             << hours << ":"
             << minutes << ":"
             << seconds << endl;
    }

    // Convert HH:MM:SS to seconds
    void timeToSeconds()
    {
        int hours, minutes, seconds, totalSeconds;

        cout << "Enter hours: ";
        cin >> hours;

        cout << "Enter minutes: ";
        cin >> minutes;

        cout << "Enter seconds: ";
        cin >> seconds;

        totalSeconds = (hours * 3600) + (minutes * 60) + seconds;

        cout << "Total seconds: " << totalSeconds << endl;
    }
};

int main()
{
    TimeConverter t;

    cout << "1. Seconds to HH:MM:SS" << endl;
    cout << "2. HH:MM:SS to Seconds" << endl;

    int choice;
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1)
    {
        t.secondsToTime();
    }
    else if (choice == 2)
    {
        t.timeToSeconds();
    }
    else
    {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
