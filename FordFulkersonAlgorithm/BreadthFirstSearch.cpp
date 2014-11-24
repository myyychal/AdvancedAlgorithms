#include "BreadthFirstSearch.h"

bool BreadthFirstSearch::isPath(float **graph, int length, int start, int dest, bool visited[], std::vector<int>& path) {
    std::queue<float> queue;
    queue.push(start);
    visited[start] = true;
    int parent[length];
    parent[start] = -1;
    while (!queue.empty()){
        int v = queue.front();
        queue.pop();
        for (int i=0; i<length; i++){
            if (graph[v][i] == 0 || visited[i] == true){
                continue;
            }
            queue.push(i);
            visited[i] = true;
            parent[i] = v;
            if (visited[dest]){
                int tempDest = dest;
                while(parent[tempDest] != -1){
                    path.push_back(tempDest);
                    tempDest = parent[tempDest];
                }
                path.push_back(tempDest);
                return true;
            }
        }
    }
    return visited[dest];
}