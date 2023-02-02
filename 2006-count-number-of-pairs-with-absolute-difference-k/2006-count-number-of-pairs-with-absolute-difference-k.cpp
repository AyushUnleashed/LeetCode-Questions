class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        //get freq of each
        // find(mp[arr[i]]+k)
        // nC1 * mC1 = n*m 
        unordered_map<int,int> mp;
        for(auto &x:nums){
            mp[x]++;
        }
        //got freq
        
        int ans=0;
        for(auto itr=mp.begin();itr!=mp.end();itr++){
            
            int key=itr->first;
            if(mp.find(key+k)!=mp.end()) {
                //+k exist
                int n = mp[key];
                int m= mp[key+k];
                int total = n*m;
                ans+=total;
            }
        }
        
        return ans;
    
    }
};