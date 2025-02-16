#include <iostream>
#include <list>
using namespace std;

class HashTable {
private:
    int capacity;
    list<int> *table;

    int hashFunction(int key) {
        return key % capacity;
    }

public:
    HashTable(int size) {
        this->capacity = size;
        table = new list<int>[capacity];
    }

    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void remove(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }

    bool search(int key) {
        int index = hashFunction(key);
        for (auto i : table[index]) {
            if (i == key)
                return true;
        }
        return false;
    }

    void display() {
        for (int i = 0; i < capacity; i++) {
            cout << "Index " << i << ": ";
            for (auto x : table[i]) {
                cout << x << " -> ";
            }
            cout << "NULL" << endl;
        }
    }

    ~HashTable() {
        delete[] table;
    }
};

int main() {
    HashTable ht(10);
    ht.insert(15);
    ht.insert(25);
    ht.insert(35);
    ht.insert(10);
    ht.insert(20);
    
    ht.display();
    
    cout << "Searching 25: " << (ht.search(25) ? "Found" : "Not Found") << endl;
    ht.remove(25);
    cout << "Searching 25 after removal: " << (ht.search(25) ? "Found" : "Not Found") << endl;
    
    ht.display();
    return 0;
}