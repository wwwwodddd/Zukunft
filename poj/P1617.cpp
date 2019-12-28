#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
char c[12],z[12],s[110];
int f[12],v[12],i,j,k,l,u;
int main()
{
	while(cin>>c&&strcmp(c,"THEEND")!=0)
	{
		cin>>s;
		l=strlen(c);
		k=strlen(s);
		u=k/l;
		strcpy(z,c);
		sort(c,c+l);
		memset(v,0,sizeof(v));
		for(i=0;i<l;i++)
			for(j=0;j<l;j++)
				if(!v[j]&&z[i]==c[j])
				{
					f[i]=j;
					v[j]=1;
					break;
				}
		for(i=0;i<u;i++)
			for(j=0;j<l;j++)
				cout<<s[u*f[j]+i];
		cout<<endl;
	}
	return 0;
}
