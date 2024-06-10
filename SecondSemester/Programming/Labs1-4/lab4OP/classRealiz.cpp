#include "classHeader.h"
#include <iostream>
#include <cstring>

using namespace std;

#pragma warning(disable : 4996)


Passprt::Passprt() //without par constructor
	{
		name = nullptr;
		address = nullptr;
		age = 0;
		cout << "-->Constructor without parameters is calling.." << this << endl;
	}

Passprt::Passprt(const char* name, int age, const char* address) // with par constructor
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name );

		this->age = age;

		this->address = new char[strlen(address) + 1];
		strcpy(this->address, address);

		cout << "-->Constructor with parameters is calling.." << this << endl;
	}

Passprt::Passprt(const Passprt& other) // copy constructor
	{
		this->name = new char[sizeof(other.name)];
		strcpy(this->name, name);
		
		this->age = other.age;

		this->address = new char[sizeof(other.address)];
		strcpy(this->address, address);

		cout << "-->Copy constructor is calling.." << this << endl;
	}

char* Passprt::GetName() 
	{
		cout << "-->Getter for name is worked!" << endl;
		return name;
	}

int Passprt::GetAge() 
	{
		cout << "-->Getter for age is worked!" << endl;
		return age;
	}

char* Passprt::GetAddress() 
	{
		cout << "-->Getter for address is worked!" << endl;
		return address;
	}

void Passprt::SetName(const char* name)
	{
		delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		cout << "-->Setter for name is worked!" << endl;
	};

void Passprt::SetAge(int age)
	{
		this->age = age;
		cout << "-->Setter for age is worked!" << endl;
	};

void Passprt::SetAddress(const char* address)
	{
		delete[] this->address;
		this->address = new char[strlen(address) + 1];
		strcpy(this->address, address);
		cout << "-->Setter for address is worked!" << endl;
	};

void Passprt::SetAll(const char* name, int age, const char* address)
	{
		delete[] this->name; 
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);

		this->age = age;

		delete[] this->address;
		this->address = new char[strlen(address) + 1];
		strcpy(this->address, address);

		cout << "-->Setter FOR ALL is worked!" << endl;
	};

void Passprt::Print() 
	{
		cout << "Passport data:" << endl;
		cout << "name   ~ > " << name << endl;
		cout << "age    ~ > " << age << endl;
		cout << "addres ~ > " << address << endl;
	};

Passprt::~Passprt()
	{
		cout << "-->Destructor is calling.." << this << endl;
		delete[] name;
		delete[] address;
	};


