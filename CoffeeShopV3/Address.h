#ifndef __ADDRESS_H__
#define __ADDRESS_H__

using namespace std;
#include <iostream>

class Address {
private:
	string city;
	string streetName;
	int streetNumber;

private:
	void setCity(const string& city) noexcept(false);
	void setStreetName(const string& city) noexcept(false);
	void setStreetNumber(int num) noexcept(false);

public:
	// ctor
	Address(const string& city, const string& streetName, int streetNumber) noexcept(false);

	// getters
	const string& getCity() const { return city; }
	const string& getStreetName() const { return streetName; }
	int getStreetNumber() const { return streetNumber; }

	// functions
	friend ostream& operator<<(ostream& os, const Address& address);
};

#endif