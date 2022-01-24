#include<bits/stdc++.h> 

using namespace std;

int trap(vector<int>& height) {
        int waterVol=0;
        
        
       for(int i = 1 ; i<height.size()-2;i++){
         if(height[i-1]>height[i] and height[i]<height[i+1]){
             int water=0;
             int l=i;
            
             //finding the left maxima and storing it in l
             
             while(height[l]<=height[l-1]){
                 --l;
             }
             // finding the right maxima and storing it in r
             int r=0;
              while(height[r]<=height[r+1]){
                 ++r;
             }
             
             //now making the area 
             int h = min(height[l],height[r]);
             int b = r-l-1;
             --r;
             ++l;
             int volTemp = h*b;
             while(r>i){
                volTemp-=height[r];
                --r;
             }
             
             while(l<=i){
                volTemp-=height[r];
                --r;
             }
             
             waterVol+=volTemp;
         }
           
       }
    return waterVol;
}

int main(){

    vector<int> height;
    int nl;
    while(--nl)
    cout<<trap(height)<<endl;


    return 0;
}