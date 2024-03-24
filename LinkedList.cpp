#include <iostream>
#include <vector>
using namespace std ; 

struct node{
	int data ; 
	node* next ;
	node(int x , node* next1){
		data = x ;
		next = next1 ;
	}
	
	node(int x){
		data = x ;
		next = nullptr ;
	}	
};

node* convert_to_ll(vector<int> &arr){
	node* head = new node(arr[0]);
	node *mover = head ;
	for(int i = 1 ; i < int(arr.size()) ; i++){
		node* temp = new node(arr[i]);
		mover->next = temp;
		mover = temp;
	}
	return head ;
}

int len_ll(node* head){
	int cnt = 0 ;
	node* temp = head ;
	while(temp){
		temp = temp -> next ;
		cnt++ ;
	}
	return cnt;
}

int chk_ll(node* head , int val){
	node* temp = head ;
	while(temp){
		if(temp -> data == val) return 1 ;
		temp = temp -> next ;
	}
	return 0;
}

node* delHEAD(node* head){
	/* Deleting Head */
	if(head == nullptr){
		return head ;
	}
	node* temp = head ;
	head = head->next;
	delete temp;
	return head ; 
}


node* delTail(node* head){
		if(head == nullptr || head->next == nullptr){
			return nullptr;
		}
		node *temp = head ;
		while(temp->next->next != nullptr){
			temp = temp->next;
		}
		delete temp->next ;
		temp->next = nullptr ;
		return head ;
}

void traverse(node* head){
		while(head != nullptr){
			cout << head->data << ' ' ;
			head = head->next ;
		}
		cout << endl ;
}

node* deleteK(node *head , int k){
	if(head == nullptr) return head; 
	if(k == 1){
		/* copy DelHead Function */
	}
	/* when k is not equal to neither haed nor tail */
	/* If k > length of ll then return head */
	int cnt = 0 ;
	node *temp = head ;
	node* prev = nullptr ;
	while(temp != nullptr){
		cnt++ ;
		if(cnt == k){
			prev->next = prev->next->next;
			delete temp ;
			break ;
		}
		prev = temp ;
		temp = temp->next ;
	}
	return head ;
}

node* deleteEle(node *head , int el){
	if(head == nullptr) return head; 
	if(head->data == el){
		/* copy DelHead Function */
	}
	/* when k is not equal to neither haed nor tail */
	/* If k > length of ll then return head */
	node *temp = head ;
	node* prev = nullptr ;
	while(temp != nullptr){
		if(temp->data == el){
			prev->next = prev->next->next;
			delete temp ;
			break ;
		}
		prev = temp ;
		temp = temp->next ;
	}
	return head ;
}

node* insertHead(node* head , int val){
	/* Inserting before head */
	node* temp = new node(val , head);
	return temp ;
}

node* insertTail(node* head , int val){
	if(head == nullptr){
		return new node(val);
	}
	node* tmp = head; 
	while(tmp->next != nullptr){
		tmp = tmp -> next ;
	}
	node* newnode = new node(val);
	tmp->next = newnode ;
	return head ;
}

node* insertK(node* head , int k , int el){
	if(head == nullptr){
		if(k == 1){
			return new node(el);
		}else return head ;
	}
	
	if(k == 1){
		node* tmp = new node(el,head);
		return tmp ;
	}
	int cnt = 0 ;
	node* tmp = head ;
	while(tmp != nullptr){
		cnt++ ;
		if(cnt == k - 1){
			node* x = new node(el);
			/* first connect */
			x->next = tmp->next ;
			tmp->next = x ;
			break ;
		}
		tmp = tmp->next ;
	}
	return head ;
}

node* insertval(node* head , int el , int val){
	if(head == nullptr){
		return nullptr;
	}
	
	if(head->data == val){
		return new node(el , head);
	}
	node* tmp = head ;
	while(tmp -> next != nullptr){
		if(tmp -> next -> data == val){
			node* x = new node(el , tmp -> next);
			/* first connect */
			tmp->next = x ;
			break ;
		}
		tmp = tmp->next ;
	}
	return head ;
}

/* STORE THESE CODES IN GITHUB */

int main(){
	vector<int> arr = {12,5,8,7} ;
	node* head = convert_to_ll(arr);
	head = insertval(head , 100 , 5);
	traverse(head);
}
