class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> linearArray;
        

        int len = matrix.size();
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<len;j++)
            {
                linearArray.push_back(matrix[i][j]);
            }
        }
        //n2
        
        sort(linearArray.begin(),linearArray.end()); // nlogn
        
        int ans  = linearArray[k-1]; //1 
        
        //0(n) = n2+ nlogn+1 => n2 
        return ans;
    }
};