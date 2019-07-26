#include<stdio.h>
#include<stdlib.h>

void fre(int arr[], int size) 
{ 
  int xor = arr[0];
  int set_bit_no;
  int i; 
  int n = size - 2; 
  int x = 0, y = 0; 
  for(i = 1; i < size; i++) 
    xor ^= arr[i];   
  for(i = 1; i <= n; i++) 
    xor ^= i;    
  set_bit_no = xor & ~(xor-1); 
  for(i = 0; i < size; i++) 
  { 
    if(arr[i] & set_bit_no) 
      x = x ^ arr[i]; 
    else
      y = y ^ arr[i]; 
  } 
  for(i = 1; i <= n; i++) 
  { 
    if(i & set_bit_no) 
      x = x ^ i; 
    else
      y = y ^ i; 
  }    
  printf("n The two repeating elements are %d & %d ", x, y); 
}      

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int arr[n+2];
		for(int i=0;i<n+2;i++)
		{
			scanf("%d",&arr[i]);
		}
		fre(arr,n+2);
		printf("\n");
	}
	return 0;
}

