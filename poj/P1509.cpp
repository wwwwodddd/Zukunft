#include<iostream>
#include<string.h>
using namespace std;
int csc,i,j,k,l;
char s[200020];
int work()
{
	int i=0,j=1,k=0;
	while(i<l&&j<l&&k<l)
	{
		if(s[i+k]==s[j+k])
			k++;
		else
		{
			if(s[i+k]>s[j+k])
				i+=(k+1);
			else
				j+=(k+1);
			if(i==j)
				j++;
				k=0;
		}
	}
	return min(i,j);
}
int main()
{

	scanf("%d",&csc);
	while(csc--)
	{
		scanf("%s",s);
		l=strlen(s);
		for(i=0;i<l;i++)
			s[l+i]=s[i];
		s[2*l]=0;
		printf("%d\n",work()+1);
	}
	return 0;
}