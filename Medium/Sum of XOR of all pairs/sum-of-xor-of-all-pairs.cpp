//{ Driver Code Starts
// An efficient C++ program to compute 
// sum of bitwise OR of all pairs
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
      long long int countOnes , countZeroes;
        long long int res = 0;
        int temp = 1;
        int m = INT_MIN;
        //finding maz int the array //
        for(int i = 0 ; i<n ; i++){
            m = max(m , arr[i]);
        }
        
        int msb = floor(log2(m)) + 1; // msb of the maximum number so to misnimise the k even more;
        
        for(int i = 0 ; i<msb ; i++){
            countOnes = 0;
            countZeroes = 0;
            for(int j = 0 ; j<n ; j++){
                if(((temp<<i) & arr[j]) != 0){ // Dont use == 1 in the check its decimal check buddy//
                    countOnes++;
                }
                else{
                    countZeroes++;
                }
            }
            
            res += (countOnes * countZeroes) * pow(2 , i);
        }
        return res;
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	 int n ;
	 cin>>n;
	 int arr[n+1];
	 for( int i=0;i<n;i++)
	    cin>>arr[i];
	 Solution ob;
	 cout<<ob.sumXOR(arr, n)<<endl;
	}	
	return 0;
}

// } Driver Code Ends