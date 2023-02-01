class Solution {
public:
    
     int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> mp;
        int maxLen=0;
         
         for(int i=0;i<nums.size();i++){
             mp[nums[i]]=true;
         }
         //all of them are starting of sequence
         
         for(int i=0;i<nums.size();i++){
             
             // if smaller element doesn't exit
             if(mp.find(nums[i]-1)==mp.end()){
                 // no smaller element exist, it's smallest in map
                 //start counting upwards
                 
                 int len=0;
                 while(mp.find(nums[i]+len)!=mp.end()){
                     len++;
                     maxLen=max(len,maxLen);
                 }
             }
         }
         return maxLen;
     }
         
};