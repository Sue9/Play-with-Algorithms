//
// Created by Sue on 2019/1/16.
//

#ifndef INC_07_GRAPH_SPARSEGRAPH_H
#define INC_07_GRAPH_SPARSEGRAPH_H

#include <cassert>
#include <vector>
#include <iostream>
#include "Edge.h"

using namespace std;

template <typename Weight>
class SparseGraph{
private:
    int vertexN;
    int edgeM;
    bool directed;

    vector<vector<Edge<Weight>*>> g;

public:
    SparseGraph( int vertexN, bool directed){
        this -> vertexN = vertexN;
        this -> edgeM = 0;
        this -> directed = directed;

        for( int i = 0; i < vertexN; i++ ){
            g.push_back( vector<Edge<Weight>*>() );
        }
    }

    ~SparseGraph(){
        for( int i = 0; i < vertexN; i++ ){
            for( int j = 0; j < g[i].size(); j++ ){
                delete g[i][j];
            }
        }
    }

    int V() { return vertexN; }
    int E() { return edgeM; }


    void addEdge( int v, int w, Weight weight ){
        assert( v >= 0 && v < vertexN );
        assert( w >= 0 && w < vertexN );


        g[v].push_back(new Edge<Weight>(v, w, weight));
        if( v != w && !directed )
            g[w].push_back(new Edge<Weight> (w, v, weight));

        edgeM ++;
    }

    bool hasEdge( int v, int w ){
        assert( v >= 0 && v < vertexN );
        assert( w >= 0 && w < vertexN );

        for( int i = 0; i < g[v].size(); i++){
            if( g[v][i] -> otherVertex() == w )
                return true;
        }

        return false;
    }

    // 显示图的信息
    void show(){

        for( int i = 0 ; i < vertexN ; i ++ ){
            cout<<"vertex "<<i<<":\t";
            for( int j = 0 ; j < g[i].size() ; j ++ )
                cout<<"( to: "<<g[i][j]->w()<<", wt: "<<g[i][j]->wt()<<")\t";
            cout<<endl;
        }
    }


    class adjIterator{
    private:
        SparseGraph &G;
        int v;
        // record the location of the iterator
        int index;

    public:
        adjIterator(SparseGraph &graph, int v): G(graph){
            this -> v = v;
            this -> index = 0;
        }

        Edge<Weight>* begin(){
            index = 0;
            // check if size == 0
            if( G.g[v].size() )
                return G.g[v][index];
            return NULL;
        }

        Edge<Weight>* next(){
            index ++;
            if( index < G.g[v].size() )
                return G.g[v][index];
            return NULL;
        }

        bool end(){
            return index >= G.g[v].size();
        }


    };
};


#endif //INC_07_GRAPH_SPARSEGRAPH_H
