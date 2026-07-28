class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int left=0,sum=0,count=0;
        int min_length=INT_MAX;
        for(int right=0;right<n;right++){
            sum+=nums[right];

            while(sum>=target){
                count++;
                min_length=min(min_length,right-left+1);
                sum-=nums[left];
                left++;
            }

        }
        if(count==0){
            min_length=0;
        }
        return min_length;
    }
};