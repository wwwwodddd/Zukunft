#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
char a[30],b[30],c[30];
int m;
int fxx(int x)
{
if(x<'a')
	return 2*(x-'A'+1);
else
	return 2*(x-'a'+1)+1;
}
int fyy(int x)
{
if(x&1)
	return ('a'-1)+x/2;
else
	return ('A'-1)+x/2;
}
void cha()
{
for(int i=0;i<m;i++)
	a[i]=fxx(a[i]);
}
void fre()
{
for(int i=0;i<m;i++)
	printf("%c",fyy(a[i]));
printf("\n");
}
int cmp(const void *a,const void *b)
{
	return *((char*)a)-*((char*)b);
return 0;
}
int main()
{
int n;
scanf("%d",&n);
while(n--)
	{
	cin >> a;
	m=strlen(a);
	cha();
	qsort(a,m,1,cmp);
	strcpy(b,a);
	fre();
	next_permutation(a,a+m);
	while(strcmp(b,a)!=0)
		{
		fre();
		next_permutation(a,a+m);
		}
	}
return 0;
}