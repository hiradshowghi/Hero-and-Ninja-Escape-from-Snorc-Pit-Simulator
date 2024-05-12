#ifndef LIST_H
#define LIST_H

template <typename T>
class List {
private:
    struct Node {
        T* data;
        Node* next;
        Node(T* item) : data(item), next(nullptr) {}
    };
    Node* head;

public:
    List();
    ~List();
    List<T>& operator+=(T* item);
    void convertToArray(T**& arr, int& size) const;
};

#endif 
