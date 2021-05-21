#include<iostream> 
#include<algorithm>

using namespace std;
void merge(int a[],int si,int ei){
    
    int mid = (si+ei)/2;
    int *aux= new int[ei-si+1];
    int i = si,j=mid+1,k = 0;

    while(i<=mid&&j<=ei){
        if(a[i]>a[j]){
            aux[k]=a[j];
            j++;
            k++;
        }
        if(a[i]<=a[j]){
            aux[k]=a[i];
            i++;
            k++;

        }
    }

    while(i<=mid)
    {
        aux[k]=a[i];
        i++;k++;
    }
    while (j<=ei)
    {
        aux[k]=a[j];
        k++;j++;
    }
    k=0;
    for(int m=si ;m<=ei;m++){
        a[m]=aux[k];
        k++;
    }
    
}
void sort(int a[],int si,int ei){
    if(si<ei){
       int mid =(si+ei)/2;
    	sort(a,si,mid);
    	sort(a,mid+1,ei);
    	merge(a,si,ei);
    }
    
}

void intersection(int *arr1, int *arr2, int n, int m) 
{
    sort(arr1,0,n-1);
    sort(arr2,0,m-1);
    int i =0,j=0;
    while (i<n&&j<m){
        if(arr1[i]==arr2[j]){
            cout<<arr1[i]<<" ";
            i++;j++;
        }
        if(arr1[i]>arr2[j]){
            j++;
        }
        if(arr1[i]<arr2[j]){
            i++;
        }
    }
}

int main(){
    

    return 0;
}