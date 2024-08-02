#include<stdio.h>
void heafify(int arr[],int n,int i){
    int largest=i;
    int left =2*i+1;
    int right=2*i+2;

    if(left<n && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        int temp=arr[largest];
        arr[largest]=arr[i];
        arr[i]=temp;
        heafify(arr,n,largest);
    }
}
void buildHeap(int arr[10],int n){
    for (int i=n/2-1;i>=0;i--){
        heafify(arr,n,i);
    }
}
int main (){
    int arr[6]={10,20,15,30,40};
    buildHeap(arr,5);
    for (int i=4;i>=0;i--){
        int temp = arr[i];
        arr[i]=arr[0];
        arr[0]=temp;
        heafify(arr,i-1,0);
    }
    for (int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
}