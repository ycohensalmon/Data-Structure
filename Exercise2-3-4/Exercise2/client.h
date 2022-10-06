#pragma once
#include <list>
#include <string>
#include <iostream>
using namespace std;

class client
{
public:
	int phone; 
	string name;
	string address;
	list<string> volunteersName;

	~client() { volunteersName.clear(); NULL; }

	client() { name = "0"; phone = 0; address = "0"; }

	/// <summary>
	/// Print list of the client
	/// </summary>
	void listOfVolunteers()
	{
		if (!volunteersName.empty())		
			for (auto it = volunteersName.begin(); it != volunteersName.end(); it++)			
				cout << (*it) << " ";			
		
		cout << endl;
	}

	/// <summary>
	/// Placement between 2 client by operator
	/// </summary>
	/// <param name="c"> client details </param>
	void operator=(client& c)
	{
		name = c.name;
		phone = c.phone;
		address = c.address;
	}

	/// <summary>
	/// Checks whether the 2 client are equal
	/// </summary>
	/// <param name="c"> client details </param>
	/// <returns> true or false </returns>
	bool operator==(client c)
	{
		return (c.phone == phone) ? true : false;
	}

	/// <summary>
	/// Gets the client details
	/// </summary>
	/// <param name="os"> Input operator </param>
	/// <param name="c"> client details </param>
	/// <returns> Input </returns>
	friend std::ostream& operator<<(std::ostream& os, client& c)
	{
		os << c.phone << ":client "
			<< "name: " << c.name
			<< " phone: " << c.phone
			<< " address: " << c.address;
		if (c.volunteersName.empty())
		{
			cout << " helped by: ";
			c.listOfVolunteers();
		}

		return os;
	}

	/// <summary>
	/// Print the client details
	/// </summary>
	/// <param name="is"> Output operator </param>
	/// <param name="c"> client details </param>
	/// <returns> Output </returns>
	friend std::istream& operator>>(std::istream& is, client& c)
	{
		string name, address;
		int phone;

		cout << "please enter name and phone and address of client \n";

		is >> name >> phone >> address;

		c.name = name;
		c.phone = phone;
		c.address = address;

		return is;
	}
};

