#include<iostream>
using namespace std;
int t,ans;
char s1[10],s2[10];
int f[256];
int C(char *s)
{
	int l=strlen(s),n=0;
	for(int i=0; i<l; i++)
	{
		if(!f[s[i]])
			continue;
		if(i&&!f[s[i-1]])
			n+=(s[i-1]-'0')*f[s[i]];
		else
			n+=f[s[i]];
	}
	return n;
}
void ch(char x)
{
	if(ans/f[x])
	{
		if(ans/f[x]!=1)
			cout<<ans/f[x];
		cout<<x;
		ans%=f[x];
	}
}
int main()
{
	f['m']=1000;
	f['c']=100;
	f['x']=10;
	f['i']=1;
	cin >> t;
	while(t--)
	{
		cin >> s1 >> s2;
		ans=C(s1)+C(s2);
		ch('m');
		ch('c');
		ch('x');
		ch('i');
		cout << endl;
	}
}
