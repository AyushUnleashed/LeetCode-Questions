//first is diff
//second is index

class Solution {
public:
    

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int,int>> diffV;
        priority_queue< pair<int,int>> pq; //Max Heap, so max diff on top gets popped
        
        for(int i=0;i<arr.size();i++){
            int diff = abs(arr[i]-x);
            diffV.push_back({diff,arr[i]});
        }
        
        vector<int> ans;
        for(int i=0;i<diffV.size();i++){
            
            pq.push(diffV[i]);
            
            if(pq.size()>k){
                pq.pop();
            }
        }
    
    
        while(!pq.empty()){
            int val=pq.top().second;
            ans.push_back(val);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};