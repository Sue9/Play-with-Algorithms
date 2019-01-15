//
// Created by Sue on 2019/1/15.
//

#ifndef INC_06_UNION_FIND_UNIONFIND4_H
#define INC_06_UNION_FIND_UNIONFIND4_H

#include <cassert>

namespace UF4{

    class UnionFind{
    private:
        int* parent;
        // rank[i] is the depth of the tree based on root i
        int* rank;
        int count;

    public:
        UnionFind(int n){
            parent = new int[ n ];
            rank = new int[ n ];
            for(int i = 0; i < n; i++){
                parent[ i ] = i;
                rank[ i ] = 1;
            }
        }

        ~UnionFind(){
            delete [] parent;
            delete [] rank;

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

            if(rank[ pRoot ] < rank[ qRoot ]){
                parent[ pRoot ] = qRoot;

            }
            else if(rank[ pRoot ] > rank[ qRoot ]){
                parent[ qRoot ] = pRoot;
            }
            else{ //rank[ pRoot ] = rank[ qRoot ]
                parent[ pRoot ] = qRoot;
                rank[ qRoot ] += 1;
            }


        }

    };

}


#endif //INC_06_UNION_FIND_UNIONFIND4_H
