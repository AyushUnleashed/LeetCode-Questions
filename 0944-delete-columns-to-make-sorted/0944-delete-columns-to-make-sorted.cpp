class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        
        int cnt=0;
        for(int j=0;j<strs[0].length();j++){
            
            int lastChar=96; // 'a'-1
            
            for(int i=0;i<strs.size();i++){     
                //column
                if(int(strs[i][j])<lastChar){
                    cnt++;
                    break;
                }
                lastChar=strs[i][j];
            }
        }
        
        return cnt;
        
        
    }
};