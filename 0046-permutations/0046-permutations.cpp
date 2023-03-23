class Solution {
public:
    vector<vector<int>> helper(vector<int>& nums) {
        
        vector<vector<int>> ans;
        
        if(nums.size()==1){
            ans.push_back(nums);
            return ans;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            int x =nums[i];
            vector<int> smallNums;
            for(int j=0;j<nums.size();j++){
                if(x==nums[j]){
                    continue;
                }
                smallNums.push_back(nums[j]);
            }
            vector<vector<int>> smallAns = helper(smallNums);
            for(int i=0;i<smallAns.size();i++){
                smallAns[i].push_back(x);
                ans.push_back(smallAns[i]);
            }
        }
        return ans;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        return helper(nums);
    }
};
