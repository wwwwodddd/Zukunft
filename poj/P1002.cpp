#include<iostream>
#include<string>
using namespace std;
int cr[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9,0};
int h[10000000];
string a,b;
void hsh()
{
int i,j=0,k=0;
k=0;
for(i=0;i<a.size();i++)
	{
	if(a[i]=='-')
		continue;
	else if(a[i]>='0'&&a[i]<='9')
		{
		b[k]=a[i];
		k++;
		}
	else
		b[k++]=cr[a[i]-'A']+'0';
	}
for(i=0;i<7;i++)
{
j*=10;
j+=b[i]-'0';
}
h[j]++;
}

int main()
{
int n;
int tx=0;
b="AAAAAAA";
cin >> n;
while(n--)
	{
	cin >> a;
	hsh();
	}
for(int i=0;i<10000000;i++)
	if(h[i]>1)
		{
		printf("%03d-%04d %d\n",i/10000,i%10000,h[i]);
		tx=1;
		}
if(tx==0)
	printf("No duplicates.");
//		cout << setw(3) << setfill('0') << setiosflags(ios::fixed) << i/10000 << '-' << i%10000 << ' ' << h[i] <<endl;
return 0;
}