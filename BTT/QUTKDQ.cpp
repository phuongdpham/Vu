#include <stdio.h>
#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;
int main()
{
	int i,j,n,min,bien,k,x,kq,ut;
	int a[100],b[100],c[100],d[100],a1[100],q[100];
	bool kt[100];
	
	
	FILE *f;
	f = fopen("QUTKDQ.txt","r");
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
	for (i=0;i<n;i++) max=max+a[i];
	for (i=0;i<n;i++) kt[i]=true;
	for (i=0;i<n;i++) a1[i]=a[i];
	for (i=0;i<n;i++) c[i]=0;
	kq=0;
	
	for (i=0;i<max;i++)
		for (k=0;k<n;k++)
		{
			if ((b[k]<=i) and (kt[k])==true)
			{
				ut=q[k];
				int dem=k;
				for (j=0;j<n;j++)
					{
						if ((b[j]<=i) and (kt[j]==true))
							if (q[j]>ut) {ut=q[j]; dem=j;}
					}
				a1[dem]=a1[dem]-1;
				if (a1[dem]==0) 
					{
						kt[dem]=false;
						c[dem]=i+1;
						d[dem]=c[dem]-b[dem]-a[dem];
						kq=kq+d[dem];
					}
				k=n;
			}
		}
		
		
		
		
	FILE *g;
	g = fopen("QUTKDQout.txt","w");
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
