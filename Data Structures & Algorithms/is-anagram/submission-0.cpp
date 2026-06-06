class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;

        int hash[26] = {0};
        
        for (int i = 0; i < s.size(); i++)
        {
            hash[s[i] - 'a']++; 
        }

        for (int i = 0; i < t.size(); i++)
        {
            hash[t[i] - 'a']--;
            if(hash[t[i]-'a'] < 0){
                return false;
            }
        }
        return true;
    }
};
