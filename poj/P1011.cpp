#include<iostream>
#include<cmath>
#include<string.h>
#include<stdlib.h>
using namespace std;
int sticks[70],b[70];
int n,mini,num,temp,temp1;
int cmp(const void *a,const void *b)
{ 
	return *(int*)b-*(int*)a;
}
bool dfs(int len,int t)
{
	int i;
	if(len==mini)
	{
		t=0;
		temp++;
		len=0;
		temp1=0;
		if(temp==num)
			return true;
	}
	for(i=t;i<n;i++)
	{
		if(len+sticks[i]<=mini&&b[i]==0&&temp1!=sticks[i]) 
		{  
			len+=sticks[i];  
			b[i]=1;  
			dfs(len,i+1);  
			if(temp==num) 
				break; 
			if(len==mini) 
				temp--;  
			len-=sticks[i]; 
			b[i]=0;   
			temp1=sticks[i];
		} 
		if(t==0&&temp!=num&&b[i]==0) 
			return false;//这个剪枝非常关键，决定程序是否超时 
	} 
	if(temp==num) 
		return true; 
	else   
		return false;
}
int main()
{
	int i,sum; 
	while(cin>>n&&n!=0)
	{  
		memset(b,0,sizeof(b));
		sum=0; 
		for(i=0;i<n;i++)  
		{   
			cin>>sticks[i];  
			sum+=sticks[i]; 
		} 
		qsort(sticks,n,sizeof(sticks[0]),cmp); 
		for(mini=sticks[0];;mini++)
		{ 
			if(sum%mini==0)   
			{   
				temp=0;  
				temp1=0;   
				num=sum/mini; 
				if(dfs(0,0))   
					break;  
			}  
		}  
		cout<<mini<<endl;
	}
	return 0;
}