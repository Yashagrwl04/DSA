//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dfs(int i, int n, string &s, vector<int> &dp, int mod) {
        if(i == n) {
            return 0;
        }
        if(dp[i] != -1) {
            return dp[i];
        }
        vector<int> seen(26);
        int ans = 0;
        for(int j=i; j<n; j++) {
            if(seen[s[j] - 'a']) {
                continue;
            }
            seen[s[j] - 'a'] = 1;
            ans = (ans + 1 + dfs(j + 1, n, s, dp, mod)) % mod;
        }
        return dp[i] = ans;
    }
    
    string betterString(string str1, string str2) {
        int n1 = str1.size(), mod = 1e9 + 7,n2 = str2.size();
        vector<int> dp1(n1, -1);
        vector<int>dp2(n2,-1);
        if(dfs(0, n1, str1, dp1, mod)>=dfs(0, n2, str2, dp2, mod))
        return str1;
        else
        return str2;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends