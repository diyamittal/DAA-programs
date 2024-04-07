#include<bits/stdc++.h>
using namespace std;
void heapify(int a[], int n, int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && a[left]>a[largest]){
        largest=left;
    }
    if(right<n && a[right]>a[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(a[i], a[largest]);
        heapify(a,i,largest);
    }
}
void heapsort(int a[], int n){
    for(int i=n-1;i>=0;i--){
        heapify(a,n,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(a[i],a[0]);
        heapify(a,i,0);
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    srand(time(0));
    for(int i=0;i<n;i++){
        a[i]=rand()%100;
        cout<<a[i]<<" ";
    }
    heapsort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;

}