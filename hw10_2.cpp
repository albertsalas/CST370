#include <iostream>
#include <vector>

using namespace std;

struct Record {
    int key;
    int state;

    explicit Record(int key) {
        this->key = key;
        this->state = 1;
    }
};

class HashTable {
public:
    vector<Record *> hashTable;
    int tableSize;
    int currentSize;

    explicit HashTable(int size) {
        hashTable.resize(size);
        tableSize = size;
        currentSize = 0;
    }

    void insertKey(int key) {
        auto *record = new Record(key);
        int hashedKey = hashFunction(key, tableSize);
        // check if bucket is occupied
        if (hashTable[hashedKey] == nullptr) {
            hashTable[hashedKey] = record;
            currentSize++;
        } else {
            // check if key at bucket is marked for deletion
            if (hashTable[hashedKey]->state == 0) {
                hashTable[hashedKey] = record;
            } else {
                // bucket has key already and is active, use linear probe
                int i = hashedKey + 1;
                if (i >= tableSize) {
                    i = 0;
                }
                while (i != hashedKey) {
                    if (hashTable[i] == nullptr || hashTable[i]->state == 0) {
                        hashTable[i] = record;
                        currentSize++;
                        break;
                    }
                    i++;
                    if (i >= tableSize) {
                        i = 0;
                    }
                }
            }
        }
        // check load factor
        if (currentSize > tableSize / 2) {
            // rehash
            rehash();
        }
    }

    void displayStatus(int bucket) const {
        if (hashTable[bucket] == nullptr) {
            cout << "Empty" << endl;
        } else {
            cout << hashTable[bucket]->key;
            if (hashTable[bucket]->state == 0) {
                cout << " Deleted";
            } else {
                cout << " Active";
            }
            cout << endl;
        }
    }

    void search(int key) const {
        cout << key;
        int hashedKey = hashFunction(key, tableSize);
        // if bucket has any key
        if (hashTable[hashedKey] != nullptr) {
            if (hashTable[hashedKey]->key == key) {
                if (hashTable[hashedKey]->state == 1) {
                    cout << " Found" << endl;
                } else {
                    cout << " Not found" << endl;
                }
                return;
            } else {
                // if bucket doesn't contain key, linear search values after bucket, looping back if necessary
                for (int i = hashedKey + 1; i != hashedKey; i++) {
                    if (hashTable[hashedKey]->key == key) {
                        if (hashTable[hashedKey]->state == 1) {
                            cout << " Found" << endl;
                        } else {
                            cout << " Not found" << endl;
                        }
                        return;
                    }
                    if (i >= tableSize) {
                        i = 0;
                    }
                }
            }
        }
        cout << " Not found" << endl;
    }

    void deleteKey(int key) {
        int hashedKey = hashFunction(key, tableSize);
        if (hashTable[hashedKey] == nullptr) {
            cout << key << " Not found";
        } else {
            if (hashTable[hashedKey]->key == key) {
                hashTable[hashedKey]->state = 0;
            } else {
                int i = hashedKey + 1;
                while (i != hashedKey) {
                    if (hashTable[i] != nullptr) {
                        if (hashTable[i]->key == key) {
                            hashTable[i]->state = 0;
                            currentSize--;
                            return;
                        }
                    }
                    i++;
                    if (i >= tableSize) {
                        i = 0;
                    }
                }
            }
        }
    }

private:
    static int hashFunction(int key, int size) {
        return key % size;
    }

    static bool isPrime(int value) {
        for (int i = 2; i < value; i++) {
            if (value % i == 0) {
                return false;
            }
        }
        return true;
    }

    static int doublePrimeNumber(int value) {
        int i = value * 2;
        while (i++) {
            if (isPrime(i)) {
                return i;
            }
        }
        return -1;
    }

    void rehash() {
        tableSize = doublePrimeNumber(tableSize);
        vector<Record *> newHashTable(tableSize);
        for (Record *r : hashTable) {
            if (r != nullptr) {
                int newBucket = hashFunction(r->key, tableSize);
                newHashTable[newBucket] = r;
            }
        }
        hashTable = newHashTable;
    }
};

int main() {
    int size;
    int numCommands;
    cin >> size >> numCommands;
    cin.ignore();
    HashTable hashTable = HashTable(size);
    vector<string> commands;
    for (int i = 0; i < numCommands; i++) {
        string command;
        getline(cin, command);
        commands.push_back(command);
    }
    for (const string &command : commands) {
        if (command.find("insert") != string::npos) {
            int key = stoi(command.substr(6, command.size()));
            hashTable.insertKey(key);
        } else if (command.find("displayStatus") != string::npos) {
            int bucket = stoi(command.substr(13, command.size()));
            hashTable.displayStatus(bucket);
        } else if (command.find("tableSize") != string::npos) {
            cout << hashTable.tableSize << endl;
        } else if (command.find("search") != string::npos) {
            int key = stoi(command.substr(6, command.size()));
            hashTable.search(key);
        } else {
            int key = stoi(command.substr(6, command.size()));
            hashTable.deleteKey(key);
        }
    }
    return 0;
}