#include <iostream>
#include <cmath>
#include <thread>
using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

void sleep_millis(unsigned int ms)
{
  std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

int x_coordinate(int char_num, double degree)
{
    double radian = degree*(3.141/180);
    double horizontal = char_num * sin(radian);
    int result = round(horizontal);
    return result;
}
int y_coordinate(int char_num, double degree)
{
    double radian = degree*(3.141/180);
    double vertical = char_num * cos(radian);
    int result = round(vertical);
    return result;
}

void printing_second_hand(int second)
{
    int degree = second * 6;
    int char_len = 20;
    bool coordinates[39][39] = {false};
    for(int i = char_len - 1 ; i >= 0; i--)
    {
        int x = x_coordinate(i,degree);
        int y = y_coordinate(i,degree);
        
        for(int i = 39; i >= 0; i--)
        {
            for(int j = 0; j <= 39; j++)
            {
                int y_position = 20 + y - 1;
                int x_position = 19 + x;
                if ((i == y_position) && (j == x_position))
                {
                    coordinates[i][j] = true;
                }
            }
        }
    }
    for(int i = 38; i >= 0; i--)
    {
        for(int j = 0; j <= 38; j++)
        {
            // cout << coordinates[i][j] << " ";
            if(coordinates[i][j])
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    for (int i = 0; i <= 59; i++)
    {
        system("clear");
        printing_second_hand(i);
        sleep_millis(1000);
    }
    // printing_second_hand(45);
    return 0;
}
