class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if(wordSet.find(endWord) == wordSet.end()) return 0;
        unordered_set<string> s1, s2;
        s1.insert(beginWord);
        s2.insert(endWord);
        int ans = 1;
        while(!s1.empty() && !s2.empty()){
            ans++;
            if(s1.size() > s2.size()) swap(s1, s2);
            unordered_set<string> temp;
            for(auto it = s1.begin(); it != s1.end(); it++){
                string w = *it;
                for(int i = 0; i < w.size(); i++){
                    char c = w[i];
                    for(int j = 0; j < 26; j++){
                        w[i] = 'a' + j;
                        if(s2.find(w) != s2.end()) return ans;
                        if(wordSet.find(w) != wordSet.end()){
                            temp.insert(w);
                            wordSet.erase(w);
                        }
                    }
                    w[i] = c;
                }
            }
            swap(s1, temp);
        }
        return 0;
    }
};
