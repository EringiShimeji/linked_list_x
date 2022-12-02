#include <iostream>
#include <string>
using namespace std;

template <class data_t>
class list {
  data_t data;
  list* next;

 public:
  list(data_t d) {
    data = d;
    next = 0;
  }
  void add(list* node) {
    node->next = this;
    next = 0;
  }
  data_t* get_data() { return &data; }
  list* get_next() { return next; }
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
  list<Station> start(start_station);
  list<Station>* p;
  list<Station>* last;

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
    p = new list<Station>(new_station);
    p->add(last);
    last = p;
  }

  list<Station>* cur = &start;
  while (cur) {
    cout << cur->get_data()->name << endl;
    cur = cur->get_next();
  }
}
