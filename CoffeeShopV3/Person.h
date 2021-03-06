#ifndef __PERSON_H__
#define __PERSON_H__

using namespace std;
#include <iostream>

class Person {
protected:
	string name;
	string phoneNumber;

private:
	// setters
	void setName(const string& name) noexcept(false);
	void setPhoneNumber(const string& phoneNumber) noexcept(false);

public:
	// ctor
	Person(const string& name, const string& phoneNumber) noexcept(false);

	// dtor
	virtual ~Person() = default;

	// operators
	virtual bool operator==(const Person& other) const;

	// getters
	const string& getName() const { return name; }
	const string& getPhoneNumber() const { return phoneNumber; }	

	// functions
	virtual void toOs(ostream& os) const = 0;
	friend ostream& operator<<(ostream& os, const Person& person);
};

#endif