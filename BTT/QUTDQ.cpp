#include <stdio.h>
#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;
int main()
{
	int i,j,n,min,bien,k,ut;
	int a[100],b[100],c[100],d[100],q[100];
	bool kt[100];
	
	
	FILE *f;
	f = fopen("QUTDQ.txt","r");
	fscanf(f,"%d",&n);
	for (i=0;i<n;i++)
	{
		fscanf(f,"%d",&a[i]);
	}
	for (i=0;i<n;i++)
	{
		fscanf(f,"%d",&b[i]);
	}
	for (i=0;i<n;i++)
	{
		fscanf(f,"%d",&q[i]);
	}
	fclose(f);
	
	int max=0;
	bien=0;
	int kq=0;
	for (i=0;i<n;i++)
	{
		max=max+a[i];
	}
	for (i=0;i<n;i++)
	{
		kt[i]=true;
	}

				
	for (i=0;i<max;i++)
	{	
		for (k=0;k<n;k++)
		{
		if ((i>=b[k]) and (kt[k]==true))
			{
				ut=q[k];
				int dem=k;
				for (j=1;j<n;j++)
					{
						if ((b[j]<=i) and (kt[j]==true))
							if (q[j]>ut) {ut=q[j]; dem=j; }
					}
				kt[dem]=false;
				i=i+a[dem];
				c[dem]=i;
				d[dem]=c[dem]-b[dem]-a[dem];
				kq=kq+d[dem];
				i--;
				k=n;
			}
		}
	}
	
	FILE *g;
	g = fopen("QUTDQout.txt","w");
	fprintf(g,"%d",i);
	fprintf(g,"\n");
	for (i=0;i<n;i++)
	{
		fprintf(g,"%d ",c[i]);
	}
	fprintf(g,"\n");
	for (i=0;i<n;i++)
	{
		fprintf(g,"%d ",d[i]);
	}
	fprintf(g,"\n");
	fprintf(g,"%d",kq);
	fclose(g);
}
