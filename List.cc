template <typename T>
List<T>::List() : head(nullptr) {}

template <typename T>
List<T>::~List() {
    Node* currNode = head, *nextNode;
    while (currNode != nullptr) {
        nextNode = currNode->next;
        delete currNode->data; 
        delete currNode;
        currNode = nextNode;
    }
}

template <typename T>
List<T>& List<T>::operator+=(T* item) {
    Node* newNode = new Node(item);
    if (!head || head->data > item) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* curr = head;
        while (curr->next && !(curr->next->data > item)) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
    return *this;
}

template <typename T>
void List<T>::convertToArray(T**& arr, int& size) const {
    size = 0;
    Node* temp = head;
    while (temp != nullptr) {
        size++;
        temp = temp->next;
    }

    arr = new T*[size];
    Node* current = head;
    for (int i = 0; i < size; ++i) {
        arr[i] = current->data;
        current = current->next;
    }
}