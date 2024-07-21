#include<stdio.h>
int BinarySearch(int a[100],int l, int r, int key)
{
    int m;
    int flag=0;
    if(l<=r)
    {
        m=(l+r)/2;
        if(key==a[m])
          flag=m;
        else if(key<a[m])
          return BinarySearch(a,l,m-1,key);
        else
          return BinarySearch(a,m+1,r,key);
    }
    else
      return flag;
}
void main()
{
    int n,a[100],i,key,flag;
    printf("Enter no of data items: ");
    scanf("%d",&n);
    printf("Enter %d data items in sorted form:\n",n);
    for(i=0;i<n;i++)
       scanf("%d",&a[i]);
    printf("Enter item to be searched: ");
    scanf("%d",&key);
    flag=BinarySearch(a,0,n-1,key);
    if(flag==0)
       printf("Search unsuccesful");
    else 
      printf("Search succesful and found at location %d",flag+1);
}