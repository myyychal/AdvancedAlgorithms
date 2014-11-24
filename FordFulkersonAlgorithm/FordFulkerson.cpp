#include "BreadthFirstSearch.h"
#include "DepthFirstSearch.h"

using namespace std;

int getMaxFlow(float **graph, int length, int start, int dest, bool dfs);
void drawNeighbourhoodMatrix(float **graph, int length);
float** copyGraph(float** from, int length);
int length(float *pDouble);

int main(int argc, char *argv[]){

    int MAX_NODES = 6;

    float **graph;
    graph = new float*[MAX_NODES];
    for (int i=0; i<MAX_NODES; i++){
        graph[i] = new float[MAX_NODES];
    }

    for(int i=0; i<MAX_NODES; i++){
        for (int j=0; j<MAX_NODES; j++){
            graph[i][j] = 0.0;
        }
    }

    //MAX_NODES = 7
//    graph[0][1] = 9;
//    graph[0][4] = 9;
//    graph[1][2] = 7;
//    graph[1][3] = 3;
//    graph[2][3] = 4;
//    graph[2][6] = 6;
//    graph[3][5] = 2;
//    graph[3][6] = 9;
//    graph[4][3] = 3;
//    graph[4][5] = 6;
//    graph[5][6] = 8;

    //MAX_NODES = 4
//    graph[0][1] = 100;
//    graph[0][2] = 100;
//    graph[1][2] = 1;
//    graph[1][3] = 100;
//    graph[2][3] = 400;


//    //MAX_NODES = 6
//    graph[0][1] = 16;
//    graph[0][2] = 13;
//    graph[1][2] = 10;
//    graph[1][3] = 12;
//    graph[2][1] = 4;
//    graph[2][4] = 14;
//    graph[3][1] = 9;
//    graph[3][5] = 20;
//    graph[4][3] = 7;
//    graph[4][5] = 4;

    //MAX_NODES = 6
    graph[0][1] = 100;
    graph[0][2] = 100;
    graph[0][4] = 100;
    graph[1][5] = 100;
    graph[2][3] = 1;
    graph[3][5] = 100;
    graph[4][3] = (sqrt(5)-1)/2;
    graph[4][5] = 100;

    int graphMaxFlow = getMaxFlow(graph, MAX_NODES,0,MAX_NODES-1, false);

    cout << "Max flow: " << graphMaxFlow;

    return 0;
}

int getMaxFlow(float **graph, int length, int start, int dest, bool dfs){
    float** residualGraph = copyGraph(graph, length);
    float maxFlow = 0.0;
    bool visited[length];
    for (int i=0; i<length; i++){
        visited[i] = false;
    }
    vector<int> path;

    FirstSearch* fs;
    if (dfs){
        fs = new DepthFirstSearch();
    } else {
        fs = new BreadthFirstSearch();
    }

    drawNeighbourhoodMatrix(residualGraph, length);

    while(fs->isPath(residualGraph, length, start, dest, visited, path)){
        reverse(path.begin(), path.end());
        float pathFlow = residualGraph[path.at(0)][path.at(1)];
        for (int i=1; i<path.size()-1; i++){
            float possiblePathFlow = residualGraph[path.at(i)][path.at(i+1)];
            if (pathFlow > possiblePathFlow){
                pathFlow = possiblePathFlow;
            }
        }
        for (int i=0; i<path.size()-1; i++){
            int from = path.at(i);
            int to = path.at(i+1);
            residualGraph[from][to] -= pathFlow;
            residualGraph[to][from] += pathFlow;
        }
        maxFlow += pathFlow;
        path.clear();
        for (int i=0; i<length; i++){
            visited[i] = false;
        }
        cout << "maxFlow: " << maxFlow << endl;
        drawNeighbourhoodMatrix(residualGraph, length);
    }
    return maxFlow;
}

void drawNeighbourhoodMatrix(float **graph, int length){
    for (int i=0; i<length; i++){
        for (int j=0; j<length; j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

float** copyGraph(float** from, int length){
    float** to = new float*[length];
    for (int i=0; i<length; i++){
        to[i] = new float[length];
    }

    for(int i=0; i<length; i++){
        for (int j=0; j<length; j++){
            to[i][j] = from[i][j];
        }
    }

    return to;
}