#include<stdio.h>
#include<stdlib.h>
#define INF 99
int prims(int n,int cost[10][10])
{
	int i,j,u,v,min,mincost,visited[10]={0},ne=1,a[10];
	while(ne<n)
	{
		min=INF;
		for(i=0;i<n;i++)
		{
			if(visited[i])
			{
				for(j=0;j<n;j++)
				{
					if(!visited[i] && cost[i][j]<min)
					{
						min=cost[i][j];
						u=i;
						v=j;
					}
				}
			}
		}
		if(min==INF)
		printf("no path");
		else
		{
			printf("%d of (%d,%d) is %d\n",ne++,u,v,min);
			mincost+=min;
			visited[v]=1;
			cost[u][v]=cost[v][u]=INF;
		}
	}
}
int main()
{
	int n=9,i,j,cost[10][10];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
			cost[i][j]=INF;
		}
	}
	prims(n,cost);
	return 0;
}
