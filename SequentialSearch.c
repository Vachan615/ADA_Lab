Sequential search
//tester
#include<stdio.h>
#include<stdlib.h>
#include<time.h>



int linearSearch(int *a, int n, int key) {
    for (int i = 0; i < n; i++) {
        if (*(a + i) == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n, key, index, choice;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements into the array\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search for: ");
    scanf("%d", &key);
    index = linearSearch(arr, n, key);
    if (index != -1)
        printf("Element found at index %d\n", index);
    else    
        printf("Element not found\n");
return 0;
}


//plotter
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count;

void main()
{
    srand(time(NULL));
    int *arr,key,r;
    int n=5;
    FILE *f1,*f2,*f3;
    f1=fopen("best.txt","w");
    f2=fopen("worst.txt","w");

    while(n<=1024)
    {
        arr=(int*)malloc(n*sizeof(int));
        
        //best case
        for(int i=0;i<n;i++)
        {
            arr[i]=1;
        }
        r=seqsearch(arr,n,1);
        fprintf(f1,"%d\t%d\n",n,r);
        
        //worst case
        for(int i=0;i<n;i++)
        {
            arr[i]=0;
        }
        r=seqsearch(arr,n,1);
        fprintf(f2,"%d\t%d\n",n,r);
        n*=2;
        free(arr);
    }
       fclose(f1);
       fclose(f2);
       fclose(f3);
}
    
    int seqsearch(int *a,int n,int key)
    {
        count=0;
        for(int i=0;i<n;i++)
        {
        count++;
        if(*(a+i)==key)
            {
                return count;
            }
        }
        return count;
    }



//commands for plotting graph
