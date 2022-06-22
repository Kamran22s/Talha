#include "String.h"

//////**********///////////
///***String copy function**//////
/////////////////////////////

void String::strCpy(char* dest, const char *src)
{
	if (dest == nullptr)
		return;
	if (src == nullptr)
	{
		dest[0] = '\0';
		return;
	}
	int i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

///////////////

//////**********///////////
///***Constructors**//////
/////////////////////////////

String::String()
{
	data = nullptr;
	size = 0;
}
String::~String()
{
	if (data)
	{
		delete[]data;
		data = nullptr;
		size = 0;
		return;
	}
	else
		return;
}
String::String(const char * a) :String()
{
	int i = 0;
	if (a[i] == '\0' || a == nullptr)
		return;
	while (a[i] != '\0')
	{
		i++;
	}
	data = new char[i + 1];
	strCpy(data, a);
	size = i + 1;
}

String::String(String && r)
{
	data = r.data;
	size = r.size;
	r.data = nullptr;
}

String::String(const String & ref)
{
	//	*this = ref;
	int temp = ref.size;
	if (temp == 0)
	{
		temp++;
	}
	this->data = new char[temp];
	strCpy(this->data, ref.data);
	this->size = temp;
}
String::String(const char c) :String()
{
	if (c == '\0')
		return;
	size = 2;
	data = new char[2]{ c,'\0' };
}
//**********/////////////

//**********************
//***AssignMent Operators OverLoaded/////////
///////////////////////////

String & String::operator=(const String & ref)
{
	if (this == &ref)
		return *this;
	if (!ref.data)
	{
		return *this;
	}
	this->~String();
	if (ref.size == 0)
	{
		size = (ref.size + 1);
	}
	this->size = ref.size;
	this->data = new char[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = ref.data[i];
	}

	return *this;
}
String & String:: operator=(String && r)
{
	this->~String();
	data = r.data;
	size = r.size;
	r.data = nullptr;
	return *this;
}

String &String:: operator=(const long long int ref)
{
	setNumber(ref);
	return *this;

}
String &String:: operator=(const double ref)
{
	setDouble(ref);
	return *this;

}
////////////

////********************************////
////OverLoaded Index Operators///
//******///////////////



char& String::operator[](int ind)
{
	if (ind >= 0 && ind < size)
	{
		return data[ind];
	}
	else
		exit(0);
}

const char& String:: operator[](int ind) const
{
	if (ind >= 0 && ind < size)
	{
		return data[ind];
	}
	else
		exit(0);
}

///////////////////////////





////////*************************
/*////////Display Function********/
//////////////////////////////
void String::display() const
{
	if (data)
		cout << data;
}






//********************
 /* GetLength Function ********/
//***************************//

int String::getLength() const
{
	int i = 0;
	if (data == nullptr || data[i] == '\0' )
		return 0;
	else
	{
		while (data[i] != '\0')
		{
			i++;
		}

	}
	return i;

}
///////////////////////
//******Getter for Size//////
////////////////////
int String::getSize()
{

	return (this->size);
}

//********************
 /* Function for finding a sub_string********/
//***************************//


int String::find(const String &subStr, const int ind) const
{

	int i = ind, j = 0;

	while (this->data[i] != '\0')
	{


		if (this->data[i] == subStr.data[0])
		{

			for (j = 0; j < subStr.getLength(); j++)
			{

				if (data[i + j] != subStr.data[j])
					break;


			}
			if (j == (subStr.getLength()))
			{

				return i;

			}
			else
			{
				j = 0;
				i++;
			}

		}
		else
			i++;
	}
	return -1;
}


/////////////////////////////////////
///*******Resize Function********///
////////////////////////////////////

void String::reSize(int ns)
{
	if (ns <= 0)
	{
		this->~String();
		return;
	}
	char * temp = new char[ns];
	int i = 0;
	while (i < ns && i < size)
	{
		temp[i] = data[i];
		i++;
	}

	temp[ns - 1] = '\0';

	this->~String();
	size = ns;
	data = temp;
}





//********************
 /* OverLoaded Concatenation OPerators********/
//***************************//


String  String::operator +(const String& s2) const
{
	if (!s2.data)
	{
		return *this;
	}
	int tempSize = (this->getLength()) + s2.getLength() + 1;
	String s;
	s.data = new char[tempSize];
	s.size = tempSize;
	int i = 0;
	while (data[i] != '\0')
	{
		s.data[i] = data[i];
		i++;
	}
	int j = 0;

	while (s2.data[j] != '\0')
	{
		s.data[i + j] = s2.data[j];
		j++;
	}
	s.data[i + j] = '\0';
	return s;
}

////ConCat Equal/////


String &  String::operator+=(const String & s2)
{
	int tempSize = (this->getLength()) + s2.getLength() + 1;
	reSize(tempSize);
	int i = this->getLength();
	int j = 0;

	while (s2.data[j] != '\0')
	{
		data[i + j] = s2.data[j];
		j++;
	}
	data[i + j] = '\0';
	return *this;
}
//***************************//



/////***************//////////
//INSERT FUNCTION*******//
//***********///////

void String::insert(const int index, const String subStr)
{
	int i = getLength();
	int k = (i + subStr.getLength() + 1);

	this->reSize(k);

	int temp = i + subStr.getLength() - 1;
	while (i > index)
	{
		data[temp] = data[i - 1];
		temp--;
		i--;
	}

	i = 0;
	while (subStr.data[i] != '\0')
	{
		this->data[i + index] = subStr.data[i];
		i++;
	}

	this->data[k - 1] = '\0';
}

/////***************//////////
// FUNCTION to Reverse the string*******//
//***********///////


void String::reverse()
{
	int temp = (this->getLength()) - 1;
	char t;
	for (int i = 0; i < (this->getLength() / 2); i++)
	{
		t = this->data[temp];
		this->data[temp] = this->data[i];
		this->data[i] = t;
		temp--;
	}
}



//********************
 /* SET NUMBER FUNCTION(INT)********/
//***************************//
void String::setNumber(const long long int num)
{
	if (num >= 0)
	{


		long long int temp = num;
		int i = 0;
		while (temp != 0)
		{
			temp = temp / 10;
			i++;
		}
		if (i == 0)
		{
			i = 1;
		}
		//cout << i;
		reSize(i + 1);
		temp = num;
		for (int j = 0; j < i; j++)
		{
			this->data[j] = ((temp % 10) + '0');

			temp = temp / 10;
		}
		this->data[i] = '\0';

		this->reverse();

	}
	else
	{
		long long int temp = num;
		int i = 0;
		while (temp != 0)
		{
			temp = temp / 10;
			i++;
		}

		reSize(i + 2);
		temp = num;
		for (int j = 0; j < i; j++)
		{
			this->data[j] = (-(temp % 10) + '0');

			temp = temp / 10;
		}
		this->data[i] = '-';
		this->data[i + 1] = '\0';

		this->reverse();

	}
}


//********************
 /* SET DOUBLE  FUNCTION********/
//***************************//

void  String::setDouble(const float num)
{
	if (num < 0)
	{
		return;
	}
	int temp = num;
	float a = num - (float)temp;
	setNumber(temp);
	(*this) += ".";
	//int i = 0;
	for (int i = 0; i < 3; i++)
	{

		temp = a * 10;
		*this += (temp + '0');
		a = a * 10;
		a = a - (float)temp;
	}


}

/////////////////////////////////////////////
///Function TO convert String to integer/////
/////////////////////////////////////////////

long long int String::convertToInteger() const
{
	int i = 0;
	long long int temp = 0;

	while (data[i] != '\0' && (data[i] >= '0' && data[i] <= '9'))
	{
		if (data[i] == '-')
		{

			i++;
			temp = ((temp * 10) + (data[i] - '0'));
		}
		else
		{

			temp = ((temp * 10) + (data[i] - '0'));
		}
		i++;
	}
	if (data[0] == '-')
	{
		return(0 - temp);

	}
	else
	{
		return temp;
	}


}


long long int String::convertToInteger(const String & s) const
{
	int i = 0;
	long long int temp = 0;
	while (s.data[i] != '\0')
	{
		temp = ((temp * 10) + (s.data[i] - '0'));
		i++;
	}
	return temp;
}




/////////////////////////////////////////////
///Function TO convert String to Double/Float/////
/////////////////////////////////////////////

float String::convertTOFloat() const
{
	return convertTOFloat(*this);
}
float String::convertTOFloat(const String &) const
{
	int i = 0;
	int count = 0;
	float temp = 0;

	while (data[i] != '\0')
	{
		if (data[i] == '.')
		{
			count++;

		}
		else if (data[i] == '-')
		{
			count = count * 10;
			i++;
			temp = ((temp * 10) + (data[i] - '0'));
		}
		else
		{
			count = count * 10;
			temp = ((temp * 10) + (data[i] - '0'));
		}
		i++;
	}
	if (count != 0)
	{
		temp = temp / count;
	}
	if (data[0] == '-')
	{

		return(0 - temp);

	}
	else
	{
		return temp;
	}
}


/////////////////////////////////////////////
///Function For Input/////
/////////////////////////////////////////////

void String::input()
{

	int i = 0;
	char temp;
	if (size == 0)
	{
		reSize(2);
	}

	while ((temp = cin.get()) != '\n')
	{
		if (i >= size)
		{
			reSize(i * 2);

		}
		data[i] = temp;
		i++;
	}
	if (i >= size)
	{
		reSize(i * 2);

	}
	data[i] = '\0';
}


/////*************////////////****/////******//////
/////Function to get Trimmed String Fropm Right///
/////////////////////////////////////////////////

String String::right(const int count)
{
	int t = getLength() - count;
	//cout << getLength() << " " << t;
	String temp(*this);

	temp.remove(0, t);
	return temp;
}

/////*************////////////****/////******//////
/////Function to get Trimmed String Fropm Right///
/////////////////////////////////////////////////


String String::left(const int count) const
{
	if (data == nullptr || *data == '\0')
	{
		exit(0);
	}

	String temp;
	int i;
	temp.reSize(count + 1);
	for (i = 0; i < count; i++)
	{
		temp.data[i] = data[i];
	}
	temp.data[i] = '\0';
	return temp;
}

/////*************////////////****/////******//////
/////OverLoaded '-' Operator///
/////////////////////////////////////////////////

String  String::operator-(const String & s2) const
{
	String temp(*this);
	int t = temp.find(s2);
	if (t == -1)
	{
		return temp;
	}
	temp.remove(t, s2.getLength());
	return temp;
}

/////*************////////////****/////******//////
/////Compare Function///
/////////////////////////////////////////////////

int String::compare(const String & str) const
{
	//int i = 0;


	if (getLength() != (str.getLength()))
	{

		return -1;

	}
	for (int j = 0;  data[j] != '\0'; j++)
	{
		if (data[j] != str.data[j])
			return -1;
	}
	return 1;


}
/////*************////////////****/////******//////
/////Comparison Operators OverLoaded///
/////////////////////////////////////////////////

bool String::operator==(const String & ref) const
{
	if (compare(ref) == 1)
		return true;
	return false;
}



//*******
//*****Remove function****////////

void String::remove(const int ind, const int count)
{
	int i = ind;

	while (data[i] != '\0')
	{
		if (i + count >= getLength())
		{
			reSize(i + 1);
			return;
		}
		data[i] = data[i + count];
		i++;
	}

	data[i] = '\0';
	reSize(i);
}

/////////////////////////////////////
//****overloaded Type cast operators****/////

String::operator bool() const
{
	if (data)
	{
		return true;
	}
	else
		return false;
}
String:: operator long long int() const
{
	return convertToInteger();
}
String:: operator double() const
{
	return convertTOFloat();
}
/////////////////////////////////////




//**OVERLOADED STREM OPERATORS**//////


istream& operator >> (istream& Cin, String & ref)
{
	ref.input();
	return cin;
}
ostream&  operator << (ostream& Cout, const String & ref)
{
	ref.display();
	return cout;
}

