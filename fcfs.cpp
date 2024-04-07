#include<bits/stdc++.h>
using namespace std;
void fcfs(int a[], int head){
    int seek_time=0;
    int cur_node,distance, size=8;
    for(int i=0;i<size;i++){
        cur_node=a[i];
        distance=abs(cur_node-head);
        seek_time+=distance;
        head=cur_node;
    }
    cout<<"Total no. of seek operations "<<seek_time<<endl;
    cout<<"Seek sequence is"<<endl;
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }

}
int main(){
    int a[8]={176, 79, 34, 60, 92, 11, 41, 114};
    fcfs(a,50);
}