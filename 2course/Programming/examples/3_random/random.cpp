/*
    Пример использования генератора (псевдо)случайных чисел.

    В стандартной библиотеке С++ используются функции из языка С.
    Отличия от random.c программы рядом только в заголовочных файлах и функцях ввода/вывода
 
    Для получения случайных числе используется функция:
        int rand();
    из <cstdlib>. Она возращает значение от 0 до RAND_MAX.
    RAND_MAX может зависеть от стандартной C-ной библиотеки, однако гарантируется,
    что это число не будет меньше 32767.

    Для получения различной последовательности случайных чисел при последовательных
    запусках программы, используется функция инициализации генератора:
        void srand (unsigned int seed);
    Она принимает один аргумент - целое число - от которого зависит, какая последовательность будет выдаваться
    функцией rand(), и не возращает никакого значения.
*/

#include <iostream>
#include <cstdlib>  // библиотека С для функций создания псевдослучайных чисел
#include <ctime>    // библиотека для получения и преобразования значений времени в языке C.

using namespace std;

int main()
{
    int rnd1, rnd2;
    double rnd3;

    // Пример инициализации генератора случайных чисел постоянными значениями.
    // Два следующих printf'а будут показывать одни и теже числа при каждом последовательном запуске программы
    srand(123);
    cout << "First 3 numbers for seed 123 are: " << rand() << ", " << rand() << ", " << rand() << endl;

    srand(8872);
    cout << "First 3 numbers for seed 8872 are: " << rand() << ", " << rand() << ", " << rand() << endl;

    /*
        Ниже используется функция
            time(...)
        из библиотеки ctime. В данном случае - time(NULL) -, она возращает количество секунд, прошедших
        с 00:00 часов 1 января 1970 года.
        Обычно в таком виде используется инициализация генератора случайных чисел для получения различных последовательностей
        чисел при повторных запусках программы.
    */
    srand(time(NULL));

    // несколько примеров
    rnd1 = rand() % 21;      // получить случайное число от 0 до 20
    rnd2 = rand() % 10 - 5;  // получить случайное число от -5 до 4.

    /*
        Получить случайное действительное число от 0 до 1.
        Здесь используется явное приведение типа int к типу double для того, чтобы операция деления была выполнена
        над действительными числами, иначе деление было целочисленными и невозможно было бы получить числа отличные
        от нуля и единицы.

        В С++ можно использовать как явное приведение типа в стиле C:
            (type) value
        , где type - тип, значение которого нужно получить; value - значение, которое нужно привести к требуемому типу.

        Так и приведение типа в функциональном стиле:
            type(value)
        Ниже используется второй вариант
    */
    rnd3 = ( double( rand() ) ) / RAND_MAX;

    cout << "random number1: " << rnd1 << endl << "random number2: " << rnd2 << endl << "random number3: " << rnd3 << endl;
    return 0;
}