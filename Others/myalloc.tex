// useage: vector<int, myalloc<int>> L;
static char space[10000000], *sp = space;
template <typename T> struct myalloc : allocator<T> {
  myalloc() {}
  template <typename T2> myalloc(const myalloc<T2> &a) {}
  template <typename T2> myalloc<T> &operator=(const myalloc<T2> &a) {
    return *this;
  }
  template <typename T2> struct rebind { typedef myalloc<T2> other; };
  inline T *allocate(size_t n) {
    T *result = (T *)sp;
    sp += n * sizeof(T);
    return result;
  }
  inline void deallocate(T *p, size_t n) {}
};
