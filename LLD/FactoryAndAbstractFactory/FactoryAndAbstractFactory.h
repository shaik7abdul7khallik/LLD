#include <bits/stdc++.h>
using namespace std;
class Car {
public:
  virtual void drive() = 0;
};

class LuxuryCar : public Car {
public:
  virtual void drive() = 0;
};

class OrdinaryCar : public Car {
public:
  virtual void drive() = 0;
};

class BMW : public LuxuryCar {
public:
  void drive() override {
    cout << "BMW is driving" << endl;
  }
};

class Audi : public LuxuryCar {
public:
  void drive() override {
    cout << "Audi is driving" << endl;
  }
};

class Ford : public OrdinaryCar {
public:
  void drive() override {
    cout << "Ford is driving" << endl;
  }
};

class Honda : public OrdinaryCar {
public:
  void drive() override {
    cout << "Honda is driving" << endl;
  }
};

class CarFactory {
public:
  virtual Car* get(string type) = 0;
};

class LuxuryCarFatory : public CarFactory {
public:
  Car* get(string type) override {
    if (type == "BMW") {
      return new BMW();
    } else if (type == "Audi") {
      return new Audi();
    } else {
      return nullptr;
    }
  }
};

class OrdinaryCarFatory : public CarFactory {
public:
  Car* get(string type) override {
    if (type == "Ford") {
      return new Ford();
    } else if (type == "Honda") {
      return new Honda();
    } else {
      return nullptr;
    }
  }
};

class AbstractCarFactory {
public:
  static CarFactory* getFactory(string type) {
    if (type == "Luxury") {
      return new LuxuryCarFatory();
    } else if (type == "Ordinary") {
      return new OrdinaryCarFatory();
    } else {
      return nullptr;
    }
  }
};