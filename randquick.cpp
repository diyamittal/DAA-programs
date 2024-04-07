#include<iostream>
#include<sys/time.h>
using namespace std;

int partition(int *a, int p, int q){
    int pv,i,j;
    pv=a[p];
    i=p;
    j=q;
    while(i<j){
        while(a[i]<=pv && i<j){
            i++;
        }
        while(a[j]>pv){
            j--;
        }
        if(i<j){
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    a[p]=a[j];
    a[j]=pv;
    return j;
}
int partition_r(int arr[], int low, int high){
    srand(time(NULL));
    int random=low+rand()%(high-low);
    swap(arr[random],arr[low]);
    return partition(arr,low,high);
}
void quicksort(int *a, int left, int right){
    int q;
    if(left<right){
        q=partition_r(a,left,right);
        quicksort(a,left,q-1);
        quicksort(a,q+1,right);
    }
}
int main(){
    int n=5;
    int a[n];
    srand(time(0));
    for(int i=0;i<n;i++){
        a[i]=rand()%1000;
    }
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}