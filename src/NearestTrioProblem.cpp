#include "NearestTrioProblem.h"

#include <cmath>
#include <vector>

NearestTrioProblem::NearestTrioProblem(NodeSet NS_): this -> NS = NS_
{

}


float NearestTrioProblem::Calculate_Distance(std::pair<float, float> p1, std::pair<float, float> p2)
{
    return sqrt( pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2) );
}


double NearestTrioProblem::SimpleSolution(std::pair<float, float>& p1, std::pair<float, float>& p2, std::pair<float, float>& p3)
{

    double min_distance = Calculate_Distance(NS.get_pair(0), NS.get_pair(1)) +
                          Calculate_Distance(NS.get_pair(0), NS.get_pair(2)) +
                          Calculate_Distance(NS.get_pair(1), NS.get_pair(2));

    for(int i = 0; i < NS.get_size(); i++)
    {
        for(int j = 0; j < NS.get_size(); j++)
        {
            for(int k = 0; k < NS.get_size(); k++)
            {
                double distance1 = Calculate_Distance(NS.get_pair(i), NS.get_pair(j));
                double distance2 = Calculate_Distance(NS.get_pair(i), NS.get_pair(k));
                double distance3 = Calculate_Distance(NS.get_pair(j), NS.get_pair(k));

                double sum_distance = distance1 + distance2 + distance3;

                if(sum_distance < min_distance)
                    min_distance = sum_distance;
            }
        }
    }

    return min_distance;
}
