class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.length();
        string rev = "";
        char a = ' ';
        int ite = 0;
        string word = "";
        while (a != '\0'){
            if (s[ite] >=48){
                word += s[ite];
                if (s[ite+1] == ' ' || s[ite+1] == '\0'){
                    reverse(word.begin(), word.end());
                    rev += word + ' ';
                    word = "";
                }
            }
            ite++;
            a = s[ite];
        }
        int newlen = rev.length();
        return rev.substr(0,newlen-1);
    }
};
