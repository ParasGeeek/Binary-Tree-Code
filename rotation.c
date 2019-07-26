#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max 100

int areRotations(char *str1,char *str2)
{
	int len1=strlen(str1);
	int len2=strlen(str2);
	char *temp;
	void *ptr;
	if(len1!=len2)
	{
		return 0;
	}
	else
	{
		temp=(char*)malloc(sizeof(char)*2*len1+1);
		temp[0]=' ';
		strcat(temp,str1);
		strcat(temp,str2);
		ptr=strstr(temp,str2);
		if(ptr)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}

int main()
{
	char str1[Max],str2[Max];
	scanf("%s %s",str1,str2);
	if(areRotations(str1,str2))
	{
		printf("Strings are rotation of each others:\n");
	}
	else
	{
		printf("Strings are not rotations of each others:\n");
	}
	return 0;
}
