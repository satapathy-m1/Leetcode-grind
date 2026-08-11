class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int i = 0, j = products.size() - 1;
        sort(begin(products), end(products));
        vector<vector<string>> ans;
        size_t idx = 0;
        while(idx < searchWord.size()) {
            int tempL = i;
            int tempR = j;
            while(tempL <= tempR && products[tempL].substr(0, min(products[tempL].length(), idx + 1)) < searchWord.substr(0, idx + 1)) {
                tempL++;
            }
            while(tempL <= tempR && products[tempR].substr(0, min(products[tempR].length(), idx + 1)) > searchWord.substr(0, idx + 1)) {
                tempR--;
            }
            vector<string> currWindow;
            for(int i = tempL; i < min(tempL + 3, j+1); i++) {
                if(products[i][idx] == searchWord[idx]) currWindow.push_back(products[i]);
                else break;
            }
            ans.push_back(currWindow);
            i = tempL; 
            j = tempR;
            idx++;
        }
        return ans;
    }
};