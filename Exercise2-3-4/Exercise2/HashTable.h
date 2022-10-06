#include <iostream>
#include <vector>
#include <cmath>
#pragma once
using namespace std;

enum state { Empty, full, deleted };

template<typename T, typename K>
class HashTable
{
	int size;
public:
	class Item
	{
	public:
		T data;
		K key;
		state flag = Empty;
		Item() { }
		Item(T d, K k, state f) { data = d; key = k; flag = f; }
	};

	HashTable<T, K>::Item* table;

	HashTable(int Usersize);
	~HashTable() { delete[] table; }
	virtual int h1(K key) = 0;
	virtual int h2(K key) = 0;
	int getSize() { return size; }
	int hash(K key, int i);
	int search(K key);
	void print();
	void deleteItem(K key);
	void primeNumber(int& size);
	void add(HashTable<T, K>::Item item);
	void operator=(HashTable<T, K>::Item item);
};

/// <summary>
/// Gets the size and initializes the table size
/// </summary>
/// <param name="Usersize">size of the array</param>
template<typename T, typename K>
HashTable<T, K>::HashTable(int Usersize)
{
	size = Usersize;
	primeNumber(size);
	table = new HashTable<T, K>::Item[size];
}

/// <summary>
/// Hashing fonction 
/// </summary>
/// <param name="key">With its help, gets the cell in the array</param>
/// <param name="i">Number of attempts</param>
/// <returns>index on the arrray</returns>
template<typename T, typename K>
int HashTable<T, K>::hash(K key, int i)
{
	return (h1(key) + i * h2(key)) % size;
}

/// <summary>
/// Search tne index in the table by the key
/// </summary>
/// <param name="key">gets the cell in the array</param>
/// <returns>if found- the index in the table, else - -1</returns>
template<typename T, typename K>
int HashTable<T, K>::search(K key)
{
	int i = 0;

	while (table[hash(key, i)].flag == full && key != table[hash(key, i)].key) // When the place is occupied by another
		if (i >= getSize())                                                    // If the entire table is complete and is not yet found
			return -1;
		else
			i++;

	if (table[hash(key, i)].flag == full)
		return hash(key, i);
	else
		return -1;
}

/// <summary>
/// print the table
/// </summary>
template<typename T, typename K>
void HashTable<T, K>::print()
{
	for (size_t i = 0; i < size; i++)
	{
		if (table[i].data && table[i].flag == full)
			cout << table[i].key << ": " << table[i].data.print << endl;
	}
}

/// <summary>
/// delete the item
/// </summary>
/// <param name="key">to found the item</param>
template<typename T, typename K>
void HashTable<T, K>::deleteItem(K key)
{
	if (search(key) != -1)
		table[search(key)].flag = deleted;
	else
		cout << "ERROR\n";
}

/// <summary>
/// Finds the nearest prime number (upwards)
/// </summary>
/// <param name="size">the number</param>
template<typename T, typename K>
void HashTable<T, K>::primeNumber(int& size)
{
	bool flag = false;
	while (!flag)
	{
		flag = true;
		int conter = 0;
		for (int i = 1; i < size / 2; i++)
		{
			if (size % i == 0)   // If the number is divisible by no remainder
			{
				conter++;
				if (conter == 2) // If the number is divisible only by 1 and by itself
				{
					size++;
					conter = 0;
					flag = false;
					break;
				}
			}
		}
	}
}

/// <summary>
/// Add an item to the table
/// </summary>
/// <param name="item">the item </param>
template<typename T, typename K>
void HashTable<T, K>::add(HashTable<T, K>::Item item)
{
	int index = 0;
	if (search(item.key) != -1) // if the item is alredy in the table
		return;

	while (table[hash(item.key, index)].flag == full)
		if (index >= getSize()) // If the item is not in all the table
			return;
		else
			index++;
	int newindex = hash(item.key, index);
	table[newindex] = item;
}

/// <summary>
/// Placement between 2 item by operator
/// </summary>
/// <param name="item"></param>
template<typename T, typename K>
void HashTable<T, K>::operator=(HashTable<T, K>::Item item)
{
	Item::data = item.data;
}