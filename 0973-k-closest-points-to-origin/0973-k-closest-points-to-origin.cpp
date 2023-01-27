typedef pair<double,vector<int>> PIVI;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // k closest point
        // heap -> Max heap, so we can pop out farthest points
        // last k points remaining in heap is ans
        // heap(key,value) -> heap(dis of pt from Origin, point)
        
        priority_queue<PIVI> pq;
        
        for(int i=0;i<points.size();i++){
            int x=points[i][0];
            int y=points[i][1];
            double minDis = sqrt( pow(x,2) + pow(y,2));
            pq.push({minDis,points[i]});
            if(pq.size()>k){
                pq.pop();
            }
        }
        
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
        
    }
};