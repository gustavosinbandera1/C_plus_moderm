#include <chrono>
#include <iostream>
#include <memory>
#include <mutex>
#include <thread>

class F {};
class G : public F {};

int main() {
    std::shared_ptr<G> sp0(new G);    // okay, template parameter G and argument G*
    std::shared_ptr<G> sp1(sp0);      // okay, template parameter G and argument shared_ptr<G>
    std::shared_ptr<F> sp2(new G);    // okay, G* convertible to F*
    std::shared_ptr<F> sp3(sp0);      // okay, template parameter F and argument shared_ptr<G>
    std::shared_ptr<F> sp4(sp2);      // okay, template parameter F and argument shared_ptr<F>
   // std::shared_ptr<int> sp5(new G);  // error, G* not convertible to int*
   // std::shared_ptr<int> sp6(sp2);    // error, template parameter int and argument shared_ptr<F>
}