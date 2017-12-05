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


double NearestTrioProblem::simpleSolution(std::pair<float, float>& p1, std::pair<float, float>& p2, std::pair<float, float>& p3)
{

    //Absolute Minimal distance
    double min_distance = std::numeric_limits<double>::infinity();

    //Auxiliar variables
    double distance1, distance2, distance3, sum_distance1, sum_distance2, sum_distance3, min;

    for(int i = 0; i < _NS.size(); i++)
    {
        for(int j = i+1; j < _NS.size(); j++)
        {
            for(int k = j+1; k < _NS.size(); k++)
            {
                //Calculate three node combs
                distance1 = calculateDistance(_NS[i], _NS[j]);
                distance2 = calculateDistance(_NS[i], _NS[k]);
                distance3 = calculateDistance(_NS[j], _NS[k]);

                //Sum the distance two to two
                sum_distance1 = distance1 + distance2;
                sum_distance2 = distance1 + distance3;
                sum_distance3 = distance2 + distance3;

                //Search the minimal of three sum_distance
                min = sum_distance1;
                if(sum_distance2 < min)
                    min = sum_distance2;
                if(sum_distance3 < min)
                    min = sum_distance3;

                //Update absolute minimal value
                if(min < min_distance)
                {
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

double NearestTrioProblem::dcSolution(NodeSet& solution)
{
    int min = 0, max = _NS.size();

    if(max > 6)
    {

    }
}
