#include<stdio.h>
#define INFINITY 9999
void dijkstra(int G[50][50],int n,int startnode);
void mindist(int n,int distance[],int visited[],int cost[][50],int previous[],int startnode);
void print(int n,int startnode,int distance[],int previous[]);
void main()
{
    int G[50][50],i,j,n,s;
    printf("Enter no. of vertices:");
    scanf("%d",&n);
    printf("\nEnter the Edge weight matrix:\n");
    
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&G[i][j]);
    
    printf("\nEnter the starting node:");
    scanf("%d",&s);
    dijkstra(G,n,s);
}
void dijkstra(int G[50][50],int n,int startnode)
{
 
    int cost[50][50],distance[50],previous[50];
    int visited[50],count,mindistance,nextnode,i,j;
    
    //previous[] stores the predecessor of each node
    //count gives the number of nodes seen so far
    //create the cost matrix
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(G[i][j]==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=G[i][j];
    
    //initialize previous[],distance[] and visited[]
    for(i=0;i<n;i++)
    {
        distance[i]=cost[startnode][i];
        previous[i]=startnode;
        visited[i]=0;
    }
    for(i=0;i<n;i++)
    {
        if(G[startnode][i]==0)
		previous[i]=-1;
    }
    distance[startnode]=0;
    visited[startnode]=1;
    count=0;
    printf("\nFrom:\t");
	for(i=0;i<n;i++)
		printf("%d\t",startnode);
	printf("\nVia:\t");
	for(i=0;i<n;i++)
	{
		if(previous[i]!=-1)
			printf("%d\t",previous[i]);
		else
			printf("-\t");
	}
	printf("\nTo:\t");
	for(i=0;i<n;i++)
		printf("%d\t",i);
	printf("\nWeight:\t");
	for(i=0;i<n;i++)
	{
		if(i==startnode)
			printf("-\t");
		else
			printf("%d\t",distance[i]);
	}
	printf("\nNode %d is visited\n",startnode);
    while(count<n-1)
    {
	printf("\nFrom:\t");
	for(i=0;i<n;i++)
		printf("%d\t",startnode);
	mindist(n,distance,visited,cost,previous,startnode);
        count++;
    }
	print(n,startnode,distance,previous);
}
void mindist(int n,int distance[],int visited[],int cost[][50],int previous[],int startnode)
{
	int mindistance,i,nextnode;
	mindistance=INFINITY;
        
        //nextnode gives the node at minimum distance
        for(i=0;i<n;i++)
            if(distance[i]<mindistance&&visited[i]!=1)
            {
                mindistance=distance[i];
                nextnode=i;
            }
	//check if a better path exists through nextnode            
            visited[nextnode]=1;
	    printf("\nVia:\t");
            for(i=0;i<n;i++)
	    {
                if(visited[i]!=1)
	        {
                    if(mindistance+cost[nextnode][i]<distance[i])
                    {
                        distance[i]=mindistance+cost[nextnode][i];
                        previous[i]=nextnode;
                    }
		}
		if(previous[i]!=-1)
			printf("%d\t",previous[i]);
		else
			printf("-\t");
	    }
	    printf("\nTo:\t");
	    for(i=0;i<n;i++)
		printf("%d\t",i);
	    printf("\nweight:\t");
	    for(i=0;i<n;i++)
	    {
		if(i==startnode)
			printf("-\t");
		else
			printf("%d\t",distance[i]);
	    }
	    printf("\nNode %d is visited\n",nextnode);
}
void print(int n,int startnode,int distance[],int previous[])
{
	int i,j;
	printf("\nResult:");
	printf("\nFrom:\t");
	for(i=0;i<n;i++)
		printf("%d\t",startnode);
	printf("\nVia:\t");
	for(i=0;i<n;i++)
	{
		if(previous[i]!=-1)
			printf("%d\t",previous[i]);
		else
			printf("-\t");
	}
	printf("\nTo:\t");
	    for(i=0;i<n;i++)
		printf("%d\t",i);
	    printf("\nweight:\t");
	    for(i=0;i<n;i++)
	    {
		if(i==startnode)
			printf("-\t");
		else
			printf("%d\t",distance[i]);
	    }
}
/*Output
	tejal@ubuntu:~/Desktop$ gcc daa4new.c
tejal@ubuntu:~/Desktop$ ./a.out
Enter no. of vertices:5

Enter the adjacency matrix:
0 3 0 7 0
3 0 4 2 0
0 4 0 5 6
7 2 5 0 4
0 0 6 4 0

Enter the starting node:0

From:	0	0	0	0	0	
Via:	-	0	-	0	-	
To:	0	1	2	3	4	
Weight:	-	3	9999	7	9999	
Node 0 is visited

From:	0	0	0	0	0	
Via:	-	0	1	1	-	
To:	0	1	2	3	4	
weight:	-	3	7	5	9999	
Node 1 is visited

From:	0	0	0	0	0	
Via:	-	0	1	1	3	
To:	0	1	2	3	4	
weight:	-	3	7	5	9	
Node 3 is visited

From:	0	0	0	0	0	
Via:	-	0	1	1	3	
To:	0	1	2	3	4	
weight:	-	3	7	5	9	
Node 2 is visited

Result:
From:	0	0	0	0	0	
Via:	-	0	1	1	3	
To:	0	1	2	3	4	
weight:	-	3	7	5	9	*/
