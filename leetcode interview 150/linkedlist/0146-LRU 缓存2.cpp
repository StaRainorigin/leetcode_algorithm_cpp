#include <unordered_map>
using namespace std;

// 还有点问题

class Node {
public:
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int key, int value) : key(key), value(value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, Node*> maps; // 哈希表，存储键值对
    Node* dummy;                   // 哨兵节点，简化链表操作
    int capacity;                  // 缓存容量

    // 将节点移动到链表头部
    void moveToHead(Node* node) {
        // 从原位置移除节点
        node->prev->next = node->next;
        node->next->prev = node->prev;

        // 将节点插入到链表头部
        node->prev = dummy;
        node->next = dummy->next;
        node->next->prev = node;
        dummy->next = node;
    }

    // 移除链表尾部节点
    void removeTail() {
        Node* tail = dummy->prev;
        maps.erase(tail->key); // 从哈希表中移除
        tail->prev->next = dummy; // 更新链表
        dummy->prev = tail->prev;
        delete tail; // 释放内存
    }

public:
    LRUCache(int capacity) : capacity(capacity) {
        dummy = new Node(-1, -1); // 初始化哨兵节点
        dummy->prev = dummy;
        dummy->next = dummy;
    }

    int get(int key) {
        if (maps.count(key)) {
            Node* node = maps[key];
            moveToHead(node); // 将节点移动到链表头部
            return node->value;
        }
        return -1; // 键不存在
    }

    void put(int key, int value) {
        if (maps.count(key)) {
            // 如果键已存在，更新值并移动到链表头部
            Node* node = maps[key];
            node->value = value;
            moveToHead(node);
        } else {
            // 如果缓存已满，移除尾部节点
            if (maps.size() == capacity) {
                removeTail();
            }
            // 创建新节点并插入到链表头部
            Node* node = new Node(key, value);
            maps[key] = node;
            moveToHead(node);
        }
    }
};