#pragma once
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>
#include <vector>

using namespace std;

int add(string note, bool rewrite);
int remove(int id);
int list();