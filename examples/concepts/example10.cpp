#include <iostream>
#include <list>
#include <vector>

template <typename T>
concept BigType = sizeof(T) > 8;

template <typename T>
concept BigClassType1 = sizeof(T) > 8 && std::is_class_v<T>;

template <typename T>
concept BigClassType2 = BigType<T> && std::is_class_v<T>;

/*
 * BigClassType1 DOES NOT subsume BigType, Hence:
 *
 * void foo1(BigType auto) {...}
 * void foo1(BigClassType1 auto) {...}
 *
 * are ambiguous
 *
 * BigClassType2 subsumes BigType, Hence:
 *
 * void foo1(BigType auto) {...}
 * void foo1(BigClassType2 auto) {...}
 *
 * are NOT ambiguous
 *
 */

int main() { return 0; }