#include<iostream>
#include<string>
using namespace std;
char r[20];
int h[20],l[20];
string a,b,c;
int i,j,k,t;
int main()
{
	cin >> t;
	while(t--)
	{
		memset(r,0,sizeof(r));
		memset(h,0,sizeof(h));
		memset(l,0,sizeof(l));
		for(i=0;i<3;i++)
		{
			cin >> a >> b >> c;
			for(j=0;j<a.size();j++)
				if(c=="even")
					r[a[j]-'A']=r[b[j]-'A']=1;
				else if(c=="up")
					h[a[j]-'A']++,l[b[j]-'A']++;
				else
					l[a[j]-'A']++,h[b[j]-'A']++;
		}
		for(i=0,k=13;i<13;i++)
			if((!r[i]||l[i]>0&&h[i]>0)&&max(l[k],h[k])<max(l[i],h[i]))
				k=i;
		printf("%c is the counterfeit coin and it is %s.\n",k+'A',h[k]>l[k]?"heavy":"light");
	}
return 0;
}
