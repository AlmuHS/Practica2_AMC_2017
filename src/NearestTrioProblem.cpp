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

double NearestTrioProblem::dcSolution(std::pair<float, float>& p1, std::pair<float, float>& p2, std::pair<float, float>& p3){
    NodeSet NS;
    double inf = std::numeric_limits<double>::infinity();

    double min_distance = dcSolution(NS, _NS, inf);

    p1 = NS[0];
    p2 = NS[1];
    p3 = NS[2];

    return min_distance;
    //return inf;
}

void NearestTrioProblem::divide(const NodeSet &NS, NodeSet &left, NodeSet &right){

    if(NS.size() < 5){
        left = NodeSet(NS.begin(), NS.begin()+3);
        right = NodeSet(NS.end()-3, NS.end());
    }

    else{
        left = NodeSet(NS.begin(), NS.begin() + NS.size()/2);
        right = NodeSet(NS.begin() + NS.size()/2 + 1, NS.end());
    }
}

double NearestTrioProblem::dcSolution(NodeSet& solution, NodeSet &origin, double &min_distance)
{
    if(origin.size() == 3){

        double a = calculateDistance(origin[0], origin[1]);
        double b = calculateDistance(origin[0], origin[2]);
        double c = calculateDistance(origin[1], origin[2]);

        double local_min = a + b;
        if(a + c < local_min) local_min = a + c;
        if(b + c < local_min) local_min = b + c;

        if(local_min < min_distance){
            min_distance = local_min;
            solution.clear();
            solution.push_back(origin[0]);
            solution.push_back(origin[1]);
            solution.push_back(origin[2]);
        }

        return min_distance;
    }

    else{
        NodeSet left, right;

        divide(origin, left, right);

        double min_left = dcSolution(solution, left, min_distance);
        double min_right = dcSolution(solution, right, min_distance);

        if(min_left < min_right) return min_left;
        else return min_right;
    }
}
