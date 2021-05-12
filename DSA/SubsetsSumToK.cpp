/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 3, 4, 2} and K = 5, then output array should contain
	{{2, 1, 4},	// Length of this subset is 2
	{2, 3, 2}}	// Length of this subset is 2

    for(int i = 0;i<SizeofArr;i++){
        //row no is i+sizeofarr
        output[SizeofArr+i][0]=output[i][0]+1;
        output[SizeofArr+i][1] = input[0];
        for(int k = 1;k<=output[i][0]+1;k++){
            output[SizeofArr+i][k+1] = output[i][k];
        }
    }

Don’t print the subsets, just save them in output.
***/
#include<iostream>
using namespace std;


int subsetSumToK(int input[], int n, int output[][50], int k) {
    if(n==0){
        if(k==0){
            output[0][0]=0;
            return 1;
        }else{
            return 0;
        }
    }
    
        
    int o1[1000][50];
    int o2[1000][50];
    //INCLUDING input[0]
    int s1 = subsetSumToK(input+1,n-1,o1,k-input[0]);
    // EXCLUDING input[0]
    int s2 = subsetSumToK(input+1,n-1,o2,k);
    //copying elements of o1
    
    for(int i = 0;i<s1;i++){
        output[i][0]=o1[i][0]+1;
        output[i][1] = input[0];
        for(int k = 1;k<=o1[i][0];k++){
            output[i][k+1] = o1[i][k];
        }   
    }
    int t = s1; // this MF is here because it starts from where the last loop ended
    // copying elements of o2
    for(int i = 0;i<(s2);i++){
        output[t][0] = o2[i][0];
        for(int k = 0;k<=o2[i][0];k++){
            output[t][k] = o2[i][k];
        }
        t++;
    }
    return s1+s2;
    
    
   
}


int main() {
  int input[20],length, output[10000][50], k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];

  cin >> k;
  
  int size = subsetSumToK(input, length, output, k);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}
