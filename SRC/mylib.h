#pragma once
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>
#include <vector>

using namespace std;

int insert(int id, string note);
int add(string note);
int remove(int id);
int list();
int edit(string new_note, int id);