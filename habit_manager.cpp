#include "habit_manager.h"
#include <iostream>
using namespace std;

// Adding a new habit
void addHabit(vector<Habit>& habits) {
    Habit h;
    cout << "Enter habit name: ";
    cin.ignore();
    getline(cin, h.name);
    cout << "Duration (in days): ";
    cin >> h.duration;
    habits.push_back(h);
    cout << "Habit added!\n";
}

// User checks in for today
void checkIn(vector<Habit>& habits) {
    if (habits.empty()) {
        cout << "No habits yet!\n";
        return;
    }

    listHabits(habits);
    int index;
    cout << "Enter habit index (0 to " << habits.size() - 1 << "): ";
    cin >> index;

    if (index >= 0 && index < habits.size()) {
        string comment;
        cout << "Reflection for today: ";
        cin.ignore();
        getline(cin, comment);

        habits[index].logs.push_back(comment);
        habits[index].streak++;
        cout << "Check-in recorded!\n";
    } else {
        cout << "Invalid index.\n";
    }
}

// View logs for a specific habit
void viewLogs(const vector<Habit>& habits) {
    if (habits.empty()) {
        cout << "No habits yet!\n";
        return;
    }

    listHabits(habits);
    int index;
    cout << "Enter habit index to view logs: ";
    cin >> index;

    if (index >= 0 && index < habits.size()) {
        cout << "Logs for: " << habits[index].name << endl;
        for (int i = 0; i < habits[index].logs.size(); ++i) {
            cout << "Day " << (i + 1) << ": " << habits[index].logs[i] << endl;
        }
    } else {
        cout << "Invalid index.\n";
    }
}

// Just showing habits to user
void listHabits(const vector<Habit>& habits) {
    if (habits.empty()) {
        cout << "No habits found.\n";
        return;
    }

    for (size_t i = 0; i < habits.size(); ++i) {
        cout << i << ". " << habits[i].name << " | Streak: " << habits[i].streak << " days" << endl;
    }
}
