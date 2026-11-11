#include <iostream>
#include <array>
#include <chrono>
#include "constants.hpp"
#include "learncppSolution.hpp"

// > logic can be optimized (exact number of array size should be declared, we have excess allocation)
// > pre-calculate the distance traveled of the ball and inserting it on an array during compile-time 
// > we set a limit of the distance (385 000 00 meters "earth to moon distance"i)
template <int ArraySize>
consteval auto heightReference() {
    std::array<double, ArraySize> height {};
    int seconds { 0 };
    double currentHeight { maximumHeight };
    double prevHeight { currentHeight };
    for (auto itHeight { height.begin() }; currentHeight > 0; ++itHeight) {
        double distanceFallen { (gravity * (seconds * seconds)) / 2.0 };
        currentHeight -= distanceFallen; 

        *itHeight = prevHeight - currentHeight;
        ++seconds;
        prevHeight = currentHeight;
    }
    return height;
}


void calcBallHeight(double gravity, double towerHeight) {
    auto start { std::chrono::steady_clock::now() };

    int seconds { 0 };
    double currentBallHeight { towerHeight };
    while (true) {
        double distanceFallen { (gravity * (seconds * seconds)) / 2.0 };
        currentBallHeight = towerHeight - distanceFallen;

        if (currentBallHeight > 0) {
            std::cout << "At " << seconds << " seconds, the ball is at height: " << currentBallHeight << " meters\n";
            ++seconds;
        } else {
            std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
            break;
        }   
    }

    auto end { std::chrono::steady_clock::now() };
    std::cout << "Time elapsed: "
            << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
            << " microseconds\n";
}

// > the function uses the pre-compiled array of pre-calculated ball distance travelled
// > the optimization trick for this function is to leverage the pre-caluclated values and just do subtraction until the 
//      entered value becomes or exceeds 0 (towards negative)
// > we enter a value and the function looks at the index 0 of the pre-compiled array, it does a subtraction of the entered 
//       value and the first array value, if the difference does not exceed zero (towards negative), move the pointer of the
//       array 1 times to the right and repeat the process until the differences becomes or if it exceeds zero (towards negative)
void calcBallHeightOptimized(auto hReference, double towerHeight) {
    auto start { std::chrono::steady_clock::now() };

    int seconds { 0 };
    const double currentBallHeight { towerHeight };
    auto itHReference { hReference.begin() };

    while (true) {
        if ((currentBallHeight - *itHReference) > 0) {
            std::cout << "At " << seconds << " seconds, the ball is at height: " << currentBallHeight - *itHReference << " meters\n";
            ++seconds;
            ++itHReference;
        } else {
            std::cout << "At " << seconds << " seconds, the ball is on the ground\n";
            break;
        }
    }

    auto end { std::chrono::steady_clock::now() };
    std::cout << "Time elapsed: "
            << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
            << " microseconds\n";
}


int main() {
    constexpr auto heightRef { heightReference<ArraySize>() };

    // learncppSolution();
    // calcBallHeight(gravity, getTowerHeight());
    calcBallHeightOptimized(heightRef, getTowerHeight());

    return 0;
}
