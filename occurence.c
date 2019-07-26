#include<stdio.h>
#include<ctype.h>

int atoi(char s[])
{
	int i,n,sign;
	for(i=0;isspace(s[i]);i++)
	;
	sign=(s[i]=='-')?-1:1;
	if(s[i]=='+' || s[i]=='-')
	{
		i++;
	}
	for(n=0;isdigit(s[i]);i++)
	{
		n=10*n+(s[i]-'0');
	}
	return sign*n;
}
int main()
{
	int n;
	scanf("%d",&n);
	char str[n];
	printf("Enter the string:\n");
	scanf("%s",str);
	printf("%d",atoi(str));
	return 0;
}
