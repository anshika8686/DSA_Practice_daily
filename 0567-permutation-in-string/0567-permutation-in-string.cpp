class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k=s1.size();
        vector<int> freq1(26, 0);
vector<int> freq2(26, 0);

        for(int i=0;i<k;i++){ //o(s1.size)
            freq1[s1[i]-'a']++;
        }

        int left=0;
        for(int right=0;right<s2.size();right++){ //o(s2.size)
            freq2[s2[right]-'a']++;

            if(right-left+1==k){
                if(freq1==freq2)
                return true;
                freq2[s2[left]-'a']--;
                left++;
            }
        }
        return false;
    }
};