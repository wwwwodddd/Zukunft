#include<iostream>
#include<string>
using namespace std;
struct L
{
	string s;
	char c;
	int u;
}l[30]={{".-",'A',2},{"-...",'B',4},{"-.-.",'C',4},{"-..",'D',3},{".",'E',1},{"..-.",'F',4},{"--.",'G',3},{"....",'H',4},{"..",'I',2},{".---",'J',4},{"-.-",'K',3},{".-..",'L',4},{"--",'M',2},{"-.",'N',2},{"---",'O',3},{".--.",'P',4},{"--.-",'Q',4},{".-.",'R',3},{"...",'S',3},{"-",'T',1},{"..-",'U',3},{"...-",'V',4},{".--",'W',3},{"-..-",'X',4},{"-.--",'Y',4},{"--..",'Z',4},{"..--",'_',4},{".-.-",',',4},{"---.",'.',4},{"----",'?',4}};
string a,b,c;
int z[100],n,p,i,j,k;
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		b=c="";
		cin>>a;
		for(j=0;j<a.length();j++)
			for(k=0;k<30;k++)
				if(a[j]==l[k].c)
				{
					z[j]=l[k].u;
					b=b+l[k].s;
					break;
				}
		p=0;
		for(j=a.length()-1;j>=0;j--)
			for(k=0;k<30;k++)
				if((b.substr(p,z[j]))==l[k].s)
				{
					c+=l[k].c;
					p+=z[j];
					break;
				}
	cout<<i<<": "<<c<<endl;;
	}
	return 0;
}