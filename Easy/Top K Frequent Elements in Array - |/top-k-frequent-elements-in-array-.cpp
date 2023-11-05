//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
         int n = nums.size();
        vector<int> freq(100001);
        int maxfreq=0;
        for(int &i:nums){ 
            freq[i]++;
            maxfreq = max(maxfreq,freq[i]);
        }
        vector<vector<int>> counted(maxfreq+1);
        for(int i=100000;i>=0;i--)
            if(freq[i]>0)
                counted[freq[i]].push_back(i);
        
        
        vector<int> ans;
        for(int i=maxfreq;i>=0;i--){
            for(int &j:counted[i]){
                ans.push_back(j);
                if(ans.size()==k) return ans;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends