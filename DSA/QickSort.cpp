#include<iostream> 

using namespace std;
int partition(int a[],int si,int ei){
    int m=si,n=si;
    //finding the index where a[0] is required to be placed and storing it in 'n'
    while(m<ei){ 
        if(a[m]<a[si]){
            n++;
        }
        m++;
    }
    // now re initialising m for a temp variable to switch the two places in the array
    m = a[n];
    a[n] = a[si];
    a[si] = m;
    //now sorting the either side of a[] by replacint the elements;
    int i=si,j=ei;
    
    while(i<n&&j>n){
        //if both the elements are not in the right spot then they are replaced
        //and if the element is equal to the elem then it is still moved to right of the anchor
        if(a[i]>=a[n]&&a[j]<a[n]){
            m = a[i];
            a[i]=a[j];
            a[j]=m;
            i++;
            j--;
        }
        if(a[i]<a[n]&&a[j]<a[n]) j--;
        if(a[i]>=a[n]&&a[j]>a[n]) i++;    
    }
    while(i<n){
        if(a[i]>=a[n]){
            m = a[i];
        	a[i] = a[n];
            a[n] = m;
            n = i;
        }
        i++;
    }
    
    while(j<n){
        if(a[j]<a[n]){
            m = a[j];
        	a[j] = a[n];
            a[n] = m;
            n = j;
        }
        j--;
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