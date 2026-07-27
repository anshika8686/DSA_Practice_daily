class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0,left=0,max_sum=INT_MIN;
        double max_avg;
        for(int right=0;right<n;right++){
            sum+=nums[right];
            if(right-left+1==k){
                max_sum=max(max_sum,sum);
                sum-=nums[left];
                left++;
            }
        }
        max_avg=(double)max_sum/k;
        return max_avg;
    }
};