#include "../Include/LinkedList.h"
Node::Node(Key key_t, STEADY_CLOCK_DURATION end_time_t)
	:key(key_t), end_time(end_time_t), next(nullptr)
{
}


LinkedList::LinkedList()
	:m_head(nullptr), m_tail(nullptr), m_size(0)
{

}


LinkedList::~LinkedList() {
	while (m_head) { //go through each node & delete it
		Node* temp = m_head;
		m_head = m_head->next;
		delete temp;
	}
}


void LinkedList::addNode(Key& key_t, STEADY_CLOCK_DURATION end_time_t)
{
	if(m_tail && m_tail->key.getKey() == '\0') //if tail is not null && pointing to a reused node
	{
		m_tail->key.setKey(key_t.getKey());
		m_tail->end_time = end_time_t;

	}
	//tail is in use or doesn't exist so create a new node to add
	Node* temp = new Node(key_t, end_time_t);
	if (m_head == nullptr) //if we just created a new LL (head == null && tail == null)
	{
		m_head = temp;
		m_tail = m_head;
	}
	else if(m_tail){ // we have a head && tail is in use
		m_tail->next = temp;
		m_tail = m_tail->next;
	}


	++m_size;

	return;
}


void LinkedList::popNode() {
	if(m_size == 0)
		return;
	if (m_head){
		Node* temp = m_head;
		m_head = m_head->next;
		
		m_tail->next = temp;
		m_tail = m_tail->next;
		m_tail->key;

	}
	--m_size;
	return;
}


Node* LinkedList::getHead() {
	return m_head;
}