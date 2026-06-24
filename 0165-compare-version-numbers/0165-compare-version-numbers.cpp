class Solution {
private: 
    vector<string> getVec(string s) {
        stringstream ss(s);
        vector<string> v;
        while(getline(ss, s, '.')) {
            v.push_back(s);
        }
        return v;
    }
    int compare(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        int i = 0, j = 0;
        while(i < m && s1[i] == '0') i++;
        while(j < n && s2[j] == '0') j++;
        if(m - i < n - j) return -1;
        else if(m - i > n - j) return 1;
        else {
            while(i < m && j < n) {
                if(s1[i] > s2[j]) return 1;
                else if(s1[i] < s2[j]) return -1;
                else {
                    i++;
                    j++;
                }
            }
            return 0;
        }
        
    }
public:
    int compareVersion(string version1, string version2) {
        vector<string> vec1 = getVec(version1);
        vector<string> vec2 = getVec(version2);
        int i = 0, j = 0;
        while(i < vec1.size() && j < vec2.size()) {
            int res = compare(vec1[i], vec2[j]);
            if(res == 0) {
                i++;
                j++;
            }
            else if(res == 1) return 1;
            else return -1;
        }
        if(i == vec1.size() && j == vec2.size()) return 0;
        while(i < vec1.size()) {
            if(stoi(vec1[i++]) != 0) return 1;
        }

        while(j < vec2.size()) {
            if(stoi(vec2[j++]) != 0) return -1;
        }

        return 0;
    }
};