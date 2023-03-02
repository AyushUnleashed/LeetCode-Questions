class Solution {
public:
    int compress(vector<char>& chars) {
        unordered_map<char,int> mp;
        int len=chars.size();

        vector<char> vecs;
        
        int count =0;
        for(int i=0;i<len-1;i++){
            
            count+=1;
            if(chars[i]!=chars[i+1]){    
                vecs.push_back(chars[i]);
                
                if(count!=1){
                    string str = to_string(count);

                    for(int i=0;i<str.length();i++){
                        vecs.push_back(str[i]);
                    }          
                }
                count=0;
                
            }
        }
        
        vecs.push_back(chars[len-1]);
        count+=1;
          if(count!=1){
                string str = to_string(count);

                for(int i=0;i<str.length();i++){
                    vecs.push_back(str[i]);
                }          
            }
            
        
        
        chars.clear();
        chars = vecs;
        return vecs.size();
    }
};