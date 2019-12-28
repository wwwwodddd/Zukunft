#include<stdio.h>
#define L(x) ((x)*2)
#define R(x) ((x)*2+1)
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
struct str_node
{
	int l,r;
	int p;
	int u,v,w;
} t[200100];
int M(int x)
{
	return (t[x].l+t[x].r)/2;
}
int E(int x)
{
	return t[x].r-t[x].l+1;
}
void I(int x)
{
	t[x].u=t[x].v=t[x].w=t[x].p?0:E(x);
	return;
}
void B(int z,int l,int r)
{
	t[z].l=l;
	t[z].r=r;
	t[z].p=z==1?0:-1;
	t[z].u=t[z].v=t[z].w=E(z);
	if(l==r)
		return;
	B(L(z),l,M(z));
	B(R(z),M(z)+1,r);
	return;
}
int S(int z,int l)
{
	if(E(z)==1&&l==1)
		return t[z].l;
	if(t[z].p!=-1)
	{
		t[R(z)].p=t[L(z)].p=t[z].p;
		I(L(z));
		I(R(z));
		t[z].p=-1;
	}
	if(t[L(z)].w>=l)
		return S(L(z),l);
	else if(t[L(z)].v+t[R(z)].u>=l)
		return t[L(z)].r-t[L(z)].v+1;
	else if(t[R(z)].w>=l)
		return S(R(z),l);
	else
		return 0;
}
void U(int z,int l,int r,int p)
{
	if(l<=t[z].l&&t[z].r<=r)
	{
		t[z].p=p;
		I(z);
		return;
	}
	if(t[z].p!=-1)
	{
		t[L(z)].p=t[R(z)].p=t[z].p;
		I(L(z));
		I(R(z));
		t[z].p=-1;
	}
	if(l<=M(z))
		U(L(z), l, r, p);
	if(M(z)+1<=r)
		U(R(z), l, r, p);
	t[z].u=t[L(z)].u;
	t[z].v=t[R(z)].v;
	t[z].w=max(max(t[L(z)].w,t[R(z)].w),t[L(z)].v+t[R(z)].u);
	if(t[z].u==E(L(z)))
		t[z].u+=t[R(z)].u;
	if(t[z].v==E(R(z)))
		t[z].v+=t[L(z)].v;
	return;
}
int main()
{
	int n,m,f,l,r,s;
	scanf("%d %d",&n,&m);
	B(1,1,n);
	while(m--)
	{
		scanf("%d",&f);
		if(f==1)
		{
			scanf("%d",&l);
			s=S(1,l);
			printf("%d\n",s);
			if(s)
				U(1,s,s+l-1,1);
		}
		else
		{
			scanf("%d %d",&l,&r);
			U(1,l,l+r-1,0);
		}
	}
	return 0;
}
