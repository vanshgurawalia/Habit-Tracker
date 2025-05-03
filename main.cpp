#include "habit_manager.h"
#include "data_handler.h"
#include <iostream>
using namespace std;

int main() {
    vector<Habit> habits = loadHabits("habit_data.txt");

    while (true) {
        cout << "\n--- Habit Tracker ---\n";
        cout << "1. Add Habit\n2. Check-in\n3. View Logs\n4. List Habits\n5. Save and Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: addHabit(habits); break;
            case 2: checkIn(habits); break;
            case 3: viewLogs(habits); break;
            case 4: listHabits(habits); break;
            case 5: saveHabits(habits, "habit_data.txt"); return 0;
            default: cout << "Invalid choice.\n"; break;
        }
    }
}
