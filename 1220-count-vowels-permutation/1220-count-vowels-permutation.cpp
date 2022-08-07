#define M  1000000007

class Solution {
public:
    
    // static int size = (2*10000)+1;
    unsigned long long dp[5][(2*10000)+1];
    
    //a-> 0, e->1,i->2, o->3,u->4
    
    Solution(){
        int size = (2*10000)+1;
        for(int i=0;i<size;i++)
        {
            for(int j=0;j<5;j++)
            {
                dp[j][i]=-1;
            }
        }
    }
    
    int countVowelPermutation(int n) {
        
         unsigned long long ansA,ansE,ansI,ansO,ansU,m,finalAns;
        ansA = cVowel(n,'a');
         ansE = cVowel(n,'e');
         ansI = cVowel(n,'i');
         ansO = cVowel(n,'o');
         ansU = cVowel(n,'u');
        
         finalAns = (ansA+ansE+ansI+ansO+ansU)%M;
        
        finalAns=(int)finalAns;
        return finalAns;
        
    }
    
    long cVowel(int n,char ch) //recursive
    {
        unsigned long long val=-1;
        if(n==1)
        {
            return 1;
        }
        
        if(ch=='a')
        {
            
            if(dp[0][n]!=-1)
            {
                return dp[0][n];
            }else{
                val =  cVowel(n-1,'e')%M;
                dp[0][n] = val;
                return val%M;
            }
            
        }else if(ch=='e')
        {
            
            if(dp[1][n]!=-1)
            {
                 return dp[1][n];
            }else{
                val =  (cVowel(n-1,'a')+cVowel(n-1,'i'))%M;
                dp[1][n] =val;
                return val;
            }
            
        }else if(ch=='i')
        {
            if(dp[2][n]!=-1)
            {
                return dp[2][n];
            }else{
                val = (cVowel(n-1,'a')+cVowel(n-1,'e')+cVowel(n-1,'o')+cVowel(n-1,'u'))%M;
                dp[2][n]=val;
                return val;
            }
            
        }else if(ch=='o')
        {
            if(dp[3][n]!=-1)
            {
                return dp[3][n];
            }else{
                 val = (cVowel(n-1,'i')+cVowel(n-1,'u'))%M;
                dp[3][n]= val;
                return val;
            }
   
        }else if(ch=='u')
        {
            if(dp[4][n]!=-1)
            {
                return dp[4][n];
            }else{
                val = (cVowel(n-1,'a'))%M;
                dp[4][n]= val;
                return val;
            }
            
        
        }
        
        return -100000; // it should never occur
        
    }
};