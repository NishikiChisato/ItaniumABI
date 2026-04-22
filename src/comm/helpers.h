#include <print>

template <typename T>
concept IsMemberDataPointer = std::is_member_object_pointer_v<T>;
template <IsMemberDataPointer Ptr>
auto ToRawVal(Ptr ptr) {
  using RawType = std::conditional_t<sizeof(ptr) == sizeof(std::ptrdiff_t),
                                     std::ptrdiff_t, std::uint32_t>;
  return std::bit_cast<RawType>(ptr);
}

template <IsMemberDataPointer... Ptrs>
void PrintMemberDataPointers(Ptrs... ptrs) {
  auto print_signle = [is_first = true](auto ptr) mutable {
    auto val = ToRawVal(ptr);
    if (is_first) {
      std::print("{}", val);
      is_first = false;
    } else {
      std::print(", {}", val);
    }
  };

  (print_signle(ptrs), ...);
  std::println("");
}

struct MemFuncPtrLayout {
  std::uintptr_t ptr;
  std::ptrdiff_t adj;
};

template <typename T>
concept IsMemberFuncPointer = std::is_member_function_pointer_v<T>;

template <IsMemberFuncPointer Ptr>
auto ToRawLayout(Ptr ptr) {
  return std::bit_cast<MemFuncPtrLayout>(ptr);
}

template <IsMemberFuncPointer... Ptrs>
void PrintMemberFuncPointers(Ptrs... ptrs) {
  auto print_signle = [is_first = true](auto ptr) mutable {
    MemFuncPtrLayout val = ToRawLayout(ptr);
    if (is_first) {
      std::print("[ptr: 0x{:x}, adj: 0x{:x}]", val.ptr, val.adj);
      is_first = false;
    } else {
      std::print(", [ptr: 0x{:x}, adj: 0x{:x}]", val.ptr, val.adj);
    }
  };

  (print_signle(ptrs), ...);
  std::println("");
}
