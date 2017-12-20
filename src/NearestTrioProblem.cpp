#include "../include/NearestTrioProblem.h"

#include <cmath>
#include <vector>
#include <limits>

NearestTrioProblem::NearestTrioProblem(NodeSet NS): _NS(NS)
{

}


float NearestTrioProblem::calculateDistance(const std::pair<float, float>& p1, const std::pair<float, float>& p2)
{
    return sqrt( pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2) );
}


double NearestTrioProblem::calculateMin(const std::pair<float, float>& p1, const std::pair<float, float>& p2, const std::pair<float, float>& p3)
{

    //Calculate three node combs
    double distance1 = calculateDistance(p1, p2);
    double distance2 = calculateDistance(p1, p3);
    double distance3 = calculateDistance(p2, p3);

    //Sum the distance two to two
    double sum_distance1 = distance1 + distance2;
    double sum_distance2 = distance1 + distance3;
    double sum_distance3 = distance2 + distance3;

    //Search the minimal of three sum_distance
    double min = sum_distance1;
    if(sum_distance2 < min)
        min = sum_distance2;
    if(sum_distance3 < min)
        min = sum_distance3;

    return min;
}

double NearestTrioProblem::simpleSolution(std::pair<float, float>& p1, std::pair<float, float>& p2, std::pair<float, float>& p3)
{

    //Absolute Minimal distance
    double min_distance = std::numeric_limits<double>::infinity();

    //Auxiliar variables
    double min;

    for(int i = 0; i < _NS.size(); i++) {
        for(int j = i+1; j < _NS.size(); j++) {
            for(int k = j+1; k < _NS.size(); k++) {
                //Calculate minimal distance in the Trio
                min = calculateMin(_NS[i], _NS[j], _NS[k]);

                //Update absolute minimal value
                if(min < min_distance) {
                    min_distance = min;
                    p1 = _NS[i];
                    p2 = _NS[j];
                    p3 = _NS[k];
                }

            }//End k for
        }//End j for
    }//End i for

    return min_distance;
}

double NearestTrioProblem::dcSolution(std::pair<float, float>& p1, std::pair<float, float>& p2, std::pair<float, float>& p3)
{
    NodeSet NS;
    double inf = std::numeric_limits<double>::infinity();

    double min_distance = dcSolution(NS, inf, 0, _NS.size());

    p1 = NS[0];
    p2 = NS[1];
    p3 = NS[2];

    return min_distance;
}

double NearestTrioProblem::dcSolution(NodeSet& solution, double &min_distance, int min, int max)
{
    if(max - min == 3) {
        double new_min = calculateMin(_NS[min], _NS[min+1], _NS[max]);

        if(new_min < min_distance) {
            min_distance = new_min;
            return new_min;
        }
        else
            return min_distance;
    }
    else if(max - min < 3) {
        return std::numeric_limits<double>::infinity();
    }

    else if(max - min >= 6) {
        double new_min_left = dcSolution(solution, min_distance, min, max/2);
        double new_min_right = dcSolution(solution, min_distance, max/2 + 1, max - 1);

        if(new_min_left < min_distance)
            min_distance = new_min_left;
        if(new_min_right < min_distance)
            min_distance = new_min_right;

        return min_distance;
    }
    else {

    }


}
