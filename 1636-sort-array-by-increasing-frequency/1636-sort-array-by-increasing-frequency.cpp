class Solution {
public:
    
    //first -> freq 
    //second -> element
    
    class Compare{
        public:
        bool operator()(pair<int,int> a,pair<int,int> b){
            if(a.first<b.first){
                //swap
                return false;
            }else if(a.first==b.first){
                if(a.second>b.second){
                    return false;
                }else return true;
            }else return true;
        }
        
    };

    
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        
        //get frequency of each element
        priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> pq;
        
        for(auto i:mp) pq.push({i.second,i.first});
        // push freq, element to Heap
        

        while(!pq.empty()){
            int freq=pq.top().first;
            while(freq>0){
               ans.push_back(pq.top().second);
                freq--;
            }
            pq.pop();
        }
        // pop elements & push them frequency times
        return ans;
    }
};