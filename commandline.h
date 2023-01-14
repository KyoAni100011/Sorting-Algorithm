#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include "sort.h"
#include "sortCompare.h"
#include "data_generate.h"
using namespace std;

string dataOrder(int *, int, string);
void createTempArray(int *, int *, int);
void createFile(string);
void readFile(int *&, int &, string);
void writeFile(string, int *, int, string);

void commandline1(int argc, char *argv[]);
void commandline2(int argc, char *argv[]);
void commandline3(int argc, char *argv[]);
void commandline4(int argc, char *argv[]);
void commandline5(int argc, char *argv[]);
