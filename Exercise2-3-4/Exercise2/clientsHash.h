#pragma once
#pragma once
#include "HashTable.h"
#include "client.h"
#include <string>
using namespace std;

class clientsHash : public HashTable<client,int>
{ 
public:
	clientsHash(int size):HashTable(size){}

	int h1(int key)
	{
		return  key % HashTable::getSize();
	}

	int h2(int key)
	{
		return (key % (HashTable::getSize() - 1)) + 1;
	}

	/*void addClient(client& c)
	{
		Item<client,int> item;

		item.data = c;
		item.key = c.phone;
		item.flag = full;

		HashTable::add(item);
	}

	void delVolunteer(int key)
	{
		HashTable::deleteItem(key);
	}*/
};

