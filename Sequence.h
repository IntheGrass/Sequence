#ifndef SEQUENCE_H
#define SEQUENCE_H
#include<string>
using namespace std;

class Sequence
{
public:
 Sequence(char* );
 int length();
 int numberOf(const char& );
 string longestConsecutive();
 string longestRepeated();
private:
 char line[2000000];
 int len;
};
#endif
