//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string s){
          int n = s.length();
        string ans(n+1 , '0');
        int i  = 0, curr = 0;
        char num = '1';
        bool goBack = false;
        while(i < n){
            if(s[i] == 'I'){
                ans[i] = num;
                num++;
                curr = i;
                if(goBack){
                    i--;
                    while(s[i] == 'D'){
                        ans[i] = num;
                        num++;
                        i--;
                    }
                    goBack = false;
                    i = curr;
                }
            }else{
                goBack = true;
            }
            i++;
        }
        if(goBack){
            i = n;
            while(ans[i] == '0'){
                ans[i] = num;
                num++;
                i--;
            }
        }else{
            ans[n] = num;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends