class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low=0;
        int n =nums.size();
        int high = n-1;
        
        if(n==1) return 0;
       
        while(low<=high){
            int mid=(low+high)/2;
            if(mid>0 && mid<n-1){
                
                if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                    //this is peak
                    return mid;
                }else if(mid-1>=0 && nums[mid]<nums[mid-1]){
                    //move left
                    high=mid-1;
                }else if(mid+1<n && nums[mid]<nums[mid+1]){
                    low=mid+1;
                }
                
            }else if(mid==0){
                if(nums[0]>nums[1]){
                    return 0;
                }else{
                    return 1;
                }
            }else if(mid==n-1){
                if(nums[n-1]>nums[n-2]){
                    return n-1;
                }else{
                    return n-2;
                }
            }
        }
        return -1;
    }
};