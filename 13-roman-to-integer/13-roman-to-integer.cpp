class Solution {
public:
    int romanToInt(string s) {
        
        int sum=0;
        int addToLast=0;
        
        for(int i=0;i<s.length();i++)
        {
            char currentCharacter = s[i];
            int currentDigit=getCurrentDigit(currentCharacter);
            
            int nextDigit = getCurrentDigit(s[i+1]);
            
            if(i==s.length()-1)
            {
               
            }
    else{ // not the last digit
            
            if(currentDigit==1 && (nextDigit ==5 || nextDigit==10))
           {
               currentDigit=-currentDigit;
           }else
           if(currentDigit==10 && (nextDigit ==50 || nextDigit==100))
           {
               currentDigit=-currentDigit;
           }else
           if(currentDigit==100 && (nextDigit ==500 || nextDigit==1000))
           {
               currentDigit=-currentDigit;
           }
        
        }
        sum=sum+currentDigit;

        }
        return sum;
        
    }
    
    int getCurrentDigit(char c)
    {
        int currentDigit=0;
            if(c=='I')
            {
                currentDigit = 1;
            }
            else if( c =='V')
            {
                currentDigit=5;
            }
            else if(c=='X')
            {
                currentDigit=10;
            }
            else if(c=='L')
            {
                currentDigit=50;
            }
            else if(c=='C')
            {
                currentDigit=100;
            }
            else if(c=='D')
            {
                currentDigit=500;
            }
            else if(c=='M')
            {
                currentDigit=1000;
            }
        
        return currentDigit;
    }
};