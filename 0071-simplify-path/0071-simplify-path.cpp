class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size(); 
        vector<string> filePaths;

        for(int i = 0; i < n; i++){
            string directory = "";
            while(i < n && path[i] != '/'){
                directory += path[i++];
            }

            if(directory == "." || directory == "")  continue;
            if(directory == ".." && filePaths.size() != 0)  filePaths.pop_back();
            else if(directory != "..") filePaths.push_back(directory);
        }
        
        if(filePaths.size() == 0)   return "/";

        string res = "";
        for(string s : filePaths)  res += "/" + s;
        return res;
    }
};