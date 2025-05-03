#include "data_handler.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

// Load saved data from file
vector<Habit> loadHabits(const string& filename) {
    vector<Habit> habits;
    ifstream file(filename);
    if (!file) return habits;

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Habit h;
        getline(ss, h.name, ',');
        ss >> h.duration;
        ss.ignore();
        ss >> h.streak;
        ss.ignore();
        string comment;
        while (getline(ss, comment, '|')) {
            h.logs.push_back(comment);
        }
        habits.push_back(h);
    }

    return habits;
}

// Save data to file so it's not lost
void saveHabits(const vector<Habit>& habits, const string& filename) {
    ofstream file(filename);
    for (const auto& h : habits) {
        file << h.name << "," << h.duration << "," << h.streak;
        for (const auto& log : h.logs) {
            file << "|" << log;
        }
        file << "\n";
    }
}
