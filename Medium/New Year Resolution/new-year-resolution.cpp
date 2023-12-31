//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    
    public:
    int isPossible(int N , int coins[]) 
    {
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=coins[i];
        }
        vector<vector<int>>dp(N,vector<int>(sum+1,-1));
        return solve(0,0,coins,N,dp);
    }
    int solve(int i,int sum,int coins[],int N,vector<vector<int>> &dp){
        if(sum>0 && (sum%20==0 || sum%24==0 || sum==2024)){
            return 1;
        }
        if(i>=N){
            return 0;
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        return solve(i+1,sum+coins[i],coins,N,dp) || solve(i+1,sum,coins,N,dp);
    }
    
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int coins[N];
        for(int i=0 ; i<N ; i++)
            cin>>coins[i];

        Solution ob;
        cout << ob.isPossible(N,coins) << endl;
    }
    return 0;
}
// } Driver Code Ends