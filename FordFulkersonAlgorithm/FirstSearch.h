#ifndef FIRST_SEARCH_H
#define FIRST_SEARCH_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <bits/stl_queue.h>

class FirstSearch{
public:
    virtual bool isPath(float **graph, int length, int start, int dest, bool visited[], std::vector<int>& path) = 0;
};

#endif