#include<iostream>
#include<queue>
using namespace std;

class Solution {
public:
    
    int findKthLargest(vector<int>& nums, int k) {
       priority_queue<int,vector<int>,greater<int>> pq;
        for(auto &x:nums){
            pq.push(x);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
        
    }
//     int findKthLargest(vector<int>& nums, int k) {
//         // build mean heap of K elements top element is ans
//         priority_queue<int,vector<int>,greater<int>> pq;
//         for(int i=0;i<k;i++){
//             pq.push(nums[i]);
//         }
        
//         for(int i=k;i<nums.size();i++){
            
//             if(pq.top()<nums[i]){
//                 pq.pop();
//                 pq.push(nums[i]);
//             }
//         }
        
//         return pq.top();
//     }
    
//     int findKthLargest(vector<int>& nums, int k){
//         priority_queue<int> pq;
//         for(auto &x:nums){
//             pq.push(x);
//         }
//         if(nums.size()==1){
//             return nums[0];
//         }
//         if(k==1){
//             return pq.top();
//         }
//         for(int i=k-1;i>0;i--){
//             pq.pop();
//         }
//         return pq.top();
        
//     }
};