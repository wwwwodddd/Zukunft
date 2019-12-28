#include<iostream>
using namespace std;
int m,n,a[1010],f[1010],g[1010];
int s,l,r,z;
int i,j,k;
int ok;
int main()
{
	while(scanf("%d%d",&m,&n)&&(n||m))
	{
		s=0;
		for(i=m;i<=n;i+=2)
		{
			s++;
			scanf("%d",&a[s]);
			if(i==-1)
				l=s;
			if(i==1)
				r=s;
			f[s]=g[s]=0;
		}
		z=g[1]=1;
		for(i=2;i<r;i++)
			if(a[i]>=a[z])
				f[i]=f[i-1]+(i-z)*2*a[z],g[i]=z=i;
			else
				f[i]=f[i-1],g[i]=z;
		z=f[s]=s;
		for(i=s-1;i>l;i--)
			if(a[i]>=a[z])
				g[i]=g[i+1]+(z-i)*2*a[z],f[i]=z=i;
			else
				g[i]=g[i+1],f[i]=z;
		ok=z=0;
		if(a[g[l]]==a[f[r]])
			printf("%d\n",min(f[l],g[r])*2+(f[r]-g[l])*2*a[g[l]]);
		else if(a[g[l]]<a[f[r]])
		{
			while(a[g[l]]>=a[r])
			{
				if((!ok)&&(a[g[l]]==a[r]))
					z+=(r-g[l])*2*a[r],g[l]=r,ok=1;
				r++;
			}
			if((ok)&&(f[l]<=(r-g[l])*2*a[g[l]]))
				printf("%d\n",f[l]*2+z);
			else
				printf("%d\n",f[l]+z+(r-g[l])*2*a[g[l]]);
		}
		else
		{
			while(a[f[r]]>=a[l])
			{
				if((!ok)&&(a[f[r]]==a[l]))
					z+=(f[r]-l)*2*a[l],f[r]=l,ok=1;
				l--;
			}
			if((ok)&&(g[r]<=(f[r]-l)*2*a[f[r]]))
				printf("%d\n",g[r]*2+z);
			else
				printf("%d\n",(f[r]-l)*2*a[f[r]]+z+g[r]);
		}
	}
	return 0;
}
