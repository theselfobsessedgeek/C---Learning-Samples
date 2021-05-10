#include<iostream>
using namespace std;

//SPIRAL 2D ARRAY
void spiralprint(int a[][100],int m,int n )
{
    int sr=0, sc=0;    
    int i;
    while (sr < m && sc < n) {
        
        for (i = sc; i < n; ++i) {
            cout << a[sr][i] << " ";
        }
        sr++;
 
        
        for (i = sr; i < m; ++i) {
            cout << a[i][n - 1] << " ";
        }
        n--;
 
        
        if (sr < m) {
            for (i = n - 1; i >= sc; --i) {
                cout << a[m - 1][i] << " ";
            }
            m--;
        }
 
       
        if (sc < n) {
            for (i = m - 1; i >= sr; --i) {
                cout << a[i][sc] << " ";
            }
            sc++;
        }
    }
}
    
    
    


int main()
{
    int a[100][100];
    int m,n;
    cout<<"enter the number of rows and columns"<<endl;
    cin>>m>>n; //m=number of rows, n= number of columns

    int val=1;

    for(int row=0; row<m; row++)
    {
        for(int col=0; col<n; col++)
        {
            a[row][col]=val;
            val=val+1;
            cout<<a[row][col]<<" ";
        }
        cout<<'\n';
    }

    cout<<endl;
    cout<<endl;

    spiralprint(a,m,n);

    return 0;

}