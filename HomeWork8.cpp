#include <iostream>

//1. Написать шаблонную функцию div, которая должна вычислять результат деления двух
//параметров и запускать исключение DivisionByZero, если второй параметр равен 0. В
//функции main выводить результат вызова функции div в консоль, а также ловить
//исключения.


template <typename T>
const T& div1(const T& a,const T& b)
{
    if (b == 0) throw "DivisionByZero";
    return a / b;
}




//2. Написать класс Ex, хранящий вещественное число x и имеющий конструктор по
//вещественному числу, инициализирующий x значением параметра. Написать класс Bar,
//хранящий вещественное число y (конструктор по умолчанию инициализирует его нулем) и
//имеющий метод set с единственным вещественным параметром a. Если y + a > 100,
//возбуждается исключение типа Ex с данными a*y, иначе в y заносится значение a. В
//функции main завести переменную класса Bar и в цикле в блоке try вводить с клавиатуры
//целое n. Использовать его в качестве параметра метода set до тех пор, пока не будет
//введено 0. В обработчике исключения выводить сообщение об ошибке, содержащее
//данные объекта исключения.

class EX
{
private:
    float x;
public:
    EX(float X): x(X) {}
};

class Bar
{
private:
    float y=0;
public:
    Bar(float Y) : y(Y) {}
    float set(float a) 
    {
        if (y + a > 100) 
        {
            throw EX(a * y);
        }
        else
        {
            return y = a;
        }
    };
};


//3. Написать класс «робот», моделирующий перемещения робота по сетке 10x10, у
//которого есть метод, означающий задание переместиться на соседнюю позицию. Эти
//методы должны запускать классы-исключения OffTheField, если робот должен уйти с
//сетки, и IllegalCommand, если подана неверная команда (направление не находится в
//нужном диапазоне). Объект исключения должен содержать всю необходимую
//информацию — текущую позицию и направление движения. Написать функцию main
//пользующуюся этим классом и перехватывающую все исключения от его методов, а
//также выводящую подробную информацию о всех возникающих ошибках.

class OffTheField
{
private:
    std::string m_error;
public:
    OffTheField(std::string error) : m_error(error)
    { }
    const char* getError() { return m_error.c_str(); }
};

class IllegalCommand
{
private:
    std::string m_error;
public:
    IllegalCommand(std::string error) : m_error(error)
    { }
    const char* getError() { return m_error.c_str(); }
};

class Bot
{
private:
    int x;
    int y;

protected:
    void set_w() {
        y=y - 1;
        if (y < 1) {
            throw OffTheField("y<0");
        }
    };
    void set_s() {
        y=y + 1;
        if (y > 10) {
            throw OffTheField("y>10");
        }
    };
    void set_a() {
        x=x - 1;
        if (x < 1) {
            throw OffTheField("x<0");
        }
    };
    void set_d() {
        x=x + 1;
        if (x > 10) {
            throw OffTheField("x>10");
        }
    };
public:
    Bot(int X, int Y) : x(X), y(Y) {}
    void enter() {
        char n;
        std::cin >> n;
        if (n == 's')
        {
            set_s();
        }
        else
        if (n == 'w')
        {
            set_w();
        }
        else
        if (n == 'a')
        {
            set_a();
        }
        else
        if (n == 'd')
        {
            set_d();
        }
        else {
            throw IllegalCommand("IllegalCommand");
        }
    }
};



int main()
{
    //Task 1
    
     //try 
     //{
     //    int a = div1(3, 0);
     //    std::cout << a;
     //}
     //catch (const char* exception)
     //{
     //    std::cerr << "DivisionByZero" << std::endl;
     //};
     //return 0;

    //Task 2
     
     //Bar ar = 0;
     //float n = 1;
     //do
     //{         
     //    std::cin >> n;
     //    try
     //    {
     //        ar.set(n);
     //    }
     //    catch (EX a)
     //    {
     //        std::cerr << "Error" << std::endl;
     //    };
     //} while (n!=0);
     //return 0;

    //Task 3

    Bot deg(1, 1);
    do
    {
        try {
            deg.enter();
        }
        catch (OffTheField tdfik)
        {
            std::cerr << "OffTheField: " << tdfik.getError() << std::endl;
            break;
        }
        catch (IllegalCommand)
        {
            std::cerr << "IllegalCommand" << std::endl;
            break;
        }
    } while (true);
    return 0;
 }
