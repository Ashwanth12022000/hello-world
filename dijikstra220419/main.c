#include <stdio.h>
#include <stdlib.h>
int visited[20],dis[20],a[20][20],n,e;
int min(int x,int y)
{

    return (x<y)?x:y;

}
void dijikstra(int s)
{

    int k,i,u,f;
    for(i=1;i<=n;i++)
    {
        visited[i]=0;
        dis[i]=a[s][i];
    }
    for(k=1;k<=n;k++)
    {
        f=999;
        for(i=1;i<=n;i++)
        {

          if(dis[i]<f&&visited[i]==0)
          {
              u=i;
              f=dis[i];
          }
        }
          visited[u]=1;
          for(i=1;i<=n;i++)
          {
              if(visited[i]==0)
                dis[i]=min(dis[i],dis[u]+a[u][i]);
          }
    }
}
int main()
{
   int i,j,w,s,v1,v2;
   printf("Enter the number f vertices\n");
   scanf("%d",&n);
   printf("Enter the number of edges\n");
   scanf("%d",&e);
   for(i=1;i<=n;i++)
   {
       for(j=1;j<=n;j++)
       {
           if(i==j)
            a[i][j]=0;
           else
            a[i][j]=999;
       }
   }
   printf("Enter the edges one by one\n");
   for(i=1;i<=e;i++)
   {
       printf("Enter edge %d:",i);
       scanf("%d%d",&v1,&v2);
       printf("weight:");
       scanf("%d",&w);
       a[v1][v2]=a[v2][v1]=w;

   }
   printf("Enter the starting vertex\n");
   scanf("%d",&s);
   dijikstra(s);
   printf("The shortest distance from %d to:\n",s);
   for(i=1;i<=n;i++)
   {
       printf("%d is:%d\n",i,dis[i]);
   }
    return 0;
}
