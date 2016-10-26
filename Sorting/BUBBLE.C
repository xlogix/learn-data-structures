#include<stdio.h>
#include<conio.h>

int main()
 {
  int i,n,temp,j,arr[10];
  clrscr();
  printf("\nEnter the elements  in the array:");
  scanf("%d",&n); // n is the number of elementsin the  array i.e n<=9
  printf("\n Enter the elements:");
 for(i=0;i<n;i++)   // This  for  loop is for accepting elements from the user
   scanf("%d", &arr[i]);
 for(i=0;i<n;i++)
  {
   for(j=0;j<n;j++)
    {
     if(arr[j]>arr[j+1]) // For swapping
      {
       temp=arr[j];
       arr[j]=arr[j+1];
       arr[j+1]=temp;
      }
    }
  }
  printf("\n  The array is sorted in ascending order");
  for(i=0;i<n;i++)
   printf("%d\t", arr[i]);// For displaying the sorted array
  getch();
  return 0;
 }