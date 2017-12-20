#include "../include/NearestTrioProblem.h"
#include "../include/GenNodeSet.h"

#include <cmath>
#include <vector>
#include <limits>
#include <iostream>

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

double NearestTrioProblem::simpleSolution(NodeSet _NS, std::pair<float, float>& p1, std::pair<float, float>& p2, std::pair<float, float>& p3)
{

    //Absolute Minimal distance
    double min_distance = std::numeric_limits<double>::infinity();

    for(int i = 0; i < _NS.size(); i++) {
        for(int j = i+1; j < _NS.size(); j++) {
            for(int k = j+1; k < _NS.size(); k++) {

                //Calculate minimal distance in the Trio
                double min = calculateMin(_NS[i], _NS[j], _NS[k]);

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

double NearestTrioProblem::simpleSolution(std::pair<float, float>& p1, std::pair<float, float>& p2, std::pair<float, float>& p3)
{
    simpleSolution(this->_NS, p1, p2, p3);
}

double NearestTrioProblem::stripClosest(NodeSet strip, double d)
{
    double min = d;  // Initialize the minimum distance as d

    // Pick all points one by one and try the next points till the difference
    // between y coordinates is smaller than d.
    // This is a proven fact that this loop runs at most 6 times
    for (int i = 0; i < strip.size(); ++i){
        for(int j = i + 1; j < strip.size(); ++j){
            for (int k = j+1; k < strip.size() && (strip[k].second - strip[j].second - strip[i].second) < min; ++k) {
                double new_min = calculateMin(strip[i], strip[j], strip[k]);
                if (new_min < min)
                    min = new_min;
            }
        }
    }


    return min;
}

double NearestTrioProblem::dcSolution(std::pair<float, float>& p1, std::pair<float, float>& p2, std::pair<float, float>& p3)
{
    NodeSet NSortedX, NSortedY, solution(3, std::make_pair(1000, 1000));
    GenNodeSet GenNS(_NS);

    NSortedX = GenNS.xSortNodeSet();
    NSortedY = GenNS.ySortNodeSet();

    double sol = dcSolution(solution, NSortedX, NSortedY, _NS.size()/sizeof(_NS[0]));

    p1 = solution[0];
    p2 = solution[1];
    p2 = solution[2];

    return sol;

}

double NearestTrioProblem::dcSolution(NodeSet& solution, NodeSet& NSX, NodeSet& NSY, int n)
{
    if(n <= 6)
        return simpleSolution(NSX, solution[0], solution[1], solution[2]);
    else if (n < 3) return std::numeric_limits<double>::infinity();

    int mid = n/2;
    std::pair<float, float> midPoint = NSX[mid];

    NodeSet NyL(mid + 1);
    NodeSet NyR(n - mid - 1);


    for (int i = 0; i < n; i++) {
        if (NSY[i].first <= midPoint.first)
            NyL.push_back(NSY.at(i));
        else
            NyR.push_back(NSY.at(i));
    }

    NodeSet aux(NSX.begin() + mid, NSX.end());

    double dl = dcSolution(solution, NSX, NyL, mid);
    double dr = dcSolution(solution, aux, NyR, n-mid);

    float dmin = dl;
    if(dr < dmin)
        dmin = dr;

        std::cout<<dmin<<std::endl;

    NodeSet strip(n);

    for (int i = 0; i < n; i++){
        double nmin = abs(NSY.at(i).first - midPoint.first);

        if (nmin < dmin){
            strip.push_back(NSY.at(i));
        }

    }

    // Find the closest points in strip.  Return the minimum of d and closest
    // distance is strip[]
    double new_min = stripClosest(strip, dmin);

    std::cout<<new_min<<std::endl;

    if(new_min < dmin){
        solution = strip;
        return new_min;
    }
    else return dmin;

}
