//Binary Search

#include<stdio.h>
#include<conio.h>
void main()
{
 int i,l,mid,end,beg,found=0,arr[10],num;
 clrscr();
 printf("enter the limit of the array\n");
 scanf("%d",&l);
 printf("enter the array\n");
 for(i=0;i<l;i++)
 scanf("%d",&arr[i]);
 printf("enter the number to search\n");
 scanf("%d",&num);
 beg=0;
 end=l-1;
 /** to find the value in the middle
 @increase the position of beginning
 @decreease the position of end
 */
 while(beg<=end)
 {
  mid=(beg+end)/2;
  if(arr[mid]==num)
  {
   printf("%d is found at the position %d\n",num,mid);
   found=1;
   break;   // to display the output only once
  }
  else if(arr[mid]>num)
  end=mid-1;
  else
  beg=mid+1;
 }
 if(found==0)
 printf("element not found in the array");
 getch();
}

