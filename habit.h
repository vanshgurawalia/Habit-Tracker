#pragma once
#include <string>
#include <vector>

// Simple struct to store habit info
struct Habit {
    std::string name;
    int duration; // Total days user wants to track
    int streak = 0;
    std::vector<std::string> logs; // daily check-in comments
};

