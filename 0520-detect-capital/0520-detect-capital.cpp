class Solution {
public:
    bool detectCapitalUse(string word) {
        int len = word.length();
        if(len==0 || len==1){
            return true;
        }
        
        if(islower(word[0])){
            //all letters should be small
            for(int i=1;i<len;i++){
                if(isupper(word[i])){
                    return false;
                }
            }
            return true;
        }else if(isupper(word[0]) && isupper(word[1])){
            // rest all should be capital

            for(int i=2;i<len;i++){
                if(islower(word[i])){
                    return false;
                }
            }
            return true;

        }else if(isupper(word[0]) && islower(word[1])){

            for(int i=2;i<len;i++){
                if(isupper(word[i])){
                    return false;
                }
            }
            return true;
        }else{
            // should never occur
        }

        return false;
        
    }
};