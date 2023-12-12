//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i,int j,int n,int m,vector<vector<int>>&arr,vector<vector<int>>&dp){
            if(j==m-1)return arr[i][j];
            if(dp[i][j]!=-1)return dp[i][j];
            if(i<n-1){
                dp[i][j]=max(dp[i][j],solve(i+1,j+1,n,m,arr,dp));
            }
            if(i>0){
                dp[i][j]=max(dp[i][j],solve(i-1,j+1,n,m,arr,dp));
            }
            dp[i][j]=max(dp[i][j],solve(i,j+1,n,m,arr,dp));
            dp[i][j]+=arr[i][j];
            return dp[i][j];
    }
    
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            ans=max(ans,solve(i,0,n,m,M,dp));
        }
        return ans;
    
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends