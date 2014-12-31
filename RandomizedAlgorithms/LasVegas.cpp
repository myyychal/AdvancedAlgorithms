#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void drawNeighbourhoodMatrix(float **graph, int length);
int* generateRandomSets(int noOfNodes);

int main() {

    srand(time(NULL));

    int MAX_NODES = 8;

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

    graph[0][1] = 1;
    graph[0][4] = 1;
    graph[0][5] = 1;
    graph[0][6] = 1;
    graph[1][2] = 1;
    graph[1][4] = 1;
    graph[1][5] = 1;
    graph[1][6] = 1;
    graph[2][3] = 1;
    graph[2][5] = 1;
    graph[2][6] = 1;
    graph[2][7] = 1;
    graph[3][4] = 1;
    graph[2][5] = 1;
    graph[2][6] = 1;
    graph[2][7] = 1;
    graph[4][5] = 1;
    graph[5][6] = 1;
    graph[6][7] = 1;

    drawNeighbourhoodMatrix(graph, MAX_NODES);

    int max = 0;

    int *rememberedSets = new int[MAX_NODES];

    int nonChangingIterations = 0;

    int maxNonChangingIterations = 1000;

    while (nonChangingIterations < maxNonChangingIterations){
        int* sets = generateRandomSets(MAX_NODES);
        int currentMax = 0;
        for (int j=0; j<MAX_NODES; j++){
            for (int k=j; k<MAX_NODES; k++){
                if (sets[j] != sets[k]){
                    if (graph[j][k] > 0 || graph[k][j] > 0){
                        currentMax++;
                    }
                }
            }
        }
        if (currentMax > max){
            max = currentMax;
            rememberedSets = sets;
            nonChangingIterations = 0;
        } else {
            nonChangingIterations++;
        }
        //delete sets;
    }

    cout << "Max cut: " << max << endl;

    cout << "First set of nodes: " << endl;
    for (int i=0; i < MAX_NODES; i++){
        if (rememberedSets[i] == 0){
            cout << i << " ";
        }
    }
    cout << endl << "Second set of nodes: " << endl;
    for (int i=0; i < MAX_NODES; i++){
        if (rememberedSets[i] == 1){
            cout << i << " ";
        }
    }

    for (int i=0; i<MAX_NODES; i++){
        delete graph[i];
    }
    delete graph;

    return 0;
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

int* generateRandomSets(int noOfNodes){
    int* sets = new int[noOfNodes];
    for (int i=0; i<noOfNodes; i++){
        sets[i] = rand() % 2;
    }
    return sets;
}