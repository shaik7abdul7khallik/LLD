#include <bits/stdc++.h>

using namespace std;

class Observer;

class Observable {
public:
  vector<shared_ptr<Observer>> observers;
  void add(shared_ptr<Observer> observer) { observers.push_back(observer); }
};

class Observer {
protected:
  shared_ptr<Observable> observable;
public:
  Observer(shared_ptr<Observable> observable) : observable(observable) {};
  virtual void notify() = 0;
  virtual ~Observer() {};
};
class SamsungObservable : public Observable {
public:
  int oneUiVersion = 0;
  void setOneUiVersion(int v) {
    oneUiVersion = v;
    for(auto ob : observers) {
      ob->notify();
    }
  }
};
class AppleObservable : public Observable {
public:
  int appleVersion = 0;
  void setAppleVersion(int v) {
    appleVersion = v;
    for(auto ob : observers) {
      ob->notify();
    }
  }
};

class SamsungObserver : public Observer {
public:
  SamsungObserver(shared_ptr<Observable> observable) : Observer(observable) {}
  void notify() {
    SamsungObservable* samsungObservable = (SamsungObservable*)(observable.get());
    cout << "Samsung SmartPhone  version update is avaiable. Update to version  " << samsungObservable->oneUiVersion << endl;
  }
};

class IphoneObserver : public Observer {
public:
  IphoneObserver(shared_ptr<Observable> observable) : Observer(observable) {}
  void notify() {
      AppleObservable* appleObservable = (AppleObservable*)(observable.get());
    cout << "Iphone SmartPhone version update is avaiable. Update to version " << appleObservable->appleVersion << endl;
  }
};

class SamsungTabObserver : public Observer {
public:
  SamsungTabObserver(shared_ptr<Observable> observable) : Observer(observable) {}
  void notify() {
    SamsungObservable* samsungObservable = (SamsungObservable*)(observable.get());
    cout << "Samsung tab version update is avaiable. Update to version " << samsungObservable->oneUiVersion << endl;
  }
};

class IphoneTabObserver : public Observer {
public:
  IphoneTabObserver(shared_ptr<Observable> observable) : Observer(observable) {}
  void notify() {
    AppleObservable* appleObservable = (AppleObservable*)(observable.get());
    cout << "Iphone tab version update is avaiable. Update to version " << appleObservable->appleVersion << endl;
  }
};
