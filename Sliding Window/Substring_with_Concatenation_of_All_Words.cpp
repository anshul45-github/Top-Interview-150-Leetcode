// https://leetcode.com/problems/substring-with-concatenation-of-all-words/

#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int wordLength = words[0].size();
        int numWords = words.size();
        unordered_map<string, int> textWords;
        for(string& str : words)
            textWords[str]++;
        for(int i = 0; i < wordLength; i++) {
            int left = i, count = 0;
            unordered_map<string, int> window;
            for(int right = left; right + wordLength <= s.size(); right += wordLength) {
                string word = s.substr(right, wordLength);
                if(textWords.count(word)) {
                    window[word]++;
                    count++;
                    while(window[word] > textWords[word]) {
                        string leftWord = s.substr(left, wordLength);
                        window[leftWord]--;
                        count--;
                        left += wordLength;
                    }
                    if(count == numWords)
                        ans.push_back(left);
                }
                else {
                    window.clear();
                    left = right + wordLength;
                    count = 0;
                }
            }
        }
        return ans;
    }
};