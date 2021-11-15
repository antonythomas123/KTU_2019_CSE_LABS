#include<stdio.h>
#include<stdlib.h>
int stack[100],choice1,choice2,a,n,top,i,opt,queue_array[100],front=-1,rear=-1,m,cqueue[100],l,x;
void push()
{
    if(top>=n-1)
    {
        printf("\nStack is full!");
        
    }
    else
    {
        printf(" Enter the value:");
        scanf("%d",&a);
        top++;
        stack[top]=a;
    }
}
void pop()
{
    if(top<=-1)
    {
        printf("\n Stack is empty!");
    }
    else
    {
        printf("\n The popped elements are: %d",stack[top]);
        top--;
    }
}
void display1()
{
    if(top>=0)
    {
        printf("\n The elements of STACK are : ");
        for(i=0; i<=top; i++)
            printf(" %d  ",stack[i]);
    }
    else
    {
        printf("\n Stack is empty");
    }
   
}
void enqueue()
{
    int add_item;
    if (rear == m - 1)
    printf("Queue Overflow \n");
    else
    {
        if (front == - 1)
        front=0;
        printf("Insert the element in queue : ");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue_array[rear] = add_item;
    }
} 
 
void dequeue()
{
    if (front == - 1 || front > rear)
    {
        printf("Queue Underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", queue_array[front]);
        front = front + 1;
    }
} 
 
void display2()
{
    int i;
    if (front == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
    }
} 

void cenqueue(int cqueue[], int item)
{
    if ((front == 0 && rear == l - 1) || (front == rear + 1))
    {
        printf("Queue is full!");
        return;
    }
    else if (rear ==  - 1)
    {
        rear++;
        front++;
    }
    else if (rear == l - 1 && front > 0)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    cqueue[rear] = item;
}

void cdequeue(int cqueue[])
{
    if (front ==  - 1)
    {
        printf("Queue is empty! ");
    }
    else if (front == rear)
    {
        printf("\n %d deleted", cqueue[front]);
        front =  - 1;
        rear =  - 1;
    }
    else
    {
        printf("\n %d deleted", cqueue[front]);
        front++;
    }
}

void display3(int cqueue[])
{
    int i;
    printf("\n");
    if (front > rear)
    {
        for (i = front; i < l; i++)
        {
            printf("%d ", cqueue[i]);
        }
        for (i = 0; i <= rear; i++)
            printf("%d ", cqueue[i]);
    }
    else
    {
        for (i = front; i <= rear; i++)
            printf("%d ", cqueue[i]);
    }
}
int main()
{
    printf("\n 1.STACK\n 2.QUEUE\n 3.CIRCULAR QUEUE\n");
    printf("\n Enter your Choice:");
    scanf("%d",&choice1);
   switch(choice1)
   {
    case 1:  top=-1;
             printf("\n Enter the size of the stack:");
             scanf("%d",&n);
            do
         {
            printf("\n 1.PUSH\n 2.POP\n 3.DISPLAY\n 4.EXIT");
            printf("\n Enter your Choice:");
            scanf("%d",&choice2);
            switch(choice2)
           {
            case 1:  push();            	               
                     display1();
                     break;
            case 2:  pop();     
            	     display1();            
                     break;                
            case 3:  display1();
                     break;              
            case 4:  printf("\n Exiting....\n ");
            	     exit(0);                                 
            default:  printf ("\n Invalid Choice!\n");
           }

      }while(opt==0);
       break;
    case 2:    printf("\n Enter the size of the Queue:");
              scanf("%d",&m);
               do
         {   
        printf("\n 1.ENQUEUE\n 2.DEQUEUE\n 3.DISPLAY\n 4.EXIT");
        printf("\n Enter your Choice:");
        scanf("%d",&choice2);
        switch(choice2)
        {
            case 1:  enqueue();              	     
            	     display2();                   
                     break;
            case 2:  dequeue();             	  
  	             display2();                    
                     break;                
            case 3:  display2();
                     break;
                
            case 4:  printf("\n Exiting.....\n ");
                      exit(0);
                
            default:  printf ("\n Invalid Choice!");
        }
          }while(opt==0); 
          break;
    case 3:       printf("\n Enter the size of the Circular Queue:");
              scanf("%d",&l);
               do
         {   
        printf("\n 1.ENQUEUE\n 2.DEQUEUE\n 3.DISPLAY\n 4.EXIT");
        printf("\n Enter your Choice:");
        scanf("%d",&choice2);
        switch(choice2)
        {
            case 1:  printf("\nEnter the element: ");
                     scanf("%d", &x);
                     cenqueue(cqueue, x);  
                     printf("The elements of the circular Queue are:");
                     display3(cqueue);                   
                     break;
            case 2:  cdequeue(cqueue);          
            	      printf("The elements of the circular Queue are:");
                     display3(cqueue);            
                     break;
                
            case 3:  display3(cqueue);
                     break;
                
            case 4:  printf("\n Exiting......\n ");
                     exit(0);
                
            default:  printf ("\n Invalid Choice!");
        }
          }while(opt!=1); 
          break;  
    default :    printf ("\n Invalid Choice!");  
   }while(opt!=4); 
}

