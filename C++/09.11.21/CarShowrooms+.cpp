

#include "CarShowrooms.h"
#include <iostream>
#include <Windows.h>
#include <ctime>
#include <vector>
#include <conio.h>

CarShowrooms::CarShowrooms()
    : car_sale(), car_purchase(), sell_auto_parts(), car_exchange(), maintenance(),
    order(Order{ PersonalInfo{"", "", ""}, Car{"", ""}, "", Registration::Unregistered, Insurance::Uninsured, TestDrive::NoTestDrive, Warranty::Year })
{ }
CarShowrooms::CarShowrooms(const CarShowrooms& other)
{
    this->car_exchange = other.car_exchange;
    this->car_purchase = other.car_purchase;
    this->car_sale = other.car_sale;
    this->sell_auto_parts = other.sell_auto_parts;
    this->maintenance = other.maintenance;

    this->order = other.order;
}

CarShowrooms::CarShowrooms(int car_sale, int car_purchase, int sell_auto_parts, int car_exchange, int maintenance, TestDrive test_drive)
    : car_sale(car_sale), car_purchase(car_purchase), sell_auto_parts(sell_auto_parts), car_exchange(car_exchange), maintenance(maintenance),
    order(Order{ PersonalInfo{"", "", ""}, Car{"", ""}, "", Registration::Unregistered, Insurance::Uninsured, test_drive, Warranty::Year })
{ }

CarShowrooms::CarShowrooms(int car_sale, int car_purchase, int sell_auto_parts, int car_exchange, int maintenance, PersonalInfo personal_info, Car car, TestDrive test_drive)
    : car_sale(car_sale), car_purchase(car_purchase), sell_auto_parts(sell_auto_parts), car_exchange(car_exchange), maintenance(maintenance),
    order(Order{ personal_info, car, "", Registration::Unregistered, Insurance::Uninsured, test_drive, Warranty::Year })
{ }

CarShowrooms::~CarShowrooms()
{
    std::cout << "~CarShowrooms" << std::endl;
}

void CarShowrooms::FillingData(PersonalInfo&& info)
{
    this->order.personal = info;
    std::cout << "Personal Data received!" << std::endl;
    Sleep(1000);
}

void CarShowrooms::PushDataCar(Car&& car)
{
    this->order.car = car;

    if (order.car_test_drive == TestDrive::Ready)
    {
        std::vector<std::string> drive
        {
            "Test Drive",
            "Cancel"
        };

        char button{};
        int num_button{};

        while (button != ' ')
        {
            system("CLS");
            for (size_t i = 0; i < drive.size(); i++)
            {
                if (i == num_button)
                {
                    std::cout << REDBACKGROUND << drive[i] << RESET << std::endl;
                }
                else
                {
                    std::cout << drive[i] << std::endl;
                }
            }

            button = _getch();

            switch (button)
            {
            case 'w': num_button != 0 ? num_button-- : num_button; break;
            case 's': num_button != drive.size() - 1 ? num_button++ : num_button; break;
            case ' ':
                if (num_button == 0)
                {
                    std::cout << "Driving..." << std::endl;
                    Sleep(1500);
                }
                break;
            }
        }
    }

    std::cout << "Car Data received!" << std::endl;
    Sleep(1000);
}

void CarShowrooms::DeliveryDate()
{
    tm date_now;
    time_t time_now = time(NULL);

    long long day{};
    do
    {
        std::cout << "How many days to deliver the car to you?" << std::endl;
        std::cin >> day;
    } while (day <= 0);

    day *= 86400;
    time_now += day;
    localtime_s(&date_now, &time_now);

    this->order.car_delivery = std::to_string(date_now.tm_mday) + "/" + std::to_string(date_now.tm_mon + 1) + "/" + std::to_string(date_now.tm_year + 1900);
    std::cout << "Approximate date of arrival of the car: " << this->order.car_delivery << std::endl;
    Sleep(1000);
}

void CarShowrooms::Submission()
{
    char button{};
    int num_button{};

    std::vector<std::string> warranty
    {
        "1 Year", "2 Years", "5 Years"
    };

    while (button != ' ')
    {
        system("CLS");
        std::cout << "Move Up [w] Move Down[s] Quit[q] Enter[ ]" << std::endl;
        std::cout << "Select Warranty" << std::endl;

        for (size_t i = 0; i < warranty.size(); i++)
        {
            if (i == num_button)
            {
                std::cout << REDBACKGROUND << warranty[i] << RESET << std::endl;
            }
            else
            {
                std::cout << warranty[i] << std::endl;
            }
        }

        button = _getch();

        switch (button)
        {
        case 'w': num_button != 0 ? num_button-- : num_button; break;
        case 's': num_button != warranty.size() - 1 ? num_button++ : num_button; break;
        case ' ':
            if (num_button == 0)
            {
                order.product_warranty = Warranty::Year;
            }
            else if (num_button == 1)
            {
                order.product_warranty = Warranty::Year_2;
            }
            else
            {
                order.product_warranty = Warranty::Year_5;
            }
            break;
        }
    }

    system("CLS");

    if (this->order.car.brand.length() != 0)
    {
        Confirmation();
        Sleep(1000);
        Processing();
        Sleep(500);
        Completion();
    }
    else
    {
        Confirmation();
        Sleep(1000);
        Processing();
        Sleep(500);
        std::cout << "Data processing is not successful" << std::endl;
        order.car_registration = Registration::Unregistered;
        order.car_insurance = Insurance::Uninsured;
    }

    Sleep(500);
}

void CarShowrooms::Confirmation()
{
    order.car_registration = Registration::Registered;
    std::cout << "Confirmation of data" << std::endl;
}

void CarShowrooms::Processing()
{
    order.car_registration = Registration::Registering;
    std::cout << "Data Processing" << std::endl;
}

void CarShowrooms::Completion()
{
    std::cout << "Data processing is successful" << std::endl;
}

void CarShowrooms::NextTask(int task)
{
    static bool first_start{ true };

    if (!first_start)
    {
        std::cout << "Press \"Enter\" to continue" << std::endl;
        std::cin.ignore(32676, '\n');
        std::cin.clear();
    }
    else
    {
        first_start = false;
    }

    system("CLS");

    switch (task)
    {
    case 0:
    {
        if (order.personal.full_name.length() == 0)
        {
            std::string full_name{};
            std::cout << "Enter Full Name: ";
            std::getline(std::cin, full_name);

            std::string id_code{};
            std::cout << "Enter Identify code: ";
            std::getline(std::cin, full_name);

            std::string passport{};
            std::cout << "Enter the information from the passport: ";
            std::getline(std::cin, passport);

            FillingData(PersonalInfo{ full_name, id_code, passport });
            task++;
        }
        else
        {
            task++;
        }
        break;
    }
    case 1:
    {
        if (order.car.brand.length() == 0)
        {
            std::string brand{};
            std::cout << "Enter the car brand: ";
            std::getline(std::cin, brand);

            std::string model{};
            std::cout << "Enter the car model: ";
            std::getline(std::cin, model);

            PushDataCar(Car{ brand, model });
            task++;
        }
        else
        {
            task++;
        }
        break;
    }
    case 2:
        Submission();
        task++;
        break;
    case 3:
        DeliveryDate();
        task = 0;
        break;
    }
}