//first is diff
//second is index

class Solution {
public:
    
    class Compare{
        public:
     bool operator()(pair<int,int> a, pair<int,int> b){
        if(b.first<a.first){
            return false;
        }else if(b.first==a.first){
            if(b.second<a.second){
                return false;
            }else return true;
        }else return true;
    }
    };

//     vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//         vector<pair<int,int>> diffV;
//         for(int i=0;i<arr.size();i++){
//             int diff = abs(arr[i]-x);
//             diffV.push_back({diff,i});
//         }
//         sort(diffV.begin(),diffV.end(),comparator);
        
        
//         for(auto &v:diffV){
//             cout<<v.first<<" "<<v.second<<endl;
//         }
        
//         vector<int> ans;
//         for(int i=0;i<k;i++){
//             ans.push_back(arr[diffV[i].second]);
//         }
//         sort(ans.begin(),ans.end());
//         return ans;
        
//     }
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int,int>> diffV;
        priority_queue< pair<int,int> , vector<pair<int,int>> , Compare > pq;
        for(int i=0;i<arr.size();i++){
            int diff = abs(arr[i]-x);
            diffV.push_back({diff,i});
        }
        
        
        for(auto &v:diffV){
            cout<<v.first<<" "<<v.second<<endl;
        }
        cout<<endl;
        vector<int> ans;
        for(int i=0;i<diffV.size();i++){
            
            pq.push(diffV[i]);
            if(pq.size()>k){
                 cout<<pq.top().first<<" "<<pq.top().second<<endl;
                pq.pop();
            }
        }
    
    
        while(!pq.empty()){
            int idx=pq.top().second;
            ans.push_back(arr[idx]);
             cout<<pq.top().first<<" "<<pq.top().second<<endl;
            pq.pop();
        }
        sort(ans.begin(),ans.end());
            
        return ans;
        
    }
};