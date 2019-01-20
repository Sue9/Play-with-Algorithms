//
// Created by Sue on 19/01/2019.
//

#ifndef INC_08_MST_EDGE_H
#define INC_08_MST_EDGE_H

#include <iostream>

using namespace std;

template <typename Weight>
class Edge{
private:
    int a, b;
    Weight weight;

public:
    Edge( int a, int b, Weight weight ){
        this -> a = a;
        this -> b = b;
        this -> weight = weight;
    }

    Edge(){}

    ~Edge(){

    }

    // get two vertexes and its weight
    int v() { return a; }

    int w() { return b; }

    Weight wt() { return weight; }

    // get the other vertex of given vertex and edge
    int otherVertex( int x ){
        assert( x == a || x == b );
        return x == a ? b : a;
    }

    friend ostream& operator<<(ostream &os, const Edge &e) {
        os<<e.a<<"-"<<e.b<<": "<<e.weight;
        return os;
    }

    bool operator<(Edge<Weight>&e){
        return weight < e.wt();
    }

    bool operator<=(Edge<Weight>&e){
        return weight <= e.wt();
    }

    bool operator>(Edge<Weight>&e){
        return weight > e.wt();
    }

    bool operator>=(Edge<Weight>&e){
        return weight >= e.wt();
    }

    bool operator==(Edge<Weight>&e){
        return weight == e.wt();
    }


};

#endif //INC_08_MST_EDGE_H
