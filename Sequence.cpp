#include "Sequence.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <algorithm> 
using namespace std;

typedef struct suffix
{
 int n;
 char *p;
}sa;
bool compare(string a,string b)
{
 return a<b;
}
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
int com(const void *a,const void *b)
{
 sa A=*((sa*)a);
 sa B=*((sa*)b);
 int i=0;
 while(true)
 {
  if(i==A.n||i==B.n)
  {
   break;
  }
  if(*(A.p+i)!=*(B.p+i))
  {
   return *(A.p+i)-*(B.p+i);
  }
   i++;
 }
 return A.n-B.n;
}
string Sequence::longestRepeated()
{
 string thelongest;
 sa *s = (sa*)new sa[len +10];
 for(int i=0;i<len;i++)
 {
  s[i].p =&line[i];
  s[i].n = len -i;
 }
 qsort(s,len,sizeof(s[0]),com);
 int start =0;
 int maxlenght = 0;
 for(int i=0;i<len-1;i++)
 {
  if((s[i].n)<=maxlenght)
  {
   continue;
  }
  if((s[i+1].n)<=maxlenght)
  {
   i++;
   continue;
  }
  for(int j=0;j<s[i].n&&j<s[i+1].n;j++)
  {
   if(*(s[i].p+j)!=*(s[i+1].p+j))
   {
    if(j>maxlenght)
    {
     start = i;
     maxlenght = j;
    }
    break;
   }
  }
 }
 for(int i=0;i<maxlenght;i++)
 {
  thelongest += *(s[start].p+i);
 }
 //string thelongest =string{s[start].p,lenght};
 delete []s;
 return thelongest;
}
