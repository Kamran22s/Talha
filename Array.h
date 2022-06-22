#ifndef   ARRAY_H 
#define   ARRAY_H

class Array
{
	int *data;
	int capacity;
	bool isValidIndex(int index) const;

	void memCpy(void * dest, const void * src, int noOfByt);
public:

	Array(int argCount = 0, ...);
	Array(const Array & ref);
	~Array();

	int getCapacity();

	int & operator[](int index);
	int get(int index);
	//const int & operator[](int index) const;
	void reSize(int newCap);
	void display();
	int getSize()const;
};

#endif // !

