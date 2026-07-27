class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int left=0;
        int max_length=0;
        vector<int>freq(256,0);
        for(int right=0;right<n;right++){
            freq[s[right]]++;
            while(freq[s[right]]>1){
                freq[s[left]]--;
                left++;
            }
            max_length=max(max_length,right-left+1);
        }
        return max_length;
        
    }
};