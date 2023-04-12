class Solution {
public:
    string simplifyPath(string path) {
        vector<string> filePaths;
        int start = -1;
        for(int end = 0; end < path.size(); end++){
            if(start == -1 && path[end] != '/')  start = end;

            else if(path[end] == '/' && start != -1){  
               string curr = path.substr(start, end - start);

               if(curr == ".." && filePaths.size() != 0)  filePaths.pop_back();
               else if(curr != ".." && curr != "." && curr != "")  filePaths.push_back(curr);
               start = -1;
            }
        }
        if(start != -1) {
            string curr = path.substr(start);

            if(curr == ".." && filePaths.size() != 0)  filePaths.pop_back();
            else if(curr != ".." && curr != "." && curr != "")  filePaths.push_back(curr);
        }
        
        if(filePaths.size() == 0)   return "/";

        string res = "";
        for(string s : filePaths)  res += "/" + s;
        return res;
    }
};