class Solution {
public:
//     int removeDuplicates(vector<int>& nums) {
//         int count = 0;
//         int len = nums.size();
        
//         for(int i=0;i<=len-2;i++){
            
//             if(nums[i]==nums[i+1]){
//                 //duplicate condition
                
//                 //shift left by 1
//                 count++;
                
//                 for(int j=i;j<len-1;j++){
//                     nums[j]=nums[j+1];   
//                 }
                
//             }
//         }
        
//         return count;
//     }
    
        int removeDuplicates(vector<int>& nums) {
            unordered_map<int,bool> mp;
            int k=0;
            for(auto &x:nums){
                if(mp[x]==false){
                    nums[k]=x;
                    k++;
                    mp[x]=true;   
                }
            }
            int tl = nums.size();
            int toPop = tl-k;
            while(toPop>0){
                nums.pop_back();
                toPop--;
            }
            return k;
        }
    
    
};