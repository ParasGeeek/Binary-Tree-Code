#include <ctype.h>
#include<string.h>
#include <stdio.h>
#define N 1000
void swap(char *,char *);
void fix_pos(char *t)
{
	int i,j;
	i=0;
	j=0;
	while(*t!='\0')
	{
		if(*(t+i)==*(t+i+1))
		{
			i++;
		}
		else if(*(t+i)!=*(t+i+1))
		{
			if((t+i-1)==(t+i))
			{
				swap((t+i),(t+i+1));
			}
		}
		else
		{
			++i;
			swap((t+j+1),(t+i));
			j++;
		}
		
}https://www.facebook.com/esperance.depardieu?__tn__=%2CdC-R-R&eid=ARCYb3Oz2s6OLugkyEet-f0dLeVGAuPWL-3atvqDiQQA1B3XtPIQS_77oWJfDOw15w9sbz6bLQqEhamv&hc_ref=ARRYKNqPNqObz0AMxKRZLC1nnPgVCdFPcqCmwIxr48nUYAj2DMdJcOhQt42pVDtc_Uk&fref=nf
}

void swap(char *a,char *b)
{
	char temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int main()
{
	char str[N];
	//fgets(str,N,stdin);
	scanf("%[^\n]%*c",str);
	
	fix_pos(str);
	printf("%s",str);
	return 0;
}
