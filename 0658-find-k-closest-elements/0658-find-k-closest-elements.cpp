//first is diff
//second is index

class Solution {
public:
    
    static bool comparator(pair<int,int> a, pair<int,int> b){
        if(b.first<a.first){
            return false;
        }else if(b.first==a.first){
            if(b.second<a.second){
                return false;
            }else return true;
        }else return true;
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int,int>> diffV;
        for(int i=0;i<arr.size();i++){
            int diff = abs(arr[i]-x);
            diffV.push_back({diff,i});
        }
        sort(diffV.begin(),diffV.end(),comparator);
        
        
        for(auto &v:diffV){
            cout<<v.first<<" "<<v.second<<endl;
        }
        
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(arr[diffV[i].second]);
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};