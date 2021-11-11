#include <stdio.h>
#include<stdlib.h>
int b, p;
void first_fit() 
{
	printf("Enter the number of blocks :");
  	scanf("%d", &b);
  	printf("\nEnter the number of processes :");
  	scanf("%d", &p);
  	int blk_size[b], pro_size[p], i, j, flag[b], allocation[b];
  	for (i = 0; i < b; i++) 
  	{
    		flag[i] = 0;
    		allocation[10] = -1;
  	}
  	printf("\nEnter the size of each block \n");
  	for (i = 0; i < b; i++) 
  	{
    		printf("Block %d:", i);
    		scanf("%d", &blk_size[i]);
  	}
  	printf("\nEnter the size of each process \n");
  	for (i = 0; i < p; i++) 
  	{
    		printf("process %d:", i);
    		scanf("%d", &pro_size[i]);
  	}
  	for (i = 0; i < p; i++) 
  	{
    		for (j = 0; j < b; j++) 
    		{
      			if (flag[j] == 0 && blk_size[j] >= pro_size[i]) 
      			{
        			allocation[j] = i;
        			flag[j] = 1;
        			break;
      			}
    		}
  	}
	printf("\nBlock number \t Block size \t Process allocated \tProcess size \n");
	for(i=0;i<b;i++)
	{
    		printf("\n%d\t\t%d\t\t", i + 1, blk_size[i]);
    		if (flag[i] == 1)
      			printf("\t%d\t\t%d", allocation[i] + 1, pro_size[i]);
    		else
      			printf("Not Allocated \t");
	}
}
void best_fit() 
{
	printf("\nEnter the number of blocks :");
  	scanf("%d", &b);
  	printf("\nEnter the number of processes :");
  	scanf("%d", &p);
  	int remain[20], blk_size[20], pro_size[20], barray[20], parray[20], i, j,
  	temp, low = 9999;
  	printf("\nEnter the size of the blocks \n");
  	for (i = 0; i < b; i++) 
  	{
    		printf("Block %d:", i);
    		scanf("%d", &blk_size[i]);
 	}	
  	printf("\nEnter the size of the processes \n");
  	for (i = 0; i < p; i++) 
  	{
  		printf("Process %d:", i);
    		scanf("%d", &pro_size[i]);
  	}
  	for (i = 0; i < p; i++) 
  	{
    		for (j = 0; j < b; j++) 
    		{
      			if (barray[j] != 1) 
      			{
        			temp = blk_size[j] - pro_size[i];
        			if (temp >= 0)
          				if (low > temp) 
          				{
            					parray[i] = j;
            					low = temp;
          				}
      			}
    		}
    		remain[i] = low;
    		barray[parray[i]] = 1;
    		low = 10000;
  	}
  	printf("\nProcess_number \tProcess_size\tBlock_number \tBlock_size\tRemaining");
  	for (i = 0; i < p; i++)
		printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,pro_size[i],parray[i],blk_size[parray[i]],remain[i]);
}
void worst_fit() 
{
	printf("\nEnter the number of blocks :");
  	scanf("%d", &b);
  	printf("\nEnter the number of processes :");
  	scanf("%d", &p);
  	int remain[20], blk_size[20], pro_size[20], barray[20], parray[20], i, j,
      	temp, high = 0;
  	printf("\nEnter the size of each block \n");
  	for (i = 0; i < b; i++) 
  	{
    		printf("Block %d:", i);
    		scanf("%d", &blk_size[i]);
  	}
  	printf("\nEnter the size of each process \n");
  	for (i = 0; i < p; i++) 
  	{
    		printf("process %d:", i);
    		scanf("%d", &pro_size[i]);
  	}
  	for (i = 0; i < p; i++) 
  	{
    		for (j = 0; j < b; j++) 
    		{
      			if (barray[j] != 1) 
      			{
        			temp = blk_size[j] - pro_size[i];
        			if (temp >= 0)
          				if (high < temp) 
          				{
            					parray[i] = j;
            					high = temp;
          				}
      			}
    		}
    		remain[i] = high;
    		barray[parray[i]] = 1;
    		high = 0;
  	}
  	printf("\nProcess_number \tProcess_size\tBlock_number \tBlock_size\tRemaining");
  	for (i = 0; i < p; i++)
		printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,pro_size[i],parray[i],blk_size[parray[i]],remain[i]);
}
void main()
{
      	int ch;
	printf("\n1.First Fit \n2.Best Fit \n3.Worst Fit \n4.Exit\n");
	do 
	{
		printf("\nEnter your Choice :");
        	scanf("%d", &ch);
        	switch (ch) 
        	{
        		case 1:
          			first_fit();
         	 		break;
        		case 2:
          			best_fit();
          			break;
        		case 3:
          			worst_fit();
         	 		break;
        		case 4:
          			printf("Exiting...!\n");
          			exit(0);
          			break;
          		default:printf("Invalid Choice!\n");
        	}
      	}while (ch != 4);
}

