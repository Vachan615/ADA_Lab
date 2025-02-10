binary search
//tester
#include<stdio.h>
#include<stdlib.h>

void main()
{
    int n,key,index,choice;
    int arr[100];
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the elements in sorted manner\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
        printf("Enter the key element\n");
    scanf("%d",&key);
    index=binsearch(arr,key,0,n-1);

    if(index!=-1)
    {
        printf("Key found at %d",index);
    }
    else
    {
        printf("Key not found\n");
    }
}

int binsearch(int *a,int key,int low,int high)
{
    int mid;
    
    if(low<=high)
    {
        mid=low+(high-low)/2;
        if(a[mid]==key)
        return mid;
        
        else if(a[mid]>key)
        return binsearch(a,key,low,mid-1);
        
        else
        return binsearch(a,key,mid+1,high);
    }
    return -1;
}

//plotter
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int count;

int binarySearch(int key, int *a, int high, int low)
{
    int mid;
    count++;
    mid = (high + low) / 2;
    if (low > high)
        return count - 1;
    if (*(a + mid) == key)
        return count;
    else if (*(a + mid) > key)
        return binarySearch(key, a, mid - 1, low);
    else
        return binarySearch(key, a, high, mid + 1);
}

void main()
{
    srand(time(NULL));
    int *arr;
    int n, key, r;
    FILE *f1, *f2, *f3;
    f1 = fopen("binarybest.txt", "a");
    f2 = fopen("binaryavg.txt", "a");
    f3 = fopen("binaryworst.txt", "a");
    n = 10;
    while (n <= 100000)
    {
        arr = (int *)malloc(n * sizeof(int));
        //best case
        for (int i = 0; i < n; i++)
            *(arr + i) = 1;
        int mid = (n - 1) / 2;
        *(arr + mid) = 0;
        count = 0;
        r = binarySearch(0, arr, n - 1, 0);
        fprintf(f1, "%d\t%d\n", n, r);
        printf("%d\t%d\n", n, count);

        //avg
        for (int i = 0; i < n; i++)
            *(arr + i) = rand() % n;
        key = rand() % n + 1;
        count = 0;
        r = binarySearch(-1, arr, n - 1, 0);
        fprintf(f2, "%d\t%d\n", n, r);
        printf("%d\t%d\n", n, count);

        //worst
        for (int i = 0; i < n; i++)
            *(arr + i) = 0;
        count = 0;
        r = binarySearch(1, arr, n - 1, 0);
        fprintf(f3, "%d\t%d\n", n, r);
        printf("%d\t%d\n", n, count);
        n = n * 2;
        free(arr);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
}

