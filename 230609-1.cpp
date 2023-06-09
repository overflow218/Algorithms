class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for(const char letter:letters)
        {
            if(target < letter) return letter;
        }   
        return letters[0];
    }
};