#include "header/basic_methods.h"
using namespace std;
struct Node
{
	char plotno[20];
	string datetime;
	char owner[25];
	string curHASH;
	string prevHASH;
	struct Node *next;
};

struct Node* head = NULL;

int arr[101]; //stores nonce
int f = 0; // stores no of plot sold
int g = 0; // no idea
int barr = 900000; // no idea

string printtime()
{
  time_t rawtime;
  struct tm * timeinfo;
  char buffer[80];
  time (&rawtime);
  timeinfo = localtime(&rawtime);
  strftime(buffer,sizeof(buffer),"%d-%m-%Y %H:%M:%S",timeinfo);
  std::string str(buffer);
  return str;
}

string insert(char *pno, char *name, string phash)
{
	struct Node* new_node = (struct Node*) calloc(1, sizeof(struct Node));
	strcpy(new_node->plotno, pno);
	strcpy(new_node->owner, name);
	new_node->datetime = printtime();
	string o(new_node->owner);
	string pn(new_node->plotno);
	int nonce = 0;
	while (1)
	{
		
		char non[2] = { (char(nonce)) };
		string nonc(non);
		new_node->curHASH = createhash(o + new_node->prevHASH + pn + new_node->datetime + nonc);
		if (new_node->curHASH[0] == '0' && new_node->curHASH[1] == '0' && new_node->curHASH[2] == '0' && new_node->curHASH[3] == '0' && new_node->curHASH[4] == '0')
		{
			
			arr[f] = nonce;
			f++;
			break;
		}
		nonce++;
	}


	new_node->prevHASH = phash;

	new_node->next = head;
	head = new_node;

	return new_node->curHASH;
}

void display()
{
	cout << "---------------------BLOCK DETAILS-----------------------" <<endl;
	cout << "-----------------------------------------------------------------------------------------------------------" << endl;
	int n = 0;
	
	struct Node* ptr;
	ptr = head;

	while (ptr != NULL)
	{
		n++;
		ptr = ptr->next;
	}
	
	ptr = head;

	while (ptr != NULL)
	{
		cout << "\n";
		cout << "Block : " << n << endl;
		cout << "Owner : " << ptr->owner << endl;
		cout << "Plot No : " << ptr->plotno << endl;
		cout << "DateTime : " << ptr->datetime << endl;
		cout << "PrevHASH : " << ptr->prevHASH << endl;
		cout << "CurrHASH : " << ptr->curHASH << endl;
		cout << "\n";
		n--;

		ptr = ptr->next;
	}
	cout << "-----------------------------------------------------------------------------------------------------------" << endl;
}

void createGenesis()
{
	char pno[20] = "0", name[25] = "GENESIS BLOCK RIMAS";
	string phash = "bf4b640926f1aec11da6359154e592fea9b4512f572934694b66706445f284d6";
	phash = insert(pno, name, phash);
}

int askFunctionality()
{
	cout << "------------------------For new transaction       : press 1------------------------" << endl;
	cout << "----------------------- For viewing block         : press 2------------------------" << endl;
	cout << "----------------------- For verifying block-chain : press 3------------------------" << endl;
	cout << "----------------------- End Program               : press 4------------------------" << endl;
	cout << "ENTER YOUR CHOICE " << endl;

	int n;
	cin >> n;

	return n;
}


int verify_bc()
{
	g = f;
	string calHASH;
	struct Node* ptr;

	ptr = head;
	int nonce = 0;
	while (ptr != NULL)
	{
		while (1)
		{

			char non[2] = { (char(nonce)) };
			string nonc(non);
			calHASH = createhash(ptr->owner + ptr->prevHASH + ptr->plotno + ptr->datetime + nonc);
			if (calHASH[0] == '0' && calHASH[1] == '0' && calHASH[2] == '0' && calHASH[3] == '0' && calHASH[4] == '0')
			{
				if (nonce == barr)
				{
					g--;
					break;
				}

				else if (nonce == arr[g])
				{
					g--;
					break;
				}

				else
				{
					cout << " BLOCK VERIFIED";
					cout << endl;
					break;
				}
			}
			nonce++;
		}
		ptr = ptr->next;
	}
	ptr = head;
	return 2;
}