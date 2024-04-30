#include <iostream>
#include <sstream>
#include <vector>

int main() {
    std::string inputString = "Hello,World,C++,Split,Example";
    std::istringstream iss(inputString);
    std::vector<std::string> tokens;

    std::string token;
    while (std::getline(iss, token, ',')) {
        tokens.push_back(token);
    }

    // Display the result
    for (const auto& t : tokens) {
        std::cout << t << std::endl;
    }

    return 0;
}
