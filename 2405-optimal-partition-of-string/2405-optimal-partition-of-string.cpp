class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> set;
        int count=1;
       //if(s.size()==1) return 1;
        
        for(int i=0;i<s.size();i++){
            if(set.find(s[i])!=set.end()){
                //exist
                count+=1;
                set.clear();
                set.insert(s[i]);
                continue;
            }else{
                set.insert(s[i]);
            }
            
        }
        //count+=1;
        return count;
    }
};