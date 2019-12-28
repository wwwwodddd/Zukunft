#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
const char st[6]={"START"};
const char ed[5]={"END"};
int main()
	{
		char a[500];
		int i,l;
		while(gets(a))
		{
		if(strcmp(a,"ENDOFINPUT")==0)
			break;
		if(strcmp(st,a)!=0&&strcmp(ed,a)!=0)
			{
			l=strlen(a);
			for(i=0;i<l;i++)
				{
				if(a[i]<='Z'&&a[i]>='A')
					printf("%c",a[i]-5>='A'?a[i]-5:a[i]+21);
				else
					printf("%c",a[i]);
				}
			printf("\n");
			}
		
		}
	return 0;
	}