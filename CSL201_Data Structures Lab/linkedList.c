#include <stdio.h>
#include <stdlib.h>
struct node
{   int data;
    struct node *next;
};
struct node *link1=NULL;
void create()
{   
	int n,i;
	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	for (int i = 1; i<=n; i++) 
    	{ 
    		int d;
    		struct node *temp,*a;
        	printf("Enter data to node %d :",i);
        	scanf("%d",&d);
        	a=(struct node *)malloc(sizeof(struct node));
       		if(link1==NULL)
        	{  
        		link1=a;
           		link1->data=d;
           		link1->next=NULL;
        	}   
       		else
        	{  
        		temp=link1;
           		while(temp->next!=NULL)
           		{  
           			temp=temp->next;
           		}
           		temp->next=a;
           		a->data=d;
           		a->next=NULL;
        	}
    		}  
}
void display()
{
	struct node *temp;
	printf("The linked list : "); 
   	temp=link1;
   	while(temp!=NULL)
         {  
              printf(" %d ",temp->data);
              temp=temp->next;
              if(temp!=NULL)
               printf("->");
         }
}
void insert_at_beginning()
{  
	int d;
	struct node *a;
   	a=(struct node *)malloc(sizeof(struct node));
   	printf("\nEnter data to insert at beginning : ");
   	scanf("%d",&d);
   	if(link1==NULL)
        {  
        	link1=a;
                link1->data=d;
             	link1->next=NULL;
             	return;
        }
   	a->data=d;
   	a->next=link1;
   	link1=a;
}
void insert_at_end()
{  
	int d;
   	struct node *a,*temp;
   	a=(struct node *)malloc(sizeof(struct node));
   	printf("\nEnter data to insert at end : ");
   	scanf("%d",&d);
   	if(link1==NULL)
        {  
        	link1=a;
              	link1->data=d;
              	link1->next=NULL;
              	return;
        }
   	temp=link1;
   	while(temp->next!=NULL)
        {  
        	temp=temp->next;
        }
   	temp->next=a;
   	a->data=d;
   	a->next=NULL;
}
void insert_at_specified_pos()
{  
	int d,pos,i;
   	struct node *temp,*a;
   	printf("\nEnter data to insert in the position : ");
   	scanf("%d",&d);
   	printf("\nEnter the position : ");
   	scanf("%d",&pos);
   	a=(struct node *)malloc(sizeof(struct node));
   	a->data=d;
   	a->next=NULL;
   	temp=link1;
   	if(pos==0)
   	{   
   		a->data=d;
       		a->next=link1->next;
       		a=link1;
       		return;
   	}
   	if(link1==NULL)
   	{  
      		link1->data=d;
      		link1->next=NULL;
      		return;
   	}
   	else
   	{  
   		do
       		{  
       			temp=temp->next;
          		a->next=temp->next;
          		temp->next=a;
          		return;
          		i++;
       		}
       		while(i!=pos-1);
   	}
}
void delete_from_specific_pos()
{   
	int pos,i;
    	struct node *temp,*a;
    	printf("\nEnter the position : ");
    	scanf("%d",&pos);
    	temp=link1;
    	if(link1==NULL)
        	printf("The linked list is empty !");
    	else
    	{    
    		for(i=1;i<pos-1;i++)
         	{  
         		temp=temp->next;
         	}
         	a=temp->next;
         	temp->next=a->next;
         	free(a);
    	}
}
void delete_from_beginning()
{   
	struct node *temp;
    	temp=link1;
    	if(link1==NULL)
         	printf("\nThe linked list is empty");
    	else
        {   
        	link1=link1->next;
            	temp->next=NULL;
        }
}
void delete_from_end()
{   
	struct node *temp,*a;
    	temp=link1;
    	while(temp->next!=NULL)
        {   
        	a=temp; 
              	temp=temp->next;
        }
    	if(temp==link1)
        	link1=0;
   	else
        	a->next=NULL;
    		free(temp);
}
void main()
{   
	int c;
    	printf("1.Create\n2.Insert at front\n3.Insert at end\n4.Insert at specific position\n5.Delete from front\n6.Delete from end\n7.Delete from specified position\n8.Exit\n");
    	do
    	{
       		printf("\nEnter the option : ");
        	scanf("%d",&c);
        	switch(c)
        	{  
        		case 1: create();
        	 	 	display(); 
        	 		break;
           		case 2:insert_at_beginning(); 
           	  		display(); 
           	  		break;
           		case 3:insert_at_end(); 
           	  		display(); 
           	  		break;
           		case 4:insert_at_specified_pos(); 
           	  		display(); 
           	  		break;
           		case 5:delete_from_beginning(); 
           	  		display(); 
           	  		break;
           		case 6:delete_from_end(); 
           	  		display(); 
           	  		break;
           		case 7:delete_from_specific_pos(); 
           	  		display(); 
           	  		break;
           		case 8:printf("Exiting...\n");
           		  	exit(0);
		        default:printf("Invalid Option!\n");
        	}
    	}
    	while(c!=8);
}

