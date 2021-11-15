#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int h,n;
char a[30],key,ch,item;
void insert(char a[n],char item,char key);
int search(int index ,char key );
void delete(char a[],char key);
void display(char a[],int index,int level);
void preorder(char a[],int index);
void postorder(char a[],int index);
void inorder(char a[],int index);
struct node
{
    char data;
    struct node *lchild;
    struct node *rchild;
};
struct node *root=NULL;
struct node *result=NULL;
struct node *ptro=NULL;
void insert_link(struct node *root, char item, char key);
struct node* search_link(struct node *ptro, char key);
void display_link(struct node *root, int level);
void preorder_link(struct node *root);
void inorder_link(struct node *root);
void postorder_link(struct node *root);
struct node *delete_link(struct node *ptr1, char item);
void binaryArr()
{
	int i,choice;
    	printf("\nBinary Tree using Array\n");
    	printf("Enter the height of tree : "); 
    	scanf(" %d",&h);
    	n = pow(2,h)-1;
    	for(i=1;i<=n;i++)
        	a[i]='\0';
    	printf("Enter the root node data : "); 
    	scanf(" %c",&ch);
    	a[1]=ch;
    	do
    	{
        	printf("\n1.Insert\n2.Search\n3.Display\n4.Delete\n5.Inorder traversal\n6.Preorder traversal\n7.Postorder traversal\n8.Main Menu\n");
        	printf("\nEnter your choice: ");
        	scanf("%d",&choice);
        	switch(choice)
        	{
            	case 1:	printf("Enter the element to insert and parent: ");
                	scanf(" %c",&item); 
                	scanf(" %c", &key);
                	insert(a,item,key); 
                	break;
            	case 2:	printf("Enter the data to be searched : ");
                	scanf(" %c",&key);
                	search(1,key);
                	int x=search(1,key);
                	if(x==0)
                    		printf("\nValue not found!\n");
                	else
                    		printf("\nValue found at index = %d \n",x);
                	break;
            	case 3:	display(a,1,0);
            		break;
            	case 4:	printf("Enter the data to delete : ");
                	scanf(" %c", &item);
                	delete(a,item); 
                	break;
            	case 5:	printf("\nInorder traversal : ");
            		inorder(a,1);
            		break;
            	case 6:	printf("\nPreorder traversal : ");
            		preorder(a,1);
            		break;
            	case 7:	printf("\nPostorder traversal : ");
            		postorder(a,1);
            		break;
            	case 8:	return;
            	default:printf("\nInvalid choice!");
        	}
    	}while(choice!=8);
}
void insert(char a[],char item,char key)
{
	int l, option;
    	l=search(1,key);
    	if(l==0)
     		printf("\nInsertion failed. Search failed!\n");
    	else
    	{
        	if(a[2*l]=='\0' || a[(2*l)+1]=='\0')
        	{
            		printf("1.Left 2.Right (1/2):");
                	scanf("%d",&option);
            		if(option==1)
            		{
                		if(a[2*l]=='\0')
                	    		a[2*l]=item;
            			else
               				printf("\nInsertion at left child not possible !");
           		}
            		else if(option==2)
            		{
               			if(a[(2*l)+1]=='\0')
                	   		a[(2*l)+1]=item;
                		else
                	    		printf("\nInsertion at right child not possible !");
            		}
        	}
    	}
}
int search(int index,char key)
{   
	int i=index,l;
    	if (i > n)
        	return 0;
    	else
    	{
        	if (a[i] == key)
            		return i;
        	if (2 * i> n)
            		return 0;
        	else 
        	{
            		l= search(2 * i, key);
            		if (l != 0) 
                		return l;
            		else 
            		{
                		if (2 * i + 1 > n)
                    			return 0;
                		else
                    			return search(2 * i + 1, key);
            		}
        	}
    	}
}
void display(char a[],int i,int level)
{
	int j;
    	if(i<=n)
    	{
       		if((2*i)+1<=n)
            		display(a,((2*i)+1),level+1);
        		printf("\n");
        		for(j=0;j<level;j++)
            			printf("   ");
        			printf(" %c",a[i]);
        		if((2*i)<=n)
            			display( a,(2*i),level+1);
   	}
}
void delete(char a[],char item)
{
	int l;
    	l=search(1,item);
    	if(l==0)
        	printf("\nDelete  failed. Node is not a leaf node!");
    	else
    	{
        	a[l] = '\0';
        	printf("\nDeleted successfully ! ");
    	}	
}
void preorder(char a[],int i)
{
	if(a[i]!='\0')
	{
	        printf(" %c ",a[i]);
        	preorder(a,2*i);
        	preorder(a,2*i+1);
	}
}
void inorder(char a[],int i)
{
	if(a[i]!='\0')
	{
        	inorder(a,2*i);
        	printf(" %c ",a[i]);
        	inorder(a,2*i+1);
    	}
}
void postorder(char a[],int i)
{
	if(a[i]!='\0')
	{
        	postorder(a,2*i);
        	postorder(a,2*i+1);
        	printf(" %c ",a[i]);
    	}
}
void binaryLinkedList()
{
	int choice; 
	char item;
	root=(struct node *)malloc(sizeof(struct node));
   	printf("\nBinary Tree Using Linked List\n");
    	printf("Enter the root node data : ");
    	scanf(" %c",&root->data);
    	root->lchild=NULL;
    	root->rchild=NULL;
    	do
    	{
        	printf("\n1.Insert\n2.Search\n3.Display\n4.Delete\n5.Inorder traversal\n6.Preorder traversal\n7.Postorder traversal\n 8.Main Menu\n");
        	printf("\nEnter your choice: ");
        	scanf("%d",&choice);
        	switch(choice)
        	{
            		case 1:	printf("Enter the element to insert and parent: ");
                		scanf(" %c %c",&item,&key); 
                		insert_link(root,item,key); 
                		break;
            		case 2:	printf("Enter the data to search: ");
                		scanf(" %c",&item);
                		result = search_link(root,item);
                		if(result == NULL)
                    			printf("\nElement %c not found!\n",item);
                		else
                    			printf("\nElement %c found.\n",item);                
                		break;
            		case 3:	display_link(root,1); 
            			break;
            		case 4:	printf("Enter the leaf node to delete: ");
                		scanf(" %c",&item);
                		delete_link(root,item); 
                		display_link(root,0); 
                		break;
            		case 5:	inorder_link(root); 
            			break;
            		case 6:	preorder_link(root); 
            			break;
            		case 7:	postorder_link(root); 
            			break;
            		case 8: return;
            		default:printf("\nInvalid choice!");
        	}
    	}while(choice!=8);
}
struct node* search_link(struct node* ptro, char key) 
{ 
	struct node *ptr, *temp;
    	ptr = ptro;
    	if(ptr->data == key)
        	return ptr;
    	if(ptr->lchild != NULL && ptr->lchild->data!='\0') 
    	{
        	temp = search_link(ptr->lchild, key);
        	if(temp != NULL) 
            		return temp;
        }
    	if(ptr->rchild != NULL && ptr->rchild->data!='\0') 
    	{
        	temp = search_link(ptr->rchild, key);
        	if(temp != NULL) 
            		return temp;
        }
    	else
        	return NULL;
}
void insert_link(struct node *root, char item, char key) 
{
	struct node *ptr, *ptr2;
    	ptr2 = malloc(sizeof(struct node));
    	ptr2->data = item;
    	int choice;
    	ptr = search_link(root, key);
    	if(ptr == NULL) 
    	{
        	printf("\nInsertion failed. Search failed!\n");
        	return;
    	}
    	else
    	{
        	if(ptr->lchild == NULL || ptr->rchild == NULL) 
        	{
            		printf("1.Left 2.Right (1/2): ");
            		scanf("%d", &choice);
            		if(choice==1)
            		{
                		if(ptr->lchild == NULL) 
                    			ptr->lchild = ptr2;
                		else
                    			printf("\nlchild node is not free!");
            		}
            		else if(choice==2)
            		{
                		if(ptr->rchild == NULL)
                    			ptr->rchild = ptr2;
                		else
                    			printf("\nrchild node is not free!");
            		}
        	}
    	}
}
void display_link(struct node *root, int level)
{
	int j;
    	struct node *ptr;
    	ptr = root;
    	if(ptr->rchild != NULL)
        	display_link(ptr->rchild, level + 1);
    		printf("\n");
    		for(j = 0; j < level; j++)
        		printf("\t");
    			printf(" %c", ptr->data);
    	if(ptr->lchild != NULL)
        	display_link(ptr->lchild, level + 1);
}
void preorder_link(struct node *root) 
{
	struct node *ptr;
    	ptr = root;
    	if(ptr!= NULL)
    	{   
    		printf(" %c", ptr->data);
        	preorder_link(ptr->lchild);
        	preorder_link(ptr->rchild);
    	}
}
void inorder_link(struct node *root)
{
	struct node *ptr;
    	ptr = root;
    	if(ptr != NULL)
    	{
        	inorder_link(ptr->lchild);
        	printf(" %c", ptr->data);
        	inorder_link(ptr->rchild);
    	}
}
void postorder_link(struct node *root)
{
	struct node *ptr;
    	ptr = root;
    	if(ptr!= NULL)
    	{
        	postorder_link(ptr->lchild);
        	postorder_link(ptr->rchild);
        	printf(" %c", ptr->data);
     	}
}
struct node *delete_link(struct node *ptr1, char item)
{
	if(ptr1 == NULL)  
     		return(NULL);
    		ptr1->lchild = delete_link(ptr1->lchild, item);  
    		ptr1->rchild = delete_link(ptr1->rchild, item);  
    	if (ptr1->data == item && ptr1->lchild == NULL && ptr1->rchild == NULL)  
        	return(NULL);  
    		return(ptr1);
}
void main()
{
	int choice;
    	do
    	{
        	printf("\nBINARY TREE\n");
        	printf("1.Array\n2.Linked List\n3.Exit\nEnter your choice: ");
        	scanf("%d",&choice);
        	switch(choice)
        	{
            		case 1:	binaryArr(); 
            			break;
            		case 2: binaryLinkedList(); 
            			break;
            		case 3: printf("Exiting... ");
            			exit(0);
            		default:printf("\nInvalid choice!"); 
        	}
    	}while(choice!=3);
}

