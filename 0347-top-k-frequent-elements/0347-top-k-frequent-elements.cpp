class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        // map (freq, val)
        // pop least freq from top
        // most freq remaining
        
        unordered_map<int,int> freq;
        
        for(int i=0;i<nums.size();i++){
            
            if(freq.find(nums[i]) != freq.end()){
                //exist in map
                freq[nums[i]]++;
            }else{
                //doesnt exist
                freq[nums[i]]=1;
            }
        }
        
        for(int i=0;i<nums.size();i++){
            
            if(freq.find(nums[i]) != freq.end()){
                //exist in map
                
                if(freq[nums[i]]==-1) continue;
                
                pq.push({freq[nums[i]],nums[i]});
                if(pq.size()>k){
                    pq.pop();
                } 
                freq[nums[i]]=-1;
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