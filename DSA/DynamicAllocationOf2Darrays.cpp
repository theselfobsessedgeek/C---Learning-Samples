


/* ----Dynamic Allocation of 2D Arrays----

 
 So, in this sample i have tried to create an array whose memory is dynamically allocated.

 
 - Need -
 
 because for dynamic allocation we cannot use the method :
 
                int *p = new int[][];           // this is an invalid statement
 
 in the heap memory only 1D arrays and variables can be stored.
 
 
 - Solution -
 
        So to resolve that we create a 1D array of arrays' pointer and it's each element 
        points to one array. Hence making a 2D array, in oder to drefernce the values of this 
        array we use a double pointer.

//for deleting shit
                     for (int i = 0; i < m; i++) {
                         delete [] p[i];
                     }
                     delete [] p;
                 }


 

*/

#include <iostream>

using namespace std;

int main(){
    int m,n,i,j;
    // enter the number of columns
    cin >> n >> m;
    
    int **p = new int*[m];
    
    //input le rha hai
    for (int i = 0; i < m; i++) {
        p[i] = new int[n];
        for (int j = 0;j <n; j++) {
            cin >> p[i][j];
        }
    }
    

    for (int f= 0 ; f< m;f++ ){
        for (int q = 0; q<n;q++){
            cout << p[f][q]<<" ";
        }
        cout << endl;
    }
      
    return 0;
}
