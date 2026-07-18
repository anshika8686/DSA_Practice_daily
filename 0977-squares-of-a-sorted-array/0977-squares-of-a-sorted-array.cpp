class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int>sorted(n);
        int l=0,r=n-1,k=n-1;
        while(l<=r){
            int left_sq=nums[l]*nums[l];
            int right_sq=nums[r]*nums[r];
            if(right_sq>=left_sq){
                sorted[k]=right_sq;
                r--;
            }else{
                 sorted[k]=left_sq;
                 l++;
            }
            k--;
        }
        return sorted;
        
    }
};