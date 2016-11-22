//Linear Serach
#include<stdio.h>
#include<conio.h>
void main()
{
	int i,arr[10],found=0,pos=-1,l,n;
	clrscr();
	printf("enter the limit=\n");
	scanf("%d",&l);
	printf("enter the array=\n");
	for(i=0;i<l;i++)
	scanf("%d",&arr[i]);
	printf("enter the numer to search=\n");
	scanf("%d",&n);
	/**
	run loop for the entire array
	@if entered number is found in the array
	@initialize found to 1
	*/
	for(i=0;i<l;i++)
	if(arr[i]==n)
	{
		found=1;
		pos=i;
		printf("%d is found at the position %d \n",n,pos);
		break;
	}
	else
	printf("number not found in the array \n");
	getch();
}
