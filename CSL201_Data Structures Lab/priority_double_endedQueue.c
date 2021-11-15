#include <stdio.h>
int n,f=-1,r=-1,m,s[50],d,e;
void insert_front(int);
void insert_rear(int);
void delete_front();
void delete_rear();
void display_dq();
void insert(int , int );
void delete();
void display();
 struct pq
    { 
	int ele;
	int pri;
    };
struct pq p[30],pi;
void main()
{
   int choice,ch;   
    do
    {
     printf("\n1.Priority Queue\n2.Double Ended Queue\n3.Exit\n");
     printf("Enter your choice:");
     scanf("%d",&choice);
     switch(choice)
     {
     case 1:
     	 printf("\nEnter the size of the Priority Queue:");
         scanf("%d",&n);
         do
          {
              printf("\nPriority Queue");
              printf("\n1.Insert Element to the Priority Queue\n2.Delete Elements from Priority Queue\n3.Display Elements\n4.Exit\n");
              printf("Enter the choice:");
              scanf("%d",&ch);
              switch(ch)
               {
               	case 1:
                   printf("\nEnter the Element and its Priority:");
                   scanf("%d %d",&pi.ele,&pi.pri);
                   insert(pi.ele,pi.pri);
                   display();
                   break;
                case 2:
                    delete();
                    display();
                    break;
                case 3:
                	display();
                	break;
                case 4:
                	printf("\nExiting.....");
                	break;
                default:
                	printf("Invalid choice!\n");
                }
              }
              while(ch!=4);
              break;
       case 2:
       	printf("\nEnter the size of the Double Ended Queue:");
        scanf("%d",&m);
        do
         {
               printf("Double Ended Queue");
               printf("\n1.Insert at Front\n2.Insert at Rear\n3.Delete from Front\n4.Delete from Rear\n5.Display\n6.Exit\n");
               printf("Enter the choice:");
               scanf("%d",&ch);
               switch(ch)
                 {
                 case 1:
                 	insert_front(d);
                 	display_dq();
                 	break;
                 case 2:
                 	insert_rear(e);
                 	display_dq();
                 	break;
                  case 3:
                  	delete_front();
                  	display_dq();
                  	break;
                  case 4:
                  	delete_rear();
                  	display_dq();
                  	break;
                  case 5:
                  	display_dq();
                  	break;
                  case 6:
                  	printf("Exiting....\n");
                  	break;
                  default:
                  	printf("Invalid Choice!");
                  	break;
                 }
              }
              while(ch!=6);
       case 3:
       		printf("Exiting.....\n");
       		break;
       default:
       		printf("Invalid Choice!");
       		break;
      }
     }
     while(choice!=3);
}
void insert_front(int d)
{ 
if(f==0 && r == m-1)
     printf("\n Double Ended Queue is FULL");
  else
  { 
  	 if(f == -1)
       		{
        		f=0;
        		r=0;
       		}
      	 else
      	    { 
      	       if(f == 0)
           	{ 
           		f=m-1;
	        }
          	else
         	  {
         	  	f=f-1;
           }
   }
   printf("\nEnter the Element to Insert at Front:");
   scanf("%d",&d);
   s[f]=d;         
  }
}
void insert_rear(int e)
{ 
	if(r==m-1)
         printf("\nDouble Ended Queue is Full");
  	else
   	{
   		r++;
   		printf("\nEnter the Element to Insert at Rear:");
   		scanf("%d",&e);
   		s[r]=e;
   		if(f==-1)
   		f=0;
   	}
 }
 void delete_front()
 { 
 	if(f==-1)
       	printf("Double Ended Queue is Empty\n");
   	else if(f==r)
     		{
     		 printf("The Deleted Element from Front is: %d", s[f]);
       		 f=-1;
       		 r=-1;
     		}
    	else
   	  { 
   	   printf("\nthe deleted element is %d", s[f]);
           f++;
    	  }
 }
void delete_rear()
 { 
 	if(f==-1)
        printf("Double Ended Queue is Empty\n");
   	else if(f==r)
   	   {
   	    printf("Deleted Element from Rear is: %d", s[r]);
            f=-1;
            r=-1;
            }
        else
          {
            printf("\nDeleted Element is: %d", s[f]);
       	    r--;
     	  }
 }
 void display_dq()
 {
  	int i;
   	if(f==-1)
         printf("\nDouble Ended Queue is Empty\n");
    	else
    	   { 
    	   	printf(" \nDouble Ended Queue\n");
      		for(i=f;i<m;i++)
      		printf("%d\n",s[i]);
    	   }
 }
void insert(int e ,int pr)
{ 
	int i;
	if(r==n-1)
	  printf("Priority Queue is Full!\n");
 	else
  	  {
  	  	if(f==-1)
      		f=0;
    		i=r;
    		r++;
   		while(p[i].pri>=pr && i>=0)
   		 {
   		 	p[i+1]=p[i];
      			i--;
    		 }
    	   p[i+1].ele=e;
   	   p[i+1].pri=pr;
  	  }
}
void delete()
{
	int q;
	if(r==-1||f>r)
   	printf("Priority Queue is Empty\n");
 	else
 	  {
 	  	pi=p[f];
    		f=f+1;
    		printf("\nDeleted Element is:%d\t [priority is:%d]\n",pi.ele,pi.pri);
   	  }
} 
void display()
{ 
	int i;
	if(r==-1|| f>r)
    	printf("Priority Queue is Empty");
  	else
  	 {
  	  printf("\nPriority Queue");
     	  for(i=f;i<=r;i++)
           printf("\n%d [%d]\n",p[i].ele,p[i].pri);
    	 }
}


