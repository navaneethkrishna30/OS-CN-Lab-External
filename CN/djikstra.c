#include<stdio.h>
#include<string.h>

#define IN 99
#define N 6

int main()
{
    int cost[N][N],w,source, target;
    for(int i=1;i<N;i++)
        for(int j=1;j<N;j++)
            cost[i][j] = IN;
    for(int x=1;x<N;x++)
     {
        for(int y=x+1;y<N;y++)
         {
            printf("Enter the weight of the path between nodes %d and %d: ",x,y);
            scanf("%d",&w);
            cost [x][y] = cost[y][x] = w;
         }
         printf("\n");
     }
     printf("\nEnter the source:");
     scanf("%d", &source);
     printf("\nEnter the target");
     scanf("%d", &target);
     int co = dijsktra(cost,source,target);
     printf("\nThe Shortest Path: %d",co);
}


int dijsktra(int cost[][N],int source,int target)
{
    int dist[N]={IN},prev[N]={-1},selected[N]={0};

    int start = source;
    selected[start]=1;
    dist[start] = 0;
    while(selected[target] ==0)
    {
        int min = IN;
        int m=0;
        for(int i=1;i<N;i++)
         {
            int d = dist[start] +cost[start][i];
            if(d<dist[i]&&selected[i]==0)
             {
                dist[i] = d;
                prev[i] = start;
             }
            if(min>dist[i] && selected[i]==0)
             {
                min = dist[i];
                m = i;
             }
        }
        start = m;
        selected[start] = 1;
    }
    int path[N];
    int j = 0;
        for (int v = target; v != -1; v = prev[v]) 
        {
            path[j++] = v;
        }
        printf("Shortest Path: ");
        for (int i = j - 1; i >= 0; i--) 
        {
            printf("%c", path[i] + 'A');
        }
        printf("\n");

        return dist[target];
}