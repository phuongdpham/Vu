#include <stdio.h>
#include <fstream>
#include <conio.h>
#include <iostream>

using namespace std;

int main()
{
	int a[100];
	int b[100];
	int c[100];
	int d[100];
	int i,n;
	int kq,dem;
	
	FILE *f;
	f = fopen("FIFO.txt","r");
	fscanf(f,"%d",&n);
	for (i=0;i<n;i++)
		fscanf(f,"%d",&a[i]);
	for (i=0;i<n;i++)
		fscanf(f,"%d",&b[i]);
	fclose(f);
	
	FILE *g;
	g = fopen("FIFOout.txt","w");
	int max=0;
	for (i=0;i<n;i++)
	{
		max=max+a[i];
	}
	dem=0;
	for (i=0;i<max;i++)
		{
			if (i>=b[dem]) 
			{
				i=i+a[dem];
				c[dem]=i;
				d[dem]=c[dem]-b[dem]-a[dem];
				kq=kq+d[dem];
				dem=dem+1;
				i--;
			}
		}
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
