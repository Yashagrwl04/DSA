//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	int is_bleak(int n)
	{
	     int val=n-32-1;
        if(val<=0){
            for(int i=1; i<=n; i++){
                int x=findbit(i)+i;
                if(x==n)
                    return 0;
            }
        }
        else{
            for(int i=val; i<=n; i++){
                int x=findbit(i)+i;
                if(x==n)
                    return 0;
            }
        }
        return 1;
    }
    int findbit(long long n){
        int cnt=0;
        while(n){
            if(n&1){
                cnt++;
            }
            n/=2;
        }
        return cnt;
	}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends