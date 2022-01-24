#include<bits/stdc++.h> 

using namespace std;
int maxProfit(vector<int>& prices);
int main(){

    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(4);

    cout<<maxProfit(nums)<<endl;

    return 0;
}
int maxProfit(vector<int>& prices) {
        int buy=0, sell=0,net=0;
        bool bought = false;
        vector<int> profits;
        if(prices.size()==1) return net;
        if(prices.size()==2) {
            if(prices[0]<prices[1]){
                return prices[1]-prices[0];
            }
            else return net;
        }
        for(int i =0;i<prices.size();i++){
            if( !bought and prices[i]<prices[i+1]){
                buy = prices[i];
                bought = true;
            }
            if(buy<prices[i] and bought){
                if(i==prices.size()-1 or prices[i]>prices[i+1]){
                    sell = prices[i];
                    bought =false;
                    profits.push_back(sell-buy);
                }       
            }
        }
        for(int i =0;i<profits.size();i++) net += profits[i];
        
        return net;
    }