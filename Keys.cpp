#pragma once

#include <map>
#include <iostream>
#include <utility>
#include <random>
#include <ctime>

//#include "Keys.h"
void generateKeys(int firstPrime, int secondPrime, int &encryption, int &decryption)
{
	
	
	int j = (firstPrime-1)*(secondPrime-1);
	
	int rPrime = 1;
	int d = 1;
	
	rPrime = relativelyPrime(j);
	d = inverse(rPrime, j);
	
	encryption = rPrime;
	decryption = d;
}

int relativelyPrime (int num)
{
	int x = 0;
	int GCD = 0;
	int divisor = 0;
	for (int i = 2; i < num; ++i)
	{
		for(int n = 1; n <=i;n++)
		{
			if (i%n == 0)
				divisor++;
		} //end n for
		if (divisor == 2)
		{
			GCD = GreatestCommonDenominator(i, num);
			if (GCD == 1)
			{
				x = i;
				break;
			} //end FDC if
			else
				divisor = 0;
		} //end divisor if
		else
			divisor = 0;
	} //end i for
	return x;
}

int GreatestCommonDenominator(int num1, int num2)
{
	int x = num1;
	int y = num2;
	
	while (y != 0)
	{
		int z = (x%y);
		x=y;
		y=z;
	} //end while
	return x;
}

int inverse(int num1, int modulus)
{
	int x = 0;
	int y = 0;
	for (int i = 0; i < modulus;i++)
	{
		y = ((i*num1)%modulus);
		if (y == 1)
		{
			x = i;
			break;
		}
	}
	return x;
}



