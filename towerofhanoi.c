#include<stdio.h>
void TOH(int,char,char,char);
void main()
{
    int n;
    printf("Enter number of disks: ");
    scanf("%d",&n);
    TOH(n,'A','C','B');
}
void TOH(int n, char A,char B, char C)
{
    if(n>0)
    {
        TOH(n-1,A,C,B);
        printf("Move disk %d from %c to %c\n",n,A,B);
        TOH(n-1,C,B,A);
    }
}