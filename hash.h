#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <cmath>
#include <random>
#include <chrono>

typedef std::size_t HASH_INDEX_T;

struct MyStringHash {
    HASH_INDEX_T rValues[5] { 983132572, 1468777056, 552714139, 984953261, 261934300 };
    MyStringHash(bool debug = true)
    {
        if(false == debug){
            generateRValues();
        }
    }
    // hash function entry point (i.e. this is h(k))
    HASH_INDEX_T operator()(const std::string& k) const
    {
        // Add your code here
        /*
        unsigned long long w[5] = {0ULL, 0ULL, 0ULL, 0ULL, 0ULL};

        const std::size_t len = k.size();
        const std::size_t numGroups = (len + 5) / 6;

        for (std::size_t g = 0; g < numGroups && g < 5; g++) {
          const std::size_t end = len - 6 * g;
          
          std::size_t start;
          if (end >= 6) {
            start = end - 6;
          }
          else {
            start = 0;
          }

          const std::size_t index = 4 - g;

          insigned long long value = 0ULL;
          for (std::size_t i = start; i < end; ++i) {
            value = value * 36ULL + static_cast<unsigned long long>(letterDigitToNumber(k[i]));
          }
          w[index] = value;
        }

        unsigned long long hash = 0ULL;
        for (int i = 0; i < 5; ++i) {
          hash += static_cast<unsigned long long>(rValues[i]) * w[i];
        }

        return static_cast<HASH_INDEX_T>(hash);
        */

    }

    // A likely helper function is to convert a-z,0-9 to an integral value 0-35
    HASH_INDEX_T letterDigitToNumber(char letter) const
    {
        // Add code here or delete this helper function if you do not want it
        /*
        const unsigned char c = static_cast<unsigned char>(letter);

        if (std::isdigit(c)) {
          const unsigned char lower = static_cast<unsigned char>(std::tolower(c));
          return static_cast<HASH_INDEX_T>(lower - static_cast<unsigned char>('a'));
        }

        return 0;
        */

    }

    // Code to generate the random R values
    void generateRValues()
    {
        // obtain a seed from the system clock:
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 generator (seed);  // mt19937 is a standard random number generator

        // Simply call generator() [it has an operator()] to get another random number
        for(int i{ 0 }; i < 5; ++i)
        {
            rValues[i] = generator();
        }
    }
};

#endif
