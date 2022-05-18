#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
using namespace std;
ifstream f("example.txt");
class node {
public:
	int j{};
	node* next;
	node() : next(nullptr) {}
};
class llist {
public:
	node* h;
	llist() : h(nullptr) {}
	void add(int j)
	{
		node* x, * y;
		y = new(node);
		y->j = j;
		if (this->h == nullptr)
		{
			this->h = y;
		}
		else
		{
			x = this->h;
			while (x->next != nullptr)
			{
				x = x->next;
			}
			x->next = y;
		}
	}
	void print()
	{
		if (this->h)
		{
			node* x;
			x = this->h;
			while (x->next != nullptr)
			{
				cout << x->j << " ";
				x = x->next;
			}
			cout << x->j << " ";
		}
	}
};
struct Tnode {
	llist l1;
	string d;
	Tnode* l, * r;
	Tnode(string d,int m) :d(d), l(nullptr), r(nullptr) 
	{
		this->l1.add(m);
	}
};
class BSTree {
public:
	BSTree() :root(nullptr) {}
	BSTree(Tnode* rN) :root(rN) {}
	void insertion(string val, int m);//bruh
	void inOrder();
private:
	Tnode* root;
	void insertion(string val, int m, Tnode*& n);
	void inOrder(Tnode* n);
};
void BSTree::insertion(string val, int m)
{
	this->insertion(val, m, this->root);
}
void BSTree::insertion(string val, int m, Tnode*& n)
{
	if (n == nullptr)
	{
		n = new Tnode(val, m);
	}
	else
	{
		if (val < n->d)
		{
			this->insertion(val, m, n->l);
		}
		else if (val > n->d)
		{
			this->insertion(val, m, n->r);
		}
		else
		{
			n->l1.add(m);
		}
	}
}
void BSTree::inOrder(Tnode* n)
{
	if (n != nullptr)
	{
		inOrder(n->l);
		cout << n->d << " ";
		n->l1.print();
		cout << "\n";
		inOrder(n->r);
	}
}
void BSTree::inOrder()
{
	this->inOrder(this->root);
}
int main()
{
	string n;
	llist l;
	BSTree T;
	for (int i = 0;!f.eof(); i++)
	{
		getline(f, n);
		T.insertion(n, i);
	}
	T.inOrder();
}