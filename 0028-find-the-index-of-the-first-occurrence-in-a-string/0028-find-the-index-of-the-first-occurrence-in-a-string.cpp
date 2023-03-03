class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int j=0; //to track needle chars
        int idx=-1;
        for(int i=0;i<haystack.length();i++){
            
            if(haystack[i]==needle[j]){
                int k=i;
                int count=needle.length();
                while(count>0){
                    if(haystack[k]==needle[j]){
                        j++;
                        if(j==needle.length()){
                            idx=k-j+1;
                            break;
                        }
                    }else{
                        j=0;
                        idx=-1;
                        break;
                    }
                    count--;
                    k++;
                }
            }
        }
        return idx;
    }
};