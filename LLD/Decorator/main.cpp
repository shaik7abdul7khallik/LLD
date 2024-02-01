#include "DecaratorDesignPattern.h"

int main1() {
  Pizza *fh = new CheeseDecorator(new OnionDecorator(new FarmHouse()));
  cout << fh->cost() << endl;
  return 0;
}