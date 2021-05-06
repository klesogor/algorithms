// ЛАБОРАТОРНА РОБОТА №1
// Проектування алгоритмів
// Студент Косенко А.П.
// Завдання:
// 1. Створити программу, яка формує одновимірний масив з n випадкових чисел
// *Значення n змінюються в межах від 10 до 50 мільйонів
// 2. Окремо визначити добуток парних чисел та добуток непарних чисел - !!! в цій частині програма не працює!!! - яке максимальне значення можна записати в int? в long?
// 3. Виконати оцінку часу виконання алгоритму експериментальним способом,
//  використовуючи будь-який обраний метод. - !!! Спробував реалізувати, але не працює строки закоментував та позначив *** (47, 67-70)
// 4. Побудувати графік залежності часу виконання від обсягу вхідних даних.
// ІНСТРУКЦІЇ:
// 1. Значення вихідних даних необхідно задавати на початку роботи програми
// за допомогою генератора випадкових чисел, причому робити це до початку
// вимірювання часу роботи алгоритму.
// 2. Алгоритм в ході вимірів повинен виконуватися в циклі декілька мільйонів разів,
// щоб він не закінчував роботу занадто швидко, а виконувався б хоча б декілька секунд
// 3. Вимірювання необхідно повторити п'ять разів для різного обсягу вихідних даних (Я так розумію мова йде про різну кількість парних та непарних чисел).
// Кількість повторювань алгоритму в кожному вимірюванні повинна бути однаковою.



#include <iostream>
#include <algorithm>
#include <numeric>
#include <ctime>
#include <chrono>
#include <pair>

using namespace std;

int* generateRandomArray(int size){
    int *array = new int[size]; // динамически выделяем память под массив
    srand(time(0));
    for(int i = 0; i < n;  i++){
        array[i] = 1 + rand() % 10;
    }
}

//will not work
std::pair<int, int> getOddAndEvenProduct(int* arr, int size){
  int odd = 1;
  int even = 1;

  for(int i = 0; i < size; i++){
    if(arr[i] % 2 == 0){
      odd *= arr[i];
    } else {
      even *= arr[i];
    }
  }

  return std::make_pair(odd,even);
}

int main()
{
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    
    for(int n = 10000000; n < 50000000; n += 10000000){
        int *arr = generateRandomArray(n); // генерируем массив
        auto t1 = high_resolution_clock::now();
        auto res = getOddAndEvenProduct(arr);
        auto t2 = high_resolution_clock::now();
        cout << "Running for size " << n << "\n";
        cout << "Execution time was " << duration_cast<milliseconds>(t2 - t1) << " ms";
        cout << "Odd product is: " << res->first <<"\nEven product is: " << res->second << "\n"; 
        cout << "---------------------------------------------------------------------" << "\n";
        delete arr;
    }
    
    return 0;//finish successfully
    
    // динамически выделяем целочисленную переменную, присваиваем ее адрес указателям для хранения значений произведений четных и нечетных чисел
    // и прямо инициализируем начальные значения переменных для хранения результатов произведений
    int *ptr_evenMultiplication = new int (1);
    int *ptr_oddMultiplication = new int (1);

    // заполняем массив рандомными числами от 1 до 10
//  ***  auto begin = std::chrono::steady_clock::now();//запускаем таймер
    // перебираем массив и проводим вычисления произведения четных и нечетных чисел
    for (int i = 0; i < n; i++)
        {
        if ((array[i] % 2) == 0) // поиск и произведение четных значений в одномерном массиве
            *ptr_evenMultiplication *= array[i];// возвращаем результат умножения четных чисел на элемент массива
        else
            return *ptr_evenMultiplication;
        }
    cout << "Result of multiplication of even numbers = " << *ptr_evenMultiplication << endl;
        
    for (int i = 0; i < n; i++)
        {
        if ((array[i] % 2) != 0) // поиск и произведение четных значений в одномерном массиве
            *ptr_oddMultiplication *= array[i]; // возвращаем результат умножения нечетных чисел на элемент массива
        else
            return *ptr_oddMultiplication;
        }
    cout << "Result of multiplication of odd numbers = " << *ptr_oddMultiplication << endl;

//  ***  auto end = std::chrono::steady_clock::now();//останавливаем таймер
    // преобразуем объект типа time_point во временной интервал в миллисекундах
//  ***  auto elapsed_ms = std::chrono::duration_cast < std::chrono::milliseconds(end - begin);
//  ***  cout << "The time of algorithm work: " << elapsed_ms.count() << " ms" << endl;

    //освобождаем выделенную память
    delete array;
    delete ptr_evenMultiplication;
    delete ptr_oddMultiplication;

// Использование алгоритма библиотеки STL для произведения элементов массива
    // for(i = 0; i < n;  i++){
    //     cout << array[i] << " ";
    // }
    // cout << endl;

    // auto *ptr_evenMultiplication = accumulate(begin(array), end(array), 1, [](int a, int b)
    // {
    //     if (b % 2 == 0)
    //         return a * b;
    //     else
    //         return a;
    // });
    
    // cout << "Result of multiplication of even numbers = " << *ptr_evenMultiplication << endl;

    // auto *ptr_oddMultiplication = accumulate(begin(array), end(array), 1, [](int a, int b)
    // {
    //     if (b % 2 != 0)
    //         return a * b;
    //     else
    //         return a;
    // });
    
    // cout << "Result of multiplication of odd numbers = " << *ptr_oddMultiplication << endl;

    system("pause");
    return 0;

}
