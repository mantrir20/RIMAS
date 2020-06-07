#include "header/create_transaction.h"
#include "header/basic_methods.h"
using namespace std;


int verify(string gn, vector<string> users, vector<long long int> y)
{
	
	long long int h, r, g = 2, p = 99929, s;
	int b, user_index=0;

	for (user_index; user_index < users.size(); user_index++)
	{
		if(user_index == users.size())
		{
			cout << "User Not in Database" << endl;
			cout << "Invalid User" << endl;
			return 0;
		}

		if (gn != users[user_index])
			continue;
		else
		{
			break;
		}	
	}

	while(1)
	{
			system("clear");
			cout << endl;
			cout << "USER AUTENTICATION"<<endl;
			cout << "------------------------------------------------------------------------------------" << endl; 
			cout << "P = 99929, G = 2, 0 <= r < 20, s = ( r + bx )mod( p-1 ), x= YOUR UNIQUE ID" << endl; 
			cout << "------------------------------------------------------------------------------------\n\n";
			cout << "Enter r : ";
			cin >> r;
			if (r <= 20 && r >= 0)
			{
				h = (((long long int)(pow(g, r))) % p);

				//random bit generation
				/*mt19937 e(random_device{}());
				bernoulli_distribution d;
				for (int n = 0; n < 1; ++n)
					b = d(e);*/
				b = 1;
				cout << "\n\n------------------------------------------------------------------------------------" << endl;
				cout << "Your b is " << b << endl;
				cout << "------------------------------------------------------------------------------------" << endl;
				cout << "Enter s : ";
				cin >> s;

				int Z;
				int A = ( (long long int)( pow(g, s) )) % p;
				int B = (((long long int)(h * (long long int)(pow(y[user_index], b))) % p) + y[user_index]);
				
				cout << "\n\n------------------------------------------------------------------------------------" << endl;
				cout << "A = " << A << endl;
				cout << "------------------------------------------------------------------------------------" << endl;
				cout << "Z = A + (( g^x )modp)" << endl << "Enter Z : ";
				cin >> Z;
				
				if (Z == B)
					break;
				else
				{
					cout << "Unable to Authenticate";
					continue;
				}
				
			}
			else
			{
				cout << " ENTER A VALID r ";
			}
	}

	return 1;
}

void transaction(int user_index, vector<string> users, vector<int> &wallet, int plotnumber[])
{
	cout << endl;
	cout << " OWNER'S NAME : " + users[user_index] + "\n\n\n";
	string oname = users[user_index];
	int nh; //no. of house the user wants to buy	
	while(1)
	{
		cout << " ENTER NUMBER OF HOUSES YOU WANT TO BUY [EACH HOUSE IS WORTH 1000 BUCKS] : ";
		cin >> nh;

		if (nh * 1000 <= wallet[user_index])
		{
			wallet[user_index] = wallet[user_index] - (nh * 1000);
			cout << " YOUR UPDATED WALLET AMOUNT : " << wallet[user_index];
			break;
		}

		else
		{
			cout << endl;
			cout << "Not Enough Credit" <<endl;
			cout << "Enter Value less than ";
			cout << (wallet[user_index]/1000) + 1 << endl; 
		}
	}

	while(nh)
	{
		cout << "\n";
		cout << " ENTER REQUIRED PLOT NUMBER : ";

		char pno[20], name[25];
		string phash = "bf4b640926f1aec11da6359154e592fea9b4512f572934694b66706445f284d6";

		cin >> pno;
		stringstream geek(pno);
		int j = 0;
		geek >> j;

		if (plotnumber[j] == 0) 
		{
			plotnumber[j] = 1;
			nh--;
			cout << " ENTER NAME OF HOUSE : ";
			cin >> name;
			//cout<< name;
			phash = insert(pno, name, phash);
		}

		else
		{
			cout << endl;
			cout << " This plot is already sold, choose another";
		}
	}
}


int transactionCreate(vector<string> users, vector<long long int> y)
{

	string givenname;

	while(1)
	{
		cout << "Enter name : ";
		cin >> givenname;
		cout << "\n";

		if( verify(givenname,users,y) )
			break;
	}

	system("clear");
	cout << " User Authenticated...";

	for (int user_index = 0; user_index < users.size(); user_index++)
	{
		if (givenname != users[user_index])
			continue;
		else
		{
			return user_index;
		}	
	}

	return 0;
}
