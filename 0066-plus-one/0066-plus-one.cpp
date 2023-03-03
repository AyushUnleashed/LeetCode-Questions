class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans(digits.size());
        int carry=1;
        for(int i=digits.size()-1;i>=0;i--){
            int val = digits[i]+carry;
            int curr = val%10;
            carry = val/10;
            ans[i]=curr;
        }
        if(carry!=0){
            reverse(ans.begin(),ans.end());
            ans.push_back(carry);
            reverse(ans.begin(),ans.end());
        }
        return ans;
    }
};