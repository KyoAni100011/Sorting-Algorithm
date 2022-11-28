<<<<<<< HEAD
#pragma once
=======
>>>>>>> ec5a860ca52402116f8f8addbbb5ddf33642d378
#include <iostream>
#include <string>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
<<<<<<< HEAD
=======
#include <cstring>
>>>>>>> ec5a860ca52402116f8f8addbbb5ddf33642d378
#include <algorithm>
#include "sort.h"
#include "sortCompare.h"
#include "data_generate.h"
using namespace std;

string dataOrder(int *, int, string);
void createTempArray(int *, int *, int);
void createFile(string);
void readFile(int *&, int &, string);
<<<<<<< HEAD
void writeFile(string, int *, int, string);
=======
void writeFile(int *, int, string);
>>>>>>> ec5a860ca52402116f8f8addbbb5ddf33642d378

void commandline1(int argc, char *argv[]);
void commandline2(int argc, char *argv[]);
void commandline3(int argc, char *argv[]);
void commandline4(int argc, char *argv[]);
void commandline5(int argc, char *argv[]);