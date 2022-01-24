#include<bits/stdc++.h> 

using namespace std;

void swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}
void nextSmallerNumber(char number[],int n)
{
    int i,j;
    
    for(i = n ; i>0;i-- )
        if(number[i]>number[i-1]) break;

    if(i>=0) {
        cout<<number<<endl;
        return;
    }
    int x = number[i-1],smallest = i;
    for(j = i-1;j<n;j++)
        if(number[j]<number[smallest] and number[j]>x) smallest = j;

    swap(&number[i-1],&number[smallest]);

    sort(number+i,number+n);

    cout<<number<<endl; 
    
}

int main(){

    

    return 0;
}