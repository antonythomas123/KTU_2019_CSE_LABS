#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int coeff;
    int deg;
    struct Node *link;
};
void insertNode(struct Node *head, int coeff, int deg) 
{
	struct Node *ptr, *ptr2;
	ptr = head;
    	ptr2 = malloc(sizeof(struct Node));
    	ptr2->coeff = coeff;
    	ptr2->deg = deg;
    	ptr2->link = NULL;
    	while (ptr->link != NULL)
        	ptr = ptr->link;
    		ptr->link = ptr2;
}
void createPoly(struct Node *head) 
{
	int n, i = 1, coeff, deg;
    	printf("Enter total number of terms : ");
    	scanf("%d", &n);
    	printf("\n");
    	while (i <= n) 
    	{
        	printf("Enter coefficient of term %d: ", i);
        	scanf("%d", &coeff);
        	printf("Enter degree of  %d^x: ", coeff);
        	scanf("%d", &deg);
        	insertNode(head, coeff, deg);
        	i++;
    	}
}
void addSameDeg(struct Node *head) 
{
	struct Node *ptr, *ptr2;
    	ptr = head->link;
    	ptr2 = ptr->link;
    	while (ptr2 != NULL) 
    	{
    		if (ptr->deg == ptr2->deg) 
        	{
            		ptr->coeff = ptr->coeff + ptr2->coeff;         
            		ptr->link = ptr2->link;
            		ptr2 = ptr->link;
        	}
        	else 
        	{
            		ptr = ptr2;
            		ptr2 = ptr2->link;
        	}
    	}
}
void sortPoly(struct Node *head) 
{
	int flag;
    	struct Node *ptr, *ptr2, *ptr3;
    	do 
    	{
        	ptr = head;
        	ptr2 = ptr->link;
        	ptr3 = ptr2->link;
        	flag = 0;
        	while (ptr3 != NULL) 
        	{
            		if (ptr2->deg < ptr3->deg) 
            		{
                		ptr->link = ptr3;
                		ptr2->link = ptr3->link;
                		ptr3->link = ptr2;
                		ptr = ptr3;
                		ptr3 = ptr2->link;               
                		flag = 1;
            		}
            		else 
            		{
                		ptr = ptr2;
                		ptr2 = ptr3;
                		ptr3 = ptr3->link;
            		}
        	}
    	} 
    	while (flag != 0);
    	addSameDeg(head);
}
void printPoly(struct Node *head) 
{
	struct Node *ptr;
    	ptr = head->link;
    	while (1) 
    	{
        	if (ptr->coeff != 0) 
        	{
            		printf("%dx^%d", ptr->coeff, ptr->deg);
            		if (ptr->link == NULL)
                	break;
            		else
                		printf(" + ");
        	}
        	ptr = ptr->link;
    	}
    	printf("\n\n");
}
void addPoly(struct Node *poly1, struct Node *poly2, struct Node *poly3) 
{
	struct Node *p1, *p2;
    	p1 = poly1->link;
    	p2 = poly2->link;
    	while (p1 != NULL && p2 != NULL) 
    	{
    		if (p1->deg > p2->deg) 
        	{
            		insertNode(poly3, p1->coeff, p1->deg);
            		p1 = p1->link;
        	}
        	else if (p1->deg < p2->deg) 
        	{
            		insertNode(poly3, p2->coeff, p2->deg);
           	 	p2 = p2->link;
        	}
        	else 
        	{
            		insertNode(poly3, p1->coeff + p2->coeff, p1->deg);
            		p1 = p1->link;
            		p2 = p2->link;
        	}
    	}
    	if (p1 == NULL) 
    	{
        	while (p2 != NULL) 
        	{
            		insertNode(poly3, p2->coeff, p2->deg);
            		p2 = p2->link;
        	}
    	}
    	if (p2 == NULL) 
    	{
        	while (p1 != NULL) 
        	{
            		insertNode(poly3, p1->coeff, p1->deg);
            		p1 = p1->link;
        	}	
    	}
}
void multiplyPoly(struct Node *poly1, struct Node *poly2, struct Node *poly3) 
{
	struct Node *p1, *p2;
    	p1 = poly1->link;
    	while (p1 != NULL) 
    	{
        	p2 = poly2->link;
        	while (p2 != NULL) 
        	{
                	insertNode(poly3, p1->coeff * p2->coeff, p1->deg + p2->deg);
                	p2 = p2->link;
        	}
        	p1 = p1->link;
    	}
    	sortPoly(poly3);
}
int main() 
{
	struct Node *poly1, *poly2, *poly3add, *poly3mult;
    	poly1 = malloc(sizeof(struct Node));
    	poly2 = malloc(sizeof(struct Node));
    	poly3add = malloc(sizeof(struct Node));
    	poly3mult = malloc(sizeof(struct Node));
    	int choice;
    	printf("Enter the First Polynomial:\n");
    	createPoly(poly1);
    	sortPoly(poly1);
    	printf("\nFirst Polynomial is:\n");
    	printPoly(poly1);
    	printf("Enter the Second Polynomial:\n");
    	createPoly(poly2);
    	sortPoly(poly2);
    	printf("\nSecond Polynomial is:\n");
    	printPoly(poly2);
    	do 
    	{
        	printf("\n1. Addition\n2. Multiplication\n3. Exit\n\n");
        	printf("Enter your choice: ");
        	scanf("%d", &choice);
        	switch (choice) 
        	{
        		case 1:
                		printf("Adding polynomials......\n");
                		addPoly(poly1, poly2, poly3add);
                		printf("Sum of Polynomial is:");
                		printPoly(poly3add);
                		break;
            		case 2:
                		printf("Multiplying polynomials......\n");
                		multiplyPoly(poly1, poly2, poly3mult);
                		printf("Product of Polynomial is:");
                		printPoly(poly3mult);
                		break;
            		case 3:
                		printf("\nExiting...");
                		break;
            		default:
                		printf("\nInvalid choice!");
        	}
    	} 
    	while (choice != 3);
    	return 0;
}

