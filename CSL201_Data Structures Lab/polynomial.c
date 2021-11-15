#include <stdio.h>
struct poly 
{
    int deg;
    float coeff;
};

void main()
{
    struct poly a[20]={},b[20]={},c[20]={};
    int i,d,d1,k;
    printf("Enter the degree of first polynomial:");
    scanf("%d",&d);
    for(i=0;i<=d;i++)
    {
        printf("Enter the coefficient of x^%d :",i);
        scanf("%f",&a[i].coeff);
        a[i].deg=i;
    }
    printf("\nEnter the degree of second polynomial:");
    scanf("%d",&d1);
    for(i=0;i<=d1;i++)
    {
        printf("Enter the coefficient of x^%d :",i);
        scanf("%f",&b[i].coeff);
        b[i].deg=i;
    }
	printf("\n\nThe first polynomial is:");
    for(i=d;i>=0;i--)
    {
        
        if(a[i].coeff==0)
            continue;
        if(i!=d)
            printf("+");
        printf(" %.2fx^%d",a[i].coeff,a[i].deg);
        
    }
    printf("= 0\n");
    printf("The second polynomial is:");
    for(i=d1;i>=0;i--)
    {
        if(b[i].coeff==0)
            continue;
        if(i!=d1)
            printf("+");
        printf(" %.2fx^%d",b[i].coeff,b[i].deg);
    }
    if(d>=d1)
        k=d;
    else
        k=d1;
    for(i=k;i>=0;i--)
    {
        c[i].coeff=a[i].coeff+b[i].coeff;
        c[i].deg=i;
    }
    
    printf("=0\n");
    printf("Sum of the two polynomials you entered is:");
    for(i=k;i>=0;i--)
    {
        if(c[i].coeff==0)
            continue;
        if(i!=k)
            printf("+");
        printf(" %.2fx^%d",c[i].coeff,c[i].deg);
    }
    printf("= 0\n\n");
}



