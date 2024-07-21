#include<stdio.h>
int main()
{
    int a[100],key,i,n;
    printf("Enter the number of elements in array: ");
    scanf("%d",&n);
    printf("Enter %d numbers :\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the number to search: ");
    scanf("%d",&key);
    for(i=0;i<n;i++)
    {
        if(a[i]==key)
        {
            printf("%d is present at location %d\n",key,i+1);
            break;
        }
    }
    if(i==n)
      printf("%d is not present in array",key);
    return 0;
}