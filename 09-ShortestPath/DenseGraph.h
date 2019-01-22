//
// Created by Sue on 2019/1/16.
//

#ifndef INC_07_GRAPH_DENSEGRAPH_H
#define INC_07_GRAPH_DENSEGRAPH_H

#include <cassert>
#include <vector>
#include <iostream>
#include "Edge.h"

using namespace std;

template <typename Weight>
// dense graph -- using Adjacency Matrix
class DenseGraph{

private:
    int vertexN, edgesM;
    bool directed;
    vector<vector<Edge<Weight> *>> g;

public:
    DenseGraph(int vertexN, bool directed){
        this -> vertexN = vertexN;
        this -> edgesM = 0;
        this -> directed = directed;

        for(int i = 0; i < vertexN; i++){
            g.push_back(vector<Edge<Weight> *>(vertexN, NULL));
        }
    }

    ~DenseGraph(){
        for( int i = 0; i < vertexN; i++ ){
            for( int j = 0; j < vertexN; j++ ){
                if( g[i][j] != NULL)
                    delete g[i][j];
            }
        }
    }

    // return the number of vertexes
    int V() { return vertexN; }
    // return the number of edges
    int E() { return edgesM; }

    void addEdge( int v, int w , Weight weight ){
        assert( v >= 0 && v < vertexN );
        assert( w >= 0 && w < vertexN );

        if( hasEdge( v, w )){
            delete g[v][w];
            if( !directed )
                delete g[w][v];
            edgesM --;
        }

        g[v][w] = new Edge<Weight>(v, w, weight);
        if( !directed )
            g[w][v] = new Edge<Weight>(w, v, weight);

        edgesM ++;
    }

    bool hasEdge( int v, int w){
        assert( v >= 0 && v < vertexN );
        assert( w >= 0 && w < vertexN );

        return g[v][w] != NULL;
    }


    // 显示图的信息
    void show(){

        for( int i = 0 ; i < vertexN ; i ++ ){
            for( int j = 0 ; j < vertexN ; j ++ )
                if( g[i][j] )
                    cout<<g[i][j]->wt()<<"\t";
                else
                    cout<<"NULL\t";
            cout<<endl;
        }
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

        Edge<Weight>* begin(){
            index = -1;
            return next();
        }

        Edge<Weight>* next(){
            for(index += 1; index < G.V(); index++){
                if( G.g[v][index] )
                    return G.g[v][index];
            }
            return NULL;
        }

        bool end(){
            return index >= G.V();
        }
    };
};


#endif //INC_07_GRAPH_DENSEGRAPH_H
