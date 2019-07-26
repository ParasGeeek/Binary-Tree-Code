#include<stdio.h>
#include<string.h>
#include<ctype.h>

char *run_length(char *str)
{
	int len=strlen(str),result_len,j=0,k;
	int Max_len=2*len+1;
	char count[Max_len];
	char *finalStr=(char*)malloc(sizeof(char)*(len*2+1));
    for(int index=0;index<len;index++)
    {
		finalStr[j++]=str[index];
		for(result_len=1;index+1<len && str[index]==str[index+1];result_len++,index++);
		sprintf(count,"%d",result_len);
		for(k=0;count[k];k++,j++)
		{
			finalStr[j]=count[k];
		}
		finalStr[j]='\0';
	}
	return finalStr;
}

int main()
{
	int n;
	scanf("%d",&n);
	char str[n];
	scanf("%s",str);
	char *ptr=run_length(str);
	printf("%s",ptr);
	return 0;
}
