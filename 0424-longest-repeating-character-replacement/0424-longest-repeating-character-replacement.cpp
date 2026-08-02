class Solution {
public:
    int characterReplacement(string s, int k) 
    {
      int left=0;
      int maxFreq=0,ans=0;
      int n=s.size();
      unordered_map<char,int>freq;
      for(int right=0;right<n;right++){ 
        freq[s[right]]++;
        maxFreq=max(maxFreq,freq[s[right]]);
        while((right-left+1)-maxFreq>k){
            freq[s[left]]--;
            if(freq[s[left]]==0) 
            freq.erase(s[left]); 
            left++;       
            }
        ans=max(ans,(right-left+1));
      }
        return ans;
    }
};