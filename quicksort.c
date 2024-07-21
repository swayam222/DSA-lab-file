#include <stdio.h>
int partition(int a[100], int l, int r)
{
    int x = l;
    int y = r;
    int p = a[l], temp;
    while (x < y)
    {
        while (a[x] <= p)
            x++;
        while (a[y] > p)
            y--;
        if (x < y)
        {
            temp = a[x];
            a[x] = a[y];
            a[y] = temp;
        }
    }
    a[l] = a[y];
    a[y] = p;
    return y;
}
void quick(int a[10], int l, int r)
{
    int p;
    if (l < r)
    {
        p = partition(a, l, r);
        quick(a, l, p - 1);
        quick(a, p + 1, r);
    }
}
void main()
{
    int a[100], n, i, l, r;
    printf("Enter no of elements: ");
    scanf("%d", &n);
    printf("Enter %d numbers: \n", n);
    l = 0;
    r = n - 1;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    /* printf("Elements before sort:\n");
     for (i = 0; i < n; i++)
     {
         printf("%d\t", a[i]);
     }*/
   // printf("\n");
    quick(a, l, r);
    printf("Elements after sort:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}