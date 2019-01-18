//
// Created by Sue on 2019/1/18.
//

#ifndef INC_07_GRAPH_SHORTESTPATH_H
#define INC_07_GRAPH_SHORTESTPATH_H

#include <queue>
#include <stack>
#include <iostream>

using namespace std;

template <typename Graph>
class ShortestPath{

private:
    Graph &G;
    int s;
    bool* visited;
    int* from;
    // ord is used to record the shortest distance from s to vertex
    int* ord;

public:
    ShortestPath(Graph &graph, int s): G(graph){
        assert( s >= 0 && s < G.V() );

        visited = new bool[ G.V() ];
        from = new int[ G.V() ];
        ord = new int[ G.V() ];
        for( int i = 0; i < G.V(); i++ ){
            visited[ i ] = false;
            from[ i ] = -1;
            ord[ i ] = -1;
        }
        this -> s = s;

        queue<int> q;

        // breadth-first-search
        q.push( s );
        visited[ s ] = true;
        ord[ s ] = 0;

        while ( !q.empty() ){
            int v = q.front();
            q.pop();

            typename Graph::adjIterator adj(G, v);
            for( int i = adj.begin(); !adj.end(); i = adj.next() ){
                if( !visited[ i ]){
                    q.push( i );
                    visited[ i ] = true;
                    from[ i ] = v;
                    ord[ i ] = ord[ v ] + 1;
                }
            }
        }
    }

    ~ShortestPath(){
        delete [] visited;
        delete [] from;
        delete [] ord;
    }

    bool hasPath( int w ){
        assert( w >= 0 && w < G.V() );
        return visited[ w ];
    }

    void path( int w, vector<int> &vec ){
        assert( w >= 0 && w < G.V() );
        stack<int> st;

        int p = w;
        while( p != -1 ){
            st.push( p );
            p = from[ p ];
        }

        vec.clear();
        while( !st.empty() ){
            vec.push_back( st.top() );
            st.pop();
        }
    }

    // print the path, from s to w
    void showPath( int w ){
        vector<int> vec;
        path( w, vec );
        for( int i = 0; i < vec.size(); i++ ){
            cout << vec[ i ];
            if( i == vec.size() - 1 )
                cout << endl;
            else
                cout << " -> ";
        }

    }

    int length( int w ){
        assert( w >= 0 && w < G.V() );
        return ord[ w ];
    }

};


#endif //INC_07_GRAPH_SHORTESTPATH_H
