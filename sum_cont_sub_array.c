/*WAP to print the largest sum of contiguous SUB-ARRAY along with the starting and the ending index of the sub-array*/

/*Kadane's Algorithm approach:*/

#include<stdio.h>
#include<limits.h>
//INT_MIN will give the lowest -ve  integer value
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

    int c=0,ct=0,s=0;
    for(i=0;i<len;i++)
    {
        if(a[i]<0)
            c++;
        if(a[i]>=0)
           {
            ct++;
            s=s+a[i];
           }
    }

    if(c==len)
        printf("\nAll the elements of the array are negative:");
    else if(ct==len)
        printf("\nAll the elements of the array are positive: hence the largest sum of contiguous sub array is the sum of all the elements of the array %d", s);
    else
    {
        //logic
        int st=0,si=0,ei=0;//start and ending index

        int max_so_far=INT_MIN;
        int max_ending_here=0;

        for(i=0;i<len;i++)
        {
            max_ending_here = max_ending_here + a[i]; //adding consecutive elements

            if(max_ending_here>max_so_far) //if sum of consecutive elements is more than max so far, initialize max so far with the current sum
            {
                max_so_far = max_ending_here;
                si=st;//starting index will be st
                ei=i;//ending index will be the latest i value
            }

            if(max_ending_here<0) //if sum of elements becomes -ve num, start with 0
            {
                max_ending_here=0;// next sub array will start from the next ith index
                st=i+1;// starting index element will be the next ith element of the array
            }
        }


    printf("\nThe largest sum of contiguous SUB-ARRAY is %d and the start index is: %d and the end index is: %d", max_so_far, si, ei);

    printf("\nThe  contiguous SUB-ARRAY is: ");
    for(i=si;i<=ei;i++)
        printf("%d ", a[i] );
    }

 return 0;
}
