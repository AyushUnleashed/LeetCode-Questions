class Solution {
public:
    int targetStorage[1001];
    
    Solution()
    {
        for(int i=0;i<1001;i++)
        {
            targetStorage[i] = -1;
        }
    }

    
    int combinationSum4(vector<int>& nums, int target) {
        
        int ans=0;
        int ct = target;
        
        if(ct == 0)
        {
            return 1;
        }
        
        for(auto &x: nums)
        {
            if(x<=ct)
            {
                if(targetStorage[ct-x]==-1)
                {
                    int val = combinationSum4(nums,ct-x);
                    targetStorage[ct-x]= val;
                    ans+=val;
                }
                else{
                    //cout<<"Target["<<ct-x<<"] got used\n";
                    ans+=targetStorage[ct-x];
                }
            }
        }
        
        return ans;
    }
    
    
//     int combinationSum4(vector<int>& nums, int target) {
        
        
        
        
        
        
        
        
//     }
};