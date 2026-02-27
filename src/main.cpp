#include <iostream>
#include "../include/helpers.h"

using namespace Math;

void ShowMenu()
{
    std::cout << "\n==== Math Helpers Demo ====\n";
    std::cout << "1. Clamp\n";
    std::cout << "2. Lerp\n";
    std::cout << "3. SmoothStep\n";
    std::cout << "4. Min\n";
    std::cout << "5. Max\n";
    std::cout << "6. Abs\n";
    std::cout << "0. Exit\n";
    std::cout << "Choose an option: ";
}

int main()
{
    int choice;

    do
    {
        ShowMenu();
        std::cin >> choice;

        float a, b, x, t;

        switch (choice)
        {
        case 1:
            std::cout << "Enter value, min, max: ";
            std::cin >> x >> a >> b;
            std::cout << "Result: " << Clamp(x, a, b) << "\n";
            break;

        case 2:
            std::cout << "Enter a, b, t: ";
            std::cin >> a >> b >> t;
            std::cout << "Result: " << Lerp(a, b, t) << "\n";
            break;

        case 3:
            std::cout << "Enter edge0, edge1, x: ";
            std::cin >> a >> b >> x;
            std::cout << "Result: " << SmoothStep(a, b, x) << "\n";
            break;

        case 4:
            std::cout << "Enter two values: ";
            std::cin >> a >> b;
            std::cout << "Result: " << Min(a, b) << "\n";
            break;

        case 5:
            std::cout << "Enter two values: ";
            std::cin >> a >> b;
            std::cout << "Result: " << Max(a, b) << "\n";
            break;

        case 6:
            std::cout << "Enter value: ";
            std::cin >> x;
            std::cout << "Result: " << Abs(x) << "\n";
            break;

        case 0:
            std::cout << "Exiting...\n";
            break;

        default:
            std::cout << "Invalid option.\n";
        }

    } while (choice != 0);

    return 0;
}