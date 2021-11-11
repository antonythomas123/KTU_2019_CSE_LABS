#include <stdio.h>
#include <stdlib.h>
int mutex=1,full=0,empty=3,item=0,buffer[10];
int wait(int s)
{
    return (--s);
}

int signal(int s)
{
    return (++s);
}

void Producer()
{
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    printf("\nEnter value to produce:");
    scanf("%d",&buffer[item]);
    item++;
    mutex = signal(mutex);
}

void Consumer()
{
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("\nConsumer consumed item %d", item);
    item--;
    mutex = signal(mutex);
}

void main()
{
    int ch;
    while (1)
    {
        printf("\n1.Produce Item\t2.Consume Item\t3.Exit\nEnter Your Choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if ((mutex == 1) && (empty != 0))
            {
                Producer();
                printf("Buffer is:");
    		for(int j=0;j<item;j++)
        		printf("%d ",buffer[j]);
            }
            else
                printf("\nBuffer is Full!!");
            break;
        case 2:
            if ((mutex == 1) && (full != 0))
            {
                Consumer();
                printf("\nBuffer is:");
    		for(int j=0;j<item;j++)
        		printf("%d ",buffer[j]);
            }
            else
                printf("\nBuffer is Empty!!");
            break;
        case 3:
        	printf("Terminating....\n");
            	exit(0);
            	break;
        }
    }
}

