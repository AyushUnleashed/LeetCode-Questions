class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> map;
        
        vector<int> ansIdx;
        
        for(int i=0;i<nums.size();i++){
            
            int second = target - nums[i];
            
            if(map.find(second) != map.end()){
                ansIdx.push_back(map[second]);
                ansIdx.push_back(i);
                return ansIdx;
                
            }
            map[nums[i]]=i;
        }
        
        return ansIdx;
    }
};