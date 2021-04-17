#include<iostream> 

using namespace std;

bool is_Sorted(int arr[],int size){
    if (size==0||size==1) return true;
    if (arr[0]>arr[1]) return false;
    return is_Sorted(arr+1,size-1);
}

int main(){
    int testcase1[]={1,2,3,4,5,6,7,8};
    int testcase2[]={8,9,4,3,4,5,6,2};
    cout<<is_Sorted(testcase1,8)<<endl;
    cout<<is_Sorted(testcase2,8)<<endl;
 
    return 0;
}