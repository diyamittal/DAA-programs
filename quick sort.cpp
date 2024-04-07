#include<iostream>
#include<sys/time.h>
using namespace std;

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
    int n=500, a[n], b[n];
    struct timeval stop, start;
    gettimeofday(&start, NULL);

    srand(time(0));
    cout<<endl;
   
    cout<<"BY QUICK SORT "<<endl;
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    quicksort(b, 0, n - 1);
    gettimeofday(&stop, NULL);
    cout<<"took %lu us "<< (stop.tv_sec - start.tv_sec) * n + stop.tv_usec - start.tv_usec;
    cout<<endl;
    cout<<endl;
    
    return 0;
}