#include<iostream>
#include<stack>
using namespace std;
int i,j,k,n;
char s[1000];
int t[1000];
int c(int x,int y)
{
	for(int i=x+1;i<y;i++)
		if(s[i]=='+'||s[i]=='-')
			return 0;
	return 1;
}
int d(int x)
{
	for(int i=x-1;i>=0;i--)
		if(s[i]!='-'&&s[i]!=' ')
			return 1;
		else if(s[i]=='-')
			return 0;
	return 1;
}
int main()
{
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		memset(t,0,sizeof(t));
		memset(s,0,sizeof(s));
		gets(s);
		int l=strlen(s);
		stack<int>st;
		for(i=0;i<l;i++)
			if(s[i]=='(')
				st.push(i);
			else if(s[i]==')')
			{
				t[st.top()]=i;
				st.pop();
			}
		int cnt=0;
		for(i=0;i<l;i++)
			if(s[i]=='(')
				if(c(i,t[i])||d(i))
					s[i]=s[t[i]]=' ';
		for(i=0;i<l;i++)
			if(s[i]!=' ')
				printf("%c",s[i]);
		printf("\n");
	}
	return 0; 
}