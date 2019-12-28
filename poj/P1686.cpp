#include<iostream>
#include<stack>
using namespace std;
char c1[2000],c2[2000];
char s1[2000],s2[2000],s[2000];
int i,j,k,t,a[126];
int ok(char c)
{
	return c>='0'&&c<='9'||c>='a'&&c<='z';
}
void S(char c[])
{
	int i,j=0,k;
	stack<char>q;
	for(i=0;i<strlen(c);i++)
	{
		if(ok(c[i]))
			s[j++]=c[i];
		else if(c[i]=='(')
			q.push(c[i]);
		else if(c[i]==')')
		{
			while(q.top()!='(')
			{
				s[j++]=q.top();
				q.pop();
			}
			q.pop();
		}
		else if(c[i]=='+'||c[i]=='-'||c[i]=='*')
		{
			while(!q.empty()&&a[c[i]]<=a[q.top()])
			{
				s[j++]=q.top();
				q.pop();
			}
			q.push(c[i]);
		}
	}
	while(!q.empty())
	{
		s[j++]=q.top();
		q.pop();
	}
	s[j]=0;
}
int C(char *s)
{
	int i,j,k;
	stack<int>q;
	for(i=0;i<strlen(s);i++)
	{
		if(ok(s[i]))
		{
			if(s[i]>='0'&&s[i]<='9')
				q.push(s[i]-'0');
			else
				q.push(s[i]);
		}
		else
		{
			j=q.top();
			q.pop();
			k=q.top();
			q.pop();
			if(s[i]=='+')
				j=j+k;
			if(s[i]=='-')
				j=k-j;
			if(s[i]=='*')
				j=k*j;
			q.push(j);
		}
	}
	return q.top();
}
int main()
{
	a['+']=1;
	a['-']=1;
	a['*']=2;
	a['(']=0;
	cin>>t;
	getchar();
	while(t--)
	{
		gets(c1);S(c1);strcpy(s1,s);
		gets(c2);S(c2);strcpy(s2,s);
		puts(C(s1)==C(s2)?"YES":"NO");
	}
	return 0;
}