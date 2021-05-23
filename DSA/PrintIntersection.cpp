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
    int t;
	cin >> t;
	while (t--)
	{

		int size1, size2;

		cin >> size1;
		int *input1 = new int[size1];

		for (int i = 0; i < size1; i++)
		{
			cin >> input1[i];
		}

		cin >> size2;
		int *input2 = new int[size2];

		for (int i = 0; i < size2; i++)
		{
			cin >> input2[i];
		}

		intersection(input1, input2, size1, size2);
		
		delete[] input1;
		delete[] input2;
		
		cout << endl;
	}

    return 0;
}