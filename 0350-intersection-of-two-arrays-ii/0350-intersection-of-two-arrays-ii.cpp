class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> freq;
        // get freq using first array
        for(int i=0;i<nums1.size();i++){
            freq[nums1[i]]++;
        }
        vector<int> ans;
        //check it in second array
        for(int i=0;i<nums2.size();i++){
            if(freq[nums2[i]]>0){
                ans.push_back(nums2[i]);
                freq[nums2[i]]-=1;
            }
        }
        return ans;
    }
};