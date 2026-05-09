#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX 1000
int graph[MAX][MAX];
bool visited[MAX];
int distance[MAX];
int bfs(int n,int start,int target)//n=vertices,start=start point,target=end point
{
	int queue[MAX],front=0,rear=0;
	visited[start]=true;
	queue[rear++]=start;//enqueue element
	while(front<rear)
	{
		int current=queue[front++];//dequeue the element
		//finding the adjacent edge and distance of the edge
		for(int i=1;i<=n;i++)
		{
			if(graph[current][i] && !visited[i])
			{
				visited[i]=true;
				distance[i]=distance[current]+1;//distance travelled
				queue[rear++]=i;
				if(i==target)
				 return distance[i];
			}
		}
	}
	return -1;//no path
}
int main()
{
	int n,m,u,v,start,target;
	scanf("%d%d",&n,&m);//n=vertices,m=edges
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&u,&v);
		graph[u][v]=graph[v][u]=1;
	}
	scanf("%d%d",&start,&target);
	int result=bfs(n,start,target);
	printf("%d\n",result!=-1?result:-1);
	return 0;
}
