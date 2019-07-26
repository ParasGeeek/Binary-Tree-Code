#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define Max 256

int *getCharCountArray(char *str)
{
	int *count=(int*)malloc(sizeof(int)*Max);
	int i;
	for(i=0;*(str+i);i++)
	{
		count[*(str+i)]++;
	}
	return count;
}

int firstNonRepeating(char *str)
{
	int *count=getCharCountArray(str);
	int index=-1;
	int i;
	for(i=0;*(str+i);i++)
	{
		if(count[*(str+i)]==1)
		{
			index=i;
			break;
		}
	}
	//free(malloc);
	printf("\n");
	printf("%c\n",str[index]);
	free(count);
	return index;
}

int main()
{
	int n;
	scanf("%d",&n);
	char str[n];
	scanf("%s",str);
	int t=firstNonRepeating(str);
	printf("%d",t);
	printf("\n");
	return 0;
}
