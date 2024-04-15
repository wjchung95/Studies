#include <iostream>
using namespace std;

#define ri register int

struct Node{
    char ch;
    Node* next, * prev;
}node[200001];

Node* h, * t, * cursor;

Node* getNode(char ch) {
    Node* n = new Node();
    n->ch = ch, n->next = n->prev = nullptr;
    return n;
}
void connect(Node* a, Node* b) {
    a->next = b;
    b->prev = a;
}
void init()
{
    h = getNode('$');
    t = getNode('$');
    connect(h, t);
    cursor = t;
}
void moveRight(int step) {
    while (cursor != t && step > 0) {
        cursor = cursor->next;
        step--;
    }
}
void moveLeft(int step) {
    while (cursor != h->next && step > 0) {
        cursor = cursor->prev;
        step--;
    }
}
void moveFinal(int step) {
    Node* current = cursor;

    if (current->ch >= 'a' && current->ch <= 'z') {
        while (current != t) {
            current = current->next;
            if (current->ch == '_') break;
        }
    }
    if (current == t) return;
    while(current != t && step > 0) {
        if (current->ch >= 'a' && current->ch <= 'z' && (current->next->ch == '_' || current->next == t)) {
            step--;
            cursor = current;
            if (step == 0) return;
        }
        current = current->next;
    }
}
void moveBegin(int step) {
    Node* current = cursor;

    if (current->ch >= 'a' && current->ch <= 'z') {
        while (current != h) {
            current = current->prev;
            if (current->ch == '_') break;
        }
    }
    if (current == h) return;
    while (current != h && step > 0)
    {
        if (current->ch >= 'a' && current->ch <= 'z' && (current->prev->ch == '_' || current->prev == h)) {
            step--;
            cursor = current;
            if (step == 0) return;
        }
        current = current->prev;
    }
}
void deleteWord(int step) {
    Node* prevNode = cursor->prev;
    Node* current = cursor;
    if (current == t) return;

    while(current != t && step > 0){
        current = current->next;
        delete current->prev;
        step--;
    }
    connect(prevNode, current);
    cursor = current;
}
void insert(char c) {
    Node* prevNode = cursor->prev;
    Node* newNode = getNode(c);
    connect(prevNode, newNode);
    connect(newNode, cursor);
}
char putString(char mStr[])
{
    ri i = 0;
    while (mStr[i]) {
        char c = mStr[i++];

        if (c >= 'A' && c <= 'Z') {
            int step = mStr[i++] - '0';
            if (c == 'R')
                moveRight(step);
            else if (c == 'L')
                moveLeft(step);
            else if (c == 'F')
                moveFinal(step);            // 왼쪽 단어의 처음 문자
            else if (c == 'B')
                moveBegin(step);            // 오른쪽 단어의 마지막 문자
            else if (c == 'D')
                deleteWord(step);
        }
        else
            insert(c);
    }
    return cursor->ch;
}

char getWord(int mX)
{
    Node* p = h->next;
    while (p != t && mX > 0) {
        if (p->ch >= 'a' && p->ch <= 'z' && (p->prev == h || p->prev->ch == '_')) {
            mX--;
            if (mX == 0) return p->ch;
        }
        p = p->next;
    }
    return '$';
}