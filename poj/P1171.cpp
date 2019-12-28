#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
struct N
{
	char s[10];
	int l,v;
}a[40010];
int l[26],v[26]={2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,6,7,5,7};
int w[26];
int vm,t;
char s[10],c[10];
int V(char s[])
{
	int re=0;
	for(int i=0;i<s[i];i++)
		re+=v[s[i]-'a'];
	return re;
}
bool add(char s[])
{
	for(int i=0;i<s[i];i++)
	{
		w[s[i]-'a']++;
		if(w[s[i]-'a']>l[s[i]-'a'])
			return 0;
	}
	return 1;
}
int main()
{
	int i,j;
	scanf("%s",s);
	int sv=V(s),sl=strlen(s);
	for(i=0;i<sl;i++)
		l[s[i]-'a']++;
	while(scanf("%s",c),*c!='.')
	{
		int cl=strlen(c),cv=V(c);
		if(cl>sl||cv>sv)    
			continue;
		memset(w,0,sizeof(w));
		if(!add(c))    
			continue;
		vm=max(vm,cv);
		if(sl==6&&cl==3||sl==7&&cl<=4)
		{
			strcpy(a[t].s,c);
			a[t].l=cl;
			a[t].v=cv;
			t++;
		}
	}
	if(sl>=6&&vm<sv)
	{
		for(i=0;i<t;i++)
			for(j=0;j<t;j++)
			{
				if(a[i].l+a[j].l>sl||a[i].v+a[j].v>sv)
					continue;
				memset(w,0,sizeof(w));
				if(!add(a[i].s))
					continue;
				if(!add(a[j].s))
					continue;
				vm=max(vm,a[i].v+a[j].v);
			}
	}
	printf("%d\n",vm);
	return 0;
}
