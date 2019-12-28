#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
using namespace std;
int a[100],b[100],e[100],t[100];
char s[100],c[100];
int mod(int *a,int x)
{
	int y=0;
	for(int i=a[0];i>0;i--)
	{
		y=y*10+a[i];
		y%=x;
	}
	return y;
}
void div(int *a,int x)
{
	int r[100],y=0;
	memset(r,0,sizeof(r));
	for(int i=a[0];i>0;i--)
	{
		y=y*10+a[i];
		r[i]=y/x;
		y%=x;
	}
	r[0]=99;
	while(!r[r[0]]&&r[0])
		r[0]--;
	memcpy(a,r,sizeof(r));
	return;
}
void print(int *p)
{
	
	for(int i=p[0];i>1;i--)
	{
		printf("%d",p[i]);
		if(i%3==1)
			printf(",");
	}
	printf("%d\n",p[1]);
	return;
}
void scan(int a,int *p)
{
	for(p[0]=1;a;p[0]++)
	{
		p[p[0]]=a%10;
		a/=10;
	}
	p[0]--;
	return;
}
void smul(int *a,int x)
{
	int i;
	int r[100];
	memset(r,0,sizeof(r));
	for(i=1;i<=a[0];i++)
		r[i]=a[i]*x;
	for(i=1;i<=a[0]+8;i++)
	{
		r[i+1]+=r[i]/10;
		r[i]%=10;
	}
	r[0]=99;
	while(!r[r[0]]&&r[0])
		r[0]--;
	memcpy(a,r,sizeof(r));
	return;
}
void plu(int *a,int *b)
{
	int i;
	a[0]=99;
	for(i=1;i<=a[0];i++)
		a[i]+=b[i];
	for(i=1;i<=a[0];i++)
	{
		a[i+1]+=a[i]/10;
		a[i]%=10;
	}
	while(!a[a[0]])
		a[0]--;
	return;
}
void ston(char *s,int *a)
{
	a[0]=strlen(s);	
	for(int i=0;i<a[0];i++)
		a[a[0]-i]=s[i]-'0';
	return;
}
void aton(char *s,int *a)
{
	a[0]=strlen(s);	
	for(int i=0;i<a[0];i++)
		a[a[0]-i]=s[i]-'a'+1;
	return;
}
void ntos(char *s,int *a)
{
	for(int i=1;i<=a[0];i++)
		s[a[0]-i]=a[i]+'0';
	return;
}
void ntoa(char *s,int *a)
{
	for(int i=1;i<=a[0];i++)
		s[a[0]-i]=a[i]+'a'-1;
	return;
}
int main()
{
	int x,i;
	while(scanf("%s",s)&&s[0]!='*')
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		if(s[0]>='0'&&s[0]<='9')
		{
			ston(s,a);
			ston(s,e);
			b[0]=1;
			while(a[0])
			{
				b[b[0]++]=mod(a,26);
				div(a,26);
			}
			b[0]--;
			for(i=1;i<b[0];i++)
				if(b[i]<=0)
				{
					b[i]+=26;
					b[i+1]--;
				}
			if(b[b[0]]==0)
				b[0]--;
			ntoa(c,b);
			printf("%s",c);
			for(i=strlen(c);i<22;i++)
				printf(" ");
			print(e);
		}
		else
		{
			aton(s,a);
			for(i=a[0];i>0;i--)
			{
				memset(t,0,sizeof(t));
				scan(a[i],t);
				smul(b,26);
				plu(b,t);
			}
			printf("%s",s);
			for(i=strlen(s);i<22;i++)
				printf(" ");
			print(b);
		}
	}
	return 0;
}
