//first is diff
//second is val

class Solution {
public:
    

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    
        priority_queue< pair<int,int>> pq; //Max Heap, so max diff on top gets popped
        
        for(int i=0;i<arr.size();i++){
            
            int diff = abs(arr[i]-x);
            pq.push({diff,arr[i]});
            
            if(pq.size()>k){
                pq.pop();
            }
        }
        
        vector<int> ans;
        while(!pq.empty()){
            int val=pq.top().second;
            ans.push_back(val);
            pq.pop();
        }
        sort(ans.begin(),ans.end()); // kLog(k)
        return ans;
        
        //kLog(n) - overall
    }
};