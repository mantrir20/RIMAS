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

using namespace std;

#define ROTRIGHT(word,bits) (((word) >> (bits)) | ((word) << (32-(bits))))
#define SSIG0(x) (ROTRIGHT(x,7) ^ ROTRIGHT(x,18) ^ ((x) >> 3))
#define SSIG1(x) (ROTRIGHT(x,17) ^ ROTRIGHT(x,19) ^ ((x) >> 10))
#define CH(x,y,z) (((x) & (y)) ^ (~(x) & (z)))
#define MAJ(x,y,z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))

#define BSIG0(x) (ROTRIGHT(x,7) ^ ROTRIGHT(x,18) ^ ((x) >> 3))
#define BSIG1(x) (ROTRIGHT(x,17) ^ ROTRIGHT(x,19) ^ ((x) >> 10))

#define EP0(x) (ROTRIGHT(x,2) ^ ROTRIGHT(x,13) ^ ROTRIGHT(x,22))
#define EP1(x) (ROTRIGHT(x,6) ^ ROTRIGHT(x,11) ^ ROTRIGHT(x,25))

string createhash(string message);
vector<unsigned long> resize_block(vector<unsigned long> input);
void cout_block_state(vector<unsigned long> block);
string show_as_hex(unsigned long input);
string show_as_binary(unsigned long input);
vector<unsigned long> convert_to_binary(const string input);
vector<unsigned long> pad_to_512bits(vector<unsigned long> block);
string compute_hash(const vector<unsigned long> block);