#include<stdio.h>
void main()
{
	int n,i,temp,j,k=0;
	//Read the number of processes
	printf("Enter the number of process : ");
	scanf("%d",&n);
	int bt[n],tat[n],wt[n],a[n],ct[n];
	//Read the burst time of the processes
	printf("Enter the Burst time of process : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&bt[i]);
	}
	//Calculate process number
	for(i=0;i<n;i++)
		a[i]=i+1;
	//Sort burst time and process number
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(bt[i]>bt[j])
			{
				temp=bt[i];
				bt[i]=bt[j];
				bt[j]=temp;
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	//Assign completion time of first process
	ct[0]=bt[0];
	//Calculate completion time
	for(i=1;i<n;i++)
		ct[i]=ct[i-1]+bt[i];
	//Calculate turn around time
	for(i=0;i<n;i++)
		tat[i]=ct[i];
	//Calculate wait time
	for(i=0,j=0;i<n;i++,j++)
		wt[i]=tat[i]-bt[j];
		printf("\nProcess\tBT\tCT\tTAT\tWT");
	for(i=0;i<n;i++)
	{
		printf("\nP%d\t%d\t%d\t%d\t%d",a[i],bt[i],ct[i],tat[i],wt[i]);
	}
	printf("\n");
}
