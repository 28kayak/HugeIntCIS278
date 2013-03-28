#include <iostream>
#include "math.h"
#include "HugeInt.h"
#include "stdlib.h"//where atoi is tored 
using namespace std; 

HugeInt::HugeInt()
{
	length = 4;
	for(int i =0; i < SIZE; i++)
	{
		if(i < 4)
		{
			digits[i] = 5;
		}
		else
		{
			digits[i] = 0;
		}

	}
}

HugeInt::HugeInt(string value)
{
	//int length;
	for(int n = 0; n < SIZE; n++)
	{//initialize array 
	 //in order to avoid to enter unknow value automatically 
		digits[n] = 0;
		//cout << digits[n] << "\n";
	}
	//cout << "2nd";

	length=value.length();
	if(allDigits(value))
	{
		//cout << "3rd\n";
		for(int i = 0; i < length + 1; i++)
		{
			
			digits[i] = atoi(&value[value.length()-1 - i]);
			value[value.length() - 1 - i] = 0x00;
			//cout << "i = " << i << "\n" ;
			//cout << "digit = " << digits[i]<< "\n";
		}

	}

}

int HugeInt::numDigits() const
{//return the num of digits in this HugeInt array 
	
	return this->length;

}
 
int HugeInt::operator[] (int n)
{
	if(n >= 0 && n < length)
	{
		return digits[n];
	}
	else
	{
		return -1;
	}
}

HugeInt HugeInt::operator++()
{//operator overloading with pre-increment 

	//HugeInt postIncrement = *this;
	HugeInt preIncrement("0");

	preIncrement.length=this->length;
	for (int i=0;i<this->length;i++)
	{
		preIncrement.digits[i]=this->digits[i];
		//cout<<this->digits[i];
	}

	int index = 0;
	//cout<<"preIncrement=";
	//cout<<preIncrement<<"\n";

	preIncrement.digits[index]++;
	
	while(index < length)
	{ 
		if(preIncrement.digits[index] == 10)
		{
			preIncrement.digits[index] = 0;
			preIncrement.digits[index + 1] += 1;
			if(index == preIncrement.length-1)
			{
				preIncrement.length += 1;
				
			}
			index++;
			 
		}
		else
		{
			return (preIncrement);
		} 
	}
	return (preIncrement);
}

HugeInt HugeInt::operator++(int)
{//opeartor overloading with post-increment 

	//HugeInt postIncrement = *this;
	HugeInt postIncrement("0");

	postIncrement.length=this->length;
	for (int i=0;i<this->length;i++)
	{
		postIncrement.digits[i]=this->digits[i];
		//cout<<this->digits[i];
	}

	int index = 0;	
	//cout<<"postIncrement=";
	//cout<<postIncrement<<"\n";
	
	postIncrement.digits[index] = this->digits[index] + 1;
	while(index < length)
	{
		if(postIncrement.digits[index] == 10)
		{
			postIncrement.digits[index] = 0;
			postIncrement.digits[index + 1] += 1;
			if(index == postIncrement.length-1)
			{
				postIncrement.length += 1;
			}
			index++;
		}
		else
		{
			return (postIncrement);
		}
	
	}
	return (postIncrement);

}

bool HugeInt::operator==(const HugeInt& operand)const
{ 
	for(int k = 0; k < SIZE; k++)
	{
		if(digits[k] != operand.digits[k])
		{
			return false;
		}
	}
	return true; 

}

bool HugeInt::operator!= (const HugeInt& operand)const
{
	if (this->length==operand.length)
	{
		for(int index = 0; index < this->length; index++)
		{
			if(digits[index] != operand.digits[index])
			{
				return true;
			}
		}
		return false;
	}else{
		return true;
	}

}
//should not define 'frind' here(only with .h file)
//do not need class name since it is not member function(?)
ostream& operator<<(ostream& out, const HugeInt& obj)
{
	//char buffer[50];
	//int hugeInt = 0;//store actual value of integer.
	//unsigned Position =0;
	cout << endl << "{ ";

	for (int i=0;i<obj.length;i++)
	{
		cout << obj.digits[obj.length-1-i];// << ", ";
	}
	cout << " }" << endl;

	return out;


}

HugeInt operator+ (const HugeInt& operand1, const HugeInt& operand2)
{	
	HugeInt sumInt;
	for(int i = 0; i < operand1.length && i < operand2.length ; i++)
	{
		sumInt.digits[i] = operand1.digits[i] + operand2.digits[i];
		if(sumInt.digits[i] >= 10)
		{
			sumInt.digits[i] = (int) (sumInt.digits[i] % 10);
			sumInt.digits[i+1] += 1;
		}
	}
	return sumInt;
}
bool HugeInt::allDigits(string str)
{
	int len;
	len=str.length();
	for(int i = 0; i < len; i++)
	{
		if(!isdigit(str[i]))
		{
			return false;	
		}
	}
	return true; 
}






/*

HugeInt HugeInt::operator=()
{//operator overloading with pre-increment

	//HugeInt postIncrement = *this;
	HugeInt target("0");

	target.length=this->length;
	for (int i=0;i<this->length;i++)
	{
		target.digits[i]=this->digits[i];
		//cout<<this->digits[i];
	}

	return (target);
}

*/
