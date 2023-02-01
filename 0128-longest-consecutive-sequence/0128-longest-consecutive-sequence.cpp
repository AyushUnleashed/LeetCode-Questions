class Solution {
public:
    
     int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> mp;
        int maxLen=0;
         
         for(int i=0;i<nums.size();i++){
             mp[nums[i]]=false;
         }
         //all of them are starting of sequence
         //false means, it has not been iterated on.
         // we use this boolean to avoid reiterating the while loop
         
         for(int i=0;i<nums.size();i++){
             
             // if smaller element doesn't exit
             if(mp.find(nums[i]-1)==mp.end()){
                 
                 if(mp[nums[i]]==true) continue;
                 
                 // no smaller element exist, it's smallest in map
                 //start counting upwards
                 
                 int len=0;
                 while(mp.find(nums[i]+len)!=mp.end()){
                     //if next element exist
                     len++; 
                 }
                 mp[nums[i]]=true; // we have iterated on this element
                 maxLen=max(len,maxLen);
             }
         }
         return maxLen;
     }
         
};