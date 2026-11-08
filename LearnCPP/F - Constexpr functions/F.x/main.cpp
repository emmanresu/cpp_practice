#include <iostream>
#include <array>
#include "constants.hpp"
#include "learncppSolution.hpp"

// logic can be optimized (exact number of array size should be declared, we have excess allocation)
// pre-calculate the distance traveled of ball using array and consteval
consteval auto heightReference() {
    std::array<double, 1000> height {};
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

// we can just pre-calculate the distance fallen at compile time
// values are stored in an array and we just move the pointer forward when (it) does not go to zero
void calcBallHeight(double gravity, double towerHeight) {
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
}

void calcBallHeightOptimized(auto hReference, double towerHeight) {
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
}

int main() {
    constexpr auto heightRef { heightReference() };
    calcBallHeightOptimized(heightRef, getTowerHeight());

    // learncppSolution();
    
    return 0;
}
