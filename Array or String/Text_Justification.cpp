// https://leetcode.com/problems/text-justification/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int currWords = 0;
        int currSize = 0;
        for(int i = 0; i < words.size(); i++) {
            if(currSize + currWords + words[i].size() <= maxWidth) {
                currWords++;
                currSize += words[i].size();
            }
            else {
                int spaceSize = maxWidth - currSize;
                int inits = maxWidth - currSize;
                if(currWords > 1) { 
                    spaceSize /= (currWords - 1);
                    inits %= (currWords - 1);
                }
                string line = "";
                for(int j = i - currWords; j < i; j++) {
                    line += words[j];
                    if(j == i - 1)
                        continue;
                    for(int i = 0; i < spaceSize; i++) 
                        line += ' ';
                    if(inits > 0)
                        line += ' ';
                    inits--;
                }
                while(line.size() < maxWidth)
                    line += ' '; 
                ans.push_back(line);
                currWords = 1;
                currSize = words[i].size();
            }
        }
        string line = "";
        for(int j = words.size() - currWords; j < words.size(); j++) {
            line += words[j];
            if(j == words.size() - 1)
                continue;
            line += ' ';
        }
        while(line.size() < maxWidth)
            line += ' ';
        ans.push_back(line);
        return ans;
    }
};