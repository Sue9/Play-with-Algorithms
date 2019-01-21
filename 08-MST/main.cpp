#include <iostream>
#include "DenseGraph.h"
#include "SparseGraph.h"
#include "ReadGraph.h"
#include <iomanip>
#include "LazyPrimMST.h"
#include "PrimMST.h"

using namespace std;

int main() {

    /*
     * test chap 8-3 lazy prim
     */

    string filename = "testG1.txt";
    int V = 8;

    SparseGraph<double> g = SparseGraph<double>(V, false);
    ReadGraph<SparseGraph<double>, double> readGraph(g, filename);

    // Test for Lazy Prim MST
    cout<<"Test Lazy Prim MST"<<endl;
    LazyPrimMST<SparseGraph<double>, double> lasyPrimMST( g );
    vector<Edge<double>> mst = lasyPrimMST.mstEdges();
    for( int i = 0; i < mst.size(); i++ )
        cout<<mst[i]<<endl;
    cout<<"The MST weight is: " << lasyPrimMST.result()<<endl;
    cout<<endl;

    // Test Prim MST
    cout<<"Test Prim MST:"<<endl;
    PrimMST<SparseGraph<double>, double> primMST(g);
    mst = primMST.mstEdges();
    for( int i = 0 ; i < mst.size() ; i ++ )
        cout<<mst[i]<<endl;
    cout<<"The MST weight is: "<<primMST.result()<<endl;

    cout<<endl;


    /*
     * test chap 8-2
     *
     *
    string filename = "testG1.txt";
    int V = 8;
    cout<<fixed<<setprecision(2);

    //Test Weighted Dense Graph
    DenseGraph<double> g1 = DenseGraph<double>(V, false);
    ReadGraph<DenseGraph<double>, double> readGraph1(g1, filename);
    g1.show();
    cout<<endl;

    //Test Weighted Sparse Graph
    SparseGraph<double> g2 = SparseGraph<double>(V, false);
    ReadGraph<SparseGraph<double>, double> readGraph2(g2, filename);
    g2.show();
    cout<<endl;
     *
     *
     *
     */


    return 0;
}