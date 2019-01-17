#include <iostream>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include <ctime>
#include "ReadGraph.h"
#include "Component.h"
#include "Path.h"

using namespace std;

int main() {


    string filename = "testG2.txt";
    SparseGraph g = SparseGraph(7, false);
    ReadGraph<SparseGraph> readGraph(g, filename);
    g.show();
    cout<<endl;

    Path<SparseGraph> path(g, 0);
    cout<<"DFS : " << endl;
    path.showPath(6);


    /*
     * chap 7 - 5
     * Test for component
     *

    // TestG1.txt - g1 and g2
    string filename1 = "testG1.txt";
    SparseGraph g1 = SparseGraph(13, false);
    ReadGraph<SparseGraph> readGraph1(g1, filename1);
    Component<SparseGraph> component1(g1);
    cout<<"TestG1.txt, Using Sparse Graph, Component Count: "<<component1.count()<<endl;

    cout<<endl;

    // TestG2.txt - g3 and g4
    string filename2 = "testG2.txt";
    SparseGraph g3 = SparseGraph(7, false);
    ReadGraph<SparseGraph> readGraph3(g3, filename2);
    Component<SparseGraph> component3(g3);
    cout<<"TestG2.txt, Using Sparse Graph, Component Count: "<<component3.count()<<endl;




     */




    /*
     * chap 7 - 4
     * Test for ReadGraph
     *
     *
     *
    string filename = "testG1.txt";
    SparseGraph g1( 13, false );
    ReadGraph<SparseGraph> readGraph1( g1, filename );
    g1.show();

    cout << endl;

    DenseGraph g2( 13, false );
    ReadGraph<DenseGraph> readGraph2( g2, filename );
    g2.show();

     */




    /*
     * chap 7 - 3
     * Test for sparse graph and dense graph
     *


    int N = 20;
    int M = 100;

    srand( time(NULL) );


    // Sparse Graph
    SparseGraph g1(N , false);
    for( int i = 0 ; i < M ; i ++ ){
        int a = rand()%N;
        int b = rand()%N;
        g1.addEdge( a , b );
    }

    // O(E)
    for( int v = 0 ; v < N ; v ++ ){
        cout<<v<<" : ";
        SparseGraph::adjIterator adj( g1 , v );
        for( int w = adj.begin() ; !adj.end() ; w = adj.next() )
            cout<<w<<" ";
        cout<<endl;
    }

    cout<<endl;


    // Dense Graph
    DenseGraph g2(N , false);
    for( int i = 0 ; i < M ; i ++ ){
        int a = rand()%N;
        int b = rand()%N;
        g2.addEdge( a , b );
    }

    // O(V^2)
    for( int v = 0 ; v < N ; v ++ ){
        cout<<v<<" : ";
        DenseGraph::adjIterator adj( g2 , v );
        for( int w = adj.begin() ; !adj.end() ; w = adj.next() )
            cout<<w<<" ";
        cout<<endl;
    }


     */


    return 0;
}