class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int len = strs[0].length();
        int n = strs.size();
        
        int cnt=0;
        
        for(int j=0;j<len;j++){
            
            bool isStrLexographic=true;
            int lastChar=96;
            
            for(int i=0;i<n;i++){     
                //column
                if(int(strs[i][j])<lastChar){
                    isStrLexographic=false;
                    cnt++;
                    break;
                }
                lastChar=strs[i][j];
            }
        }
        
        return cnt;
        
        
    }
};