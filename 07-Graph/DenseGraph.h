//
// Created by Sue on 2019/1/16.
//

#ifndef INC_07_GRAPH_DENSEGRAPH_H
#define INC_07_GRAPH_DENSEGRAPH_H

#include <cassert>
#include <vector>

using namespace std;

// dense graph -- using Adjacency Matrix
class DenseGraph{

private:
    int vertexN, edgesM;
    bool directed;
    vector<vector<bool>> g;

public:
    DenseGraph(int vertexN, bool directed){
        this -> vertexN = vertexN;
        this -> edgesM = 0;
        this -> directed = directed;

        for(int i = 0; i < vertexN; i++){
            g.push_back(vector<bool>(vertexN, false));
        }
    }

    ~DenseGraph(){

    }

    // return the number of vertexes
    int V() { return vertexN; }
    // return the number of edges
    int E() { return edgesM; }

    void addEdge( int v, int w ){
        assert( v >= 0 && v < vertexN );
        assert( w >= 0 && w < vertexN );

        if( hasEdge( v, w ))
            return;

        g[v][w] = true;
        if( !directed )
            g[w][v] = true;

        edgesM ++;
    }

    bool hasEdge( int v, int w){
        assert( v >= 0 && v < vertexN );
        assert( w >= 0 && w < vertexN );

        return g[v][w];
    }


    class adjIterator{
    private:
        int index;
        int v;
        DenseGraph &G;

    public:
        adjIterator(DenseGraph &graph, int v): G(graph){
            this -> v = v;
            this -> index = -1;
        }

        int begin(){
            index = -1;
            return next();
        }

        int next(){
            for(index += 1; index < G.V(); index++){
                if( G.g[v][index] )
                    return index;
            }
            return -1;
        }

        bool end(){
            return index >= G.V();
        }
    };
};


#endif //INC_07_GRAPH_DENSEGRAPH_H
