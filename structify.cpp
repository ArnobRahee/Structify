#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

// A structure to represent a point with a value, type, and index
struct Point {
    double value; // The radian measure of the point
    bool isStart; // True if it's a start point, false if it's an end point
    int index;    // Index to pair start and end points of the same chord
};

// Comparator for sorting points
bool comparePoints(const Point& a, const Point& b) {
    return a.value < b.value;
}

// Function to count the intersections
int countIntersections(const std::vector<double>& measures, const std::vector<std::string>& identifiers) {
    std::vector<Point> points;
    std::set<int> activeChords;
    int intersections = 0;

    // Pair the measures with their identifiers
    for (size_t i = 0; i < identifiers.size(); ++i) {
        bool isStart = identifiers[i][0] == 's'; // Check if the identifier is for a start point
        int index = std::stoi(identifiers[i].substr(1)) - 1; // Convert identifier to index (assuming 1-based index)
        points.push_back({measures[i], isStart, index});
    }

    // Sort the points by their radian measure
    std::sort(points.begin(), points.end(), comparePoints);

    // Sweep through the points to count intersections
    for (const auto& point : points) {
        if (point.isStart) {
            // Check for intersections with active chords
            for (int idx : activeChords) {
                intersections++;
            }
            activeChords.insert(point.index);
        } else {
            activeChords.erase(point.index);
        }
    }

    return intersections;
}

int main() {

    std::vector<double> measures = {0.9,1.3,1.7,2.92};
    std::vector<std::string> identifiers = {"s1", "e1", "s2", "e2"};

    // Count the intersections
    int result = countIntersections(measures, identifiers);

    // Print the result
    std::cout << "The number of intersections is: " << result << std::endl;

    return 0;
}
