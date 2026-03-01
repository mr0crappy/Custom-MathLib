#include <iostream>
#include "../include/helpers.h"
#include "../include/vec2.h"

using namespace Math;

void ShowMenu()
{
    std::cout << "\n==== Math Library Demo ====\n";
    std::cout << "1. Scalar Helpers\n";
    std::cout << "2. Vec2 Arithmetic\n";
    std::cout << "3. Vec2 LengthSq\n";
    std::cout << "0. Exit\n";
    std::cout << "Choose option: ";
}

int main()
{
    int choice;

    do
    {
        ShowMenu();
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            float x = -3.7f;
            std::cout << "\nAbs(" << x << ") = " << Abs(x) << "\n";
            std::cout << "Clamp(1.5) = " << Clamp(1.5f) << "\n";
            std::cout << "Round(" << x << ") = " << Round(x) << "\n";
            std::cout << "WrapToPI(370 deg) = "
                      << WrapToPI(DegToRad(370.0f)) << "\n";
            break;
        }

        case 2:
        {
            Vec2 a(2.0f, 3.0f);
            Vec2 b(4.0f, 1.0f);

            Vec2 sum = a + b;
            Vec2 diff = a - b;
            Vec2 scaled = a * 2.0f;

            std::cout << "\nVec2 Arithmetic:\n";
            std::cout << "a = (" << a.x << ", " << a.y << ")\n";
            std::cout << "b = (" << b.x << ", " << b.y << ")\n";

            std::cout << "a + b = (" << sum.x << ", " << sum.y << ")\n";
            std::cout << "a - b = (" << diff.x << ", " << diff.y << ")\n";
            std::cout << "a * 2 = (" << scaled.x << ", " << scaled.y << ")\n";

            break;
        }

        case 3:
        {
            Vec2 v(3.0f, 4.0f);
            std::cout << "\nVec2 LengthSq Test:\n";
            std::cout << "v = (" << v.x << ", " << v.y << ")\n";
            std::cout << "LengthSq = " << v.LengthSq() << "\n";
            break;
        }

        case 0:
            std::cout << "Exiting...\n";
            break;

        default:
            std::cout << "Invalid option.\n";
        }

    } while (choice != 0);

    return 0;
}