//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        priority_queue<long long> pq; //max heap
        
        long long largest;
        if(K1>K2){
            largest=K1;
        }else{
            largest=K2;
        }
        
        for(long long i=0;i<N;i++){
            pq.push(A[i]);
            if(pq.size()>(largest-1)){
                pq.pop();
            }
        }
        // we get  heap of size (largest-1)
        
        long long t=abs(K1-K2)-1; //6th - 3rd  = 3, but 3-1 = 2 elements between them, 4th&t5h 
    
        long long sum=0;
        while(!pq.empty() && t>0){
            sum+=pq.top();
            pq.pop();
            t--;
        }
        
        return sum;
    }
};

//{ Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}

// } Driver Code Ends