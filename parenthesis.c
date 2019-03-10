#include <stdio.h>
int factorial(int n);
int main()
{
    int n;
    printf("Enter number of matrices\n");
    scanf("%d",&n);
    int ways=factorial(2*(n-1))/(factorial(n)*factorial(n-1));

    printf("No. of ways parenthesize is %d", ways);

    return 0;
}
int factorial(int n){
    if (n >= 1)
        return n*factorial(n-1);
    else
        return 1;
}
