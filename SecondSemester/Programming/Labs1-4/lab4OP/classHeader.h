#ifndef _CLASSREALIZ_CPP_
#define _CLASSREALIZ_CPP_

class Passprt
{
	char* name;
	int age;
	char* address;
public:
	Passprt();//without par
	Passprt(const char* name, int age,const char* address);//with par
	Passprt(const Passprt&);//copy

	char* GetName();
	int GetAge();
	char* GetAddress();

	void SetName(const char*);
	void SetAge(int);
	void SetAddress(const char*);
	void SetAll(const char*, int, const char*);

	void Print();

	~Passprt();

};	

#endif 