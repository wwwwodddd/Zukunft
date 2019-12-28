#include<iostream>
#include<string>
using namespace std;
string s;
int x,i;
int main()
{
	while(cin>>s)
	{
		x=0;
		for(i=s.length()-1;i>=0;i--)
		{
			char c=s[i];
			if(c>='p'&&c<='z')
				x++;
			else if(c=='N')
			{
				if(x<1)
					break;
			}
			else if(c=='C'||c=='D'||c=='E'||c=='I')
			{
				x--;
				if(x<1)
					break;
			} 
			else
			{
				x=-1;
				break;
			}
			
		}
		if(x==1)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
