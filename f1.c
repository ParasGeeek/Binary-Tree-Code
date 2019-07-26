#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define Max 1000

int main()
{
int c=0,index;
int arr[10]={0};
size_t n=0;
size_t count=0;
printf("Enter the Alphanumeric String:\n");
while(n<Max && (c==getchar())!=EOF && c!='\n')
{
    if(c>=65 || c<= 90)
    {
        continue;
    }
    else
    {
        index=c%10;
        if(arr[index]==1)
        {
            count++;
            //printf("%d\t",count);
            arr[index]=count;
        }
        else
        {
          arr[index]=1;
          count++;
        }

    }
}
for(int j=0;j<10;j++)
{
    printf("%d\t",arr[j]);
}  
    return 0;
}
