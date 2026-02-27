#include <iostream>
#include "../include/helpers.h"

using namespace Math;

void ShowMenu()
{
    std::cout << "\n==== Math Scalar Test ====\n";
    std::cout << "1. Basic Helpers (Abs, Min, Max, Sign)\n";
    std::cout << "2. Interpolation (Clamp, Lerp, SmoothStep)\n";
    std::cout << "3. Rounding (Floor, Ceil, Round, Fract)\n";
    std::cout << "4. Angle Helpers (Deg/Rad, Wrap)\n";
    std::cout << "5. Comparison (IsZero, NearlyEqual)\n";
    std::cout << "6. Modulo\n";
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
            std::cout << "Min(3,7) = " << Min(3.0f, 7.0f) << "\n";
            std::cout << "Max(3,7) = " << Max(3.0f, 7.0f) << "\n";
            std::cout << "Sign(-5) = " << Sign(-5) << "\n";
            break;
        }

        case 2:
        {
            std::cout << "\nClamp(1.5) = " << Clamp(1.5f) << "\n";
            std::cout << "Lerp(0,10,0.5) = " << Lerp(0.0f, 10.0f, 0.5f) << "\n";
            std::cout << "SmoothStep(0,1,0.5) = "
                      << SmoothStep(0.0f, 1.0f, 0.5f) << "\n";
            break;
        }

        case 3:
        {
            float x = -2.3f;
            std::cout << "\nFloor(" << x << ") = " << Floor(x) << "\n";
            std::cout << "Ceil(" << x << ") = " << Ceil(x) << "\n";
            std::cout << "Round(" << x << ") = " << Round(x) << "\n";
            std::cout << "Fract(" << x << ") = " << Fract(x) << "\n";
            break;
        }

        case 4:
        {
            float angle = 370.0f;
            std::cout << "\nDegToRad(90) = " << DegToRad(90.0f) << "\n";
            std::cout << "RadToDeg(PI) = " << RadToDeg(PI) << "\n";
            std::cout << "WrapToTAU(370 deg in rad) = "
                      << WrapToTAU(DegToRad(angle)) << "\n";
            std::cout << "WrapToPI(370 deg in rad) = "
                      << WrapToPI(DegToRad(angle)) << "\n";
            break;
        }

        case 5:
        {
            float a = 1.0000001f;
            float b = 1.0000002f;
            std::cout << "\nIsZero(1e-7) = " << IsZero(1e-7f) << "\n";
            std::cout << "NearlyEqual(a,b) = "
                      << NearlyEqual(a, b) << "\n";
            break;
        }

        case 6:
        {
            std::cout << "\nMod(-5.5, 2.0) = "
                      << Mod(-5.5f, 2.0f) << "\n";
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