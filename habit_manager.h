#pragma once
#include "habit.h"
#include <vector>

void addHabit(std::vector<Habit>& habits);
void checkIn(std::vector<Habit>& habits);
void viewLogs(const std::vector<Habit>& habits);
void listHabits(const std::vector<Habit>& habits);
