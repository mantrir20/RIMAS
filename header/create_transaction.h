#include <iostream>
#include<ctime>
#include<string>
#include <sstream>
#include <bitset>
#include <vector>
#include <iomanip>
#include <cstring>
#include<random>
#include<math.h>
#include<stdlib.h>
#include<bits/stdc++.h>
#include "basic_methods.h"
using namespace std;

int verify(string gn, vector<string> users, vector<long long int> y);
void transaction(int user_index, vector<string> users, vector<int> &wallet, int plotnumber[]);
int transactionCreate(vector<string> users,vector<long long int> y);