#include <iostream>
#include <chrono>
#include <thread>
#include <cmath>

static constexpr int max_speed = 180;
static constexpr double pi = 3.14159265358979323846;

static auto to_radians = [](double degrees) {
    return degrees/180 * pi;
};

// Function that simulates speed over time using mathematical model.
// https://www.wolframalpha.com/input?i=abs%28sin%28t%29%2Bsin%284*t%29%2F4%2B2*sin%28t%2F8%29%29%2F3
static auto calculate_speed = [](std::size_t time) {
    auto t = to_radians(time);
    using namespace std;
    return static_cast<int>(abs(sin(t)+sin(4*t)/4+2*sin(t/16))/3 * max_speed);
};

int main() {
    using namespace std::chrono_literals;

    for (std::size_t t = 0;; ++t) {
        std::this_thread::sleep_for(50ms);
        std::cout << calculate_speed(t) << std::endl;
    }
}
