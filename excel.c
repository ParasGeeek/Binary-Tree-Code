#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max 50

void reverse(char *,int);
void printString(int n)
{
	int rem;
	int i=0;
	char str[Max];
	while(n>0)
	{
		rem=n%26;
		if(rem==0)
		{
			str[i++]='Z';
			n=(n/26)-1;
		}
		else
		{
			str[i++]=(rem-1)+'A';
			n=n/26;
		}
	}
	str[i]='\0';
	reverse(str,strlen(str));
	printf("%s",str);
	return;
}

void reverse(char *str,int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		str[i]=str[len-1-i];
	}
	str[i]='\0';
}

int main()
{
	int n,m,i;
	printf("Enter the numbers:\n");
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d",&n);
		printString(n);
	}
	return 0;
}
