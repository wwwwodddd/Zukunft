#include<iostream>
#include<algorithm>
using namespace std;
int l;
char a[210];
int main()
{
	gets(a);
	l=strlen(a);
	sort(a,a+l);
	do
		puts(a);
	while(next_permutation(a,a+l));
	return 0;
}