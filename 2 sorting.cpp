#include<iostream>
#include<sys/time.h>
using namespace std;
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
void merge(int A[],int p, int q, int r){
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
void merge_sort(int A[],int p,int r){
    if(p<r){
        int q=(p+r)/2;
        merge_sort(A,p,q);
        merge_sort(A,q+1,r);
        merge(A,p,q,r);
    }
}
int partition(int a[], int p, int q)
{
    int pv, i, j;
    pv = a[p];
    i = p;
    j = q;
    while (i < j)
    {
        while (a[i] <= pv && i < j)
        {
            i++;
        }
        while (a[j] > pv)
        {
            j--;
        }
        if (i < j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    a[p] = a[j];
    a[j] = pv;
    return j;
}
void quicksort(int a[], int left, int right)
{
    int q;
    if (left < right)
    {
        q = partition(a, left, right);
        quicksort(a, left, q - 1);
        quicksort(a, q + 1, right);
    }
}
int main(){
    int n=1000, a[n], b[n];
    struct timeval stop, start;
    gettimeofday(&start, NULL);
    for(int i=0;i<n;i++){
        a[i]=rand()%1000;
    }


    srand(time(0));
    cout<<endl;
    cout<<"BY INSERTION SORT "<<endl;
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    insertion(b,n);
    gettimeofday(&stop, NULL);
    cout<<"took %lu us "<< (stop.tv_sec - start.tv_sec) * n + stop.tv_usec - start.tv_usec;
    cout<<endl;
    cout<<endl;

    cout<<"BY SELECTION SORT "<<endl;
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    selection(b,n);
    gettimeofday(&stop, NULL);
    cout<<"took %lu us "<< (stop.tv_sec - start.tv_sec) * n + stop.tv_usec - start.tv_usec;
    cout<<endl;
    cout<<endl;

    cout<<"BY BUBBLE SORT "<<endl;
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    bubble(b,n);
    gettimeofday(&stop, NULL);
    cout<<"took %lu us "<< (stop.tv_sec - start.tv_sec) * n + stop.tv_usec - start.tv_usec;
    cout<<endl;
    cout<<endl;

    cout<<"BY QUICK SORT "<<endl;
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    quicksort(b, 0, n - 1);
    gettimeofday(&stop, NULL);
    cout<<"took us "<< (stop.tv_sec - start.tv_sec) * n + stop.tv_usec - start.tv_usec;
    cout<<endl;
    cout<<endl;

    cout<<"BY MERGE SORT "<<endl;
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    merge_sort(b,0,n-1);
    gettimeofday(&stop, NULL);
    cout<<"took  us "<< (stop.tv_sec - start.tv_sec) * n + stop.tv_usec - start.tv_usec;
    cout<<endl;
    cout<<endl;
    
    return 0;
}