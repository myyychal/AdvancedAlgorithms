#include "FirstSearch.h"

class BreadthFirstSearch : public FirstSearch{
public:
    bool isPath(float **graph, int length, int start, int dest, bool visited[], std::vector<int>& path);
};