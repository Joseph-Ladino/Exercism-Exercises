#pragma once

#include <stdexcept>

namespace linked_list {
	template <typename DataType>
	struct DLNode {
		DataType data;
		DLNode* next = nullptr, *prev = nullptr;

		inline DLNode(DataType data, DLNode* next = nullptr, DLNode* prev = nullptr) : data(data), next(next), prev(prev) {}
	};

	template <typename DataType>
	class List {
		using Node = DLNode<DataType>;
		Node* head = nullptr, *tail = nullptr;
		size_t numNodes;

	public:

		// insert data to end of list
		inline void push(DataType val) {
		
			Node* node = new Node(val);
			
			if (isEmpty()) {
				head = tail = node;
			}
			else {
				tail->next = node;
				node->prev = tail;
				tail = node;
			}

			numNodes++;
		}
		
		// remove and return data from end of list
		inline DataType pop() {
			if(isEmpty()) throw std::runtime_error("Cannot pop empty list!");

			Node* node = tail;
			DataType data = node->data;

			tail = node->prev;

			if(tail != nullptr) tail->next = nullptr;
			else {
				tail = head = nullptr;
			}

			delete node;

			numNodes--;

			return data;
		}
		
		// remove and return data from front of list
		inline DataType shift() {
			if (isEmpty()) throw std::runtime_error("Cannot shift empty list!");

			Node* node = head;
			DataType data = node->data;

			head = node->next;

			if (head != nullptr) head->prev = nullptr;
			else {
				head = tail = nullptr;
			}

			delete node;

			numNodes--;

			return data;
		}
		
		// insert data to front of list
		inline void unshift(DataType val) {
			Node* node = new Node(val);

			if (isEmpty()) {
				head = tail = node;
			}
			else {
				head->prev = node;
				node->next = head;
				head = node;
			}

			numNodes++;
		}
		
		// get total number of elements (nodes) in list
		inline size_t count() {
			return numNodes;
		}

		inline bool isEmpty() {
			return numNodes == 0;
		}

		// remove first instance of data from list
		inline void erase(DataType val) {
			if (isEmpty()) return;

			Node* node = head;
			bool nodeFound = false;

			while (node != nullptr) {
				if (node->data == val) {
					nodeFound = true; break;
				}
				node = node->next;
			}

			if (nodeFound) {
				if (node == head) {
					shift(); return;
				}
				if (node == tail) {
					pop(); return;
				}

				node->prev->next = node->next;
				node->next->prev = node->prev;

				delete node;
				numNodes--;
			}
		}

		inline ~List() {
			Node* node;
			while (head != nullptr) {
				node = head;
				head = head->next;
				delete node;
			}
		}
	};
	
}  // namespace linked_list
