#include "../include/NearestTrioProblem.h"

#include <cmath>
#include <vector>

NearestTrioProblem::NearestTrioProblem(NodeSet NS): _NS(NS)
{

}


float NearestTrioProblem::calculateDistance(const std::pair<float, float>& p1, const std::pair<float, float>& p2)
{
    return sqrt( pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2) );
}


double NearestTrioProblem::simpleSolution(std::pair<float, float>& p1, std::pair<float, float>& p2, std::pair<float, float>& p3)
{

    p1 = _NS.getPair(0);
    p2 = _NS.getPair(1);
    p3 = _NS.getPair(2);

    double min_distance = calculateDistance(p1, p2) + calculateDistance(p1, p3) + calculateDistance(p2, p3);


    for(int i = 0; i < _NS.getSize(); i++)
    {
        for(int j = i+1; j < _NS.getSize(); j++)
        {
            for(int k = j+1; k < _NS.getSize(); k++)
            {
                double distance1 = calculateDistance(_NS.getPair(i), _NS.getPair(j));
                double distance2 = calculateDistance(_NS.getPair(i), _NS.getPair(k));
                double distance3 = calculateDistance(_NS.getPair(j), _NS.getPair(k));

                double sum_distance = distance1 + distance2 + distance3;

                if(sum_distance < min_distance)
                {
                    min_distance = sum_distance;
                    p1 = _NS.getPair(i);
                    p2 = _NS.getPair(j);
                    p3 = _NS.getPair(k);
                }
            }//End k for
        }//End j for
    }//End i for

    return min_distance;
}

double NearestTrioProblem::dcSolution(std::pair<float, float>& p1, std::pair<float, float>& p2, std::pair<float, float>& p3 )
{

}
