class Solution {
public:
    
    //first -> freq 
    //second -> element
    static bool comparator(pair<int,int> a,pair<int,int> b){
        if(a.first>b.first){
            //swap
            return false;
        }else if(a.first==b.first){
            if(a.second<b.second){
                return false;
            }else return true;
        }else return true;
    }
    
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<pair<int,int>> temp;
        for(auto i:mp) temp.push_back({i.second,i.first});
        // push freq, element
        
        //sort vector acc. to freq
        sort(temp.begin(),temp.end(),comparator);
        for(auto &v:temp){
            int freq=v.first;
            while(freq>0){
               ans.push_back(v.second);
                freq--;
            }
            
        }
        return ans;
    }
};