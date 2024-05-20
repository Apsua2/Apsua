// -----1-----

// **std::sort** - сортировка элементов контейнера:

//   #include <algorithm>
//   #include <vector>
//   #include <iostream>

//   int main() {
//       std::vector<int> vec = {5, 2, 8, 1, 9};
//       std::sort(vec.begin(), vec.end());
//       for (int num : vec) {
//           std::cout << num << " ";
//       }
//       return 0;
//   }
   
// -----2-----

// **std::find** - поиск элемента в контейнере:

//   #include <algorithm>
//   #include <vector>
//   #include <iostream>

//   int main() {
//       std::vector<int> vec = {5, 2, 8, 1, 9};
//       auto it = std::find(vec.begin(), vec.end(), 8);
//       if (it != vec.end()) {
//           std::cout << "Элемент найден\n";
//       } else {
//           std::cout << "Элемент не найден\n";
//       }
//       return 0;
//   }
   
// -----3-----

// **std::for_each** - применение функции к каждому элементу контейнера:

//   #include <algorithm>
//   #include <vector>
//   #include <iostream>

//   void printSquare(int num) {
//       std::cout << num * num << " ";
//   }

//   int main() {
//       std::vector<int> vec = {5, 2, 8, 1, 9};
//       std::for_each(vec.begin(), vec.end(), printSquare);
//       return 0;
//   }
   
// -----4-----

//  **std::count** - подсчет количества элементов в контейнере:

//   #include <algorithm>
//   #include <vector>
//   #include <iostream>

//   int main() {
//       std::vector<int> vec = {5, 2, 8, 1, 9, 8, 3};
//       int count = std::count(vec.begin(), vec.end(), 1);
//       std::cout << "Количество элементов 1: " << count << "\n";
//       return 0;
//   }
   
// -----5-----

// **std::transform** - применение функции к каждому элементу контейнера и сохранение результатов в другой контейнер

//   #include <algorithm>
//   #include <vector>
//   #include <iostream>

//   int square(int num) {
//       return num * num;
//   }

//   int main() {
//       std::vector<int> vec = {5, 2, 8, 1, 9};
//       std::vector<int> result(vec.size());
//       std::transform(vec.begin(), vec.end(), result.begin(), square);
//       for (int num : result) {
//           std::cout << num << " ";
//       }
//       return 0;
//   }
   
// -----6-----

// **std::replace** - замена всех вхождений элемента в контейнере на другой элемент:
 
//   #include <algorithm>
//   #include <vector>
//   #include <iostream>

//   int main() {
//       std::vector<int> vec = {5, 2, 8, 1, 9};
//       std::replace(vec.begin(), vec.end(), 8, 1000);
//       for (int num : vec) {
//           std::cout << num << " ";
//       }
//       return 0;
//   }
   
// -----7-----

// **std::reverse** - обращение порядка элементов в контейнере:
   
  #include <algorithm>
  #include <vector>
  #include <iostream>

  int main() {
      std::vector<int> vec = {5, 2, 8, 1, 9};
      std::reverse(vec.begin(), vec.end());
      for (int num : vec) {
          std::cout << num << " ";
      }
      return 0;
  }
