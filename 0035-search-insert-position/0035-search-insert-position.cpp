class Solution {
public:
    
    int bSearch(vector<int>& nums, int target){
        int low=0;int high =nums.size()-1;
        int idx=-1;
        while(low<=high){
            int mid = (low+high)/2;
            
            if(nums[mid]==target){
                idx= mid;
                break;
            }else if(target < nums[mid]){
                high=mid-1;
                
            }else{
                low = mid+1;
                
            }
        }
        if(idx==-1){
            return (high+1);
        }
        return idx;
    }
    int searchInsert(vector<int>& nums, int target) {
        
        int idx=bSearch(nums,target);
        return idx;
    }
};