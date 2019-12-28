#include<iostream>
#include<algorithm>
using namespace std;
char s[20];
int a[100];
char c[100][20];
int v[100];
int n,m,t,l;
int cmp1(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
int cmp2(const void *a,const void *b)
{
	char a1[20]="";
	char b1[20]="";
	int i;
	strcpy(a1,(char *)a);
	strcpy(b1,(char *)b);
	for(i=0;a1[i];i++)
	  a1[i]=(a1[i]>=65&&a1[i]<=90)?a1[i]+32:a1[i];
	for(i=0;b1[i];i++)
	  b1[i]=(b1[i]>=65&&b1[i]<=90)?b1[i]+32:b1[i];
	return strcmp(a1,b1);
}
void change(char s[])
{
	sscanf(s,"%d",&a[n++]);
	v[t++]=1;
}
void solve()
{
	int i,x=0,y=0;
	qsort(a,n,sizeof(a[0]),cmp1);
	qsort(c,m,sizeof(c[0]),cmp2);
	for(i=0;i<t;i++)
	{
		if(v[i])
			printf("%d",a[x++]);
		else
			printf("%s",c[y++]);
		if(i==t-1)
			printf(".");
		else
			printf(", ");
	}
	printf("\n");
	m=n=t=0;
}
int main()
{
	while(scanf("%s",s)+1)
	{
		if(s[0]=='.')
			break;
		l=strlen(s);
		if((s[0]>='0'&&s[0]<='9')||s[0]=='-'||s[0]=='+')
			change(s);
		else
		{
			strcpy(c[m],s);
			c[m++][l-1]='\0';
			v[t++]=0;
		}
		if(s[l-1]=='.')
			solve();
	}
	system("pause");
	return 0;
}