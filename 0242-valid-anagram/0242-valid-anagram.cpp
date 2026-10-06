class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int,int>mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            mpp[t[i]]--;
            if(mpp[t[i]]==0){
                mpp.erase(t[i]);
            }
        }
        if(mpp.empty()) return true;
        return false;
    }
};