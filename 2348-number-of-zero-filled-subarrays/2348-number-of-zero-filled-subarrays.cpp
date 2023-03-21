class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {

        long count=0;
        // count stores the no. of consecutive zeros
        long total=0; 
        // no. of sub arrays = n*(n+1)/2 for n elements
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                count++;
            }else{
                total+=count*(count+1)/2;
                count=0;
            }
        }
        if(count!=0){
            total+=count*(count+1)/2;
            count=0;  
        }
        return total;
    }
};