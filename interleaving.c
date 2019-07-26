x #include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max 100

int interleaving(char *a,char *b,char *c)
{
	int i,j;
	int l=strlen(a);
	int m=strlen(b);
	int table[l+1][m+1]={0};
	if((l+m)!=strlen(c))
	{
		return 0;
	}
	for(i=0;i<=M;++i)
	{
		for(j=0;j<=N;++j)
		{
			if(i==0 && j==0)
			{
				table[i][j]=true;
			}
			else if(i==0 && b[j-1]==c[j-1])
			{
				table[i][j]=table[i][j-1];
			}
			else if(j=0 && a[i-1]==c[i-1])
			{
				table[i][j]=table[i-1][j];
			}
			else if(a[i-1]==c[i+j-1] && b[j-1]!=c[i+j-1])
			{
				table[i][j]=table[i-1][j];
			}
			else if(a[i-1]!=c[i+j-1] && b[j-1]==c[i+j-1])
			{
				table[i][j]=table[i][j-1];
			}
			else if(a[i-1]==c[i+j-1] && b[j-1]==c[i+j-1])
			{
				table[i][j]=(table[i-1][j] || table[i][j-1]);
			}
		}
	}
	return table[l][m];
}

int main()
{
	int t;
	scanf("%d",&t);
	char a[Max],b[Max],c[Max];
	while(t--)
	{
		scanf("%s %s %s",a,b,c);
	}
	int count=interleaving(a,b,c);
	if(count==1)
	{
		printf("C is interleaving of a and b:\n");
	}
	else
	{
		printf("C is not interleaving of a and b:\n");
	}
	return 0;
}


