//C++ program for encryption and decryption
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdio.h>
using namespace std;

long int firstPrime, secondPrime, keyModulus, totientFunction, i, flag;
long int publicKey[50], publicKeyInverse[50], temp[50], maxValOfKey;
char encrypted[50], decrypted[50];
char message[100];
long int prime(long int); //function to check for prime number
void encryption_key();
long int cd(long int);
void encrypt();
void decrypt();

int main()
{
   cout << "\nENTER FIRST PRIME NUMBER\n";
   cin >> firstPrime;

   //checking whether input is prime or not
   flag = prime(firstPrime);
   if(flag == 0)
   {
      cout << "\nINVALID INPUT\n";
      exit(0);
   }

   cout << "\nENTER SECOND PRIME NUMBER\n";
   cin >> secondPrime;

   flag = prime(secondPrime);
   if(flag == 0 || firstPrime == secondPrime)
   {
      cout << "\nINVALID INPUT\n";
      exit(0);
   }

   cout << "\nENTER MESSAGE OR STRING TO ENCRYPT\n";
   cin >> message;

   for(i = 0; message[i] != NULL; i++)
      decrypted[i] = message[i];
   keyModulus = firstPrime * secondPrime;
   totientFunction = (firstPrime - 1) * (secondPrime - 1);

   encryption_key();
   cout << "\nPOSSIBLE VALUES OF publicKey AND publicKeyInverse ARE\n";

   for(i = 0; i < maxValOfKey - 1; i++)
      cout << "\n" << publicKey[i] << "\t" << publicKeyInverse[i];

   encrypt();
   decrypt();
   return 0;
} //end of the main program

long int prime(long int pr)
{
   long int i;
   maxValOfKey = sqrt(pr);
   for(i = 2; i <= maxValOfKey; i++)
   {
      if(pr % i == 0)
         return 0;
   }
   return 1;
 }

//function to generate encryption key
void encryption_key()
{
   long int key;
   key = 0;
   for(i = 2; i < totientFunction; i++)
   {
      if(totientFunction % i == 0)
         continue;
      flag = prime(i);
      if(flag == 1 && i != firstPrime && i != secondPrime)
      {
         publicKey[key] = i;
         flag = cd(publicKey[key]);
         if(flag > 0)
         {
            publicKeyInverse[key] = flag;
            key++;
         }
         if(key == 99)
         break;
      }
   }
}

long int cd(long int a)
{
   long int key = 1;
   while(1)
   {
      key = key + totientFunction;
      if(key % a == 0)
         return(key/a);
   }
}

//function to encrypt the message
void encrypt()
{
   long int pt, ct, key = publicKey[0], actualKey, len;
   i = 0;
   len = strlen(message);

   while(i != len)
   {
      pt = static_cast<long int>(decrypted[i]);
      pt = pt - 96;
      actualKey = 1;
      for(maxValOfKey = 0; maxValOfKey < key; maxValOfKey++)
      {
         actualKey = actualKey * pt;
         actualKey = actualKey % keyModulus;
      }
      temp[i] = actualKey;
      ct= actualKey + 96;
      encrypted[i] = static_cast<char>(ct);
      i++; 																						//64 112 128 140 152
   }
   encrypted[i] = -1;
   cout << "\n\nTHE ENCRYPTED MESSAGE IS\n";
   for(i=0; encrypted[i] != -1; i++)
      cout << encrypted[i];
}

//function to decrypt the message
void decrypt()
{
   long int pt, ct, key = publicKeyInverse[0], actualKey;
   i = 0;
   while(encrypted[i] != -1)
   {
      ct = temp[i];
      actualKey = 1;
      for(maxValOfKey = 0; maxValOfKey < key; maxValOfKey++)
      {
         actualKey = actualKey * ct;
         actualKey = actualKey % keyModulus;
      }
      pt = actualKey + 96;
      decrypted[i] = static_cast<char>(pt);
      i++;
   }
   decrypted[i] = -1;
   cout << "\n\nTHE DECRYPTED MESSAGE IS\n";
   for(i = 0; decrypted[i] != -1; i++)
      cout << decrypted[i];

  cout << endl;
}
