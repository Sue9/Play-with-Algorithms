//
// Created by Sue on 2019/1/16.
//

#ifndef INC_07_GRAPH_READGRAPH_H
#define INC_07_GRAPH_READGRAPH_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cassert>

using namespace std;

template <typename Graph, typename Weight>
class ReadGraph{
public:
    ReadGraph(Graph &graph, const string &filename){
        ifstream file(filename);
//        ifstream file;
//        file.open(filename);
        string line;
        int V, E;


        assert( file.is_open() );
        assert( getline(file, line) );
        stringstream ss( line );

        ss>>V>>E;
//        cout << "graph.V() = " << graph.V() << endl;
//        cout << "V = " << V << endl;
        assert( V == graph.V() );

        for( int i = 0; i < E; i++ ){
            assert( getline(file, line) );
            stringstream ss(line);

            int a, b;
            Weight w;
            ss>>a>>b>>w;
            assert( a>= 0 && a < V);
            assert( b>= 0 && b < V);

            graph.addEdge( a, b, w );

        }
    }
};

#endif //INC_07_GRAPH_READGRAPH_H
