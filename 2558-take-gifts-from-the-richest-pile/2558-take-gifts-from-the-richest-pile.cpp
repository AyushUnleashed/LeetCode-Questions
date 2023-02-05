class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long> pq; // since we want max element from array

        for(auto it:gifts) pq.push(it);

        while(k--){ // for k times
            long long temp = pq.top(); pq.pop(); // get max element
            temp = sqrt(temp); pq.push(temp); //modify it and push back
        }
        long long sum = 0; 
        // get sum of all elements & return
        while(pq.size()!=0){
            sum+=pq.top(); pq.pop();
        }
        return sum;
    }
};