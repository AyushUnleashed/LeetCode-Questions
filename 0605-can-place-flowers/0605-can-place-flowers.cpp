class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(flowerbed.size()==1){
           if(n==0 || (n==1 && flowerbed[0]==0)){
               return true;
           }
            return false;
        }
        
        for(int i=0;i<flowerbed.size();i++){
            if(n==0){
                break;
            }
            if(flowerbed[i]==0){
                
                if(i==0){
                    if(flowerbed[i+1]!=1){
                        n--;
                        flowerbed[i]=1;
                    }
                    continue;
                }
                if(i==flowerbed.size()-1){
                    if(flowerbed[i-1]!=1){
                        n--;
                        flowerbed[i]=1;
                    }
                    continue;
                }

                
                if( flowerbed[i-1]!=1 && flowerbed[i+1]!=1 ){
                    n--;
                    flowerbed[i]=1;
                }   
            }
        }
        
        if(n==0){
            return true;
        }
        return false;
    }
};