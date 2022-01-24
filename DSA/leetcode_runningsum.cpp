#include<bits/stdc++.h> 

using namespace std;
int runningSum(vector<int>& nums) {
        int total=0;
        for(int i = nums.size()-1;i>=0;i--){
           total+=nums[i];
       } 
    return total;
}
int main(){

    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(4);

    cout<<runningSum(nums)<<endl;

    return 0;
}