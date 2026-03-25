class Solution {
    vector<int> parseVersion(string& version) {
        int curr = 0;
        vector<int> parsed;

        for(int i = 0; i < version.size(); i++) {
            if(version[i] == '.') {
                parsed.push_back(curr);
                curr = 0;
                continue;
            }

            if(version[i] == '0' && curr == 0)  continue;

            int digit = version[i] - '0';
            curr = (curr * 10) + digit; 
        }

        parsed.push_back(curr);

        return parsed;
    }
public:
    int compareVersion(string version1, string version2) {
        vector<int> parsedV1 = parseVersion(version1);
        vector<int> parsedV2 = parseVersion(version2);

        int i = 0, j = 0;
        int n1 = parsedV1.size(), n2 = parsedV2.size();

        while(i < n1 && j < n2) {
            if(parsedV1[i] < parsedV2[j]) {
                return -1;
            } else if(parsedV1[i] > parsedV2[j]) {
                return 1;
            }

            i++; 
            j++;
        } 

        while(i < n1 && parsedV1[i] == 0)  i++;
        if(i < n1)  return 1;

        while(j < n2 && parsedV2[j] == 0)  j++;
        if(j < n2)  return -1;

        return 0;
    }
};