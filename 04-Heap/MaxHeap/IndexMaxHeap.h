//
// Created by zhaoxu on 2018/12/26.
//

#ifndef MAXHEAP_INDEXMAXHEAP_H
#define MAXHEAP_INDEXMAXHEAP_H


using namespace std;

template <typename Item>
class IndexMaxHeap{
private:
    Item* data;
    //new array to store indexes
    int* indexes;
    int* reverse;
    int count;
    int capacity;

    //k is index
    void shiftUp(int k){
        while(k > 1 && data[indexes[k]] > data[indexes[k / 2]]){
            swap(indexes[k], indexes[k / 2]);
            reverse[indexes[k]] = k;
            reverse[indexes[k / 2]] = k / 2;
            k /= 2;
        }
    }

    void shiftDown(int k){
        while(2*k <= count){
            //assume change the position with j
            int j = 2 * k;
            //if it has the right child & right child node > left child node
            //then we'd chose right child node, which to chose the larger one
            if(j + 1 <= count && data[indexes[j]] < data[indexes[j + 1]]){
                j += 1;
            }

            //if the father node is the largest, stop the loop here
            if(data[indexes[k]] >= data[indexes[j]])
                break;

            swap(indexes[k], indexes[j]);
            reverse[indexes[k]] = k;
            reverse[indexes[j]] = j;
            k = j;

        }
    }






public:
    IndexMaxHeap(int capacity){
        data = new Item[capacity + 1];
        indexes = new int[capacity + 1];
        reverse = new int[capacity + 1];
        for(int i = 0; i <= capacity; i ++){
            reverse[i] = 0;
        }

        count = 0;
        this -> capacity = capacity;
    }



    ~IndexMaxHeap(){
        delete [] data;
        delete [] indexes;
        delete [] reverse;
    }


    int size(){
        return count;
    }

    bool isEmpty(){
        return count == 0;
    }

    //for users, index i starts from 0
    //for our heap, index i starts from 1, we need to deal with it here
    //user indicates to insert item on index i
    void insert(int i, Item item){
        assert( count + 1 <= capacity );
        assert( i + 1 >= 1 && i + 1 <= capacity );
        i += 1;


        data[i] = item;
        indexes[count + 1] = i;
        reverse[i] = count+1;
        count ++;
        shiftUp( count );

    }


    Item extractMax(){
        assert( count > 0 );
        Item ret = data[indexes[1]];

        swap(indexes[1] , indexes[count]);
        reverse[indexes[1]] = 1;
        reverse[indexes[count]] = 0;
        count --;

        shiftDown( 1 );

        return ret;
    }


    int extractMaxIndex(){
        assert(count > 0);
        int ret = indexes[1] - 1;

        swap(indexes[1], indexes[count]);
        reverse[indexes[1]] = 1;
        reverse[indexes[count]] = 0;
        count --;

        shiftDown( 1 );
        return ret;
    }

    bool contain(int i){
        assert(i >= 0 && i + 1 <= capacity);
        return reverse[i+1] != 0;
    }

    Item getItem(int i){
        assert( contain(i) );
        return data[i+1];
    }

    void change(int i, Item newItem){
        //we should assure, index i is in the heap
        assert( contain(i) );
        i += 1;

        data[i] = newItem;
        //find indexes[j] = i, j means where data[i] is in the heap
        //then shiftUp(j), shiftDown(j)
//        for(int j = 1; j <= count; j++){
//            if (indexes[j] == i){
//                shiftUp(j);
//                shiftDown(j);
//            }
//
//        }

        int j = reverse[i];
        shiftUp(j);
        shiftDown(j);


    }

};


#endif //MAXHEAP_INDEXMAXHEAP_H
