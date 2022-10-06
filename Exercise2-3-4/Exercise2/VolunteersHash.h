#pragma once
#include "HashTable.h"
#include "Volunteer.h"
#include <string>
using namespace std;
class VolunteersHash : public HashTable <volunteer,string>
{
public:
	VolunteersHash(int size) : HashTable(size){}

	/// <summary>
	/// Converts the key from a string to an int to insert into a hach function
	/// </summary>
	/// <param name="key"> the string </param>
	/// <returns> int after conversion </returns>
	int keyConvert(string key)
	{
		int convert = 0;

		for (size_t i = 0; i < key.length(); i++)
		{
			convert += key[i];
		}

		return convert;
	}

	int h1(string key)
	{
		return  keyConvert(key) % HashTable::getSize();
	}

	int h2(string key)
	{
		return (keyConvert(key) % (HashTable::getSize() - 1)) + 1;
	}


};

