#include <iostream>
#include <lrucache.h>

int main() {

    LRUCache<int, std::string, 3> cache;

    cache.put(1, "one");
    cache.put(2, "two");
    cache.put(3, "three");
    // cache.print(); // Ожидаем: {3:three} {2:two} {1:one}


    cache.put(4, "four");
    // cache.print(); // Ожидаем: {4:four} {3:three} {2:two}


    std::cout << "Get 3: " << cache.get(3) << std::endl; // Ожидаем: three
    // cache.print(); // Ожидаем: {3:three} {4:four} {2:two}


    cache.put(4, "four");
    std::cout << "Get 4: " << cache.get(4) << std::endl; // Ожидаем: FOUR
    // cache.print(); // Ожидаем: {4:FOUR} {3:three} {2:two}


    std::cout << "Contains 2: " << cache.contains(2) << std::endl; // 1 (true)
    std::cout << "Contains 5: " << cache.contains(5) << std::endl; // 0 (false)

    return 0;
}


// #include <iostream>
// #include "lrucache.h"

// // Пример использования
// int main() {
//     std::cout << "Программа запущена" << std::endl;
//     Cache<int, std::string, 3> cache;

//     cache.put(1, "one");
//     cache.put(2, "two");
//     cache.put(3, "three");
//     cache.print(); // {3:three} {2:two} {1:one}

//     std::cout << "Get 2: " << cache.get(2) << std::endl;
//     cache.print(); // {2:two} {3:three} {1:one}

//     cache.put(4, "four"); // Вытеснит 1, так как он был использован давнее всех
//     cache.print(); // {4:four} {2:two} {3:three}

//     try {
//         std::cout << "Get 1: " << cache.get(1) << std::endl;
//     } catch (const std::exception& e) {
//         std::cout << "Error: " << e.what() << std::endl;
//     }

//     return 0;
// }

// #include "mainwindow.h"

// #include <QApplication>

// int main(int argc, char *argv[])
// {
//     QApplication a(argc, argv);
//     MainWindow w;
//     w.show();
//     return a.exec();
// }
