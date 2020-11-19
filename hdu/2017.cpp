#include<stdio.h>
#include<iostream>
char s[3000];
int z;
int main()
{
	for(gets(s);gets(s);printf("%d\n",z))
		for(int i=z=0;s[i];i++)
			if(isdigit(s[i]))
				z++;
}
