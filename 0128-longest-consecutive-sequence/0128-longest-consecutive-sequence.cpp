class Solution {
public:
    
     int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashset;
        int maxLen=0;
         
         for(int i=0;i<nums.size();i++){
             hashset.insert(nums[i]);
         }
         //all of them are starting of sequence
         
         for(int i=0;i<nums.size();i++){
             
             // if smaller element doesn't exit
             if(hashset.find(nums[i]-1)==hashset.end()){
                 // no smaller element exist, it's smallest in map
                 //start counting upwards
                 
                 int len=0;
                 while(hashset.find(nums[i]+len)!=hashset.end()){
                     //if next element exist
                     len++; 
                 }
                 maxLen=max(len,maxLen);
             }
         }
         return maxLen;
     }
         
};