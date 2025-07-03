class Solution {
public:
    vector<string> split(string s, char del) {
        vector<string> splits;
        string split = "";
        for(char c : s) {
            if(c == del) {
                splits.push_back(split);
                split = "";
            } else {
                split += c;
            }
        }
        splits.push_back(split);

        return splits;
    }

    int compareVersion(string version1, string version2) {
        vector<string> revisions1 = split(version1, '.');
        vector<string> revisions2 = split(version2, '.');

        for(int i = 0, j = 0; i < revisions1.size() || j < revisions2.size(); i++, j++) {
            int revision1 = (i >= revisions1.size() || revisions1[i] == "") ? 0 : stoi(revisions1[i]);
            int revision2 = (j >= revisions2.size() || revisions2[j] == "") ? 0 : stoi(revisions2[j]);

            if(revision1 > revision2) {
                return 1;
            } else if (revision1 < revision2) {
                return -1;
            }
        }

        return 0;
    }
};