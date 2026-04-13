class Solution {
    bool countDiff(string a, string b) {
        int diff = 0;
        for(int i = 0; i < a.size(); i++) {
            if(a[i] != b[i]) {
                if(diff)  return false;
                diff++;
            }
        }

        return diff == 1;
    }

    int bfs(int start, int end, vector<int>& visited, vector<vector<int>>& graph) {
        queue<int> q;
        q.push(start);
        visited[start] = 1;

        int level = 0;

        while(!q.empty()) {
            level++;
            int size = q.size();
            while(size--) {
                int curr = q.front();
                q.pop();

                if(curr == end) return level;

                for(int nebr : graph[curr]) {
                    if(visited[nebr] == 0) {
                        visited[nebr] = 1;
                        q.push(nebr);
                    }
                }
            }
        }

        return 0;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int start = -1, end = -1;
        for(int i = 0; i < wordList.size(); i++) {
            if(wordList[i] == beginWord) {
                start = i;
                break;
            }
        }

        if(start == -1) {
            start = wordList.size();
            wordList.push_back(beginWord);
        }

        int n = wordList.size();
        vector<vector<int>> graph(n, vector<int>());

        for(int i = 0; i < n; i++) {
            if(wordList[i] == endWord)    end = i;

            for(int j = 0; j < n; j++) {
                if(i == j)  continue;

                if(countDiff(wordList[i], wordList[j])) {
                    graph[j].push_back(i);
                }
            }
        }

        vector<int> visited(n, 0);

        return bfs(start, end, visited, graph);
    }
};