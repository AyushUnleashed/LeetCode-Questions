class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> finalAns;
        
        // we normalize both the given pattern and each word 
        // then we compare them
        // mff -> abb , gee -> abb 
        // if both normalised answers are same 
        // we add to final ans;
        
        string convertedPattern = convertString(pattern);
        
        for(auto &word: words)
        {
            string convertedWord = convertString(word);
            if(convertedWord==convertedPattern)
            {
                finalAns.push_back(word);
            }
        }
        
        return finalAns;
    }
    
    string convertString(string input){
        string convertedAns="";
        //Logic to convert string
        
        int placeHolder[26];
        // 0 -25 a-z 
        // value of placeHolder is associated character[0-25]
        
        // by default -1
        for(int i=0;i<26;i++)
        {
            placeHolder[i]=-1;
        }
    
        
        // logic to convert string
        
        // 0 + 97 -> 'a'
        // 25+ 97 ->'z'
        
        int charCount=0; // start from a 

        
        for(int i=0;i<input.length();i++)
        {
            // index of letter of each word
            int letterIndex=input[i]-'a';
            
            char convertedCharacter;
            
            // if letter not mapped
            if(placeHolder[letterIndex]==-1)
            {
                
                // map it with a letter
                placeHolder[letterIndex]=charCount;
                
                convertedCharacter = (charCount+97);
                
                convertedAns+=convertedCharacter;

                charCount++;
            }
            else{             // if letter already mapped
            
                //retrieve it from the map
                convertedCharacter = (placeHolder[letterIndex]+97);
                convertedAns+=convertedCharacter;
            }
            
        }
        
        return convertedAns;
    
    }
};