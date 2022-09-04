#include <bits/stdc++.h>
using namespace std;

#define ll long long int

void file_i_o()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
/*
LRU cache: This is a data structure which can store two elements key and a corresponding value.
It keeps track of the least recently used element and deletes it if the data structure is full, and it wants to 
insert new key,value pair.

*/
class LRU_cache {
    public:
    class node{
        public:
        int key;
        int value;
        node* next;
        node* prev;
/*  Constructor for node            */
        node(int k, int v){
            key = k;
            value = v;
            next = NULL;
            prev = NULL;
        }

    };

    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
    node* traverse = head;

    int cap;
    unordered_map<int, node*> mp;

/* Constructor for LRU_cache        */
    LRU_cache(int capacity){
        cap = capacity;
        head->next = tail;
        tail->prev = head;

    }
/*    Adding a node just after head           */ 
    void addNode_afterHead(node* newNode){
        node* temp = new node(0,0);
        temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        temp->prev = newNode;
        head->next = newNode;
    }
/*     Deleting a node                 */

    void deleteNode(node* delnode){
        node* delprev = new node(0,0);
        delprev = delnode->prev;
        node* delnext = delnode->next;

        delprev->next = delnext;
        delnext->prev = delprev;
    }
/*  get operaton    */
    int getEle(int _key){
        if(mp.find(_key) == mp.end()) return -1;
        node* resNode = mp[_key];
        int result = resNode->value;
        deleteNode(resNode);
        addNode_afterHead(resNode);
        mp.erase(_key);
        mp[_key] = head->next;

        return result;
    }

/*  Put the new node after head by eleminating less recently used node      */
    void put(int key, int value){
        node* newNode = new node(key, value);
        if(mp.find(key) != mp.end()){
            deleteNode(mp[key]);
            mp.erase(key);
        }

        if(cap == mp.size()){
            int tail_prev_key = tail->prev->key;
            mp.erase(tail_prev_key);
            deleteNode(tail->prev);
        }
        addNode_afterHead(newNode);
        mp[key] = head->next;

    }    
};

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    LRU_cache L(3);
    L.put(5,5);
    L.put(6,6);
    L.put(8,8);
    cout<<L.getEle(5)<<endl;
    L.put(10, 10);
    cout<<L.getEle(6)<<endl;
    cout<<L.getEle(10)<<endl;


/*  Displaying every element in LRU cache          */ 
    L.traverse = L.traverse->next;
    while(L.traverse != L.tail){
        cout<<L.traverse->key<<" "<<L.traverse->value<<endl;
        L.traverse = L.traverse->next;
    }




#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n Executed In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}