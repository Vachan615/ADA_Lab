//tester for merge sort
#include<stdio.h>
#include<stdlib.h>
void mergesort(int arr[],int s,int e,int mid){
    int i=s;
    int j=mid+1;
    int k=0;
    int temp[e-s+1];
    while(i<=mid && j<=e){
        if(arr[i]<arr[j]){
            temp[k]=arr[i];
            i++;
        }else{
            temp[k]=arr[j];
            j++;
        }
        k++;
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=e){
        temp[k++]=arr[j++];
    }
    i=s;
    for(k=0;k<e-s+1;k++){
        arr[i]=temp[k];
        i++;
    }
}
void merge(int arr[],int s,int e){
    if(s>=e){
        return;
    }
    int mid=(s+e)/2;
    merge(arr,s,mid);
    merge(arr,mid+1,e);
    mergesort(arr,s,e,mid);
}
int main(){
    int arr[]={5,4,1,6,3,2};
    merge(arr,0,5);
    for(int i=0;i<6;i++){
        printf("%d ",arr[i]);
    }
}

//plotter 
#include<stdio.h>
#include<stdlib.h>
int cnt;
void mergesort(int arr[],int s,int e,int mid){
    int i=s;
    int j=mid+1;
    int k=0;
    int temp[e-s+1];
    while(i<=mid && j<=e){
        cnt++;
        if(arr[i]<arr[j]){
            temp[k]=arr[i];
            i++;
        }else{
            temp[k]=arr[j];
            j++;
        }
        k++;
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=e){
        temp[k++]=arr[j++];
    }
    i=s;
    for(k=0;k<e-s+1;k++){
        arr[i]=temp[k];
        i++;
    }
}
void merge(int arr[],int s,int e){
    if(s>=e){
        return;
    }
    int mid=(s+e)/2;
    merge(arr,s,mid);
    merge(arr,mid+1,e);
    mergesort(arr,s,e,mid);
}
void worstcase(int arr[],int s,int e){
    if(s<e){
        int mid=(s+e)/2;
        int n1=mid-s+1;
        int n2=e-mid;
        int a[n1],b[n2];
        for(int i=0;i<n1;i++){
            a[i]=arr[(2*i)];
        }
        for(int i=0;i<n2;i++){
            b[i]=arr[(2*i)+1];
        }
        worstcase(a,s,mid);
        worstcase(b,mid+1,e);
        int i;
        for(i=0;i<n1;i++){
            arr[i]=a[i];
        }
        for(int j=0;j<n2;j++){
            arr[i+j]=b[j];
        }
    }
}
void plotter(){
    FILE *fp1,*fp2,*fp3;
    fp1=fopen("5bc.txt","w");
    fp2=fopen("5ac.txt","w");
    fp3=fopen("5wc.txt","w");
    for(int i=2;i<=1024;i*=2){
        int *arr=(int*)malloc(sizeof(int)*i);
        //bestcase
        cnt=0;
        for(int j=0;j<i;j++){
            arr[j]=j+1;
        }
        merge(arr,0,i-1);
        fprintf(fp1,"%d\t%d\n",i,cnt);
        //worstcase
        cnt=0;
        worstcase(arr,0,i-1);
        merge(arr,0,i-1);
        fprintf(fp3,"%d\t%d\n",i,cnt);
        //avgcase
        cnt=0;
        for(int j=0;j<i;j++){
            arr[j]=rand()%i;
        }
        merge(arr,0,i-1);
        fprintf(fp2,"%d\t%d\n",i,cnt);
        free(arr);
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
}
int main(){
    plotter();
}
