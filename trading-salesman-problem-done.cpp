#include <iostream>
#include <chrono>
#include <stdlib.h>

#define CITIES 4
#define STARTING_CITY 0

int distances[CITIES][CITIES] = {
        {0, 10, 8, 6},
        {10, 0, 3, 7},
        {8, 3, 0, 1},
        {6, 7, 1, 0}
};

using namespace std;

int* generateDefaultCitiesOrder() {
    static int cities[CITIES];

    for(int i = 0; i < CITIES; i++) {
        cities[i] = i;
    }

    return cities;
}

int* excludeStartingCity(int* allCities) {
    static int newCities[CITIES - 1];

    int cityFound = 0;
    for(int i = 0; i < CITIES; i++) {
        if(i == STARTING_CITY) {
            cityFound = 1;
            continue;
        }

        newCities[i - cityFound] = i;
    }

    return newCities;
}

void printArray(int* array, int size) {
    for(int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }

    cout << endl;
}

int distanceBetweenCities(int currentCity, int targetCity) {
    return distances[currentCity][targetCity];
}

int findDistanceForRoute(int* route) {
    int currentDistance = 0;

    int currentCity = STARTING_CITY;

    for(int i = 0; i < CITIES - 1; i++) {
        int targetCity = route[i];

        currentDistance += distanceBetweenCities(currentCity, targetCity);

        currentCity = targetCity;
    }

    currentDistance += distanceBetweenCities(currentCity, STARTING_CITY);

    return currentDistance;
}

int findMinimumDistance(int* cities) {
    int currentMinimumDistance = numeric_limits<int>::max();

    do {
        int distance = findDistanceForRoute(cities);

        currentMinimumDistance = currentMinimumDistance < distance ? currentMinimumDistance : distance;
    } while(next_permutation(cities, cities + CITIES - 1));

    return currentMinimumDistance;
}

int main() {
    int* cities = generateDefaultCitiesOrder();

    cities = excludeStartingCity(cities);

    int minimumDistance = findMinimumDistance(cities);

    cout << minimumDistance;
}