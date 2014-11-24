#include "DepthFirstSearch.h"

bool DepthFirstSearch::isPath(float **graph, int length, int start, int dest, bool visited[], std::vector<int>& path) {
    if (visited[dest] == true){
        return true;
    }
    visited[start] = true;
    bool deadEnd = true;
    for (int i=0; i < length; i++){
        if (graph[start][i] > 0 && visited[i] == false && visited[dest] != true){
            deadEnd = false;
            isPath(graph, length, i, dest, visited, path);
        }
    }
    if (!(start != dest && deadEnd)){
        if (path.size() == 0){
            if (start == dest){
                path.push_back(start);
            }
        } else {
            path.push_back(start);
        }
    }
    return visited[dest];
}