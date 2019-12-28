#include<stdio.h>
int C(char c)
{
	const static char w[]="0A23456789XJQK";
	for(int i=1;i<14;i++)
		if(w[i]==c)
			return i;
}
int two,thr,fou,str,flu;
char s[5][3];
int work()
{
	two=thr=fou=str=0,flu=1;
	for(int i=0;i<4;i++)
		if(*s[i]!=*s[i+1])
			flu=0;
	int c[20]={};
	for(int i=0;i<5;i++)
		c[C(s[i][1])]++;
	int x=c[1]&&c[10]&&c[11]&&c[12]&&c[13];
	for(int i=1;i<14;i++)
		if(c[i]==4)
			fou=1;
		else if(c[i]==3)
			thr=1;
		else if(c[i]==2)
			two++;
		else if(c[i]&&c[i-1])
			x++;
	if(x==4)
		str=1;
	if(str&&flu)
		return 1000;
	if(fou)
		return 750;
	if(thr&&two)
		return 500;
	if(flu)
		return 350;
	if(str)
		return 250;
	if(thr)
		return 200;
	if(two==2)
		return 100;
	if(two==1)
		return 50;
	return 0;
}
int main()
{
	int t;
	for(scanf("%d",&t);t--;)
	{
		for(int i=0;i<5;i++)
			scanf("%s",s[i]);
		printf("%d\n",work());
	}
}
