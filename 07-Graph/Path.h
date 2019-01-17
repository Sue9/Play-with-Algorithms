//
// Created by Sue on 2019/1/17.
//

#ifndef INC_07_GRAPH_PATH_H
#define INC_07_GRAPH_PATH_H


#include <iostream>
#include <cassert>
#include <vector>
#include <stack>

using namespace std;

template <typename Graph>
class Path{
private:
    Graph &G;
    // s stands for 'source'
    int s;
    bool* visited;
    int* from;

    void dfs( int v ){
        visited[ v ] = true;
        cout << "visiting: " << v << endl;
        typename Graph::adjIterator adj(G, v);
        for(int i = adj.begin(); ! adj.end(); i = adj.next()){
            if( !visited[ i ] ) {
                // the vertex i we are visiting, comes from vertex v

                from[i] = v;
                dfs(i);
            }
        }
    }


public:
    Path(Graph &graph, int s): G(graph){
        assert( s >= 0 && s < G.V() );

        visited = new bool[ G.V() ];
        from = new int[ G.V() ];
        for( int i = 0; i < G.V(); i++ ){
            visited[ i ] = false;
            from[ i ] = -1;
        }

        this -> s = s;

        // Algorithm: find path
        dfs( s );
    }

    ~Path(){
        delete [] visited;
        delete [] from;
    }

    // check if there exists path from source s to vertex w
    bool hasPath( int w ){
        assert( w >= 0 && w < G.V() );
        return visited[ w ];
    }

    void path( int w, vector<int> &vec ){
        assert( hasPath(w) );

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
};
#endif //INC_07_GRAPH_PATH_H
