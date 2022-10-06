#include "Trie.h"

int Trie::printAutoSuggestions(string prefix)
{
	TrieNode* p = getEndWordPointer(prefix);

	if (p == nullptr) // if there are no words that begin with this chars
		return 0;

	if (p->isEndWord) // if the word that was entred already exsist
		cout << prefix << endl;

	printAutoSuggestions(p); // print the other words that begin with the same chars

	return 1;
}

bool Trie::search(string word)
{
	TrieNode* p = getEndWordPointer(word);

	if (p != nullptr && p->isEndWord == true) // if the word exist in the tree
		return true;

	return false;
}

bool Trie::Delete(string str)
{
	if (!search(str)) // if the string is empty
		return false;

	TrieNode* node = getEndWordPointer(str);
	int j = str.length() - 1;

	while (node != root)
	{
		if (!node->isLeaf)
		{
			node->isEndWord = false;
			break;
		}
		else
		{
			node = node->parent;                  // get the parent
			delete node->children[str[j] - 'a'];  // delete the children
			node->children[str[j] - 'a'] = nullptr;
			if (IsLeaf(node))
				node->isLeaf = true; // update the leaf
		}
		
		j--;
	}

	return true;
}

bool Trie::IsLeaf(TrieNode* node)
{
	for (int i = 0; i < 26; i++)
		if  (node->children[i] != nullptr)
			return false;
	return true;
}

void Trie::insert(string word)
{
	if (search(word))
		return;

	TrieNode* p = root;

	for (size_t i = 0; i < word.length(); i++)
	{
		char j = word[i];


		if (p->children[j - 'a'] != nullptr)  // if the first char in the tree is empty
			p = p->children[j - 'a'];         // creat a new son for the general root

		else // if the tree if this char already exist
		{
			p->children[j - 'a'] = new TrieNode(p, j); // creat a new node in the encien tree
			p = p->children[j - 'a'];
		}

		if (p->isLeaf == true) // if the word that are inserted is longer from similar word with less char
			p->isLeaf = false;
	}

	if (!p->children)
		p->isLeaf = true;
	p->isEndWord = true;
}

void Trie::printAutoSuggestions(TrieNode* p)
{
	for (size_t i = 0; i < 26; i++)
	{
		if (p->children[i] != nullptr) // only on trees that are not empty
		{

			if (p->children[i]->isEndWord)
				printPath(p->children[i]); // print the word

			printAutoSuggestions(p->children[i]); // send the child (recursive)
		}
	}
}

void Trie::printPath(TrieNode* p)
{
	stack<char> path;

	while (p->parent != nullptr)
	{
		path.push(p->currentLetter);

		p = p->parent;
	}

	while (!path.empty())
	{
		cout << path.top();
		path.pop();
	}

	cout << endl;
}