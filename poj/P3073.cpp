#include<iostream>
#include<string>
using namespace std;
string c[]={"4","|3","(","|)","3","|=","6","#","|","_|","|<","|_","|//|","|/|","0","|0","(,)","|?","5","7","|_|","//","////","><","-/","2"};
string s,p,q;
int f[401];
int i,j;
int main()
{
	while(1)
	{
		cin >> s;
		if(s=="end")
			break;
		p="$";
		for(i=0;i<s.length();i++)
			p+=c[s[i]-'A'];
		memset(f,0,sizeof(f));
		f[0]=1;
		for(i=1;i<p.size();i++)
		{
			for(j=0;j<26;j++)
				if(i>=c[j].size()&&p.substr(i-c[j].size()+1,c[j].size())==c[j])
					f[i]+=f[i-c[j].size()];
		}
		printf("%d\n",f[p.size()-1]);
	}
	return 0;
}