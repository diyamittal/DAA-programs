#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
void merge(int *A,int p,int q,int r){
    int nl=q-p+1;
    int nr=r-q;
    int a[nl];
    int b[nr];
    for(int i=0;i<nl;i++){
        a[i]=A[p+i];
    }
    for(int j=0;j<nr;j++){
        b[j]=A[q+1+j];
    }
    int k=p;
    int i=0;
    int j=0;
    while(i<nl && j<nr){
        if(a[i]<=b[j]){
            A[k]=a[i];
            i=i+1;
        }
        else{
            A[k]=b[j];
            j=j+1;
        }
        k=k+1;
    }
    while(i<nl){
        A[k]=a[i];
        i=i+1;
        k=k+1;
    }
    while(j<nr){
        A[k]=b[j];
        j=j+1;
        k=k+1;
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
    return 0;
}