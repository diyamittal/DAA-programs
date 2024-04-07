#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
int insertion(int arr[],int n){
    int key,j;
    for(int i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}
int selection(int arr[],int n){
    int min,j,temp;
    for(int i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        if(min!=i){
            temp=arr[min];
            arr[min]=arr[i];
            arr[i]=temp;
        }
    }
}
int bubble(int arr[],int n){
    int temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void merge(int *A,int p, int q, int r){
    int nl=q-p+1;
    int nr=r-q;
    int a[nl],b[nr];
    for(int i=0;i<nl;i++){
        a[i]=A[p+i];
    }
    for(int j=0;j<nr;j++){
        b[j]=A[q+1+j];
    }
    int k=p,i=0,j=0;
    while(i<nl && j<nr){
        if(a[i]<=b[j]){
            A[k]=a[i];
            i++;
        }
        else{
            A[k]=b[j];
            j++;
        }
        k++;
    }
    while(i<nl){
        A[k]=a[i];
        i++;
        k++;
    }
    while(j<nr){
        A[k]=b[j];
        j++;
        k++;
    }
}
void merge_sort(int *A,int p,int r){
    if(p<r){
        int q=(p+r)/2;
        merge_sort(A,p,q);
        merge_sort(A,q+1,r);
        merge(A,p,q,r);
    }
}
int main(){
    int start;
    time_t t;
    start=time(&t)*1000;
    printf("time at start \t %d msec\n",start);
    int n;
    printf("Enter size");
    scanf("%d",&n);
    int a[n];
    srand(time(0));
    printf("Before sorting");
    for(int i=0;i<n;i++){
        a[i]=rand()%1000;
        printf("%d ",a[i]);

    }
    merge_sort(a,0,n-1);
    printf("after sorting");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    int end;
    time_t l;
    end=time(&l)*1000;
    printf("time at end \t %d msec\n",end);
    int diff;
    diff=end-start;
    int final=diff;
    printf("time in all \t %d msec\n",final);
    return 0;
}