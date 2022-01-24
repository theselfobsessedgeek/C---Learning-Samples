#include <bits/stdc++.h>
#include<vector>
using namespace std;
vector< vector<int> > merge(vector<vector<int> > &intervals)
{
    sort(intervals.begin(),intervals.end());

    return intervals;
}
int main()
{
    vector<vector<int> > intervals ;
    vector<int> temp;

    int nums[] = {1,3,2,6,8,10,15,18};
    cout<<endl;

    for (int i = 0; i < 8; i+=2)
    {
        temp.push_back(nums[i]);
        temp.push_back(nums[i+1]);
        intervals.push_back(temp);
        temp.clear();
    }

    for(int i = 0;i<intervals.size();i++){
        cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
    }
    cout<<endl;
    merge(intervals);

     for(int i = 0;i<intervals.size();i++){
        cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
    }

    return 0;
}