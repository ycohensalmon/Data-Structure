#include "Node.h"
#include <iostream>
#include <list>
#include <string>
using namespace std;

//Tree: the Decision Tree
class Tree
{
	Node* root;

	//searching string value in the decision tree and makes pointer "p" to point on his node
	//and the parent to point on his parent node
	void search(Node*& p, string val, Node*& parent, Node* p2, Node* parent2);

	//returns node t where the string equals val. If t has a prent, the pointer parent will contain its address.
	Node* search(Node* p, string val, Node*& parent)
	{
		Node* p2 = p, * parent2 = parent;
		search(p, val, parent, p2, parent2);
		return p;
	};
	 
	//printing the backword path from the current value until the root
	bool searchAndPrint(Node* p, string val);

	//printing all the desicion tree hierarchically
	void print(Node* p, int level = 0);

	//print the next question by the user answer
	void process(Node* p);
public:
	Tree() { root = NULL; }
	~Tree() {
		deleteAllSubTree(root);
		root = 0;
	}

	//deleting all the sub tree from the current node including the current node
	void deleteAllSubTree(Node* t);
	void addRoot(string newval);

	//adding answer and question for this answer
	bool addSon(string fatherquestion, string newanswer, string newval);
	
	void searchAndPrint(string val)
	{
		if (!searchAndPrint(root, val))
			cout << "Value not found" << endl;
	}

	void searchAndPrintArea(string val)
	{
		Node* parent = nullptr;
		Node* area = search(root, val, parent);
		if (area) print(root);
	}
	void printAllTree() { print(root); }
	//string printToString(Node* p);
	//string printToString() { return printToString(root); }

	//deleting the sub tree without the current node
	void deleteSubTree(string val);
	void process() { process(root); }
};

