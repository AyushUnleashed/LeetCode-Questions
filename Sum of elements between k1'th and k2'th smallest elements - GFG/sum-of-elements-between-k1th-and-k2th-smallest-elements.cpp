//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    
    long long kthSmallestElement(long long A[],long long N,long long K){
        priority_queue<long long> pq; //max heap
        for(long long i=0;i<N;i++){
            pq.push(A[i]);
            if(pq.size()>K){
                pq.pop();
            }
        }
        return pq.top();
    }
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
       
        long long k1th=kthSmallestElement(A,N,K1);
        long long k2th=kthSmallestElement(A,N,K2);
        
        long long largest,smallest;
        if(k1th>k2th){
            largest=k1th;
            smallest=k2th;
        }else{
            largest=k2th;
            smallest=k1th;
        }
        
            
        long long sum=0;
        for(long long i=0;i<N;i++){
            if(A[i]>smallest && A[i]<largest){
                sum+=A[i];
            }
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