#include "Sequence.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
using namespace std;

Sequence::Sequence(char* filename)
{
 ifstream in(filename);
 if(!in)
  {
    cout << "error"<<endl;
  }
 else
  {
   int flag =0;
   char a;
   while(in>>a)
   {
     if(a!='\n')
     {
       line[flag]= a;
       ++flag;
     }
   }
   len = flag;
  }
}

int Sequence::length()
{
  return len;
}

int Sequence::numberOf(const char& base)
{
  int number=0;
  for(int i=0;i<len;i++)
  {
    if(line[i]== base)
     {
      ++number;
     }
  }
  return number;
}

string Sequence::longestConsecutive()
{
 int longest=1;
 string longestcon;
 int left = 0;
 int right = 0;
 for(int i=0;i<len-1;i++)
 {
   if(longest>len-i)
   {
    break;
   }
   if(line[i+longest]!=line[i])
   {
    continue;
   }
   for(int j=i+1;j<len;j++ )
   {
    if(line[j]!=line[i])
    {
     if((j-i)>longest)
     {
      longest=j-i;
      left = i;
      right = j-1;
     }
     i=j-1;
     break;  
    }  
   }
 }
 for(int i=left;i<=right;i++)
 {
   longestcon+=line[i];
 }
 return longestcon;
}

string Sequence::longestRepeated()
{
 string longest;
 int num = 120;
 for(int i = 0;i<len-1;i++)
 {
  string tem1;
  if(num >= 150)
  {
   break;
  }
  if((len-i-1)<num)
  {
   break;
  }
  for(int j= i;j < len-1; j++)
  {
   tem1 += line[j];
   int a = tem1.length();
   if(a< num)
   {
    continue;
   }
    for(int k = j+1;k<len - a;k++)
    {
     string tem2;
     int counter=0;
     for(int m = k;m<k+a;m++)
     {
      if(line[m]!= tem1[m-k])
      {
       break;
      }
      tem2+=line[m];
      ++counter;
     }
     if(counter ==a)
     {
      longest = tem1;
      num =counter;
     }
    }
  }
 }
 return longest;
}
