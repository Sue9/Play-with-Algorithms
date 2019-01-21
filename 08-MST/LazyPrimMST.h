//
// Created by Sue on 2019/1/21.
//

#ifndef INC_08_MST_LAZYPRIMMST_H
#define INC_08_MST_LAZYPRIMMST_H

#include "MinHeap.h"
#include "Edge.h"

using namespace std;

template <typename Graph, typename Weight>
class LazyPrimMST{
private:
    Graph &G;
    //pq = priority queue
    MinHeap<Edge<Weight>> pq;
    bool* marked;
    vector<Edge<Weight>> mst;
    Weight mstWeight;

    void visit( int v ){
//        assert( v >= 0 && v < G.V() );
        assert( !marked[ v ] );
        marked[ v ] = true;
        typename Graph::adjIterator adj(G, v);
        for( Edge<Weight>* e = adj.begin(); !adj.end(); e = adj.next() ){
            if( !marked[e -> otherVertex(v)] )
                pq.insert(*e);
        }
    }

public:
    LazyPrimMST(Graph &graph): G(graph), pq(MinHeap<Edge<Weight>>(graph.E())){

        //initialise
        marked = new bool[G.V()];
        for( int i = 0; i < G.V(); i++ ){
            marked[ i ] = false;
        }
        mst.clear();

        //Lasy Prim
        visit( 0 );
        while( !pq.isEmpty() ){
            Edge<Weight> e = pq.extractMin();
            if( marked[e.v()] == marked[e.w()] )
                continue;
            mst.push_back( e );

            if( !marked[e.v()] )
                visit( e.v() );
            else
                visit( e.w() );
        }

        mstWeight = mst[ 0 ].wt();
        for( int i = 1; i < mst.size(); i++ ){
            mstWeight += mst[ i ].wt();
        }
    }

    ~LazyPrimMST(){
        delete [] marked;
    }

    vector<Edge<Weight>> mstEdges(){
        return mst;
    }

    Weight result(){
        return mstWeight;
    }
};

#endif //INC_08_MST_LAZYPRIMMST_H
