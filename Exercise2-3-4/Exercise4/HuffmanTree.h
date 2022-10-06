#pragma once
#include "HuffmanNode.h"
#include <map>

class HuffmanTree
{
	HuffmanNode* root;
	int numbersLeaves;
public:
	/// <summary>
	/// initilize a new empty Huffman tree
	/// </summary>
	HuffmanTree() { root = NULL; numbersLeaves = 0; }

	~HuffmanTree() { clear(root); }

	/// <summary>
	/// creat a new huffman tree by the word
	/// </summary>
	/// <param name="word">word the by him we build this tree</param>
	void buildHuffmanTree(string word);

	/// <summary>
	/// rebuil the huffman tree by the string
	/// </summary>	
	bool rebuildHuffmanTree(string text, string tree);

	/// <summary>
	/// initilize the num of level in the tree
	/// </summary>
	/// <param name="num">the levels</param>
	void setNumberOfLeaves(int num) { numbersLeaves = num; }

	/// <summary>
	/// get the num of levels in the tree
	/// </summary>
	/// <returns>num of levels</returns>		
	int getLeaves() { return numbersLeaves; }

	/// <summary>
	/// get the order of the letters
	/// </summary>
	/// <returns>new string with the order of the latter</returns>
	string getOrderOfLetters() { string str; calculateOrderOfLetters(root, str); return str; }

	/// <summary>
	/// get the string of the tree on binary
	/// </summary>
	/// <returns>binary tree string</returns>
	string getTreeStructure() { string str; calculateTreeStructure(root, str); return str; }

	/// <summary>
	/// get EncodedText
	/// </summary>
	/// <param name="word"></param>
	/// <returns></returns>
	string getEncodedText(string word);

	/// <summary>
	/// get an encoded text and decoded him
	/// </summary>
	/// <param name="encodedText">the encoded text</param>
	/// <returns>the decoded text</returns>
	string getDecodedText(string encodedText);
private:

	/// <summary>
	/// calculate all codes to a binary code
	/// </summary>
	/// <param name="current">the current node</param>
	/// <param name="str">the string on the tree</param>
	/// <param name="codesEncode">the code text in binary</param>
	void calculateAllCodes(HuffmanNode* current, string str, map<char, string>& codesEncode);

	/// <summary>
	/// calculate order of the letters
	/// </summary>
	/// <param name="current">the current node</param>
	/// <param name="str">the string on the tree</param>
	void calculateOrderOfLetters(HuffmanNode* current, string& str);

	/// <summary>
	/// calculate if the node is left or rigth (0 or 1)
	/// </summary>
	/// <param name="current">the current node</param>
	/// <param name="str">the string in the tree</param>
	void calculateTreeStructure(HuffmanNode* current, string& str);

	/// <summary>
	/// rebuildthe huffman tree by setting the default tree
	/// </summary>
	/// <param name="current">the current node</param>
	/// <param name="text">the string in the tree</param>
	/// <param name="i">rigth son</param>
	/// <param name="j">left son</param>
	void rebuildHuffmanTree(HuffmanNode* current, string text, string tree, int& i, int& j);

	/// <summary>
	/// calculate all values
	/// </summary>
	/// <param name="current">the current node</param>
	/// <param name="str">the string in the tree</param>
	/// <param name="codesDecode">the decoded code</param>
	void calculateAllValues(HuffmanNode* current, string str, map<string, char>& codesDecode);

	/// <summary>
	/// delete the tree
	/// </summary>
	/// <param name="current">the current Huffman Node</param>
	void clear(HuffmanNode* current);
};