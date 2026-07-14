class Solution {
public:
    bool isPalindrome(string s) {
        int k=0;
        for(int i=0;i<s.size();i++){
            if(isalnum(s[i])){
                if(isupper(s[i])){
                    s[k]=tolower(s[i]);
                }else{
                    s[k]=s[i];
                }
                k++;
            }
        }
        int i=0;
        int j=k-1;
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;j--;
        }
        return true;   
    }
};