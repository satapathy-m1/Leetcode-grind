class Solution {
public:
    string sortSentence(string s) {
        vector<string> vec;
        string temp = "";
        for(char c : s) {
            if(c != ' ') {
                temp = temp + c;
            }
            else {
                vec.push_back(temp);
                temp = "";
            }
        }
        vec.push_back(temp);
        auto lambda = [&](string &a, string &b) {
            return a[a.size() - 1] < b[b.size() - 1];
        };
        sort(begin(vec), end(vec), lambda);
        for(string& s : vec) s.pop_back();
        temp = "";
        for(string s : vec) {
            temp += s + " ";
        }
        temp.pop_back();
        return temp;
    }
};