#include <cstdint>
#include <set>
#include <vector>

// std::ranges::range<CollT> is a concept from standard library
template <typename CollT>
concept SequenceCont =
    std::ranges::range<CollT> && requires(std::remove_cvref_t<CollT> c,
                                          std::ranges::range_value_t<CollT> v) {
      // Can push_back
      c.push_back(v);
      // Can pop_back
      c.pop_back();
      // Can insert
      c.insert(c.begin(), v);
      // Can erase
      c.erase(c.begin());
      // Can clear
      c.clear();
      // Can be constructed using initializer list
      std::remove_cvref_t<CollT>{v, v, v};
      // Can be assigned using initializer list
      c = {v, v, v};
      // Support partial equal
      { c < c } -> std::convertible_to<bool>;
    };

template <typename CollT, typename T>
void add(CollT &coll, const T &val)
  requires SequenceCont<CollT>
{
  coll.push_back(val);
}

void add(auto &coll, const auto &val) { coll.insert(val); }

int main() {
  std::vector<int> coll1;
  std::set<int> coll2;

  static_assert(SequenceCont<std::vector<int>>);

  add(coll1, 42);
  add(coll2, 42);
  return 0;
}