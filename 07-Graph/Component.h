//
// Created by Sue on 2019/1/17.
//

#ifndef INC_07_GRAPH_COMPONENT_H
#define INC_07_GRAPH_COMPONENT_H

#include <iostream>
#include <cassert>
using namespace std;

template <typename Graph>
class Component{

private:
    Graph &G;
    bool* visited;
    int ccount;
    int* id;

    // depth-first-search
    void dfs( int v ){
        visited[ v ] = true;
        id[ v ] = ccount;
        typename Graph::adjIterator adj(G, v);
        for(int i = adj.begin(); ! adj.end(); i = adj.next()){
            if( !visited[ i ] )
                dfs( i );
        }
    }

public:
    Component(Graph &graph): G(graph){
        visited = new bool[G.V()];
        ccount = 0;
        id = new int[G.V()];

        for( int i = 0; i < G.V(); i++ ){
            visited[ i ] = false;
            id[ i ] = -1;
        }

        // Traversal
        for( int i = 0; i < G.V(); i++ ){
            if( !visited[i] ){
                dfs( i );
                ccount ++;
            }
        }
    }

    ~Component(){
        delete [] visited;
        delete [] id;
    }

    int count(){
        return ccount;
    }

    bool isConnected(int v, int w){
        assert( v >= 0 && v < G.V() );
        assert( w >= 0 && w < G.V() );
        return id[ v ] == id[ w ];
    }
};

#endif //INC_07_GRAPH_COMPONENT_H
