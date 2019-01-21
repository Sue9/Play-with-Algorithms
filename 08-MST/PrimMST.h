//
// Created by Sue on 2019/1/21.
//

#ifndef INC_08_MST_PRIMMST_H
#define INC_08_MST_PRIMMST_H

#include <iostream>
#include <vector>
#include <cassert>
#include "Edge.h"
#include "IndexMinHeap.h"


using namespace std;

template<typename Graph, typename Weight>
class PrimMST{
private:
    Graph &G;                     // 图的引用
    IndexMinHeap<Weight> ipq;     // 最小索引堆, 算法辅助数据结构
    vector<Edge<Weight>*> edgeTo; // 访问的点所对应的边, 算法辅助数据结构
    bool* marked;                 // 标记数组, 在算法运行过程中标记节点i是否被访问
    vector<Edge<Weight>> mst;     // 最小生成树所包含的所有边
    Weight mstWeight;             // 最小生成树的权值

    void visit( int v ){
        assert( !marked[v] );
        marked[v] = true;

        typename Graph::adjIterator adj(G,v);
        for( Edge<Weight>* e = adj.begin() ; !adj.end() ; e = adj.next() ) {
            int w = e->otherVertex(v);
            if( !marked[ w ] ){
                if( !edgeTo[ w ]){
                    ipq.insert(w, e->wt());
                    edgeTo[ w ] = e;
                }
                else if ( e->wt() < edgeTo[ w ]->wt() ){
                    ipq.change(w, e->wt());
                    edgeTo[ w ] = e;
                }
            }
        }
    }

public:
    PrimMST(Graph &graph): G(graph), ipq(IndexMinHeap<double>(graph.V())) {
        //initialisation
        marked = new bool[G.V()];
        for( int i = 0 ; i < G.V() ; i ++ ){
            marked[i] = false;
            edgeTo.push_back(NULL);
        }
        mst.clear();

        //Prim
        visit( 0 );
        while( !ipq.isEmpty() ){
            int v = ipq.extractMinIndex();
            assert( edgeTo[ v ] );
            mst.push_back( *edgeTo[ v ] );
            visit( v );
        }

        mstWeight = mst[0].wt();
        for( int i = 1 ; i < mst.size() ; i ++ )
            mstWeight += mst[i].wt();
    }

    ~PrimMST(){
        delete[] marked;
    }

    vector<Edge<Weight>> mstEdges(){
        return mst;
    };

    Weight result(){
        return mstWeight;
    };

};

#endif //INC_08_MST_PRIMMST_H
