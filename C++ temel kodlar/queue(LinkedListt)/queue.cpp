#include <iostream>

using namespace std;

class queueNode
{	
	public:
	int data;
	queueNode* next;
	queueNode(int veri)
	{
		data = veri;
		next = 0;
	}
	~queueNode()
	{
		
	}
};   
class queue
{
	private:
		queueNode* head;
		queueNode* last;
		int size;
 	public:
		queue()
		{
			head = 0;
			last = 0;
			size = 0;
		}
		~queue()
		{
			clean();
		}
		int getSize()
		{
			return size;
		}
		bool isEmpty()
		{
			return size == 0;
		}
		int getHeadNode()
		{
			if(!isEmpty())
				return head->data;
			throw out_of_range("kuyruk bos");
		}
		void Enqueue(int newData)
		{
			queueNode* newNode = new queueNode(newData);
			if(isEmpty())
				head = newNode;last = newNode; 
			else
			{
				last->next = newNode;
				newNode = last;
			}
			size++;
		}
		void Dequeue()
		{
			if(!isEmpty())
			{
				queueNode* willDelete = head;
				head = head->next;
				delete willDelete;
				size--;
			}
			else
				return;
		}
		void clean()
		{
			while(!isEmpty())
			{
				Dequeue();
			}
		}
}  