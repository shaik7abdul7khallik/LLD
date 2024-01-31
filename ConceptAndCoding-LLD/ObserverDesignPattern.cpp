#include <bits/stdc++.h>

using namespace std;

class Observable;
class Oberserver {
public:
  shared_ptr<Observable> observable;
  virtual void notify() = 0;
};

class Samsung : public Oberserver {
public:
  void notify() { cout << "Samsung is updated msg is " << observable->msg << endl; }
};

class Iphone : public Oberserver {
public:
  void notify() { cout << "Iphone is updated msg is " << observable->msg << endl; }
};
class Observable {
  string msg = "no msg";
public:
  vector<shared_ptr<Oberserver>> observers;
  void add(shared_ptr<Oberserver> observer) {
    observers.push_back(observer);
  }
  void setData(string m) {
    msg = m;
    for(auto ob : observers) {
      ob->notify();
    }
  }
};