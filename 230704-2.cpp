#include <algorithm>
class Solution {
public:
    /*
    이게 가능하려면 결국에는
    등장한 알파벳의 종류가 같아야하고, 알파벳 개수가 같아야함.
    */
    bool closeStrings(string word1, string word2) {
        int counter1[26] = {0};
        int counter2[26] = {0};
        vector<int> vec1;
        vector<int> vec2;
        if(word1.size() != word2.size()) return false;

        for(int i = 0; i < word1.size(); i++)
        {
            counter1[word1[i] - 'a']++;
            counter2[word2[i] - 'a']++;
        }

        for(int i = 0; i < 26; i++)
        {
            if((counter1[i] > 0 && counter2[i] == 0) || (counter1[i] == 0 && counter2[i] > 0)) return false;
            vec1.push_back(counter1[i]);
            vec2.push_back(counter2[i]);
        }
        sort(vec1.begin(), vec1.end());
        sort(vec2.begin(), vec2.end());
        
        for(int i = 0; i < vec1.size(); i++)
        {
            if(vec1[i] != vec2[i]) return false;
        }
        return true;
    }
};