// https://practice.geeksforgeeks.org/problems/ways-to-write-n-as-sum-1587115621/1/
#define MOD 1000000007

int countWays(int value){
    vector<int> numbers;
    for(int i=1;i<value;i++)
        numbers.push_back(i);

    vector<int> dp(value+1, 0);
    dp[0] = 1;

    for(auto no: numbers){
        for(int val=1;val<=value;val++){
            if(val>=no){
                dp[val] = (dp[val]+dp[val-no])%MOD;
            }
        }
    }
    return dp[value];
}