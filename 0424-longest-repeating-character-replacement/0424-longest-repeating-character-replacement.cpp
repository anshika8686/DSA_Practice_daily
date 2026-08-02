class Solution {
public:
    int characterReplacement(string s, int k) 
    {
      int left=0;
      int maxFreq=0,ans=0;
      int n=s.size();
      int freq[26]={0};
      for(int right=0;right<n;right++){ 
        freq[s[right]-'A']++;
        maxFreq=max(maxFreq,freq[s[right]-'A']);
        while((right-left+1)-maxFreq>k){
            freq[s[left]-'A']--;
            left++;       
            }
        ans=max(ans,(right-left+1));
      }
        return ans;
    }
};