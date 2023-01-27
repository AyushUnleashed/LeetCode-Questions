class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        // map (freq, val)
        // pop least freq from top
        // most freq remaining
        
        unordered_map<int,int> freq;
        
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;       
        }
        
        for(auto i=freq.begin();i!=freq.end();i++){       
            pq.push({i->second,i->first});
            if(pq.size()>k){
                pq.pop();
            } 
        }
        
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};