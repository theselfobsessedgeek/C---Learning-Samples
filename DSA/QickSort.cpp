#include<iostream> 

using namespace std;
int partition(int a[],int si,int ei){
    int m=si,n=si;
    //finding the index where a[0] is required to be placed and storing it in 'n'
    int x = a[si];
    
    for(m = si + 1;m<=ei;m++){
        if(a[m] <= a[si]) 
            n++;
    }
    // now re initialising m for a temp variable to switch the two places in the array
    m = a[n];
    a[n] = a[si];
    a[si] = m;
    //now sorting the either side of a[] by replacint the elements;
    int i=si,j=ei;
    
    while(i<( n)&&j>n){  
        if(a[i]<=x){
            i++;
        }else if(a[j]>x){
            j--;
        }else{
            int var=a[i];
            a[i]=a[j];
            a[j]=var;
            i++;
            j--;
        }
    }
    
    return n;
    
}

void qs(int a[],int si,int ei){
    if (si<ei){
        int p = partition(a,si,ei);
    	qs(a,si,p);
    	qs(a,p+1,ei);
    }   
}


void quickSort(int input[], int size) {
    qs(input,0,size-1);
}

int main(){

    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

    return 0;
}