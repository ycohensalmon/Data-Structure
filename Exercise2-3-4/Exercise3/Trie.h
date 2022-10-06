#pragma once
#include <string>
#include<iostream>
#include<stack>
using namespace std;
class Trie
{
public:
	class TrieNode
	{
	public:
		TrieNode* children[26]; //size of the alpha beth
		TrieNode* parent;
		bool isEndWord = false;
		bool isLeaf = false;
		char currentLetter;

		TrieNode(TrieNode* p, char letter)
		{
			parent = p;
			currentLetter = letter;
		}
	};
	TrieNode* root;

	Trie() { root = new TrieNode(nullptr, 0); }

	void insert(string word);
	bool search(string word);
	bool Delete(string str);
	int printAutoSuggestions(string prefix);
	void printAutoSuggestions(TrieNode* p);
	bool IsLeaf(TrieNode* node);
	void printPath(TrieNode* p);

	TrieNode* getEndWordPointer(string word)
	{
		TrieNode* p = root;

		for (int i = 0; i < word.length(); i++)
		{
			char j = word[i];

			if (p->children[j - 'a'] == nullptr) // if the word dont exist
			{
				p = nullptr;
				break;
			}

			p = p->children[j - 'a']; // get the son
		}

		return p; // return the chars in the word tha exist in the tree
	}
};

