class Solution {
   public:
    string encode(vector<string>& strs) {
        string res = "";

        for (string s : strs) {
            res += to_string(s.length()) + "#" + s;
        }

        return res;
    }

    vector<string> decode(string str) {
        vector<string> res;
        int i = 0;

        while (i < str.length()) {
            int j = i;

            while (str[j] != '#') {
                j++;
            }

            int length = stoi(str.substr(i, j - i));

            res.push_back(str.substr(j + 1, length));

            i = j + 1 + length;
        }

        return res;
    }
};
