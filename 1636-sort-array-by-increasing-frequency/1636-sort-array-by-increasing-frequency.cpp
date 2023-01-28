// PQ => reverse of normal in comparator

class Solution {
public:
    
    //first -> freq 
    //second -> element
    
    class Compare{
        public:
        bool operator()(pair<int,int> a,pair<int,int> b){
            // Jo condition chahiye return true;
            // a, left .. b, right
            if(a.first>b.first){
                return true;
            }else if(a.first==b.first){
                if(a.second<b.second){
                    return true;
                }else return false;
            }else return false;
        }
    };
    
    // static bool comparator(pair<int,int> a,pair<int,int> b){
    //         // Jo condition chahiye return true;
    //         // a, left .. b, right
    //         if(a.first<b.first){
    //             return true;
    //         }else if(a.first==b.first){
    //             if(a.second>b.second){
    //                 return true;
    //             }else return false;
    //         }else return false;
    // }

    
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
        
//         vector<pair<int,int>> temp;
//         for(auto i:mp) temp.push_back({i.second,i.first});
//         sort(temp.begin(),temp.end(),comparator);
        
//         for(int i=0;i<temp.size();i++){
//             int freq=temp[i].first;
//             while(freq>0){
//                ans.push_back(temp[i].second);
//                 freq--;
//             }
//         }
        
        return ans;
    }
};