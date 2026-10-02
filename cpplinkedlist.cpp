#include <iostream>
#include <vector>
#include <memory>

template <typename T>
class Node{
public:
  T data;
  std::unique_ptr<Node<T>>next;
  Node(T n_data):data(n_data),next(nullptr){}
};
template <typename T>
class LinkedNodes{
private:
  std::unique_ptr<Node<T>>head;
  std::size_t len;
  Node<T>*nodeTraverse(std::size_t pos){
    Node<T>*current=head.get();
    while(pos--) 
      current=current->next.get();
    return current;
  }
public:
  LinkedNodes(std::vector<T>&vals):head(nullptr),len(vals.size()){
    if(vals.empty())return;
    head=std::make_unique<Node<T>>(vals[0]);
    Node<T>*current=head.get();
    for(std::size_t i=1;i<vals.size();i++){
      current->next=std::make_unique<Node<T>>(vals[i]);
      current=current->next.get();
    }
    current->next=nullptr;
  }
  std::size_t size() const{return len;}
  Node<T>*get(std::size_t pos){return nodeTraverse(pos);}
  void remove(std::size_t pos){
    if(pos<1){head=std::move(head->next);len--;return;}
    Node<T>*current=nodeTraverse(pos-1);
    if(!current||!current->next)return;
    current->next=std::move(current->next->next);len--;
  }
  void insert(T data,std::size_t pos){
    if(pos<1){auto tempNode=std::move(head);head=std::make_unique<Node<T>>(data);
      head->next=std::move(tempNode);len++;return;}
    Node<T>*current=nodeTraverse(pos-1);
    if(!current)return;
    auto tempNode=std::move(current->next);
    current->next=std::make_unique<Node<T>>(data);
    current->next->next=std::move(tempNode);len++;
  }  
};

int main(int argc,char*argv[]){return 0;}
