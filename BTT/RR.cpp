#include <stdio.h>
#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;
int main()
{
	int i,j,n,min,bien,k,x,kq;
	int a[100],b[100],c[100],d[100],a1[100];
	int stack[100];
	bool kt[100],kt1[100];
	
	
	FILE *f;
	f = fopen("RR.txt","r");
	fscanf(f,"%d",&n);
	fscanf(f,"%d",&x);
	for (i=0;i<n;i++)
	{
		fscanf(f,"%d",&a[i]);
	}
	for (i=0;i<n;i++)
	{
		fscanf(f,"%d",&b[i]);
	}
	fclose(f);
	
	int max=0;
	for (i=0;i<n;i++) max=max+a[i];
	for (i=0;i<n;i++) kt[i]=true;
	for (i=0;i<n;i++) a1[i]=a[i];
	for (i=0;i<n;i++) c[i]=0;
	for (i=0;i<n;i++) kt1[i]=true;
	int dau=0;
	int cuoi=0;
	stack[0]=0;
	kq=0;
	
	for (i=0;i<max;i++)
		{	
			
			if ((i>=b[stack[dau]]) and (kt[stack[dau]]))
			{
				if ((a1[stack[dau]]-x)<=0)
				{
					kt[stack[dau]]=false;
					c[stack[dau]]=i+a1[stack[dau]];
					d[stack[dau]]=c[stack[dau]]-b[stack[dau]]-a[stack[dau]];
					kq=kq+d[stack[dau]];
					i=i+a1[stack[dau]];
					for (j=1;j<n;j++)
						if ((i>=b[j]) and (kt1[j]))
						{
							cuoi=cuoi+1;
							stack[cuoi]=j;
							kt1[j]=false;
						}
					i=i-1;
					a1[stack[dau]]=0;
					
				}
				else
				{
					a1[stack[dau]]=a1[stack[dau]]-x;
					i=i+x;
					for (j=1;j<n;j++)
						if ((i>=b[j]) and (kt1[j]))
							{
								cuoi=cuoi+1;
								stack[cuoi]=j;
								kt1[j]=false;
							}	
					i=i-1;
					cuoi=cuoi+1;
					stack[cuoi]=stack[dau];
					
				}
				dau=dau+1;
			}
		}
		
		
		
		
	FILE *g;
	g = fopen("RRout.txt","w");
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
