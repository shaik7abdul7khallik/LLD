#include "ObserverDesignPattern.h"

int main1() {
  auto sobe = make_shared<SamsungObservable>();
  shared_ptr<Observer> so = make_shared<SamsungObserver>(sobe);
  shared_ptr<Observer> sto = make_shared<SamsungTabObserver>(sobe);
  auto iobe = make_shared<AppleObservable>();
  shared_ptr<Observer> io = make_shared<IphoneObserver>(iobe);
  shared_ptr<Observer> ito = make_shared<IphoneTabObserver>(iobe);
  sobe->add(so);
  sobe->add(sto);
  iobe->add(io);
  iobe->add(ito);
  sobe->setOneUiVersion(5);
  iobe->setAppleVersion(14);
  return 0;
}