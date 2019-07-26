#include<stdio.h>
#include<string.h>


void reverse(char str[])
{
	int c;
	for(int i=0,j=strlen(str)-1;i<j;i++,j--)
	{
		c=str[i],str[i]=str[j],str[j]=c;
	}
	return;
}

int main()
{
	int n;
	scanf("%d",&n);
	char str[n];
	printf("Enter the string:\n");
	scanf("%s",str);
	reverse(str);
	printf("%s",str);
	return 0;
}
