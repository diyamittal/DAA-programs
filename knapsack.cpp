#include<iostream>
#include<sys/time.h>
using namespace std;
void knapsack(int n,float profit[],float weight[],int capacity){
    int i,u=capacity;
    float x[10],P=0;
    for(i=0;i<n;i++){
        x[i]=0.0;
    }
    for(i=0;i<n;i++){
        if(weight[i]>u){
            break;
        }
        else{
            x[i]=1.0;
            u=u-weight[i];
            P=P+profit[i];
        }
    }
    if(i<n){
        x[i]=u/weight[i];
        P=P+x[i]*profit[i];
    }
    cout<<" The result vector is : "<<endl;
    for(i=0;i<n;i++){
        cout<<x[i]<<" ";
    }
    cout<<"Total profit is: "<<P<<endl;
}
int main(){
    float weight[20], profit[20], capacity;
    int num, i, j;
    float ratio[20],temp;
    cout<<"Enter the no of objects"<<" ";
    cin>>num;
    cout<<"Enter weights of objects"<<" ";
    srand(time(0));
    for(int i=0;i<num;i++){
        weight[i]=rand()%100;
        cout<<weight[i]<<" ";
    }
    cout<<endl;
    cout<<"Enter profits of objects"<<" ";
    for(int i=0;i<num;i++){
        profit[i]=rand()%100;
        cout<<profit[i]<<" ";
    }
    cout<<endl;
    cout<<" Enter capacity of knapsack ";
    cin>>capacity;
    for (int i = 0; i < num; i++) {
        ratio[i] = profit[i] / weight[i];
    }
    for (int i = 0; i < num; i++) {
        for (int j = i + 1; j < num; j++) {
            if (ratio[i] < ratio[j]) {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;
                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;
                temp = profit[j];
                 profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }
    knapsack(num, weight, profit, capacity);
    return(0);
}