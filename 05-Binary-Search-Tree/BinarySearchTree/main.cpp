#include <iostream>
#include <stdio.h>
#include <malloc.h>
#include <vector>
#include <time.h>
#include <queue>
#include <cassert>
#include "FileOps.h"
#include "SequenceST.h"

using namespace std;

template <typename Key, typename Value>
class BST{

private:
    struct Node{
        Key key;
        Value value;
        Node *left;
        Node *right;

        Node(Key key, Value value){
            this->key = key;
            this->value = value;
            this->left = this->right = NULL;
        }

        Node(Node* node){
            this -> key   = node -> key;
            this -> value = node -> value;
            this -> left  = node -> left;
            this -> right = node -> right;
        }
    };

    Node *root;
    //record how many node this tree has
    int count;

public:
    BST(){
        root = NULL;
        count = 0;
    }
    ~BST(){
        // TODO: ~BTS()
        destroy(root);

    }

    int size(){
        return count;
    }

    bool isEmpty(){
        return count == 0;
    }

    void insert(Key key, Value value){
        root = insert(root, key, value);
    }

    // check if the tree contains given key
    bool contain(Key key){
        return contain(root, key);
    }

    Value* search(Key key){
        return search(root, key);
    }


    void preOrder(){
        preOrder(root);
    }

    void inOrder(){
        inOrder(root);
    }

    void postOrder(){
        postOrder(root);
    }

    // breadth first search
    void levelOrder(){
        queue<Node*> q;
        q.push(root);
        while( !q.empty() ){
            Node* node = q.front();
            q.pop();
            cout << node->key << endl;
            if(node->left )
//                q.push(&(node->left));
                q.push(node->left);
            if(node->right )
//                q.push(&(node->right));
                q.push(node->right);
        }
    }

    // return min key
    Key minimum(){
        assert( count != 0 );

        Node* node = minimum( root );
        return (node -> key);
    }

    Key maximum(){
        assert( count != 0);

        Node* node = maximum( root );
        return (node -> key);
    }

    void removeMin(){
        if ( root ){
            root = removeMin( root );
        }
    }

    void removeMax(){
        if( root ){
            root = removeMax( root );
        }
    }


    void remove(Key key){
//        assert(contain(key));
        root = remove(root, key);
    }


private:
    // insert (key, value) into node
    // return new tree
    Node* insert(Node *node, Key key, Value value){
        if( node == NULL ){
            count ++;
            return new Node(key, value);
        }

        if( key == node -> key )
            node -> value = value;
        else if( key < node -> key )
            node -> left = insert(node -> left, key, value);
        else // key > node -> key
            node -> right = insert(node -> right, key, value);

        return node;
    }

    bool contain(Node* node, Key key){
        if( node == NULL )
            return false;

        if(key == node -> key)
            return true;
        else if(key < node -> key)
            return contain(node -> left, key);
        else
            return contain(node -> right, key);
    }


    Value* search(Node* node, Key key){
        if( node == NULL )
            return NULL;

        if( key == node -> key )
            return &(node -> value);
        else if( key < node -> key )
            return search(node -> left, key);
        else
            return search(node -> right, key);
    }


    void preOrder(Node* node){
        if( node != NULL ){
            cout << node -> key << endl;
            preOrder(node -> left);
            preOrder(node -> right);

        }
    }

    void inOrder(Node* node){
        if( node != NULL ){
            inOrder(node -> left);
            cout << node -> key << endl;
            inOrder(node -> right);

        }
    }


    void postOrder(Node* node){
        if( node != NULL ){
            postOrder(node -> left);
            postOrder(node -> right);
            cout << node -> key << endl;

        }
    }

    void destroy(Node* node){
        if( node != NULL ){
            destroy(node -> left);
            destroy(node -> right);

            delete node;
            count --;
        }
    }

    Node* minimum(Node* node){
        if( node -> left == NULL )
            return node;

        return minimum(node -> left);
    }


    Node* maximum(Node* node){
        if( node -> right == NULL )
            return node;

        return maximum(node -> right);
    }


    Node* removeMin(Node* node){
        if( node -> left == NULL ){
            Node* rightNode = node -> right;
            delete node;
            count --;
            return rightNode;
        }

        node -> left = removeMin( node->left );
        return node;
    }


    Node* removeMax(Node* node){
        if( node -> right == NULL ){
            Node* leftNode = node -> left;
            delete node;
            count --;
            return leftNode;
        }

        node -> right = removeMax( node -> right );
        return node;
    }

    Node* remove(Node* node, Key key){
        if( node == NULL )
            return NULL;

        if( key < node -> key ){
            node -> left = remove( node -> left, key );
            return node;
        }
        else if( key > node -> key ){
            node -> right = remove( node -> right, key );
            return node;
        }
        else{   // key == node -> key
            if( node -> left == NULL ){
                Node* rightNode = node -> right;
                delete node;
                count --;
                return rightNode;
            }
            else if ( node -> right == NULL ){
                Node* leftNode = node -> left;
                delete node;
                count --;
                return leftNode;
            }
            else{ // have both left and right child
                Node* s = new Node(minimum(node -> right));
                count ++;
                s -> left = node -> left;
                s -> right = removeMin(node -> right);
                return s;

            }
        }
    }

};



int main() {

    // 使用圣经作为我们的测试用例
    string filename = "bible.txt";
    vector<string> words;
    if( FileOps::readFile(filename, words) ) {

        cout << "There are totally " << words.size() << " words in " << filename << endl;
        cout << endl;


        // 测试 BST
        time_t startTime = clock();

        // 统计圣经中所有词的词频
        // 注: 这个词频统计法相对简陋, 没有考虑很多文本处理中的特殊问题
        // 在这里只做性能测试用
        BST<string, int> bst = BST<string, int>();
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = bst.search(*iter);
            if (res == NULL)
                bst.insert(*iter, 1);
            else
                (*res)++;
        }

        // 输出圣经中god一词出现的频率
        if(bst.contain("god"))
            cout << "'god' : " << *bst.search("god") << endl;
        else
            cout << "No word 'god' in " << filename << endl;

        time_t endTime = clock();

        cout << "BST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
        cout << endl;


        // 测试顺序查找表 SST
        startTime = clock();

        // 统计圣经中所有词的词频
        // 注: 这个词频统计法相对简陋, 没有考虑很多文本处理中的特殊问题
        // 在这里只做性能测试用
        SequenceST<string, int> sst = SequenceST<string, int>();
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = sst.search(*iter);
            if (res == NULL)
                sst.insert(*iter, 1);
            else
                (*res)++;
        }

        // 输出圣经中god一词出现的频率
        if(sst.contain("god"))
            cout << "'god' : " << *sst.search("god") << endl;
        else
            cout << "No word 'god' in " << filename << endl;

        endTime = clock();

        cout << "SST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
    }


    return 0;
}