#ifndef STRING_H
#define STRING_H
#include <iostream>
using namespace std;

class String
{
	char*data;
	int size;

	void strCpy(char*, const char *);
	float convertTOFloat() const;
	long long int convertToInteger() const;

public:

	String(const String &);
	String();
	String(char c);
	String(const char*);
	String(String && r);
	~String();

	void reSize(int);
	void reverse();
	void input();
	void display() const;

	void remove(const int ind, const int count);
	void insert(const int index, const String subStr);
	void setNumber(const long long int);
	void  setDouble(const float);

	int find(const String &subStr, const int = 0) const;
	int getSize();
	int getLength() const;


	char & operator[](int ind);
	const char & operator[](int ind) const;


	String  operator+(const String & s2) const;
	String & operator+=(const String & s2);




	long long int convertToInteger(const String &) const;
	float convertTOFloat(const String &) const;

	String right(const int count);
	int compare(const String &) const;
	String left(const int count) const;

	String  operator-(const String & s2) const;
	bool operator==(const String &) const;
	String & operator=(const String &);
	String &  operator=(String && r);
	String & operator=(const long long int);
	String & operator=(const double);
	


	explicit operator bool() const;
	explicit operator long long int() const;
	explicit operator double() const;
};


istream& operator >> (istream& Cin, String&);
ostream& operator<< (ostream& Cout, const String &);

#endif