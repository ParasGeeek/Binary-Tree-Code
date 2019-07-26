//dot products
#include<stdio.h>
void sort(int *array,int n)
{
	int c,d,swap;;
	  for (c = 0 ; c < ( n - 1 ); c++)
  	{
  	  for (d = 0 ; d < n - c - 1; d++)
  	  {
  	    if (array[d] > array[d+1]) /* For decreasing order use < */
  	    {
  	      swap       = array[d];
  	      array[d]   = array[d+1];
 	       array[d+1] = swap;
 	     }
 	   }
 	 }
}

int main()
{
int t,m;
scanf("%d",&t);
for(m=1;m<=t;m++)
{


	int sum,c,n,d,i,j,a[1000],b[1000];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	for(i=0;i<n;i++)
	scanf("%d",&b[i]);
	
	
sort( &a[0],n);
sort( &b[0],n);
sum=0;
for(i=0;i<n;i++)
{
	sum=sum+a[i]*b[n-1-i];
}

printf("Case#%d:%d\n",m,sum);

}
	
}
