#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ASCII_SIZE 256

char getMaxOccuringChar(char *str)
{
	int count[ASCII_SIZE]={0};
	int len=strlen(str);
	int max=0;
	char result;
	for(int i=0;i<len;i++)
	{
		count[str[i]]++;
		if(max<count[str[i]]){
			max=count[str[i]];
			result=str[i];
		}
	}
	return result;
}

int main()
{
	int l;
	scanf("%d",&l);
	char str[l];
	scanf("%s",str);
	printf("Maximum Occuring character is %c:",getMaxOccuringChar(str));
	return 0;
}
