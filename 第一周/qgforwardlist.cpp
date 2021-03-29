#include"qgforwardlist.h"
#include<new>
#include<iostream>
using namespace std;
QGForwardList::QGForwardList() {
	cout << "���Ǹ��޽�׳�Եĳ���";
	head = new Node;
	head->next = nullptr;
	tail = new Node;
	tail->next = nullptr;
	head->next = tail;
	ElemType num;
	cout << endl<<"����"<<endl;
	cin >> num;
	while (1) {
		tail->data = num;
		cout << "������Y/N" << endl;
		cin.clear();
		char c;
		cin >> c;
		if (c == 'Y' ||c=='y') {
			cout << "����"<<endl;
			cin >> num;
			Node* temp = new Node;
			temp->next = nullptr;
			tail->next = temp;
			tail = temp;
			tail->data = num;
		}
		else if (c == 'N'||c=='n') { 
			break;
		}
		else {
			cout << "bad enter "<<endl;
			cin.clear();
			break;
		}
	}
	cout << "��������:" << endl;
	Node* T = head->next;
	while (T != nullptr) {
		cout << T->data<<" ";
		T = T->next;
	}
}
QGForwardList::~QGForwardList() {
	Node* p1 = head->next;
	Node* p2;
	while (p1 != nullptr) {
		p2 = p1->next;
		delete p1;
		p1 = p2;
	}
	p1 = p2 = nullptr;
	cout << "ָ���ͷ�";
}
QGForwardList::ElemType & QGForwardList::front() {
	return head->next->data;
}
QGForwardList::ElemType& QGForwardList::back() {
	Node* p = head->next;
	if (p != nullptr) {
		while (p->next != nullptr) {
			p = p->next;
		}
		return p->data;
	}
	else cout << "��������-1";
	QGForwardList::ElemType i = -1;
		return i;
}
bool QGForwardList::push_front(ElemType& e) {
	if (Node* temp = new Node) {
		temp->next = nullptr;
		temp->data = e;
		temp->next = head->next->next;
		head->next = temp;
		return true;
	}
	else  return false;
}
bool QGForwardList::pop_front() {
	Node* p = head->next;
	if (p) {
		head->next = p->next;
		delete p;
		return true;
	}
	return false;
}
bool QGForwardList::push_back(ElemType& e) {
	Node* T = head->next;
	while (T->next) {
		T = T->next;
	}
	Node* N = new Node;
	N->next = nullptr;
	T->next = N;
	N->data = e;
	return true;
}
bool QGForwardList::pop_back() {
	Node* front;
	Node* last;
	front = head->next, last = head;
	if (front) {
		while (front->next != nullptr) {
			front = front->next;
			last = last->next;
		}
	}
	delete front;
	last->next = nullptr;
	return true;
}
bool QGForwardList::insert(unsigned int index, ElemType& e) {
	int rec = 0;
	Node* p = head;
	while (p != nullptr&&rec<index) {
		p = p->next;
		rec++;
	}
	if (p == nullptr)return false;
	if (Node* add = new Node) {
		add->data = e;
		add->next = p->next;
		p->next = add;
		return true;
	}
	else return true;
}
bool QGForwardList::erase(unsigned int index) {//11
	int rec = 1;
	Node* f = head->next;
	Node* t = head;
	while(f!=nullptr&&rec<index){
		f = f->next;
		t = t->next;
		rec++;
	}
	if (f == nullptr)return false;
	else {
		t->next = f->next;
		delete f;
	    return true;
	}
	return false;
	/*Node* y = head->next;
	while (y) {
		cout << y->data<<" ";
		y = y->next;
	}*/
}
bool QGForwardList::clear() {
	Node* q = head->next;
	while (q) {
		q->data = 0;
		q = q->next;
	}
	return true;
}
bool QGForwardList::contain(ElemType& e) {
	Node* p = head->next;
	int flag = 0;
	while (p != nullptr) {
		if (p->data == e) {
			cout << "��������" << e<<endl;
			return true;
		}
		p = p->next;
	}
	cout << "������û" << e << endl;
	return false;
}
unsigned int QGForwardList::size() {
	unsigned int num=0;
	Node* p = head->next;
	while (p!= nullptr) {
		num++;
		p = p->next;
	}
	return num;
}
bool QGForwardList::traverse(void (*visit)(ElemType& e)) {
	Node* p = head->next;
	while (p != nullptr) {
		(*visit)(p->data);
		p = p->next;
	}
	/*Node* start = head->next;
	while (start) {
		cout << " " << start->data;
		start = start->next;
	}*/
	return true;
}
bool QGForwardList::reverse() {
	Node* p = head->next;
	Node* q = p->next;
	Node* temp = nullptr;
	p->next = nullptr;
	while (q!= nullptr) {
			temp = q->next;
			q->next = p;
			p = q;
			q = temp;
		}
	head->next = p;
	/*Node* start = head->next;
	while (start) {
		cout<< " " << start->data;
		start = start->next;
	}*/
	return true;
}
bool QGForwardList::isLoop() {
	Node* fast, * slow;
	fast = head, slow = head;
	do {
		fast = fast->next->next;
		slow = slow->next;
		if (fast = nullptr) {
			return false;
		}
	} while (head != slow);
		return false;
}
QGForwardList::ElemType& QGForwardList::middleElem() {
	Node* fast=head, * slow=head;
	ElemType num;
	if (size() % 2 == 0) {
		while (fast->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
		}
		num = slow->data;
		return num;
	}
	else {
		while (fast->next->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
		}
		slow = slow->next;
		num = slow->data;
		return num;
	}
}
bool QGForwardList::reverseEven() {
	Node* ji = head->next;
	Node* ou = head->next->next;
	Node* temp;
	if (!ou) {
		return true;
	}
	head->next = ou;
	Node* jitemp=ou->next;
	if (!jitemp) {
		head->next = ou;
		ou->next = ji;
		ji->next = nullptr;
		/*Node* start = head->next;
		while (start) {
			cout << " " << start->data;
			start = start->next;
		}*/
		return true;
	}
	head->next = ou;
	Node* outemp=nullptr;
	while (jitemp) {
		outemp = jitemp->next;
		if (!outemp) {
			ou->next = ji;
			ji->next = jitemp;
			ji = jitemp;
			ji->next = nullptr;
			Node* start = head->next;
			while (start) {
				cout << " " << start->data;
				start = start->next;
			}
			return true;
		}
		//��ż����
		ou->next = ji;
		ji->next = outemp;
		ji = jitemp;
		ou = outemp;
		if (outemp->next == nullptr) {
			ou->next = ji; break;
		}
		jitemp = jitemp->next->next;
	}
	if (outemp) {
		outemp->next->next = nullptr;
	}
	Node* start = head->next;
	while (start) {
		cout << " " << start->data;
		start = start->next;
	}
	return true;
}