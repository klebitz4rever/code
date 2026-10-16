#include <stdio.h>
#include <math.h>

double dist( double x1, double y1, double x2, double y2 );

int main()
{    
    double x1, y1, x2, y2;

    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
    printf("dist = %.2f\n", dist(x1, y1, x2, y2));
    
    return 0;
}

double dist( double x1, double y1, double x2, double y2 ){
    double dis_x = fabs(x2 - x1);
    double dis_y = fabs(y2 - y1);
    double distance = sqrt(dis_x * dis_x + dis_y * dis_y);
    return distance;
}