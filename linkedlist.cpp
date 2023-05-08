#include "linked_list.h"
#include <string>

linked_list::linked_list() {
    head = nullptr;
    tail = nullptr;
}

linked_list::~linked_list() {
    game* runner;

    while(head){
        runner = head;
        head = head->next;
        delete runner;
    }
}

bool linked_list::isEmpty() const {
    if(head){
        return false;
    }

    return true;
}

unsigned linked_list::listSize() const {
    return length;
}

game& linked_list::operator[](int n) {
    game* runner = head;
    for (int i = 0; i < n; i++) runner = runner->next;
    return *runner;
}

void linked_list::append(game newgame) {
    if(!head){
        head = new game(newgame);
        tail = head;
    }
    else{
        tail->next = new game(newgame);
        tail = tail->next;
    }
    tail->setId(length);
    length++;
}

void linked_list::remove(int r) {
    if (r > length) return;
   
    game* runner = head;
    game* prev;
    for (int i = 0; i < r; i++) {
        prev = runner;
        runner = runner->next;
    }
    
    if (runner == head) {
        if (head == tail) tail = nullptr;
        head = head->next;
        delete runner;
        return;
    }
    
    if (runner == tail) {
        prev->next = nullptr;
        delete runner;
        tail = prev;
        return;
    }
    
    prev->next = runner->next;
    delete runner;
}
