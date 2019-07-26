#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
#define ll long long

int partition(ll arr[],int l,int r)
{
  int i=l;
  ll temp;
  for(int j=l;j<=r-1;j++)
  {
    if(arr[j]<=arr[r])
    {
      temp=arr[j];
      arr[j]=arr[i];
      arr[i]=temp;
      i++;
    }
  }
  temp=arr[r];
  arr[r]=arr[i];
  arr[i]=temp;
  return i;
}

void quick_sort(ll arr[],int l,int r)
{
  if(l<r)
  {
    int p=partition(arr,l,r);
    quick_sort(arr,l,p-1);
    quick_sort(arr,p+1,r);
  }
}

int main()
{
  int  t;
  scanf("%d",&t);
  while(t--)
  {
    int n;
    scanf("%d",&n);
  
    ll arr[n];
    for(int i=0;i<n;i++)
    scanf("%lld",&arr[i]);
    
     quick_sort(arr,0,n-1);
    int l=0,r=n-1;
    ll sum=1000000007,temp;

    while(l<r)
    {
      temp=arr[l]+arr[r];

      if(abs(sum) > abs(temp))
      sum=temp;

      if(temp<0)
      l++;
      else
      r--;
    }
    printf("%lld\n",sum);
  }
  return 0;
}
