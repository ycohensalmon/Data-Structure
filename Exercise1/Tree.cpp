#include "Tree.h"

//searching string value in the decision tree and makes pointer "p" to point on his node
//and the parent to point on his parent node
void Tree::search(Node*& p, string val, Node*& parent, Node* p2, Node* parent2)
{
	//the current node is the one we search for
	if (p2->value == val)
	{
		p = p2;
		parent = parent2;
		return;
	}

	//the value alredy found
	if (p->value == val)
		return;

	//searching in the all sons
	for (list<Answer*>::iterator it = p2->answersList.begin(); it != p2->answersList.end(); ++it)
	{
		parent2 = p2;
		search(p, val, parent, (*it)->son, parent2);
	}

}

//printing the backword path from the current value until the root
bool Tree::searchAndPrint(Node* p, string val)
{
	Node* parent, *node = search(p, val, parent);

	//we are in the root
	if (root->value == val)
	{
		cout << node->value << endl;
		return true;
	}

	//the value not found
	if (node->value != val)
		return false;

	//printing the current value and sending the parent value
	cout << node->value << endl;
	searchAndPrint(root, parent->value);
	return true; 
}

//printing all the desicion tree hierarchically
void Tree::print(Node* p, int level)
{
	//printing the current value
	cout << p->value << endl;

	//printing the answer and sending the son
	for (list<Answer*>::iterator it = p->answersList.begin(); it != p->answersList.end(); it++)
	{
		cout << (*it)->ans << endl;
		print((*it)->son, level++);
	}
}

//print the next question by the user answer
void Tree::process(Node* p)
{
	//printing current question
	cout << p->value << endl;

	//the qusetion is actualy answer without answers
	if (p->answersList.empty())
		return;

	//getting answer from user
	string str;
	cin >> str;

	//searching the user answer in answers list and sending the question of this answer
	for (list<Answer*>::iterator it = p->answersList.begin(); it != p->answersList.end(); it++)
	{
		if ((*it)->ans == str)
			process((*it)->son);
	}
}

//deleting a node with all his sons
void Tree::deleteAllSubTree(Node* p)
{
	//deleting the sons first 
	while (!(p->answersList.empty()))
	{
			deleteAllSubTree(p->answersList.front()->son);
			p->answersList.pop_front();
	}
	
	//deleting the root
	p->answersList.clear();
	delete p;
	return;
}


void Tree::addRoot(string newval)
{
	root = new Node(newval);
}

//adding answer and question for this answer
bool Tree::addSon(string fatherquestion, string newanswer, string newval)
{
	//searching for the father of the new question
	Node* parent;
	Node* p = search(root, fatherquestion, parent);

	//the father of the question exists
	if (p->value == fatherquestion)
	{
		Node* node = new Node(newval);
		Answer* answer = new Answer(newanswer, node);
		p->answersList.push_back(answer);
		p->setIsLeaf(false);

		return true;
	}
	//the father of this question not exists
	return false;
}

//deleting the sub tree without the current node
void Tree::deleteSubTree(string val)
{
	Node* parent;
	Node* p = search(root, val, parent);

	//if the value not found
	if (p->value != val)
		return;

	//deleting all the sons and the answers list
	while (!p->answersList.empty())
	{
		deleteAllSubTree(p->answersList.front()->son);
		p->answersList.pop_front();
	}
	p->setIsLeaf(true);
 }
