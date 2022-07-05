class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int numsSize = nums.size();
        if(numsSize==0 || numsSize==1)
        {
            return numsSize;
        }
        
        int finalCount=1;int tempCount=1;
        //sort array
        sort(nums.begin(),nums.end());
        //remove duplicate elements
        
                
        cout<<"After Sorting\n";

        for (auto element :nums) {
            cout<< element << " ";
        }
        cout<<endl;
        
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                cout<<nums[i]<<"removed\n";
                nums.erase(nums.begin() + i);
                i--;
            }
        }
        
        cout<<"After Removing duplicate\n";

        for (auto element :nums) {
            cout<< element << " ";
        }

        
        numsSize=nums.size();
        
         if(numsSize==0 || numsSize==1)
        {
            return numsSize;
        }
        
        //int start=nums[0];
        
        cout<<"nums:"<<endl;
        
        for(int i=0;i<numsSize-1;i++)
        {
            if(nums[i+1]-nums[i]==1)
            {
                tempCount++;
                if(i==numsSize-2)
                {
                    if(tempCount>finalCount)
                    {
                        finalCount=tempCount;                    
                    }
                    cout<<"FinalCount:"<<finalCount<<endl;
                    return finalCount;
                }
                
                cout<<nums[i]<<" "<<tempCount<<endl;
            }else{
                //start=nums[i+1];
                
                if(tempCount>finalCount)
                {
                    finalCount=tempCount;                    
                }
                tempCount=1;
                cout<<"FinalCount:"<<finalCount<<endl;
            }
        }
        
        return finalCount;

    }
};