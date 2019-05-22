#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node* next;
};

node* head;

// void insert(int x)
// {
//     //  insertion is done at the beginning of the list
// 	node* temp = new node();
// 	temp->data = x;
// 	temp->next = head;
// 	head = temp;
// }

void insert(int x, int n)
{
	node* temp = new node();
	temp->data = x;
	temp->next = NULL;
	if(n == 1){
		temp->next = head;
		head = temp;
		return;
	}
	node* temp1 = head;
	for(int i=0; i<n-2; i++)
	{
		temp1 = temp1->next;
	}
	temp->next = temp1->next;
	temp1->next = temp;
}

void del(int n)
{
	node* temp = head;
	if(n == 1){
		head = temp->next;
		free(temp);
		print();
		return;
	}
	for(int i=0; i<n-2; i++)
	{
		temp = temp->next;
	}
	node* temp1 = temp->next;
	temp->next = temp1->next;
	free(temp1);
	print();
}

void print()
{
	node* temp = head;
	cout << "Linked list is : ";
	while(temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << "\n-----\n";
}

int main()
{
	head = NULL;
	cout << "How many nodes would you like to insert?\n";
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cout << "Enter the number : \n";
		int x;
		cin >> x;
		cout << "Position : \n";
		int idx;
		cin >> idx;
		insert(x, idx);
		print();
	}
	cout << "No. of deletions: \n";
	int d;
	cin >> d;
	for(int i=0; i<d; i++)
	{
		cout << "Enter position of node to be deleted: \n";
		int pos;
		cin >> pos;
		del(pos);
	}

	return 0;
}
 