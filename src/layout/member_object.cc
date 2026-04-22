#include "comm/helpers.h"

  struct A {
    std::uint32_t a;
  };

  struct B {
    std::uint32_t b;
  };

  struct C : A, B {
    std::uint32_t c;
  };

int main() {
  // Base-2-Derived
  std::uint32_t B::* p1 = &B::b;
  std::uint32_t C::* p2 = p1;
  PrintMemberDataPointers(p1, p2);
  // Derived-2-Base
  std::uint32_t C::* p3 = &C::b;
  std::uint32_t B::* p4 = static_cast<std::uint32_t B::*>(p3);
  PrintMemberDataPointers(p3, p4);
  // intreasting things
  std::uint32_t C::* p5 = &C::c;
  std::uint32_t B::* p6 = static_cast<std::uint32_t B::*>(p5);
  // p6 is invalid
  // The C++ standard does not permit base-to-derived and derived-to-base
  // conversions of member pointers to cross a virtual base relationship, and so
  // a static offset is always known.

  PrintMemberDataPointers(p5, p6);
  return 0;
}
