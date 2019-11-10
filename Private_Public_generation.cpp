//C++ program for encryption and decryption
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<string.h>

using namespace std;

int firstPrime, secondPrime, keyModulus, totientFunction, i, flag;
long int publicKey[50], publicKeyInverse[50], temp[50], maxValOfKey;
char en[50], m[50];
char message[100];
int prime(long int); //function to check for prime number
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
      m[i] = message[i];
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

int prime(long int pr)
{
   int i;
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
   int key;
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
   long int pt, ct, key = publicKey[0], key, len;
   i = 0;
   len = strlen(message);

   while(i != len)
   {
      pt = m[i];
      pt = pt - 96;
      key = 1;
      for(maxValOfKey = 0; maxValOfKey < key; maxValOfKey++)
      {
         key = key * pt;
         key = key % keyModulus;
      }
      temp[i] = key;
      ct= key + 96;
      en[i] = ct;
      i++;
   }
   en[i] = -1;
   cout << "\n\nTHE ENCRYPTED MESSAGE IS\n";
   for(i=0; en[i] != -1; i++)
      cout << en[i];
}

//function to decrypt the message
void decrypt()
{
   long int pt, ct, key = publicKeyInverse[0], key;
   i = 0;
   while(en[i] != -1)
   {
      ct = temp[i];
      key = 1;
      for(maxValOfKey = 0; maxValOfKey < key; maxValOfKey++)
      {
         key = key * ct;
         key = key % keyModulus;
      }
      pt = key + 96;
      m[i] = pt;
      i++;
   }
   m[i] = -1;
   cout << "\n\nTHE DECRYPTED MESSAGE IS\n";
   for(i = 0; m[i] != -1; i++)
      cout << m[i];

  cout << endl;
}
