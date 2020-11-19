#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
int main()
{
	string s;
	for(int i=0;i<100000;i++)
		s+=rand()%26+'a';
	cout << s.size() << ' ' << 17 << endl;
	cout << s << endl;
	return 0;
}
