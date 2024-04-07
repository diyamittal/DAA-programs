#include <iostream>
#include<sys/time.h>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main(){
    int n=50, a[n], b[n];
    struct timeval stop, start;
    gettimeofday(&start, NULL);
    for(int i=0;i<n;i++){
        a[i]=rand()%1000;
    }

    srand(time(0));
    cout<<endl;
   
    cout<<"BY HEAP SORT "<<endl;
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    heapSort(b, n);
    gettimeofday(&stop, NULL);
    cout<<"took us "<< (stop.tv_sec - start.tv_sec) * n + stop.tv_usec - start.tv_usec;
    cout<<endl;
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<b[i]<<" ";
    }
    
    return 0;
}
