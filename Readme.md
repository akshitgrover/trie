<p align="center">
<img src="https://github.com/akshitgrover/trie/blob/master/static/logo.png" alt="LOGO">
<br><br>
<b>STL Compatible TRIE data structure implementation</b>
</p>

# Trie
Trie is nothing but a data structure in the form of a tree which is in turn used to retrieve data. Trie store value against a key which is a string, Since each character of a string gets a new node, Trie is also known as a prefix tree.
Data in a Trie is stored in a lexographical order.

Tries offer retreival of data against a string in **O(M)** where M is the key size unlike binary tree which takes **O(M * log(N))** where N is the total number of keys stored.

There are certain memory optimized data structures derived from `TRIE` such as `TSTs` but this project deals only with `TRIEs`.

# Navigate

- [Trie](#trie)
- [Navigate](#navigate)
- [Reference](#reference)
  - [Constructor](#constructor-triet)
  - [Insert](#insert-void-trietinsertstdstring-key-t-value)
  - [Exist](#exist-bool-trietexiststdstring-key)
  - [Empty](#empty-bool-trietempty)
  - [Iterator](#iterator-trietiterator)
    - [Begin iterator](#begin-iterator-typename-trietiterator-trietbegin)
    - [End iterator](#end-iterator-typename-trietiterator-trietend)
    - [Reverse Begin iterator](#reverse-begin-iterator-typename-trietiterator-trietrbegin)
    - [Reverse End iterator](#reverse-end-iterator-typename-trietiterator-trietrend)
  - [Find](#find-typename-trietiterator-trietfindstdstring-key)
- [Copyright & License](#copyright--license)

<p align="center">
<img src="https://github.com/akshitgrover/trie/blob/master/static/sample.jpeg" alt="sample">

Image Courtesy: <a href="https://medium.com/coinmonks/ethereum-under-the-hood-part-4-the-trie-a3f71f8dbef8">Article</a>
</p>

# Reference

## Constructor trie\<T>()

T -> std::string || char* || char[]

Constructor function returns a reference to newly initialized trie data structure.

```cpp
#include <string>
#include <trie>

int main() {
  trie<std::string> t; // Default Constructor
  return 0;
}
```
or

```cpp
#include <string>
#include <trie>

int main() {
  trie<std::string> t = *(new trie<std::string>());
  return 0;
}
```

## Insert: void trie\<T>::insert(std::string key, T value)

Insert member function is used to insert key & value into the trie data structure.

```cpp
#include <string>
#include <trie>

int main() {
  trie<std::int> t; // Default Constructor
  std::string s = "helloworld";
  t.insert(s, 11);
  return 0;
}
```

## Exist: bool trie\<T>::exist(std::string key)

Exist member function is used to check existence of a key in the trie data structure.

```cpp
#include <string>
#include <trie>

int main() {
  trie<std::int> t; // Default Constructor
  std::string s = "helloworld";
  t.insert(s, 11);
  t.exist(s); // true
  t.exist("hello"); // false
  return 0;
}
```

## Empty: bool trie\<T>::empty()

Return true/false depending on if the data structure is empty or not.

```cpp
#include <string>
#include <trie>

int main() {
  trie<std::int> t; // Default Constructor
  std::string s = "helloworld";
  t.empty(); // true;
  t.insert(s, 11);
  t.empty(); // false
  return 0;
}
```


## Iterator: trie\<T>::iterator

Iterators are a very important part of STL.
Trie project also has iterators to support the same.

```cpp
#include <trie>

int main() {
  trie<std::int> t; // Default Constructor
  trie<std::int>::iterator it;
  return 0;
}
```

### Begin iterator: typename trie\<T>::iterator trie\<T>::begin()

Points to the beginning of the data structure.

```cpp
#include <trie>

int main() {
  trie<std::int> t; // Default Constructor
  trie<std::int>::iterator it = t.begin();
  return 0;
}
```

### End iterator: typename trie\<T>::iterator trie\<T>::end()

Points to end of the data structure.

```cpp
#include <trie>

int main() {
  trie<std::int> t; // Default Constructor
  trie<std::int>::iterator it = t.end();
  return 0;
}
```

***Note:*** If Trie is empty `begin == end`

### Reverse Begin iterator: typename trie\<T>::iterator trie\<T>::rbegin()

Points to the last element of the data structure.

```cpp
#include <trie>

int main() {
  trie<std::int> t; // Default Constructor
  trie<std::int>::iterator it = t.rbegin();
  return 0;
}
```

### Reverse End iterator: typename trie\<T>::iterator trie\<T>::rend()

Points to reverse end of the data structure.
Used by reverse begin iterator to find the end.

```cpp
#include <trie>

int main() {
  trie<std::int> t; // Default Constructor
  trie<std::int>::iterator it = t.rend();
  return 0;
}
```

***Note:*** If Trie is empty `rbegin == rend`

**PS:** Iterators can both be incremented and decremented.

## Find: typename trie\<T>::iterator trie\<T>::find(std::string key)

Find is used to search and return iterator pointing to that particular key.
If key is not present find returns end iterator.

```cpp
#include <iostream>
#include <string>
#include <trie>

int main() {
  trie<std::int> t; // Default Constructor
  std::string s = "helloworld";
  t.insert(s, 11);
  trie<std::int>::iterator it = t.find(s);
  std::cout << *it; // 11
  return 0;
}
```

# Copyright & License

[MIT License](https://opensource.org/licenses/MIT)

Copyright (c) 2019 Akshit Grover
