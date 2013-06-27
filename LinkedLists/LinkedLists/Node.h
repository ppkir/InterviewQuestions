#ifndef __LinkedList_Node__
#define __LinkedList_Node__

#include <string>
#include <vector>
#include <iostream>
#include <exception>

template <typename T>
struct Node;

template <typename T>
struct Node {
	T data;
	typename Node<T>* next;
};

template<typename T>
Node<T>* CreateList(T* data, size_t len) {
	if (len == 0) return 0;
	
	Node<T>* head = CreateNode(data[0]);
	Node<T>* node = head;
	for (size_t i = 1; i < len; i++) {
		node->next = CreateNode(data[i]);
		node = node->next;
	}

	return head;
}

template<typename T>
void RemoveNode(Node<T>* node, Node<T>* parent) {
	if (node == 0) return;
	parent->next = node->next;

	DeleteNode(node);
}

template<typename T>
void RemoveNode(Node<T>*& node) {
	if (node == 0) return;
	if (node->next) {
		// a->b->c-d->e
		//Remove('c')
		// a->b->d->e
		node->data = node->next->data;
		RemoveNode(node->next, node);
	} else {
		throw std::logic_error("Cannot delete last node");
	}
}

template<typename T>
Node<T>* FindNode(Node<T>* head, T data) {
	Node<T>* n = head;
	while (n != 0) {
		if (n->data == data) {
			return n;
		}

		n = n->next;
	}

	return 0;
}

template<typename T>
Node<T>* CreateNode(T data) {
	Node<T>* head = new Node<T>();
	head->next = 0;
	head->data = data;

	return head;
}

template<typename T>
void DeleteNode(Node<T>* node) {
	delete node;
}

template <typename T>
std::vector<T> ToVector(Node<T>* head) {
	std::vector<T> res;
	if (head == 0) res;
	Node<T>* n = head;
	while (n != 0) {
		res.push_back(n->data);
		n = n->next;
	}

	return res;
}

template <typename T>
Node<T>* nthToTheLast(Node<T>* head, size_t n) {
	if (n == 0) return 0;

	Node<T>* it = head;
	for (size_t i = 1; i <= n; i++) {
		if (it == 0) return 0;
		it = it->next;
	}

	Node<T>* node = head;
	while(it != 0) {
		it = it->next;
		node = node->next;
	}

	return node;
}

template <typename T>
void printList(Node<T>* head, const std::string& separator = " ") {
	if (head == 0) return;
	Node<T>* n = head;
	while (n != 0) {
		std::cout << n->data;
		n = n->next;
		if (n != 0) {
			std::cout << separator;
		}
	}
}

#endif