/*WAP to count the number of pairs in an integer array,
whose sum equals to the given sum*/

#include<stdio.h>

int main()
{
    int len;
    printf("Enter length of array: ");
    scanf("%d", &len);
    int a[len];
    printf("\nEnter the elements of array with a space among elements: ");
    int i;
    for(i=0;i<len;i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\nArray is: ");
    for(i=0;i<len;i++)
    {
        printf("%d ", a[i] );
    }
    int sum;
    printf("\nEnter the sum: ");
    scanf("%d", &sum);

    int j,count=0;
    for(i=0;i<len;i++)
    {
        for(j=i+1;j<len;j++)
        {
            if(a[i]+a[j]==sum)
            {
                count++;
            }
        }
    }

    printf("\nThe count of number of pairs is %d in the integer array whose sum is %d .", count, sum);
    return 0;
}
