#include<iostream>
#include "HugeInt.h"
#include "stdio.h"
using namespace std;

int main()
{
	HugeInt bigInt();
	/*
	HugeInt bigInt1("1234");
	cout << bigInt1;
	
	HugeInt bigInt2("1234");
	cout << bigInt2;
	
	printf("BigInt1 contains: %d digits\n", bigInt1.numDigits());
	printf("BigInt2 contains: %d digits\n", bigInt2.numDigits());

	if(bigInt1 == bigInt2) 
	{
		cout << "BigInt1 and BigInt2 have the same value\n";
	}	
	else
	{
		cout << "BigInt1 is not same as BigInt2\n";
	}
	if(bigInt1 != bigInt2)
	{
		cout << "BigInt1 and BigInt2 are the different value\n";
	}else
	{
		cout << "BigInt1 and BigInt2 are same\n";
	}
	*/
	
	HugeInt a("1345");
	HugeInt b("999");
	HugeInt c("109");

	cout << "before increment\n";
	cout << "1345 = " << a ;
	cout << "999 = "<<b ;
	cout << "109 = "<<c ;
	
	/*  //preincrement test
	//a = ++b;

	cout << "After pre-increment\n";	
	cout << "1345+1 =" <<++a ;
	cout << "999+1 =" <<++b ;
	cout << "109+1 =" <<++c ;
	*/
	
	//postincrement test
	/*
	cout << "before post-increment\n";
	cout << a << "\n"; 
	cout << b << "\n"; 
	*/
	//bigInt = b++;

	cout << "After post-increment\n";	
	cout << a++ << "\n";
	cout << b++ << "\n";
	//cout << bigInt <<"\n";
	


	cout << "a + b = " <<  a + b;



	/*
	int index = 0;
	cout << "which digits would you like to know?\n";	
	cin >> index;
	cout << "index : " << index << "\n";
	//cout << "element: "  << BigInt1.[index];
	//BigInt1[index]* = 6;//insert 6 where user want to see
*/

	//return 0;
}//main
