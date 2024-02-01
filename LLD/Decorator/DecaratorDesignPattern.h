#include "bits/stdc++.h"

using namespace std;

class Pizza {
public:
  virtual int cost () = 0;
};

class Margherita : public Pizza {
public:
  int cost() {
    return 100;
  }
};

class FarmHouse : public Pizza {
public:
  int cost() {
    return 200;
  }
};

class VegDelight : public Pizza {
public:
  int cost() {
    return 300;
  }
};

class ToppingsDecorator : public Pizza {
protected:
  Pizza *pizza;
public:
  ToppingsDecorator(Pizza *pizza) {
    this->pizza = pizza;
  }
  virtual int cost() = 0;
};

class CheeseDecorator : public ToppingsDecorator {
public:
  CheeseDecorator(Pizza *pizza) : ToppingsDecorator(pizza) {}
  int cost() {
    return pizza->cost() + 10;
  }
};

class CornDecorator : public ToppingsDecorator {
public:
  CornDecorator(Pizza *pizza) : ToppingsDecorator(pizza) {}
  int cost() {
    return pizza->cost() + 20;
  }
};

class OnionDecorator : public ToppingsDecorator {
public:
  OnionDecorator(Pizza *pizza) : ToppingsDecorator(pizza) {}
  int cost() {
    return pizza->cost() + 30;
  }
};