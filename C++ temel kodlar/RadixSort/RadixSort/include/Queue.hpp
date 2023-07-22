#ifndef KUYRUK_HPP
#define KUYRUK_HPP

#include <iostream>
using namespace std;

template <typename Object>
class Node{
	public:
		Object item;
		Node<Object> *next;
		Node(Object itm,Node<Object> *nxt=NULL){
			item=itm;
			next=nxt;
		}
};

template <typename Object>
class Queue{
	private:
		Node<Object> *front;
		Node<Object> *back;
		int length;
		
	public:
		Queue(){
			front=back=NULL;
			length=0;
		}
		void clear(){
			while(!isEmpty()) dequeue();
		}
		int count() const{
			return length;
		}
		bool isEmpty() const {
			return length == 0;
		}
		/// Kuyrukta en öndeki elemanı getirir
		const Object& peek() const{
			if(isEmpty()) throw "Queue is empty";
			return front->item;
		}
		void enqueue(const Object& item){			
			Node<Object> *last = new Node<Object>(item);	
			if(isEmpty()) front = back = last;
			else{
				back->next = last;
				back = last;
			}
			length++;
		}
		void dequeue(){
			if(isEmpty()) throw "Queue is empty";			
			Node<Object> *eskiOn = front;
			front = front->next;
			delete eskiOn;
			length--;
		}
		~Queue(){
			clear();
		}		
};
#endif