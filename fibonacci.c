#include<stdio.h>
int fibo();
int main()
{
    int i,n;
    printf("Enter n: ");
    scanf("%d",&n);
    printf("Fibonacci numbers upto %d terms:\n",n);
    for(i=0;i<n;i++){
      printf("%d\t",fibo(i));
    }
}
int fibo(int k)
{
    if(k==0 || k==1)
      return 1;
    else 
      return fibo(k-1)+fibo(k-2);
}