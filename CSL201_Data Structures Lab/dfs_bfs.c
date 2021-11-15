#include<stdio.h>
#include<stdlib.h>
#define max 50
char open[max], visit[max];
int top=-1,i1=-1;
char OPEN[max], VISIT[max];
int front=-1, rear=-1, i2=-1;
void push(char);
char pop();
int search(char[],char);
void enqueue(char x);
char dequeue();
void dfs_traversal(int n,int array[n][n], char element[n]);
void bfs_traversal(int n,int array[n][n], char element[n]);
void main()
{
	int n,i,j,choice;
    	printf("Enter number of nodes:");
	scanf("%d", &n);
    	int array[n][n];
    	char element[n],x;
    	printf("Enter the node data's: \n");
    	for(i=0;i<n;i++)
        	scanf(" %c", &element[i]);
    	printf("Enter adjacency matrix representation : \n");
    	for(i=0;i<n;i++)
    		for(j=0;j<n;j++)
        		scanf("%d", &array[i][j]);
        do
        {
        	printf("1.DFS Traversal\n2.BFS Traversal\n3.Exit\nEnter Your Choice:");
        	scanf("%d",&choice);
        	switch(choice)
        	{
    			case 1:	dfs_traversal(n,array,element);
    				break;
    			case 2:	bfs_traversal(n,array,element);
				break;
			case 3:	printf("Exiting....!\n");
				exit(0);
			default:printf("Invalid Choice!\n");
		}
	}while(choice!=3);
}
void dfs_traversal(int n,int array[n][n], char element[n])
{
	printf("\nDFS");
    	int i,j,a;
    	char u,x;
    	if(n==0)
    	{
        	printf("Graph is Empty!\n"); 
        	return;
    	}
    	printf("\nEnter the starting element: "); 
    	scanf(" %c", &x);
    	push(x);
    	while(top!=-1)
    	{
        	u=pop();
        	if(search(visit,u)==0)
        	{
            		visit[++i1]=u;
            		for(i=0;i<n;i++)
                		if(element[i]==u)
                    			a=i;
            		for(i=0;i<n;i++)
            		{
                		if(array[a][i]==1)
                			push(element[i]);
            		}
        	}
    	}
    	printf("VISIT: ");
    	for(i=0;i<=i1;i++)
        	printf("%c  ",visit[i]);
        printf("\n");
}
void push(char x)
{
	if(top!=max-1)
         open[++top]=x;
}
char pop()
{
	char x=open[top];
    	top--;
    	return x;
}
int search(char visit[], char x)
{
	int i,flag=0;
    	for(i=0; i<=max; i++)
        	if(visit[i]==x)
        	{
            		flag=1; 
            		break;
        	}
    		return flag;
}
void bfs_traversal(int n,int array[n][n], char element[n])
{
	printf("\nBFS");
    	if (n==0)
    	{
        	printf("Graph is empty! \n"); 
        	return;
    	}
    	char u,x;
    	int i,a;
    	printf("\nEnter the starting element: "); 
    	scanf(" %c", &x);
    	enqueue(x);
    	while(!(front==-1 || front>rear))
    	{
        	u=dequeue();
        	if(search(VISIT,u)==0)
        	{
            		VISIT[++i2]=u;
            		for(i=0;i<n;i++)
                		if(element[i]==u)
                    			a=i;
            		for(i=0;i<n;i++)
            		{
                		if(array[a][i]==1)
                			enqueue(element[i]);
            		}
        	}
	}
    	printf("VISIT: ");
    	for(i=0;i<=i2;i++)
        	printf("%c  ",VISIT[i]);
	printf("\n");
}
void enqueue(char x)
{
	if (front==-1)
        front=0;
    	rear++;
    	OPEN[rear]=x;
} 
char dequeue()
{
	char x= OPEN[front];
	front++;
    	return x;
}

