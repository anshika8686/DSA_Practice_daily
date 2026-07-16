class Solution {
public:
    // vector<int> twoSum(vector<int>& nums, int target) 
    // {
    //     //TC=O(N2) SC=O(1)
    //     vector<int>index;
    //     int n=nums.size();
    //     for(int i=0;i<n;i++){
    //         for(int j=i+1;j<n;j++){
    //             if(nums[i]+nums[j]==target){
    //                 index.push_back(i);
    //                 index.push_back(j);
    //             }
    //         }
    //     }
    //     return index;  
    // }

     vector<int> twoSum(vector<int>& nums, int target) 
     {
        unordered_map<int,int>mpp;
        int complement;
        int n=nums.size();
        for(int i=0;i<n;i++){
            complement=target-nums[i];
        if(mpp.find(complement)!=mpp.end()){
            return {mpp[complement], i};
        }
        mpp[nums[i]]=i;
     }
     return {};
    }

    
};