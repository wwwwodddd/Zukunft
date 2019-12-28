#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct xlk
{
xlk *nt[26];
int flag;
};
xlk* rt;
char str[1000][25],sub[1000][25];
void insert(char *str)
{
	int i,in;
	xlk *cur=rt,*nxk;
	for(i=0;str[i];i++)
	{
		in=str[i]-'a';
		if(cur->nt[in]!=0)
		{
			cur=cur->nt[in];
			(cur->flag)++;
		}
		else
		{
			nxk=(xlk*)calloc(1,sizeof(xlk));
			cur->nt[in]=nxk;
			cur=nxk;
			cur->flag=1;
		}
	}
}
void find(char *str,char *sub)
{
	int i,in;
	xlk *cur=rt;
	for(i=0;str[i];i++)
	{
		in=str[i]-'a';
		cur=cur->nt[in];
		sub[i]=str[i];
		if(cur->flag==1)
			return;
	}
	return;
}
int main()
{
	int j,i=0;
	rt=(xlk*)calloc(1,sizeof(xlk));
	while(scanf("%s",str[i])!=EOF)
		insert(str[i++]);
	for(j=0;j<i;j++)
		find(str[j],sub[j]);
	for(j=0;j<i;j++)
		printf("%s %s\n",str[j],sub[j]);
	return 0;
}
