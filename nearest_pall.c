/*
WAP to find the nearest palindrome number whose absolute difference with the USER ENTERED number is minimum,
if the difference are same then print the lowest nearest palindrome number of the USER ENTERED number
*/

#include<stdio.h>
int main()
{
    int pall(int n);
    int nearPall(int num);

    int num;
    printf("Enter any positive integer number greater than equal to 11: \n");
    scanf("%d", &num);
    int res=nearPall(num);
    printf("\nThe nearest palindrome number is: %d", res);
    return 0;
}

int nearPall(int num)
{
    int low=0,high=0;
    int i,j;
    for(i=num; i>=11; i--)
    {
            if(pall(i)==1)
            {
                low=i;
                break;
            }
    }

    for(j=num; j<=2*num; j++)
    {
        if(pall(j)==1)
        {
            high=j;
            break;
        }
    }

    int x=num-low;
    int y=high-num;
    if(x==y)
    {
        if(low<high)
            return low;
        else
            return high;
    }

    else if(x<y)
    {
        return low;
    }
    else
    {
        return high;
    }
    //printf("%d %d", low, high);
}

int pall(int n)
{
    int rem=0,rev=0;
    int t=n;
    while(t>0)
    {
        rem=t%10;
        rev=rev*10+rem;
        t=t/10;
    }
    if(rev==n)
    {

        return 1;
    }
}
