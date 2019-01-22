//
// Created by Sue on 2019/1/22.
//

#ifndef INC_09_SHORTESTPATH_DIJKSTRA_H
#define INC_09_SHORTESTPATH_DIJKSTRA_H

#include <iostream>
#include <vector>
#include <stack>
#include "Edge.h"
#include "IndexMinHeap.h"

using namespace std;

template <typename Graph, typename Weight>
class Dijkstra{
private:
    Graph &G;
    // s: source
    int s;
    bool *marked;
    // results
    Weight *distTo;
    vector<Edge<Weight>*> from;


public:
    Dijkstra(Graph &graph, int s): G(graph){
        this -> s = s;

        marked = new bool[G.V()];
        distTo = new Weight[G.V()];
        for( int i = 0; i < G.V(); i++ ){
            marked[ i ] = false;
            distTo[ i ] = Weight(); //default constructor of this type Weight
            from.push_back( NULL );
        }

        IndexMinHeap<Weight> ipq( G.V() );

        //Dijkstra
        distTo[ s ] = Weight();
        marked[ s ] = true;
        from[ s ] = new Edge<Weight>(s, s, Weight());

        ipq.insert( s, distTo[ s ] );
        while( !ipq.isEmpty() ){
            int v = ipq.extractMinIndex();
            // distTo[ v ] is the shortest path from s to v
            marked[ v ] = true;

            // Relaxation
            typename Graph::adjIterator adj(G, v);
            for( Edge<Weight>* e = adj.begin(); !adj.end(); e = adj.next() ){
                int w = e -> otherVertex( v );
                if( !marked[ w ] ){
                    if( from[ w ] == NULL || distTo[ w ] > distTo[ v ] + e->wt() ){
                        distTo[ w ] = distTo[ v ] + e->wt();
                        from[ w ] = e;

                        if( ipq.contain( w ) )
                            ipq.change( w, distTo[ w ] );
                        else
                            ipq.insert( w, distTo[ w ] );
                    }


                }
            }
        }
    }

    ~Dijkstra(){
        delete [] marked;
        delete [] distTo;
    }

    Weight shortestPathTo( int w ){
        return distTo[ w ];
    }

    bool hasPathTo( int w ){
        return marked[ w ];
    }

    // 寻找从s到w的最短路径, 将整个路径经过的边存放在vec中
    void shortestPath( int w, vector<Edge<Weight>> &vec ){

        assert( w >= 0 && w < G.V() );
        assert( hasPathTo(w) );

        // 通过from数组逆向查找到从s到w的路径, 存放到栈中
        stack<Edge<Weight>*> s;
        Edge<Weight> *e = from[w];
        while( e->v() != this->s ){
            s.push(e);
            e = from[e->v()];
        }
        s.push(e);

        // 从栈中依次取出元素, 获得顺序的从s到w的路径
        while( !s.empty() ){
            e = s.top();
            vec.push_back( *e );
            s.pop();
        }
    }

    // 打印出从s点到w点的路径
    void showPath(int w){

        assert( w >= 0 && w < G.V() );
        assert( hasPathTo(w) );

        vector<Edge<Weight>> vec;
        shortestPath(w, vec);
        for( int i = 0 ; i < vec.size() ; i ++ ){
            cout<<vec[i].v()<<" -> ";
            if( i == vec.size()-1 )
                cout<<vec[i].w()<<endl;
        }
    }

};

#endif //INC_09_SHORTESTPATH_DIJKSTRA_H
