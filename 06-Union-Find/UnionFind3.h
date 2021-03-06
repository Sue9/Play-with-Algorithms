//
// Created by Sue on 2019/1/15.
//

#ifndef INC_06_UNION_FIND_UNIONFIND3_H
#define INC_06_UNION_FIND_UNIONFIND3_H

#include <cassert>

namespace UF3{

    class UnionFind{
    private:
        int* parent;
        // sz[i] is the size of the tree whose root is i
        int* sz;
        int count;

    public:
        UnionFind(int n){
            parent = new int[ n ];
            sz = new int[ n ];
            for(int i = 0; i < n; i++){
                parent[ i ] = i;
                sz[ i ] = 1;
            }
        }

        ~UnionFind(){
            delete [] parent;
            delete [] sz;

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

            if( sz[ pRoot ] < sz[ qRoot ]){
                parent[ pRoot ] = qRoot;
                sz[ qRoot ] += sz[ pRoot ];
            }
            else{
                parent[ qRoot ] = pRoot;
                sz[ pRoot ] += sz[ qRoot ];
            }


        }

    };

}


#endif //INC_06_UNION_FIND_UNIONFIND3_H
