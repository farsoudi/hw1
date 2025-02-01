#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

using namespace std;

// Helper functions to set up different scenarios
ULListStr setup_empty_list() {
  return ULListStr();
}

ULListStr setup_one_item_node() {
  ULListStr dat;
  dat.push_back("1");
  return dat;
}

ULListStr setup_multiple_item_nodes() {
  ULListStr dat;
  for (int i = 1; i <= ARRSIZE + 2; ++i) {
    dat.push_back(to_string(i));
  }
  return dat;
}

// Test functions
void test_push_back(ULListStr& dat) {
  dat.push_back("new");
  cout << "test push_back: ";
  for (size_t i = 0; i < dat.size(); ++i) {
    cout << dat.get(i) << " ";
  }
  cout << endl;
}

void test_push_front(ULListStr& dat) {
  dat.push_front("new");
  cout << "test push_front: ";
  for (size_t i = 0; i < dat.size(); ++i) {
    cout << dat.get(i) << " ";
  }
  cout << endl;
}

void test_pop_back(ULListStr& dat) {
  dat.pop_back();
  cout << "test pop_back: ";
  for (size_t i = 0; i < dat.size(); ++i) {
    cout << dat.get(i) << " ";
  }
  cout << endl;
}

void test_pop_front(ULListStr& dat) {
  dat.pop_front();
  cout << "test pop_front: ";
  for (size_t i = 0; i < dat.size(); ++i) {
    cout << dat.get(i) << " ";
  }
  cout << endl;
}

void test_back(ULListStr& dat) {
  cout << "test back: " << dat.back() << endl;
}

void test_front(ULListStr& dat) {
  cout << "test front: " << dat.front() << endl;
}

void test_size(ULListStr& dat) {
  cout << "test size: " << dat.size() << endl;
}

void test_clear(ULListStr& dat) {
  dat.clear();
  cout << "test clear: " << dat.size() << endl;
}

int main(int argc, char* argv[]) {
//   // Test with empty list
//   ULListStr empty_list = setup_empty_list();
//   cout << "Testing with empty list:" << endl;
//   test_push_back(empty_list);
//   test_push_front(empty_list);
//   test_pop_back(empty_list);
//   test_pop_front(empty_list);
//   test_size(empty_list);
//   test_clear(empty_list);

  // Test with one item node
  ULListStr one_item_node = setup_one_item_node();
  cout << "Testing with one item node:" << endl;
  test_push_back(one_item_node);
  test_push_front(one_item_node);
  test_pop_back(one_item_node);
  test_pop_front(one_item_node);
  test_back(one_item_node);
  test_front(one_item_node);
  test_size(one_item_node);
  test_clear(one_item_node);

  // Test with multiple item nodes
  ULListStr multiple_item_nodes = setup_multiple_item_nodes();
  cout << "Testing with multiple item nodes:" << endl;
  test_push_back(multiple_item_nodes);
  test_push_front(multiple_item_nodes);
  test_pop_back(multiple_item_nodes);
  test_pop_front(multiple_item_nodes);
  test_back(multiple_item_nodes);
  test_front(multiple_item_nodes);
  test_size(multiple_item_nodes);
  test_clear(multiple_item_nodes);

  return 0;
}
