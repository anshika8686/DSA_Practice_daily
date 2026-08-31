class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string ,int>>q;
        set<string>st;
        for(auto it:wordList){
            st.insert(it);
        }
        q.push({beginWord,1});
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                string word=q.front().first;
                int index=q.front().second;
                q.pop();

                if(word==endWord){
                    return index;   
                }
                string temp=word;

                for(int i=0;i<word.size();i++){
                    char original=temp[i];
                    for(char j='a';j<='z';j++){
                        temp[i]=j;
                       
                        if(st.count(temp)){
                            q.push({temp,index+1});
                            st.erase(temp);
                        }
                    }
                    temp[i]=original;
                }

            }
        }
        return 0;     
    }
};