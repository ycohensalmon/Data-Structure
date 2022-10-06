#pragma once
#include <iostream>
#include "VolunteersHash.h"
#include "clientsHash.h"
#include "HashTable.h"
using namespace std;

class HashTbls
{
public:
	VolunteersHash volunteersTable;
	clientsHash clientsTable;

	HashTbls() : volunteersTable(100), clientsTable(100) { }

	/// <summary>
	/// Add volunteer to the table
	/// </summary>
	/// <param name="v"> the volunteer </param>
	void addVolunteer(volunteer& v)
	{
		HashTable<volunteer, string>::Item item(v, v.name, full);
		volunteersTable.add(item);
	}

	/// <summary>
	/// delete de volunteer from the table
	/// </summary>
	/// <param name="key"> key to find the volunteer </param>
	void delVolunteer(string key)
	{
		volunteersTable.deleteItem(key);
	}

	/// <summary>
	/// Add client to the table
	/// </summary>
	/// <param name="c"> the client </param>
	void addClient(client& c)
	{
		HashTable<client, int>::Item item(c, c.phone, full);
		clientsTable.add(item);
	}

	/// <summary>
	/// Delete the client from the table
	/// </summary>
	/// <param name="key"> key to find the client </param>
	void delClient(int key)
	{
		clientsTable.deleteItem(key);
	}

	/// <summary>
	/// Connects the volunteer to the client
	/// </summary>
	/// <param name="v"> the volunteer </param>
	/// <param name="c"> the client </param>
	void addVolunteerToClient(volunteer v, client c)
	{
		if (volunteersTable.search(v.name) != -1 && clientsTable.search(c.phone) != -1) // if the volunteer is found
		{
			bool flag = true;
			for (auto it = clientsTable.table[clientsTable.search(c.phone)].data.volunteersName.begin(); it != clientsTable.table[clientsTable.search(c.phone)].data.volunteersName.end(); it++)
			{
				if ((*it) == v.name)
				{
					cout << "ERROR\n";
					flag = false;
					break;
				}
			}
			if (flag)
				clientsTable.table[clientsTable.search(c.phone)].data.volunteersName.push_back(v.name);
		}
	
		else
			cout << "ERROR\n";
	}

	/// <summary>
	/// list Of Volunteers
	/// </summary>
	/// <param name="c">the client </param>
	void listOfVolunteers(client c)
	{
		cout << "The volunteers that helped to client " << c.phone << ": ";
		if (clientsTable.search(c.phone) != -1)
			clientsTable.table[clientsTable.search(c.phone)].data.listOfVolunteers();
	}

	/// <summary>
	/// List the clients that were helped by volunteer
	/// </summary>
	/// <param name="v"> the volunteer </param>
	void listOfClients(volunteer v)
	{
		cout << "The clients that were helped by volunteer " << v.name << ": ";

		for (int i = 0; i < 100; i++)
		{
			for (auto it2 = clientsTable.table[i].data.volunteersName.begin(); it2 != clientsTable.table[i].data.volunteersName.end(); it2++)
				if (v.name == (*it2)) // if found
					cout << clientsTable.table[i].data.name << " ";
		}

		cout << endl;
	}

	/// <summary>
	/// Print the list of the volunteer and of the client
	/// </summary>
	void print()
	{
		cout << "Volunteers: \n";
		for (size_t i = 0; i < 100; i++)
		{
			if (volunteersTable.table[i].flag == full)
				cout << volunteersTable.table[i].data << endl;
		}
		cout << endl;

		cout << "Clients: \n";
		for (size_t i = 0; i < 100; i++)
		{
			if (clientsTable.table[i].flag == full)
				cout << clientsTable.table[i].data << endl;
		}
	}
};