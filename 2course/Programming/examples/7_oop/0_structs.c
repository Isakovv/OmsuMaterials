/*
    Итак, до того, как приступать к изучению объектно-ориентированных особенностей C++,
    будет полезно узнать/вспомнить как себя ведут структуры в языке C.

    Структура - это составной тип данных, объединяющий множество поименнованных
    элементов под одним названием. Или, более неформально: это объединение кучи значений
    разных типов под единными именем.

    Синтаксис определения структуры в общем виде:
        struct <название структуры>
        {
            <тип_1> <поле_1>;
            <тип_2> <поле_2>;
            ...
            <тип_n> <поле_n>;
        };

    struct - ключевое слово языка,
    <название структуры> - выбираете на свой вкус (в некоторых случаях, навание может быть пропущено),
    <тип_1> и <поле_1> - определение именованного поля любого доступного типа данных языка (само определение
    аналогично определению переменных).

    Элементы структуры называются её полями. Рассмотрим конкретный пример - опишем материальную точку.
    Из физики, такая сущность определяется тремя пространственными координатами и весом точки.

        struct MaterialPoint
        {
            int x, y, z;
            float weight;
        };

    Как видно, поля одного типа можно определять, как и при объявлении переменных - просто через запятую.
    В итоге, был определён новый тип данных с названием MaterialPoint и 4-мя элементами.
    Пора его использовать. В языке C для определения переменных типа структура, нужно перед её названием
    указывать ключевое слово struct:
        struct MaterialPoint point1; // в данный момент все поля структуры инициализируются нулевыми значениями
                                     // 0 - для целых чисел, 0.0 - для действительных
    Объявив переменную типа объявленной структуры, доступ к каждому полю можно получить с
    помощью оператора '.':
        point1.x = 1;
        point1.y = 2;
        point1.weight = 3.5;

    И всё, на этом особые операции со структурой и её полями закончены.

    Можно остановиться на ещё на паре моментов. При объявлении переменной структуры возможно ещё
    одновременное определение всех полей с помощью следующего синтаксиса:
        struct MaterialPoint point2 = { 1, 3, 4, 1.2 };
    В фигурных скобках полям присваиваются значения в порядке их объявления в структуре. Если не все поля
    перечислены:
        struct MaterialPoint point2 = { 1, 3 };
    то последним двум полям будут присвоены нули.

    Второй момент связан с объявлением типа структуры. Не всем нравится писать ключевое слово struct
    при объявлении переменных и для облегчения своей тяжелой участи используется оператор - typedef.
    Данный оператор позволяет определить новый псевдоним для любого существующего типа данных.
    Его синтаксис:
        typedef <старый тип> <новое название>;
    Например,
        typedef int MyInt;
        MyInt i1 = 10, i2 = 20;

    Аналогично, можно применять оператор typedef для структур:
        typedef struct MatPoint
        {
            int x, y, z;
            float weight;
        } MaterialPoint;

        MaterialPoint point4; // теперь ключевое слово struct можно упускать.

    Структуры в языке С полезны для решения конкретных задач, когда приходится
    иметь дело со связанным набором некоторых значений. Также в первом приблежении,
    они позваляют описывать предметную область задачи и функции работы с ней. Как пример,
    структура MaterialPoint избавляет от необходимости согласовывать 4 независимых переменных.
*/

#include <stdio.h>
#include <stdlib.h>

struct MaterialPoint
{
    int x, y, z;
    float weight;
};

// Структуры, как и обычные типы данных можно передавать в функцию
void print_mp(struct MaterialPoint mp)
{
    printf("[Point: (%d, %d, %d) - %f]", mp.x, mp.y, mp.z, mp.weight);
}

int main(void)
{
    struct MaterialPoint point1 = { 1, 3, 4, 5.5 };

    print_mp(point1);

    // Также можно определять указатели на структуру
    struct MaterialPoint *p_point;
    p_point = &point1;

    // разыменование указателя
    print_mp(*p_point);

    // Доступ к полю через указатель можно получить так:
    (*p_point).x = 3;
    // Но лучше воспользоваться специальным оператором ->
    p_point->y = 5; // действие аналогична строке 106

    // как обычно, сама переменная point1 была изменена выше через указатель
    print_mp(point1);

    // Также экземпляр структуры может быть создан динамически через malloc или calloc
    // Динамически выделяем память под одну структуру
    p_point = (struct MaterialPoint*) calloc( 1, sizeof(struct MaterialPoint) );
    if ( p_point == NULL ) {
        perror("Could not allocate memory");
        exit(1);
    }

    p_point->x = p_point->y = p_point->z = 5;
    p_point->weight = 4.8;

    print_mp(*p_point);

    // Освобождение динамической памяти
    free(p_point);

    return 0;
}

