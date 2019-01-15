//
// Created by Sue on 2019/1/15.
//

#ifndef INC_06_UNION_FIND_UNIONFIND2_H
#define INC_06_UNION_FIND_UNIONFIND2_H

#include <cassert>

namespace UF2{

    class UnionFind{
    private:
        int* parent;
        int count;

    public:
        UnionFind(int n){
            parent = new int[ n ];
            for(int i = 0; i < n; i++){
                parent[ i ] = i;
            }
        }

        ~UnionFind(){
            delete [] parent;
        }

        int find(int p){
            assert(p >= 0 && p < count);
            while( p != parent[ p ]){
                p = parent[ p ];

            }

            return p;
        }


        bool isConnected(int p, int q){
            return find(p) == find(q);
        }

        void unionElements(int p, int q){
            int pRoot = find( p );
            int qRoot = find( q );

            if( qRoot == pRoot )
                return;

            parent[ pRoot ] = qRoot;
        }

    };

}

#endif //INC_06_UNION_FIND_UNIONFIND2_H
