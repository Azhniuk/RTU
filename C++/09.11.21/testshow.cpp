#include "CarShowrooms.h"

int main(void)
{
    CarShowrooms car_showrooms;

    CarShowrooms car_showrooms_1{ 5, 10 ,20, 30, 40, CarShowrooms::TestDrive::Ready };
    CarShowrooms car_showrooms_2{
      5, 10 ,20, 30, 40,
      CarShowrooms::PersonalInfo{"fdsaf", "543252345", "passport"},
      CarShowrooms::Car{"ford", "fas"},
      CarShowrooms::TestDrive::Ready
    };

    CarShowrooms car_showrooms_3 = car_showrooms_2;

    for (size_t i = 0; i < 4; i++)
    {
        car_showrooms.NextTask(i);
    }

    for (size_t i = 0; i < 4; i++)
    {   
        car_showrooms_1.NextTask(i);
    }

    for (size_t i = 2; i < 4; i++)
    {
        car_showrooms_2.NextTask(i);
    }

    for (size_t i = 2; i < 4; i++)
    {
        car_showrooms_3.NextTask(i);
    }

    CarShowrooms* obj_ptr = new CarShowrooms;
    delete obj_ptr;
}