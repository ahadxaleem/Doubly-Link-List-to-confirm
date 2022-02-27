#include<iostream>
#include<conio.h>
using namespace std;
class node
{
private:
	node* nextnodeptr;
	node* prenodeptr;
	int data;
public:
	node(int data=0)
	{
		this->data = data;
		nextnodeptr = NULL;
		prenodeptr = NULL;
	}
	void setdata(int d)
	{
		data = d;
	}
	void setnextnodeptr(node*p)
	{
		nextnodeptr = p;
	}
	void setprenodeptr(node*p)
	{
		prenodeptr = p;
	}
	int getdata()
	{
		return data;
	}
	node* getnextnodeptr()
	{
		return nextnodeptr;
	}
	node* getprenodeptr()
	{
		return prenodeptr;
	}
};
class list
{
private:
	node*header;
	node*taler;
public:
	list()
	{
		header = NULL;
		taler=new node();
		taler->setprenodeptr(header);
	}
	void insertatstart(node* n);
	void insertattail(node* n);
	void insertatmiddle(int i, node* n);
	int search(int value);
	void update(int i, int value);
	void deleteathead();
	void deleteattale();
	void deleteatmiddle(int i);
	void display();
	void menu();
	~list();
};
void list::insertatstart(node* p)
{
	if (header == NULL)
	{
		header = p;
		header->setnextnodeptr(taler);
		taler->setprenodeptr(header);
	}
	else
	{
		node*temp = header;
		p->setnextnodeptr(header);
		header = p;
		p = temp;
		p->setprenodeptr(header);
	}
}
void list::insertattail(node* p)
{
	if (header == NULL)
	{
		header = p;
		header->setnextnodeptr(taler);
		taler->setprenodeptr(header);
	}
	else
	{
		node *rptr = taler->getprenodeptr();
		rptr->setnextnodeptr(p);
		p->setprenodeptr(rptr);
		p->setnextnodeptr(taler);
		taler->setprenodeptr(p);
	}
}
void list::insertatmiddle(int i, node* n)
{
	if (header == NULL)
	{
		header = n;
	}
	else
	{
		node*rptr = header;
		int curr_ind = 1;
		while (curr_ind != i)
		{
			rptr = rptr->getnextnodeptr();
			curr_ind++;
		}
		n->setnextnodeptr(rptr->getnextnodeptr());
		rptr->setnextnodeptr(n);
	}
}

void list::display()

{
	node *rptr = header;
	while (rptr->getnextnodeptr() != taler)
	{
		cout << rptr->getdata() << endl;
		rptr = rptr->getnextnodeptr();
	}
	cout << rptr->getdata() << endl << endl;
}
int list::search(int value)
{
	if (header == NULL)
	{
		return -1;
	}
	else
	{
		int curr_ind = 0;
		node *rptr = header;
		while (rptr->getnextnodeptr() != NULL)
		{
			if (rptr->getdata() == value)
			{
				return curr_ind;
			}
			rptr = rptr->getnextnodeptr();
			curr_ind++;
		}return -1;
	}
}
void list::update(int i, int value)
{
	node*rptr = header;
	int curr_ind = 0;
	while (curr_ind != i)
	{
		rptr = rptr->getnextnodeptr();
		curr_ind++;
	}
	rptr->setdata(value);
}
void list::deleteathead()
{
	node*temp = header;
	header = header->getnextnodeptr();
	delete temp;
}
void list::deleteattale()
{
	node *rptr = taler->getprenodeptr();
	taler->setprenodeptr(rptr->getprenodeptr());
	(rptr->getprenodeptr())->setnextnodeptr(taler);
	delete rptr;
}
void list::deleteatmiddle(int i)
{
	node*rptr = header;
	int curr_ind = 0;
	while (curr_ind != i)
	{
		rptr = rptr->getnextnodeptr();
		curr_ind++;
	}
	(rptr->getprenodeptr())->setnextnodeptr(rptr->getnextnodeptr());
	delete rptr;
}
void list::menu()
{
	while (1)
	{
		system("CLS");
		cout << "***************************************************" << endl;
		cout << "********* Welcome user this is a list class *******" << endl;
		cout << "***************************************************" << endl << endl;
		cout << "This list has 1,2,3 values to respective index starting from 0.." << endl;
		cout << "You can perform the following operation on the list...." << endl << "1. insert node at the start." << endl;
		cout << "2. insert node at the end." << endl << "3. insert node at any index." << endl << "4. search a specific value." << endl << "5. update a value." << endl;
		cout << "6. remove a node from start." << endl << "7. remove from end." << endl << "8. remove value from any index." << endl << "9. Display the list.\n\n";
		cout << "Please select an option through 1,2,3,4,5,6....";
		int x, y;
		cin >> x;
		switch (x)
		{
		case 1:
		{
			system("CLS");
			cout << "Enter the value u want to insert : ";
			cin >> y;
			insertatstart(new node(y));
			cout << "\n value added successfully :" << endl;
			break;
		}
		case 2:
		{
			system("CLS");
			cout << "Enter the value u want to insert : ";
			cin >> y;
			insertattail(new node(y));
			cout << "\n value added successfully :" << endl;
			break;
		}
		case 3:
		{
			system("CLS");
			int temp;
			cout << "Enter the index :";
			cin >> temp;
			cout << "Enter the value u want to insert : ";
			cin >> y;
			insertatmiddle(temp, new node(y));
			cout << "\n value added successfully :" << endl;
			break;
		}
		case 4:
		{
			system("CLS");
			cout << "Enter the value u want to search : ";
			cin >> y;
			int temp = search(y);
			if (temp == -1)
			{
				cout << "\n no such node exists ....." << endl;
			}
			else
			{
				cout << "\n node found at index " << temp << endl;
			}
			break;
		}
		case 5:
		{
			system("CLS");
			int i;
			cout << "Enter the index : ";
			cin >> i;
			cout << "Enter the value u want to update : ";
			cin >> y;
			update(i, y);
			cout << "\n value updated successfully......." << endl;
			break;
		}
		case 6:
		{
			system("CLS");
			deleteathead();
			cout << "value deleted successfully.....";
			break;
		}
		case 7:
		{
			system("CLS");
			deleteattale();
			cout << "value deleted successfully.....";
			break;
		}
		case 8:
		{
			system("CLS");
			cout << "Enter the index u want to remove :";
			cin >> y;
			deleteatmiddle(y);
			cout << "value deleted successfully.....";
			break;
		}
		case 9:
		{
			system("CLS");
			display();
			break;
		}
		default:
		{
			cout << "You entered a wrong option....";
			break;
		}
		}
		int t;
		cout << "\nEnter 1 to return to the main menu and any other to exit...";
		cin >> t;

		if (t != 1)
		{
			break;
		}

	}

}
list::~list()
{
	while (header->getnextnodeptr() != NULL)
	{
		node*rptr = header;
		header = header->getnextnodeptr();
		delete rptr;
	}
	delete taler;
}
void main()

{

	list L1;

	L1.insertattail(new node(1));

	L1.insertattail(new node(2));

	L1.insertattail(new node(3));

	L1.menu();
	_getch();
}