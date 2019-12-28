#include<stdio.h>
int main()
{
	for(int i=8;i<=125;i++)
		for(int j=i;j<=592;j++)
			for(int k=(2000-i-j)/2-1;k>=j&&i*j*k>1000000;k--)
				if(((i+j+k)*1000000)%(i*j*k-1000000)==0)
				{
					int l=((i+j+k)*1000000)/(i*j*k-1000000);
					if(i+j+k+l<=2000&&l>=k)
						printf("%.2f %.2f %.2f %.2f\n",i*.01,j*.01,k*.01,l*.01);
				}
}
