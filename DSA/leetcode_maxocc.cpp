#include<bits/stdc++.h> 

using namespace std;

int main(){
    map<int,int> m;
    
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);

    for(int i =0; i<nums.size(); i++){
        if (m.count(nums[i]) > 0) m[nums[i]]++;
        else m[nums[i]] =1;
    }
    map<int, int>::iterator itr;
    for (itr = m.begin(); itr != m.end(); ++itr) {
        cout << '\t' << itr->first
             << '\t' << itr->second << '\n';
    }
    cout << endl;
    return 0;
}