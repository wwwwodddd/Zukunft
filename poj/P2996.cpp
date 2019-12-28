#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
char g[35][35];
char r[15]=" KQRBNPkqrbnp";
int c[100],i;
string ans;
int use;
int main()
{
	for(int i=17;i>=1;i--)
		gets(g[i]);
	for(int i=1;i<=8;i++)
		for(int j=1;j<=8;j++)
			if(g[i*2][j*4-2]!='.' && g[i*2][j*4-2]!=':')
			{
				use++;
				for(int k=1;k<=6;k++)
					if(g[i*2][j*4-2]==r[k])
						c[use]=k*100+i*10+j;
				for(int k=7;k<=12;k++)
					if(g[i*2][j*4-2]==r[k])
						c[use]=k*100+(9-i)*10+j;
			}
	sort(c+1,c+use+1);
	printf("White: ");
	for(i=1;i<=use;i++)
		if(c[i]<700)
		{
			if(r[c[i]/100]!='P')
				ans+=r[c[i]/100];
			c[i]%=100;
			int x=c[i]/10;
			c[i]%=10;
			ans+=c[i]+'a'-1;
			ans+=x+'0';
			ans+=',';
		}
		else
			break;
	if(ans!="")
		ans.erase(ans.length()-1);
	cout << ans << endl;
	printf("Black: ");
	ans="";
	for(;i<=use;i++)
	{
		if(r[c[i]/100]!='p')
			ans+=r[c[i]/100]-'a'+'A';
		c[i]%=100;
		int x=9-c[i]/10;
		c[i]%=10;
		ans+=c[i]+'a'-1;
		ans+=x+'0';
		ans+=',';
	}
	if(ans!="")
		ans.erase(ans.length()-1);
	cout << ans << endl;
	return 0;
}