#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
        
        vector<int> kElements;
        while(k>0){
            int dig = k%10;
            kElements.push_back(dig);
            k=k/10;
        }
        
        int diff =kElements.size() - num.size();
        if(diff>0){
            reverse(num.begin(),num.end());
            while(diff>0){
                num.push_back(0);
                diff--;
            }
            reverse(num.begin(),num.end());
        }
        reverse(kElements.begin(),kElements.end());
        
        vector<int> kVec(num.size()-kElements.size(),0);
        for(int i=0;i<kElements.size();i++){
            kVec.push_back(kElements[i]);
        }
        
        vector<int> sum(num.size());
        int c=0;
        for(int i=num.size()-1;i>=0;i--){
            int temp = num[i]+kVec[i]+c;
            c= temp/10;
            sum[i]=temp%10;
        }
        
        if(c==0){
            //do nothing
        }else{
            //need to add one more element in beginning of sum
            reverse(sum.begin(),sum.end());
            sum.push_back(c);
            reverse(sum.begin(),sum.end());
        }
        return sum;
    }
    
//     vector<int> addToArrayForm(vector<int>& num, int k) {
//         int number=0;
//         int p=0;
//         for(int i=num.size()-1;i>=0;i--){
//             number+=num[i]*pow(10,p);
//             p++;
//         }
        
//         number+=k;
//         vector<int> ans;
        
//         while(number>0){
//             int dig = number%10;
//             ans.push_back(dig);
//             number/=10;
            
//         }
//         reverse(ans.begin(),ans.end());
//         return ans;
//     }

};