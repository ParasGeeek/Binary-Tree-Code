#include<iostream>
#include<cstring>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

void bfs(int x,int num)
{
	queue<int>q;
	q.push(num);
	while(!q.empty())
	{
		num=q.front();
		q.pop();
		if(num<=x)
		{
			cout << num << " ";
			int last_dig=num%10;
			if(last_dig==0)
			{
				q.push((num*10)+last_dig+1);
			}
			else if(last_dig==9)
			{
				q.push((num*10+last_dig-1));
			}
			else
			{
				q.push(num*10+last_dig-1);
				q.push(num*10+last_dig+1);
			}
		}
	}
}
void printJumping(int x)
{
	cout <<0 << " ";
	for(int i=1;i<9 && i<=x;i++)
	{
		bfs(x,i);
	}
	return;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int x;
		scanf("%d",&x);
		printJumping(x);
	}
	return 0;
}
