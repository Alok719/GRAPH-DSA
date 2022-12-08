#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
    {
        // Code here
        queue<pair<string, int>> q;
        queue<pair<int,pair<int,int>>> q;
        unordered_set<string> st(wordList.begin(), wordList.end());
        q.push({startWord, 1});
        while (!q.empty())
        {    
            string words = q.front().first;
            int steps = q.front().second;
            q.pop();
            if (words == targetWord)
                return steps;
            for (int i = 0; i < words.size(); i++)
            {
                char initial = words[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    words[i] = ch;
                    if (st.find(words) != st.end())
                    {
                        q.push({words, steps + 1});
                        st.erase(words);
                    }
                }
                words[i] = initial;
            }
        }
        return 0;
    }
};