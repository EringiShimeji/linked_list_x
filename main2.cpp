#include <iostream>
#include <string>
using namespace std;

// doubly linked list
template <class data_t>
class dllist {
  data_t data;
  dllist* next;
  dllist* pre;

 public:
  dllist(data_t d) {
    data = d;
    next = pre = 0;
  }
  // 前後のノードの間に挟む
  void insert(dllist* node) {
    // このノードの次のノードに対して、ひとつ前のノードをnodeにする
    if (this->next) this->next->pre = node;
    // nodeの次のノードはこのノードの次のノードにする
    node->next = this->next;
    // このノードの次のノードはnode
    this->next = node;
    // nodeのひとつ前はこのノード
    node->pre = this;
  }
  data_t* get_data() { return &data; }
  dllist* get_next() { return next; }
  dllist* get_pre() { return pre; }
};

class Station {
 public:
  string name;
  bool is_train_stopped;

  Station() { name = "", is_train_stopped = false; };
  Station(string s) { name = s, is_train_stopped = false; }
};

int main() {
  string head_name;
  cout << "始発駅: ";
  cin >> head_name;

  Station start_station(head_name);
  dllist<Station> start(start_station);
  dllist<Station>* p;
  dllist<Station>* last;

  last = &start;

  int stations_cnt;
  do {
    cout << "追加する駅数: ";
    cin >> stations_cnt;
  } while (stations_cnt < 0);

  for (int i = 0; i < stations_cnt; i++) {
    string name;
    cout << i + 1 << "番目の駅名: ";
    cin >> name;

    Station new_station(name);
    p = new dllist<Station>(new_station);
    last->insert(p);
    last = p;
  }

  dllist<Station>* cur = &start;
  cout << "上り: ";
  while (cur) {
    cout << cur->get_data()->name;
    cur = cur->get_next();
    if (cur) cout << " -> ";
  }
  cout << endl;

  cur = last;
  cout << "下り: ";
  while (cur) {
    cout << cur->get_data()->name;
    cur = cur->get_pre();
    if (cur) cout << " -> ";
  }
  cout << endl;
}
