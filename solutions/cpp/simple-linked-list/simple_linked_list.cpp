#include "simple_linked_list.h"

#include <stdexcept>

namespace simple_linked_list {

size_t List::size() {
    return current_size;
}

void List::push(int entry) {
    Element *item = new Element(entry);
    
    if(current_size == 0) {
        head = item;
        tail = item;
    } else {
        tail->next = item;
        tail = item;
    }

    current_size++;
}

int List::pop() {
    if(tail == nullptr) return 0;
    
    int value = tail->data;
    current_size--;
    
    if (current_size == 0) {
        delete head;
        head = nullptr;
        tail = nullptr;
        
        return value; 
    }

    auto* node = head;
    while(node != nullptr && node->next != tail) node = node->next;
    delete node->next;
    node->next = nullptr;
    tail = node;
    
    return value;
}

void List::reverse() {
    if(current_size < 2) return;

    Element *current = head;
    Element *prev = nullptr, *next = nullptr;
 
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    tail = head;
    head = prev;
}

List::~List() {
    auto* node = head;
    while(node != nullptr) {
        auto next = node->next;
        delete node;
        current_size--;
        node = next;
    }
}

}  // namespace simple_linked_list
