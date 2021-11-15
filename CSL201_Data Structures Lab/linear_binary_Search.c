#include <stdio.h>
#include<stdlib.h>
void sort(int a[],int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j=(i+1);j<n;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
void main()
{
	int arr[50],size,search,i,flag,ch,pos;
	int f,l,mid;
	printf("Enter the size of the array: ");
	scanf("%d",&size);
	printf("Enter the array elements: ");
	for(i=0;i<size;i++)
		scanf("%d",&arr[i]);
	do
	{
		printf("1.Linear search\n2.Binary Search\n3.Exit\nEnter the choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				flag=0;
				printf("Enter the element to be searched: ");
				scanf("%d",&search);
				for(i=0;i<size;i++)
				{
					if(arr[i]==search)
					{
						flag=1;	
						pos=i+1;
						break;
					}
				}
				if(flag==1)
					printf("%d Found at position %d \n",search,pos);
				else
					printf("Element not found!\n");
					break;
			case 2:
				flag=0;
				printf("Enter the element to be searched: ");
				scanf("%d",&search);
				sort(arr,size);
				for(i=0;i<size;i++)
					printf("%d \t",arr[i]);
					printf("\n");
					f=0;
					l=size-1;
					mid=(f+l)/2;
					while(f<=l)
					{
						if(arr[mid]==search)	
						{
							flag=1;
							pos=mid+1;
							break;
						}
						else if(arr[mid]<search)		
							f=mid+1;
						else
							l=mid-1;
							mid=(f+l)/2;
					}
					if(f>l)
						printf("Element not Found!\n");
						if(flag==1)
							printf("%d Found at %d\n",search,pos);
					break;
			case 3:
				printf("Exiting....!\n");
				exit(0);
			default :
				printf("Invalid Choice!\n");
				break;
		}
	}
	while(ch!=3);
}

