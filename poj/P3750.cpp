#include<stdio.h>
#include<iostream>
using namespace std;
struct pe
{
	char a[20];
	pe *next,*last;
}b[65],*now;
char c;
int main()
{
	int i,n,k=0,s,m,j=1;
	cin >> n;
	for(i=0;i<n;i++)
	{
		cin >> b[i].a;
		b[i].last=&b[i-1];
		b[i].next=&b[i+1];
	}
	b[0].last=&b[n-1];
	b[n-1].next=&b[0];
	cin >> s >> c >> m;
	now=&b[s-1];
	while(k!=n)
	{
		if(j==m)
			{
				now->last->next=now->next;
				j=0;
				cout << now->a <<endl;
				k++;
			}
		now=now->next;
		j++;
	}
	return 0;
}