//
// Created by Sue on 2019/1/21.
//

#ifndef INC_08_MST_KRUSKALMST_H
#define INC_08_MST_KRUSKALMST_H

#include <iostream>
#include <vector>
#include "MinHeap.h"
#include "UF.h"
#include "Edge.h"
#include "UnionFind.h"

using namespace std;

template <typename Graph, typename Weight>
class KruskalMST{
private:
    vector<Edge<Weight>> mst;
    Weight mstWeight;

public:
    KruskalMST(Graph &graph){
        //step 1: insert all edges into priority queue, and sorted
        MinHeap<Edge<Weight>> pq(graph.E());
        // Traversal on all vertexes
        for( int i = 0; i < graph.V(); i++ ){
            typename Graph::adjIterator adj(graph,i);
            for( Edge<Weight> *e = adj.begin() ; !adj.end() ; e = adj.next() ){
                if( e->v() < e->w() )
                    pq.insert( *e );
            }
        }

        //step 2: get the lowest weighted edge, check if it would form a circle
        UnionFind uf( graph.V() );

        while( !pq.isEmpty() && mst.size() < graph.V() - 1 ){
            Edge<Weight> e = pq.extractMin();
            if( uf.isConnected( e.v(), e.w() ))
                continue;

            mst.push_back( *e );
            uf.unionElements( e.v(), e.w() );
        }

        mstWeight = mst[0].wt();
        for( int i = 1 ; i < mst.size() ; i ++ )
            mstWeight += mst[i].wt();
    }

    ~KruskalMST(){

    }


    vector<Edge<Weight>> mstEdges(){
        return mst;
    };


    Weight result(){
        return mstWeight;
    };

}


#endif //INC_08_MST_KRUSKALMST_H
