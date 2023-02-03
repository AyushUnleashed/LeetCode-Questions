class Solution {
public:
    
     int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hs;
        int maxLen=0;
         
         for(int i=0;i<nums.size();i++){
             hs.insert(nums[i]);
         }
         //all of them are starting of sequence
         
         for(int i=0;i<nums.size();i++){
             
             // if smaller element doesn't exit
             if(hs.find(nums[i]-1)==hs.end()){
                 
                 // no smaller element exist, it's smallest in map
                 //start counting upwards
                 
                 int len=0;
                 while(hs.find(nums[i]+len)!=hs.end()){
                     //if next element exist
                     len++; 
                 }
                 maxLen=max(len,maxLen);
             }
         }
         return maxLen;
     }
         
};