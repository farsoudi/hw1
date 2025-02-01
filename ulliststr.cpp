#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val) {
  //Empty list:
  if (empty()) {
    tail_ = head_ = new Item();
    head_->first = 0;
    head_->last = 1;
    head_->val[0] = val;
    size_++;
    return;
  } else if (tail_->last < ARRSIZE) { //Space in tail
    tail_->val[tail_->last] = val;
    tail_->last++; size_++;
    return;
  } else {
    Item* newTail = new Item();
    newTail->first = 0;
    newTail->last = 1;
    newTail->val[0] = val;
    newTail->prev = tail_;
    tail_->next = newTail;
    tail_ = newTail;
    size_++;
    return;
  }
}

void ULListStr::pop_back() {
  if (empty()) {
    return;
  } else if (size() == 1) {                    //Single Element
    delete head_;
    head_=tail_=nullptr;
  } else if (tail_->first+1 != tail_->last) {  //Multiple Elements in tail
    tail_->last--;
  } else {                                     //Single Element in tail
    Item* prev = tail_->prev;
    delete tail_;
    tail_ = prev;
    tail_->next = nullptr;
  }

  size_--;
}

void ULListStr::push_front(const std::string& val) {
  if (empty()) {                        //Empty
    tail_ = head_ = new Item();
    head_->first = 0;
    head_->last = 1;
    head_->val[0] = val;
    size_++;
    return;
  } else if (head_->first > 0) {   //Head has space
    head_->val[head_->first-1] = val;
    head_->first--; size_++;
  } else {                              //Head is full
    Item* newHead = new Item();
    newHead->first = ARRSIZE - 1;
    newHead->last = ARRSIZE;
    newHead->val[newHead->first] = val;
    newHead->next = head_;
    head_->prev = newHead;
    head_ = newHead;
    size_++;
    return;
  }
}

void ULListStr::pop_front() {
  if (empty()) {                                  //Empty
    return;
  } else if (size() == 1) {                       //Single element
    delete head_;
    head_=tail_=nullptr;
  } else if (head_->first+1 != head_->last) {     //Multiple in head
    head_->first++;
  } else {                                        //Single element in head
    Item* next = head_->next;
    delete head_;
    head_=next;
    head_->prev = nullptr;
  }

  size_--;
}



std::string const & ULListStr::back() const {
  if (empty()) {
    return nullptr;
  }
  return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const {
  if (empty()) {
    return nullptr;
  }
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
  if (loc >= size_) {
    return nullptr;
  }
  Item* curr = head_;
  size_t index = 0;

  while (curr != nullptr) {

    size_t currSize = curr->last - curr->first;

    if ((loc >= index) && (loc < index+currSize)) {
      return &(curr->val[curr->first + (loc-index)]);
    }

    index += currSize;
    curr = curr->next;
  }
  return nullptr;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
