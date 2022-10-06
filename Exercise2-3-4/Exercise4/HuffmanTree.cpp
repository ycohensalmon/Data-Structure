#include "HuffmanTree.h"
#include <queue>
#include <map>

void HuffmanTree::buildHuffmanTree(string word)
{
	// if the tree is not rmpty
	if (root)
	{
		// reseat the tree
		clear(root);
		root = NULL;
		numbersLeaves = 0;
	}

	HuffmanNode* left, * right, * top;
	priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNode> minHeap;
	map<char, int> chars;

	// the num of levels in the huffman tree
	for (std::string::iterator it = word.begin(); it != word.end(); ++it)
		chars[*it] += 1;

	// the huffman tree
	for (std::map<char, int>::iterator it = chars.begin(); it != chars.end(); ++it)
		minHeap.push(new HuffmanNode(it->first, it->second));

	// push the values on the huffman tree
	while (minHeap.size() != 1) {

		left = minHeap.top();
		minHeap.pop();

		right = minHeap.top();
		minHeap.pop();

		top = new HuffmanNode('@', left->frequency + right->frequency);

		top->left = left;
		top->right = right;

		minHeap.push(top);
	}

	root = minHeap.top();
	numbersLeaves = chars.size();
}

bool HuffmanTree::rebuildHuffmanTree(string text, string tree)
{
	int sumOfleavesByTreeStructure = 0;
	for (size_t i = 0; i < tree.length(); i++)
	{
		if (tree[i] == '1')
			sumOfleavesByTreeStructure++;
	}

	if (sumOfleavesByTreeStructure != numbersLeaves)
		return false;


	// if the tree is not rmpty
	if (root)
	{
		// reseat the tree
		clear(root);
		root = NULL;
		numbersLeaves = 0;
	}


	int i = 0, j = 0;
	root = new HuffmanNode;
	// initilize the tree
	rebuildHuffmanTree(root, text, tree, i, j);
	return true;

}


string HuffmanTree::getEncodedText(string word)
{
	map<char, string> codesEncode;
	calculateAllCodes(root, "", codesEncode);

	string str;
	for (std::string::iterator it = word.begin(); it != word.end(); ++it)
		str += codesEncode[*it];
	return str;
}

string HuffmanTree::getDecodedText(string encodedText)
{
	string decodedText, code;
	map<string, char> codesDecode;

	calculateAllValues(root, "", codesDecode);

	for (std::string::iterator it = encodedText.begin(); it != encodedText.end(); ++it)
	{
		code += *it;
		if (!(codesDecode.find(code) == codesDecode.end()))
		{
			decodedText += codesDecode[code];
			code.clear();
		}
	}

	return decodedText;
}

void HuffmanTree::calculateAllCodes(HuffmanNode* current, string str, map<char, string>& codesEncode)
{
	// if is the end of the tree
	if (!current)
		return;

	calculateAllCodes(current->left, str + "0", codesEncode);
	if (current->str != '@')
		codesEncode[current->str] = str;
	calculateAllCodes(current->right, str + "1", codesEncode);
}

void HuffmanTree::calculateOrderOfLetters(HuffmanNode* current, string& str)
{
	// if is the end of the tree
	if (!current)
		return;

	calculateOrderOfLetters(current->left, str);
	if (current->str != '@')
		str += current->str;
	calculateOrderOfLetters(current->right, str);
}

void HuffmanTree::calculateTreeStructure(HuffmanNode* current, string& str)
{
	// if is the end of the tree
	if (!current)
		return;

	// calculate if the son is 0 or 1
	if (current->left != NULL || current->right != NULL) {
		str += "0";
		calculateTreeStructure(current->left, str);
		calculateTreeStructure(current->right, str);
	}
	else
		str += "1";
}

void HuffmanTree::rebuildHuffmanTree(HuffmanNode* current, string text, string tree, int& i, int& j)
{
	// build the rigth son with default values
	if (text[i] != '\0' && tree[j] == '0')
	{
		current->str = '@';
		current->frequency = 1;
		current->left = new HuffmanNode;
		current->right = new HuffmanNode;
		rebuildHuffmanTree(current->left, text, tree, i, ++j);
		rebuildHuffmanTree(current->right, text, tree, i, ++j);
	}
	//build the left son with default values
	else if (text[i] != '\0' && tree[j] == '1')
	{
		current->str = text[i];
		current->frequency = 1;
		i++;
	}
}

void HuffmanTree::calculateAllValues(HuffmanNode* current, string str, map<string, char>& codesDecode)
{
	// if is the end of the tree
	if (!current)
		return;

	// calculate the values
	calculateAllValues(current->left, str + "0", codesDecode);
	if (current->str != '@')
		codesDecode[str] = current->str;
	calculateAllValues(current->right, str + "1", codesDecode);
}

void HuffmanTree::clear(HuffmanNode* current)
{
	// if the tree is not empty
	if (current)
	{
		//delete the nodes
		if (current->left)
			clear(current->left);
		if (current->right)
			clear(current->right);
		delete current;
	}
}