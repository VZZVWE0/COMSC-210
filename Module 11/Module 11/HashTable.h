// Programmer: Dhanush Patel
// Programmer's ID: 1553428

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <list>
#include <queue>

using namespace std;

template <typename K, typename V, int CAP>
class HashTable {
    struct Node
    {
        K key;
        V value;
    };

    list<Node> data[CAP];
    int(*hashCode)(const K&); 
    int siz;
    Node dummy;

public:
    HashTable(int(*)(const K&) = 0);
    double loadFactor() const { return 1.0 * siz / CAP; }
    V operator[](const K& key) const;
    V& operator[](const K&); 
    bool containsKey(const K&) const; 
    void deleteKey(const K&); 
    int size() const { return siz; }
    void clear();
    queue<K> keys() const;
    
};

template <typename K, typename V, int CAP>
HashTable<K, V, CAP>::HashTable(int(*p)(const K&)) {
    siz = CAP;
    hashCode = p;
}

template <typename K, typename V, int CAP> 
void HashTable<K, V, CAP>::clear() {
    for (int i = 0; i < siz; i++) {
        data[i].clear();
    }
}

template <typename K, typename V, int CAP>
V HashTable<K, V, CAP>::operator[](const K& key) const {
    int index = hashCode(key) % CAP;
    if (index < 0) index += CAP;
    typename list<Node>::const_iterator it;
    for (it = data[index].begin(); it != data[index].end(); it++) {
        if (it->key == key) {
            return it->value;
        }
    }
    return V();
}

template <typename K, typename V, int CAP>
V& HashTable<K, V, CAP>::operator[](const K& key) {
    int index = hashCode(key) % CAP;
    if (index < 0) index += CAP;
    typename list<Node>::iterator it;
    for (it = data[index].begin(); it != data[index].end(); it++) {
        if (it->key == key) {
            return it->value;
        }
    }
    Node temp = { key, V() };
    data[index].push_back(temp);
    siz++;
    return data[index].back().value;
}

template <typename K, typename V, int CAP> 
void HashTable<K, V, CAP>::deleteKey(const K& key) {
    int index = hashCode(key) % CAP;
    if (index < 0) index += CAP;
    typename list<Node>::iterator it;
    for (it = data[index].begin(); it != data[index].end(); it++) {
        if (it->key == key)
            break;
    }
    if (it != data[index].end()) {
        data[index].erase(it);
        siz--;
    }
}

template <typename K, typename V, int CAP>
bool HashTable<K, V, CAP>::containsKey(const K& key) const {

    int index = hashCode(key) % CAP;
    if (index < 0) index += CAP;
    typename list<Node>::const_iterator it; 
    for (it = data[index].begin(); it != data[index].end(); it++) {
        if (it->key == key) {
            return true;
        }
    }

    return false; 
}

template <typename K, typename V, int CAP>
queue<K> HashTable<K, V, CAP>::keys() const {
    queue<K> q;
    typename list<Node>::const_iterator it;
    for (int i = 0; i < siz; i++) {
        for (it = data[i].begin(); it != data[i].end(); ++it) {
            q.push(it->key);
        }
    }
    return q;
}

#endif HASHTABLE_H

