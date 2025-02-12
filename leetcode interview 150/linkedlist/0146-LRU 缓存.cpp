
#include <unordered_map>
using namespace std;

// class Node {
//     int key, value;
//     Node *next, *prev;
//     Node(int key, int value) : key(key), value(value), next(nullptr), prev(nullptr) {}
//     Node(int key, Node *next, Node *prev) : val(x), next(next), prev(prev) {}
// };

class Node {
public:
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int key, int value) : key(key), value(value) {}

};


class LRUCache {
private:

    unordered_map<int, Node*> maps;
    Node *dummy;
    int capacity = 0, count = 0;
    
public:
    LRUCache(int capacity) {
        Node* head = new Node(0, 0);
        head->prev = head;
        head->next = head;

        this->dummy = head;
        this->capacity = capacity;
        this->count = 0;
    }
    
    int get(int key) {
        if(maps.count(key) == 0) {
            return -1;
        } else {
            Node* node = maps[key];
            node->prev->next = node->next;
            node->next->prev = node->prev;

            node->prev = dummy;
            node->next = dummy->next;
            node->next->prev = node;
            dummy->next = node;
            return node->value;
        }
    }
    
    void put(int key, int value) {
        if (maps.count(key) == 0) {
            if (count == capacity) {
                maps.erase(dummy->prev->key);

                dummy->key = key;
                dummy->value = value;
                maps[dummy->key] = dummy;

                dummy = dummy->prev;
            } else {
                Node* node = new Node(key, value);
                maps[key] = node;

                node->prev = dummy;
                node->next = dummy->next;
                node->next->prev = node;
                dummy->next = node;

                count++;
            }
        } else {
            Node* node = maps[key];
            node->value = value;
            node->prev->next = node->next;
            node->next->prev = node->prev;

            node->prev = dummy;
            node->next = dummy->next;
            node->next->prev = node;
            dummy->next = node;
        }
    }
};