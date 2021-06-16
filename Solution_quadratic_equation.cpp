/*Квадратик*/
/*Облаков Никита Александрович
Дата создания: 19.03.2021
Версия: 1.0
Дата последнего изменения: 19.03.2021*/

#include <typeinfo>
#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

void s_qf(float a, float b, float c);
void s_vt(float a, float b, float c);
void s_factorize(float a, float b, float c);
void s_transfer(float a, float b, float c);
void s_square(float a, float b, float c);

int main()
{
    system("cls"); //чистим экран
    while (1)
    {
        float a, b, c;
        while (1)
        {
            cout << "Enter coefficients a, b and c: ";
            cin >> a >> b >> c; // ввод коэффициентов
            if (!cin)
            {
                cout << "\nIncorrect coefficients, try again\n";
                cin.clear();
                cin.ignore(10000, '\n');
                system("pause");
                system("cls");
            }
            if (a == 0 && b == 0 && c == 0) //просьба перезаписать коэффициенты + очистка экрана + переход в начало
            {
                cout << endl << "Really? Let's try again\n";
                system("pause");
                system("cls");
            }
            else if (a == 0) // решение линейного уравнения + очистка экрана + переход в начало + сообщение об ошибке + просьба перезаписать коэффициенты
            {
                if (b == 0) // ошибка
                {
                    cout << "\nOk, now you broked me :/\n";
                    system("pause");
                    cout << "\nIn theory of course\n\n";
                    Sleep(450);
                    system("cls");
                    continue;
                }
                else if (c == 0)
                {
                    cout << "X = 0" << endl;
                    system("pause");
                    system("cls");
                    continue;
                }
                cout << "X = " << -c / b << endl;
                system("pause");
                system("cls");

            }
            else break;
        }
        int t;
        cout << "\nHow would you like to solve?";
        while (1)
        {
            cout << endl << "Enter from 1 to 5:\n\t1 - Quadratic Formula\n\t2 - Using Vieta's Theorem\n\t3 - Factorization\n\t4 - \"Transfer\" method\n\t5 - \"Full square selection method\"" << endl; // меню методов
            cout << "\t0 - EXIT" << endl;
            cin >> t;
            switch (t) // выбор метода
            {
            case 0: return 0;
            case 1: s_qf(a, b, c); break;         // Метод решения по формуле дискриминанта   
            case 2: s_vt(a, b, c); break;         // Метод решения по Виета 
            case 3: s_factorize(a, b, c); break;  // Метод разложения на множители
            case 4: s_transfer(a, b, c); break;   // Метод "Переброски"
            case 5: s_square(a, b, c); break;     // Метод выделения полного квадрата
            }
            while (1) // отклик программы о дальнейших действиях
            {
                cout << endl << "Anything else?\n\t1 - Another method\n\t2 - New equation\n\t0 - EXIT" << endl;
                cin >> t;
                if (t == 1 || t == 2 ) { system("cls"); break; }
                else if (t == 0) return 0;
                else cout << "\n\nEnter from 0 to 2, please\n" << endl;
            }
            if (t == 2) break;
        }
    }
}

void s_qf(float a, float b, float c)
{
    float x1, x2, discriminant = 0;
    discriminant = b * b - 4 * a * c;
    cout << "\nDiscriminant = b^2 - 4*a*c\n" << endl; 
    cout << "Discriminant = " << discriminant;
    if (discriminant >= 0) 
    {
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        x2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << " > 0 => Roots are real and different\n" << endl;
        cout << "X1,2 = (-b +- sqrt(discriminant)) / (2 * a)\n" << endl;
        cout << "X1 = " << x1 << endl;
        cout << "X2 = " << x2 << endl;
    }

    else 
    {
        cout << " < 0 => There are no real solutions :(\n";   
    }
}

void s_vt(float a, float b, float c) // из-за перебора больших значений и статического шага этот метод самый медленный и самый недостоверный
{
    int n = 0;
    float x1, x2 = abs(c / a);
    cout << "\n-b/a = " << -b / a << endl << "c/a = " << c / a << endl;
    for (; x2 >= -abs(c / a); x2 -= 0.0000001)
    {
        x1 = (c / a) / x2;
        if (x1 + x2 == -b / a)
        {
            n = 1;
            break;
        }
    }
    if (n == 1)
        cout << "\nX1 = " << x1 << "\nX2 = " << x2 << endl;
    else cout << "\nThere are no real solutions :(" << endl;
}

void s_factorize(float a, float b, float c)
{
    float x1, x2, discriminant = 0;
    discriminant = b * b - 4 * a * c;
    cout << "\nDiscriminant = " << discriminant;
    if (discriminant >= 0)
    {
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        x2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << " > 0 => Can be factorized => Roots are real and different\n" << endl;
        if (x1 < 0 && x2 > 0) cout << "Factorized equation: " << "(x+" << x1 * (-1) << ") * (x" << x2 * (-1) << ") = 0\n" << endl;
        else if (x1 < 0 && x2 < 0) cout << "Factorized equation: " << "(x+" << x1 * (-1) << ") * (x+" << x2 * (-1) << ") = 0\n" << endl;
        else if (x1 > 0 && x2 < 0) cout << "Factorized equation: " << "(x" << x1 * (-1) << ") * (x+" << x2 * (-1) << ") = 0\n" << endl;
        else cout << "Factorized equation: " << "(x" << x1 * (-1) << ") * (x" << x2 * (-1) << ") = 0\n" << endl;
        cout << "X1 = " << x1 << endl;
        cout << "X2 = " << x2 << endl;
    }

    else
    {
        cout << " < 0 => Can not be factorized => There are no real solutions :(\n";
    }
}

void s_transfer(float a, float b, float c)
{
    cout << "\nax^2+bx+c = 0" << endl;
    cout << "ax^2+bx+c = (ax)^2+abx+ca" << endl << "y = ax" << endl << "y^2 + by + ca" << endl;
    float y1, y2, discriminant;
    discriminant = b * b - 4 * a * c;
    cout << "\nDiscriminant = " << discriminant;
    float c_1 = c * a;
    if (discriminant >= 0)
    {
        y1 = (-b + sqrt(discriminant)) / 2;
        y2 = (-b - sqrt(discriminant)) / 2;
        cout << " > 0 => Roots are real and different\n" << endl;
        cout << "y1,2 = (-b +- sqrt(discriminant)) / 2\nx1,2 = y1,2 / a\n" << endl;
        cout << "X1 = " << y1 / a << endl;
        cout << "X2 = " << y2 / a << endl;
    }

    else
    {
        cout << " < 0 => There are no real solutions :(\n";
    }
}

void s_square(float a, float b, float c)
{
    float x1, x2;
    if ((pow((b / (2 * a)), 2) - c / a) < 0) {cout << "\nThere is the square root of a negative number => There are no real solutions :(\n"; return;}
    if ((b * a) < 0) cout << "\nFull square is " << "x" << b / (2 * a) << endl;
    else cout << "\nFull square is " << "x+" << b / (2 * a) << endl;
    x1 = -sqrt(b / (2 * a) * b / (2 * a) - c / a) - b / (2 * a);
    x2 = sqrt(b / (2 * a) * b / (2 * a) - c / a) - b / (2 * a);
    cout << "\nX1 = " << x1 << endl;
    cout << "X2 = " << x2 << endl;
}