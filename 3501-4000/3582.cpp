class Solution {
public:
    string generateTag(string caption) {
        if (caption.find_first_not_of(" \t\n\r") == string::npos) {
            return "#";
        }

        stringstream ss(caption);
        string word;
        string res = "#";
        vector<string> arr;

        while (ss >> word) {
            arr.push_back(word);
        }

        if (arr.empty()) return "#";

        string first_word = arr[0];
        first_word[0] = tolower(first_word[0]);
        for (size_t i = 1; i < first_word.size(); ++i)
            first_word[i] = tolower(first_word[i]);

        res += first_word;

        for (size_t i = 1; i < arr.size(); ++i) {
            string w = arr[i];
            w[0] = toupper(w[0]);
            for (size_t j = 1; j < w.size(); ++j)
                w[j] = tolower(w[j]);
            res += w;
            if (res.length() >= 100) break;
        }

        return res.substr(0, 100);
    }
};
