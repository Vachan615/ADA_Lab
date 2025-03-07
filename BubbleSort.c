Bubble sort
//tester and plotter
#include<stdio.h> 
#include<stdlib.h> 
#include<time.h>

int count; 

int bubblesort(int *a, int n) 
{ 
    count = 0; 
    for (int i = 0; i < n - 1; i++) 
    { 
        int flag = 0; 
        for (int j = 0; j < n - i - 1; j++)     
        { 
            count++;     
            if (a[j] > a[j + 1]) 
            { 
                int temp = a[j]; 
                a[j] = a[j+1]; 
                a[j+1] = temp; 
                flag = 1; 
            }   
        } 
        if (flag == 0) 
            break; 
    } 
    return count; 
} 

void plotter() 
{ 
    int *arr, n = 10; 
    srand(time(NULL)); 
    FILE *f1, *f2, *f3; 
    f1 = fopen("b_b.txt", "a"); 
    f2 = fopen("b_w.txt", "a"); 
    f3 = fopen("b_a.txt", "a"); 
    
    while (n <= 30000) 
    { 
        arr = (int *)malloc(sizeof(int) * n); 

        // best case 
        count = 0; 
        for (int i = 0; i < n; i++)
            arr[i] = i + 1; 
        bubblesort(arr, n); 
        fprintf(f1, "%d\t%d\n", n, count); 

        // worst case 
        count = 0; 
        for (int i = 0; i < n; i++)
            arr[i] = n - i;  
        bubblesort(arr, n); 
        fprintf(f2, "%d\t%d\n", n, count); 

        // AVG case 
        count = 0;
        for (int i = 0; i < n; i++) 
            arr[i] = rand() % n; 
        bubblesort(arr, n); 
        fprintf(f3, "%d\t%d\n", n, count); 
        
        if (n < 10000) 
            n = n * 10; 
        else 
            n = n + 10000; 
            
        free(arr); 
    } 
    fclose(f1); 
    fclose(f2); 
    fclose(f3); 
} 

void tester() 
{ 
    int *arr, n; 
    printf("Enter the number of elements : "); 
    scanf("%d", &n); 
    arr = (int *)malloc(sizeof(int) * n); 
    printf("Enter the elements of the array : \n"); 
    for (int i = 0; i < n; i++) 
        scanf("%d", &arr[i]); 
 
    printf("The elements of the array before Sorting are : \n");  
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
 
    bubblesort(arr, n); 
 
    printf("The elements of the array after Sorting are :\n");  
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
    free(arr);
} 

void main() 
{ 
    while(1)
    { 
        int key; 
        printf("Enter your choice :  \n1. Tester \n2. Plotter\n0. Exit\n"); 
        scanf("%d", &key); 
        switch (key) 
        { 
            case 1:
                tester();
                break; 
            case 2:
                plotter();
                printf("Plotter files generated successfully");
                exit(0); 
            default:
                exit(1); 
        }  
    } 
}
