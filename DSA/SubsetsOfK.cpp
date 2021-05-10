#include<iostream> 

using namespace std;

int subset(int input[], int n, int output[][20]) {
	if(n == 0){
        output[0][0] = 0;
        return 1;
    }
    int SizeofArr = subset(input+1,n-1,output);
    
    for(int i = 0;i<SizeofArr;i++){
        //row no is i+sizeofarr
        output[SizeofArr+i][0]=output[i][0]+1;
        output[SizeofArr+i][1] = input[0];
        for(int k = 1;k<=output[i][0]+1;k++){
            output[SizeofArr+i][k+1] = output[i][k];
        }
    }
        
    return 2*SizeofArr;

}
int main(){
    int input[20],length, output[35000][20];
    cin >> length;
    for(int i=0; i < length; i++)
    cin >> input[i];
  
    int size = subset(input, length, output);

    for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
        cout << endl;
    }
    return 0;
}