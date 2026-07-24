class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int area;
        int maxi_area=0;
        int left=0,right=n-1;
        while(left<right){
            area=min(height[left],height[right])*(right-left);
            maxi_area=max(maxi_area,area);
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxi_area;   
    }
};