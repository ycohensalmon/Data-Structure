#pragma once
#include <string>
using namespace std;


class volunteer
{
public:

	int phone; 
	string name;
	string address;

	volunteer() {name = "0"; phone = 0; address = "0";}

	~volunteer() {nullptr;}

	string getName() { return name; }

	/// <summary>
	/// Placement between 2 volunteer by operator
	/// </summary>
	/// <param name="volunteer">Volunteer details</param>
	void operator=(volunteer volunteer)
	{
		name = volunteer.name;
		phone = volunteer.phone;
		address = volunteer.address;
	}

	/// <summary>
	/// Checks whether the 2 volunteer are equal
	/// </summary>
	/// <param name="v"> Volunteer details </param>
	/// <returns> true or false </returns>
	bool operator==(volunteer v)
	{
		return (v.name == name) ? true : false;
	}

	/// <summary>
	/// Gets the Volunteer details
	/// </summary>
	/// <param name="os"> Input operator </param>
	/// <param name="v"> Volunteer details </param>
	/// <returns> Input </returns>
	friend std::ostream& operator<<(std::ostream& os, volunteer& v)
	{
		os << v.name << ":volunteer "
			<< "name=" << v.name
			<< " phone=" << v.phone
			<< " address=" << v.address;

		return os;
	}
	
	/// <summary>
	/// Print the Volunteer details
	/// </summary>
	/// <param name="is"> Output operator </param>
	/// <param name="v"> Volunteer details </param>
	/// <returns> Output </returns>
	friend std::istream& operator>>(std::istream& is, volunteer& v)
	{
		string name, address;
		int phone;

		cout << "Enter volunteer name phone address \n";

		is >> name >> phone >> address;
		v.name = name;
		v.phone = phone;
		v.address = address;

		return is;
	}
};