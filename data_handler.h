#pragma once
#include "habit.h"
#include <vector>
#include <string>

std::vector<Habit> loadHabits(const std::string& filename);
void saveHabits(const std::vector<Habit>& habits, const std::string& filename);
