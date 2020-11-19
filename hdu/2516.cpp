/*
  Name: 
  Copyright: 
  Author: 
  Date: 30-12-11 00:02
  Description: 
*/
#include<stdio.h>
int f[60],i,n;
int main()
{
	f[0]=f[1]=1;
	for(n=2;n<46;n++)
		f[n]=f[n-1]+f[n-2];
	while(scanf("%d",&n),n)
	{
		for(i=0;i<46;i++)
			if(f[i]==n)
				break;
		puts(i==46?"First win":"Second win");
	}
	return 0;	
}
// shuru jieshu tiaojian
