#include<iostream>
using namespace std;
int k,i,n,c,p[1020],s,e;
int Q(int n)
{
	for(int i=2;i*i<=n;i++)
		if(n%i==0)
			return 0;
	return 1;
}
int main()
{
	for(i=1;i<2020;i++)
		if(Q(i))
			p[k++]=i;
	while(cin>>n>>c)
	{
		cout<<n<<" "<<c<<":";
		k=0;
		while(p[k]<=n)
			k++;  
		if(c>=k)
		{
			for(i=0;i<k;i++)
				cout<<" "<<p[i];
		}
		else
		{
			s=(k+1)/2-c;
			e=k/2+c-1;
			for(i=s;i<=e;i++)
				cout<<" "<<p[i];
		}
		cout<<endl<<endl;
	}
	return 0;
}