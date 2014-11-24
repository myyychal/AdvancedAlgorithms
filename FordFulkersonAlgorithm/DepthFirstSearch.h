#include "FirstSearch.h"

class DepthFirstSearch : public FirstSearch{
public:
    bool isPath(float **graph, int length, int start, int dest, bool visited[], std::vector<int>& path);
};