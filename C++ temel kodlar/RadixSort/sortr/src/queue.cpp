#include "queue.hpp"
#include <iostream>
using namespace std;

queue::queue()
{
	bas = son = 0;
	boyut = 0;
}
void queue::temizle()
{
	while(!bosMu()) 
		eksilt();
}
int queue::say() 
{
	return boyut;
}
bool queue::bosMu()  
{
	return boyut == 0;
}
		
int queue::getir() 
{
	if(!bosMu()) 
		return bas->dugumVeri;
	throw std::out_of_range("kuyruk bos");
}
void queue::ekle(int dugumVeri){			
	queueNode* eklenecek = new queueNode (dugumVeri);	
	if(bosMu()) 
		bas = son = eklenecek;
	else
	{
		son->ileri = eklenecek;
		son = eklenecek;
	}
	boyut++;
}
void queue::eksilt()
{
	if(bosMu()) 
		return;			
	queueNode* eskiBas = bas;
	bas = bas->ileri;
	delete eskiBas;
	boyut--;
}
queue::~queue()
{
	temizle();
}
