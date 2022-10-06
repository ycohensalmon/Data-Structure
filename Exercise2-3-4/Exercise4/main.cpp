#include <iostream>
#include <queue>
#include <list>
#include <string>
#include <cmath>
#include "HuffmanTree.h"
using namespace std;


int main()
{
	char choice;
	string word;

	HuffmanTree* t = new HuffmanTree();
	cout << "enter E to encode a text\n";
	cout << "enter D to decode a text\n";
	cout << "enter X to exit\n";

	do
	{
		cin >> choice;
		switch (choice)
		{
		case 'E':
		{
			cout << "enter the original text" << endl;
			cin >> word;

			//Build Huffman tree given the data inside "word".
			//Then find the code of each letter.
			//Then print the output - number of leaves, order of letters, tree structure and the encoded text - according to the explanation in the exercise.

			t->buildHuffmanTree(word);
			cout << "The encoded string is\n";
			cout << t->getLeaves() << endl;
			cout << t->getOrderOfLetters() << endl;
			cout << t->getTreeStructure() << "\n";
			cout << t->getEncodedText(word) << "\n";

			break;
		}
		case 'D':
		{
			//input the number of leaves, the  order of letters, tree structure and the encoded text.
			//build the Huffman Tree according to the tree strcture. put the letters in the leaves according to the given order. 
			//Given the Huffman Tree and the encoded text, find the original text, and print it.

			int num;
			string lettersOrder, treeStructure, encodedTxt;
			cout << "enter n\n";
			cin >> num;
			cout << "enter the letters\n";
			cin >> lettersOrder;
			cout << "enter the encoded structure\n";
			cin >> treeStructure;
			cout << "enter the encoded text\n";
			cin >> encodedTxt;
			t->setNumberOfLeaves(num);
			if (t->rebuildHuffmanTree(lettersOrder, treeStructure))
			{
				cout << "The decoded string is\n";
				cout << t->getDecodedText(encodedTxt) << endl;
			}
			else
				cout << "ERROR\n";
			break;
		}


		}

	} while (choice != 'X');
	cout << "bye";
	return 0;
}