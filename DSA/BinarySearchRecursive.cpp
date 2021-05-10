#include<iostream> 

using namespace std;
int search(int input[],int high ,int low,int elem);
// input - input array
// size - length of input array
// element - value to be searched
int binarySearch(int input[], int size, int element) {
    
    return search(input,size-1,0,element);

}

int search(int input[],int high ,int low,int elem){
    int mid =(low+high)/2;
    if(input[mid]==elem){ 
    return mid;
    }else if(input[mid]>elem){ 
    return search(input,mid,low,elem);
    }else if(input[mid]<elem){ 
    return search(input,high,mid,elem);
    }else{ 
    return -1;
    }
}


int main(){

    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    { 
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;

    return 0;
}