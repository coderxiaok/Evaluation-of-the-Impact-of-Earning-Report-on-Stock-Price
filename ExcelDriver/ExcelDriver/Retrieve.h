
#ifndef test11_Retrieve_h
#define test11_Retrieve_h

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

int write_data(void *ptr, int size, int nmemb, FILE *stream);
int write_data2(void *ptr, size_t size, size_t nmemb, void *data);
void *myrealloc(void *ptr, size_t size);
void Retrieve_Data(char *StockUrl, char *SPYUrl, vector<double>& v);

#endif