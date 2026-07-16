class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        //TC=O(N2) SC=O(1)
        vector<int>index;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]==target){
                    index.push_back(i);
                    index.push_back(j);
                }
            }
        }
        return index;  
    }

    // vector<int> twoSum(vector<int>& nums, int target) 
    // {
    //     //TC=O(Nlogn) SC=O(1)
    //     vector<int>index;
    //     int n=nums.size();
    //     sort(nums.begin(),nums.end());
    //     int l=0,r=n-1;
    //     while(l<r){
    //         if(nums[l]+nums[r]==target){
    //             index.push_back(l);
    //             index.push_back(r);
    //             break;
    //         }
    //         else if(nums[l]+nums[r]>target){
    //             r--;
    //         }
    //         else{
    //             l++;
    //         }
    //     }
    //     return index;  
    // }
};