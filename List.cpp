#include <iostream>
#include <stdexcept>

struct List {
	List(int val):data(val) {}
	
	int data; 
	List* next = nullptr;
};

void append(List* list, int val) {
	if(!list) {
		list = new List(val);
		return;
	}
	
	auto tmp = list;
	while(tmp->next) {
		tmp = tmp->next; 
	}
	
	tmp->next = new List(val);
}

void poll(List* list) {
	if(!list) {return;}
	if(!list->next) {
		delete list; 
		list = nullptr; 
		return;
	}

	auto tmp = list;
	while(tmp->next->next) {
		tmp = tmp->next;
	}

	delete tmp->next;
	tmp->next = nullptr;
}

int get_val(List* list, int i) {
	if(!list) {throw std::runtime_error("empty list");}
	
	auto tmp = list;
	
	int curr_i = 0;
	while(tmp && curr_i < i) {
		tmp = tmp->next;
		++curr_i;
	}
	
	if(tmp) {
		return tmp->data;
	}
	else {
		throw std::runtime_error("out of bounds");
	}
}

void insert(List* list, int val, int i) {
	
	//TODO: create find() function
	if(!list) return;
	
	auto tmp = list;
	int curr_i = 0;
	while(tmp && curr_i + 1 < i) {
		tmp = tmp->next;
		++curr_i;
	}
	
	if(!tmp) return;
	auto next = tmp->next;
	tmp->next = new List(val);
	tmp->next->next = next;
}

void remove(List* list, int val, int i) {
	
	//todo: create find() function
	if(!list) return;
	
	auto tmp = list;
	int curr_i = 0;
	while(tmp && curr_i + 1 < i) {
		tmp = tmp->next;
		++curr_i;
	}
	
	if(!tmp) return;
	if(!tmp->next) return;
	auto next = tmp->next->next;
	delete tmp->next;
	tmp->next = next;
}

int main() {
	
	// your code goes here
	return 0;
}