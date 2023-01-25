#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
    protected:
        map<int, Node*> mp; //map the key to the node in the linked list
        // unordered_map<int, Node*> mp; //map the key to the node in the linked list
        int cp;  //capacity
        Node* tail; // double linked list tail pointer
        Node* head; // double linked list head pointer
        virtual void set(int, int) = 0; //set function
        virtual int get(int) = 0; //get function
};

class LRUCache : public Cache{
    public:
        int counter, size;
        LRUCache(int capacity){
            cp = capacity;
            // counter = 0;
            size = 0;
            head = NULL;
            tail = NULL;
        }
        void set(int key, int value){
            if (mp.find(key) == mp.end()){
                if (size == cp){
                    int x = dequeue();
                    mp.erase(x);
                }
            }
            else{
                delete_by_node(mp[key]);
                // delete_by_key(key);
            }
            enqueue(key, value);
            mp[key] = {tail};
        }
        void enqueue(int key, int value){
            Node* temp = new Node(key, value);
            if (head == NULL || tail == NULL){
                head = tail = temp;
            }
            else{
                tail->next = temp;
                temp->prev = tail;
                tail = tail->next;
            }
            size++;
        }
        int dequeue(){
            if (head == NULL || tail == NULL){
                return -1;
            }
            else if (head == tail){
                int x = head->key;
                delete head;
                head = NULL;
                tail = NULL;
                size--;
                return x;
            }
            else{
                int x = head->key;
                head = head->next;
                delete head->prev;
                head->prev = NULL;
                size--;
                return x;
            }
        }
        void delete_by_node(Node* temp){
            if (temp == head){
                dequeue();
            }
            else if (temp == tail){
                tail = tail->prev;
                delete tail->next;
                tail->next = NULL;
            }
            else{
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
            }
            size--;
        }
        /*
        void delete_by_key(int key){
            if (head->key == key){
                dequeue();
            }
            else if (tail->key == key){
                tail = tail->prev;
                delete tail->next;
                tail->next = NULL;
            }
            else{
                Node* current = head;
                while (current->key != key){
                    current = current->next;
                }
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
            }
            size--;
        }
        */
        /*
        void set(int key, int value){
            Node* temp = new Node(key, value);
            if (head == NULL){
                head = temp;
                mp.insert({key, temp});
                counter++;
            }
            else{
                if (counter < cp){
                    Node* current = head;
                    while (current->next != NULL)
                        current = current->next;
                    current->next = new Node(current, NULL, current->key, current->value);
                    tail = current->next;
                    while (current != head){
                        current->key = current->prev->key;
                        current->value = current->prev->value;
                        current = current->prev;
                    }
                    current = temp;
                    mp.insert({key, temp});
                    counter++;
                }
                else{
                    Node* current = tail;
                    mp.erase(current->key);
                    for(int i=1; i<cp; i++){
                        current->key = current->prev->key;
                        current->value = current->prev->value;
                        current = current->prev;
                    }
                    current = temp;
                    mp.insert({key, temp});
                    counter++;
                }
            }
        }
        */
        int get(int key){
            auto it = mp.find(key);
            if (it == mp.end()){
                return -1;
            }
            else{
                return it->second->value;
            }
        }
};

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}