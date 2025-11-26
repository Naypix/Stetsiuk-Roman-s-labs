#include <iostream>
using namespace std;

template <typename T>
void invertArray(T arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        T temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };

    Node* head;   
    Node* tail;   
    int count;  

public:
    Queue() : head(nullptr), tail(nullptr), count(0) {}

    ~Queue() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(T value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }

    T pop() {
        if (isEmpty()) {
            throw runtime_error("Черга порожня!");
        }
        Node* temp = head;
        T value = temp->data;

        head = head->next;
        delete temp;
        count--;

        if (head == nullptr) tail = nullptr;

        return value;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    int size() const {
        return count;
    }

    void print() const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    int a[] = { 1, 2, 3, 4, 5 };
    int n = 5;

    invertArray(a, n);

    for (int x : a) cout << x << " " ;
    cout << endl;


    Queue<string> q;

    q.push("game");
    q.push("word");
    q.push("mouse");

    cout << "Queue: ";
    q.print();

    cout << "Deleted: " << q.pop() << endl;

    cout << "Queue after pop(): ";
    q.print();

    cout << "Quantity of elements: " << q.size() << endl;
    return 0;
}
