#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Trie{

public:
	Trie();
	bool isEmpty()const;
	void print()const;
	void insert(const string str);
private:
	struct Node;
	Node* root;
	Node* insert(Node* root, const char c);
	void insert(Node* root, const string str);
	void print(Node *,string str)const;
};
bool Trie::isEmpty()const{
	return nullptr == root;
}


struct Trie::Node{
	char c;
	bool isLeaf;
	Node* arr [26]; 
};

Trie::Trie(): root{new Node}{
	root->c= 0;
	root->isLeaf = true;
}



Trie::Node* Trie::insert(Node* root, const char c){
	Node * temp = new Node;
	for(auto &i:temp->arr){
		i = nullptr;
	}
	temp->c = c;
	temp->isLeaf = true;

	int pos = (int)c - 'a';
	if(nullptr==root->arr[pos]){
		root->arr[pos] = temp;
		root->isLeaf = false;
		return temp;
	}else{
		return root->arr[pos];
	}
	
	
}

void Trie::insert(const string str){
	Node* ptr = this->root;
	for(auto i:str){
		ptr = insert(ptr,i);
	}
	
}

void Trie::print(Node * root,string str)const{
	if(0==root){
		cout<<"Empty Trie"<<endl;
		return;
	}
	if(root->isLeaf){
		if(0!=root->c){
			str+=root->c;
			cout<<str<<endl;
		}
		return;
	}else{
		if(0!=root->c){
			str+= root->c;
		}
		for(auto &i:root->arr){
			if(nullptr!=i){
				print(i,str);
			}
		}
	}
	
}

void Trie::print()const{
	print(this->root,"");
}


int main(int argc, char* argv[]){
	Trie trie;


	ifstream stream("twl.txt");
	string input;
	while(stream>>input){
		trie.insert(input);
	}
	// trie.insert("cat");
	// trie.insert("cab");
	// trie.insert("caf");
	// trie.insert("dog");
	cout<<trie.isEmpty()<<endl;
	trie.print();

}
