//
// Created by puzinka on 23.12.2021.
//

#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "There are " << argc << " arguments:\n";

    // Перебираем каждый аргумент и выводим его порядковый номер и значение
    for (int count=0; count < argc; ++count)
        std::cout << count << " " << argv[count] << '\n';

    return 0;
}