#include <iostream>
#include <vector>
#include "header/create_transaction.h"
#include "header/basic_methods.h"
using namespace std;

// --- Global Definations ---//

vector<string> users { "RAUNAK","IRA","MUSKAN","AKSHAT","SRISHTI" };
vector<long long int> y { 65536,97215,78217,9438,4458 };
vector<int> wallet { 10000,10000,10000,10000,10000 };
int plotnumber[101];
// y is the value of (g^x mod p);




int main()
{
	
	createGenesis();

	while(1)
	{

		int n = askFunctionality();
		system("clear");

		if (n == 1)
		{
			int user_index = transactionCreate(users,y);
			transaction(user_index, users, wallet, plotnumber);
		}

		else if (n == 2)
		{
			display();
		}

		else if (n == 3)
		{
			int m = verify_bc();
			if (m == 2)
				cout << "---------------------------Block Chain Verified-------------------------------\n\n" << endl;
			else
				cout << "Block Chain Not Verified\n\n" << endl;
		}

		else if (n == 4)
			return 0;

		else
		{
			cout << "Enter Valid Choice" << endl;
		}
	}

	return 0;

}