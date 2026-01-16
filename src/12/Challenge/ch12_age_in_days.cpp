// C++ Code Challenges, LinkedIn Learning

// Challenge #12: Age in Days Calculator
// Write an application that asks the user's birth date and responds with the user's age in days. 
// If the user claims to be over 120 years old, output a message calling the bluff.

#include <iostream>
#include <string>
#include <ctime>

const unsigned char days_in_month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

int is_leap_year(int year){
    if(year%4)
        return 0;
    if(year%100)
        return 1;
    if(year%400)
        return 0;
    return 1;
}

int days_in_range(int start_y, int start_m, int start_d, int end_y, int end_m, int end_d)
{
    int days = 0;
    while (start_d != end_d || start_m != end_m || start_y != end_y)
    {
        //increment days count
        days++;
        // Increment the day
        start_d++;
        // Check if we need to increment month
        if (start_d > days_in_month[start_m -1 ])
        {
            // allow 29 days in February of a leap year
            if (start_m == 2 && is_leap_year(start_y) && start_d == 29)
            {
            }
            else // Increment month and reset day
            {
                start_d = 1;
                start_m++;
                // Increment year if needed
                if (start_m > 12)
                {
                    start_m = 1;
                    start_y++;
                }
            }
        }
    }
    
    return days;
}

// Age in Days, main()
// Summary: This application asks the user's birth date and prints their age in days.
int main(){
    int birth_y, birth_m, birth_d, today_y, today_m, today_d, age;

    std::cout << "Enter your birth date's month as a number: " << std::flush;
    std::cin >> birth_m;
    std::cout << "Enter your birth date's day: " << std::flush;
    std::cin >> birth_d;
    std::cout << "Enter your birth date's year: " << std::flush;
    std::cin >> birth_y;

    //check for valid month
    if(birth_m < 1)
        birth_m = 1;
    if(birth_m > 12)
        birth_m = 12;

    //check for valid day
    if(birth_d < 1)
        birth_d = 1;
    if(birth_d > 31)
        birth_d = 31;

    //get the current date
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    today_y = now->tm_year + 1900;
    today_m = now->tm_mon + 1;
    today_d = now->tm_mday;

    age = days_in_range(birth_y, birth_m, birth_d, today_y, today_m, today_d);

    if(age < 43830)
        std::cout << "You are " << age << " days old.";
    else
        std::cout << "Come on. You can't be " << age << " days old!";
    std::cout << std::endl << std::flush;

    //test daysinrange function and validate with std::difftime function   
    std::tm birth_tm{0, 0, 0, birth_d, birth_m - 1, birth_y - 1900};
    std::time_t birth_time = std::mktime(&birth_tm);
    std::tm today_tm{0, 0, 0, today_d, today_m - 1, today_y - 1900};
    std::time_t today_time = std::mktime(&today_tm);
    double diff_seconds = std::difftime(today_time, birth_time);
    int diff_days = static_cast<int>(diff_seconds / (24 * 60 * 60));
    if(diff_days != age)
        std::cout << "Error: calculated age does not match std::difftime = " << diff_days << std::endl;
    else
        std::cout << "Calculated age matches std::difftime result of " << diff_days << " days." << std::endl;

    //now test all dates from today to 1900-01-01
    
    int test_count = 0;
    for(int year = today_y-1; year > 1900; year--){
        for(int month = 12; month >=1; month--){
            int dim = days_in_month[month-1];
            //adjust for leap year in February
            if(month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))){
                dim = 29;
            }
            for(int day = dim; day >=1; day--){
                int test_age = days_in_range(year, month, day, today_y, today_m, today_d);
                std::tm test_birth_tm{0, 0, 0, day, month - 1, year - 1900};
                std::time_t test_birth_time = std::mktime(&test_birth_tm);
                std::tm test_today_tm{0, 0, 0, today_d, today_m - 1, today_y - 1900};
                std::time_t test_today_time = std::mktime(&test_today_tm);
                double test_diff_seconds = std::difftime(test_today_time, test_birth_time);
                int test_diff_days = static_cast<int>(test_diff_seconds / (24 * 60 * 60));
                if(test_diff_days != test_age){
                    std::cout << "Error: calculated age does not match std::difftime result for date " << year << "-" << month << "-" << day << "." << std::endl;
                }
                test_count++;
            }
        }
    }
    std::cout << "Total test cases: " << test_count << std::endl;

    return 0;
}
