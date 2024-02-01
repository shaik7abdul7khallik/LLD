#include "FactoryAndAbstractFactory.h"

int main() {
  auto carFactory = AbstractCarFactory::getFactory("Luxury");
  auto bmw = carFactory->get("BMW");
  bmw->drive();
  return 0;
}