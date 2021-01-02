#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
using namespace std;
int main(){
    int a,b,h,m;
    cin >> a >> b >> h >> m;
    double theta1=(h+m/60.0)/12.0*2*3.1415926535897932384;
    double theta2=m/60.0*2*3.1415926535897932384;
    double x1 = a * sin(theta1);
    double y1 = a * cos(theta1);
    double x2 = b * sin(theta2);
    double y2 = b * cos(theta2);
    double dist = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    cout << setprecision(20)<< dist << endl;
    return 0;
}