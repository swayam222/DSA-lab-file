#include <stdio.h>
void bubble(int[], int);
void main()
{
    int n;
    int a[100], i;
    printf("Enter no of data items: ");
    scanf("%d", &n);
    printf("Enter %d data items: \n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("The data items before sorting:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
    printf("\n");
    bubble(a, n);
    printf("The data items after sorting:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
}
void bubble(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n-1; i++)
    {
        for(j=0;j<n-1;j++)
        {
            temp = a[j];
            if(a[j]>a[j+1])
            {
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}