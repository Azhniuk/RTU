#include <string>
#define REDBACKGROUND "\033[1;41m"
#define RESET "\033[m"
#define TAB "\t"

class CarShowrooms
{
public:
    struct PersonalInfo
    {
        std::string full_name;
        std::string id_code;
        std::string passport;
    };

    struct Car
    {
        std::string brand;
        std::string model;
    };

    enum class Registration
    {
        Registered,
        Unregistered,
        Registering,
    };

    enum class Insurance
    {
        Insured,
        Uninsured
    };

    enum class TestDrive
    {
        Ready,
        NotReady,
        NoTestDrive,
    };

    enum class Warranty
    {
        Year = 1,
        Year_2,
        Year_5 = 5,
    };

    CarShowrooms();
    CarShowrooms(const CarShowrooms& other);
    CarShowrooms(int car_sale, int car_purchase, int sell_auto_parts, int car_exchange, int maintenance, TestDrive test_drive);
    CarShowrooms(int car_sale, int car_purchase, int sell_auto_parts, int car_exchange, int maintenance, PersonalInfo personal_info, Car car, TestDrive test_drive);
    ~CarShowrooms();

    void NextTask(int);

private:
    void FillingData(PersonalInfo&& info);
    void PushDataCar(Car&& car);
    void DeliveryDate();
    void Submission();
    void Confirmation();
    void Processing();
    void Completion();

    struct Order
    {
        PersonalInfo personal;
        Car car;

        std::string car_delivery;

        Registration car_registration;
        Insurance car_insurance;
        TestDrive car_test_drive;
        Warranty product_warranty;
    };

    int car_sale;
    int car_purchase;
    int sell_auto_parts;
    int car_exchange;
    int maintenance;

    Order order;
};