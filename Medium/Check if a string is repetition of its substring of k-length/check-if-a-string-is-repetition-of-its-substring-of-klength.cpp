//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int kSubstrConcat (int n, string s, int k)
	{
	    // Your Code Here
	      if(n%k!=0)
      {
          return 0;
      }
      int i=0;
      
      set<string>v;
      
      while(i<n)
         {
             string r=s.substr(i,k);
             v.insert(r);
             i+=k;
             
         }
         
      if(v.size()<=2)
      {
      return 1;
      }
      else
        return 0;
	}
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		int k; cin >> k;
        Solution  ob;
		cout << ob.kSubstrConcat (n, s, k) << endl;
	}
}
// } Driver Code Ends