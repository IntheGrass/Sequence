#include "Sequence.h"
#include <iostream>
#include <ctime>
#include <unistd.h>
#include <algorithm>
using namespace std;

int main()
{
  Sequence text("dna.txt");
  //int a[2]={0,1};
  //sort(a,a+2);
  cout << text.length() << endl;
  cout << text.numberOf('A')<< endl;
  cout << text.numberOf('T')<<endl;
  cout << text.numberOf('C')<<endl;
  cout << text.numberOf('G')<<endl;
  //clock_t starttime = clock();
  cout << text.longestConsecutive() << endl;
  //clock_t endtime = clock();
 // cout << (double)(endtime - starttime)/CLOCKS_PER_SEC<<endl;
  clock_t starttime = clock();
  cout <<  text.longestRepeated() << endl;
  clock_t endtime = clock();
  cout << (double)(endtime - starttime)/CLOCKS_PER_SEC<<endl;
  return 0;
}
