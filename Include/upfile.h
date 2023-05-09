#ifndef UPFILE_H
#define UPFILE_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "../include/object.h"

using namespace std;

void upFILE(string str, vector<booker> list_booker);
void readFIle(string str, vector<book> &list_book);
void stringProcessing(string str, vector<book> &list_book);
int count(string str);
int convert(string str);
void clearFile(string str);

#endif