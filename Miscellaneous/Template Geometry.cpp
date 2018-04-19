#include <bits/stdc++.h>
using namespace std;

///...............GEOMETRY BASE TEMPLATE.................................

/// Geometry Base Template
/// Include necessary functions from here to use in other codes
/// If coordinates are double, change accordingly

struct Point {
    LL x, y;
    Point(){}
    Point(LL a, LL b){
        x = a, y = b;
    }
    Point operator - (const Point &t) const{
        Point res;
        res.x = x - t.x;
        res.y = y - t.y;
        return res;
    }
};

LL sqrDist(Point P, Point Q) {
    return (P.x - Q.x) * (P.x - Q.x) + (P.y - Q.y) * (P.y - Q.y);
}

double dist(Point P, Point Q) {
    double res = (P.x - Q.x) * (P.x - Q.x) + (P.y - Q.y) * (P.y - Q.y);
    return sqrt(res);
}

/// 0 = Collinear, 1 = Clockwise, 2 = Counterclockwise.
int orientation(Point P, Point Q, Point R) {
    LL ret = (Q.y - P.y) * (R.x - Q.x) - (Q.x - P.x) * (R.y - Q.y);
    if (ret > 0) return 1; /// Polar angle of (Q - R) is smaller than (P - Q) with respect to x axis.
    if (ret < 0) return 2; /// Polar angle of (Q - R) is greater than (P - Q) with respect to x axis.
    return 0; /// Co linear
}

double polygonArea(vector<Point> polygon) {
    double area = 0;
    for (int i = 1; i + 1 < polygon.size(); i++){
        area += (polygon[i].y - polygon[0].y) * (polygon[i + 1].x - polygon[i].x)
                - (polygon[i].x - polygon[0].x) * (polygon[i + 1].y - polygon[i].y);
    }
    return FABS(area / 2.0);
}

/// Compute A X B:
int crossAB(Point A, Point B){
    return (A.x * B.y - A.y * B.x);
}

/// Compute A dot B:
int dotAB(Point A, Point B){
    return (A.x * B.x + A.y * B.y);
}

///Compute the cross product AB X AC
int crossABC(Point A, Point B, Point C) {
    Point AB = Point(B.x - A.x, B.y - A.y); /// AB vector
    Point AC = Point(C.x - A.x, C.y - A.y); /// AC vector
    return crossAB(AB, AC);
}

///Compute the dot product AB dot BC
int dotABC(Point A, Point B, Point C) {
    Point AB = Point(B.x - A.x, B.y - A.y); /// AB vector
    Point BC = Point(C.x - B.x, C.y - B.y); /// BC vector
    return dotAB(AB, BC);
}

/// The angle between two vectors:
double angle(Point A, Point B){
    double ans = fabs((atan2(A.y, A.x) - atan2(B.y, B.x)));
    return ans > pi+eps ? 2*pi-ans : ans;
}

/// Returns angle from positive X
double angelFromAxis(Point P){
    double ang = atan2(P.y, P.x);
    if(ang+eps<0.0) ang += 2.0*pi;
    return ang;
}

///..................................................................

///.............................GEOMETRY LINE..........................

/// Line Geometry
/// Use necessary functions related to line
/// Don't forget to include base template

struct lineGeometry{

    /// Returns A,B,C of the equation Ax + By = C.
    piii lineEquation(Point P1, Point P2){
        int A = P2.y - P1.y;
        int B = P1.x - P2.x;
        int C = A * P1.x + B * P1.y;
        return MP(MP(A,B), C);
    }

    /// Find minimum distance between C and line/segment (A - B)
    double pointToLineDistance(Point A, Point B, Point C, bool isSeg) {
        double d = (double)crossABC(A, B, C) / dist(A, B);
        if (isSeg) { /// AB is a line segment
            if (dotABC(A, B, C) > 0) return dist(B, C);
            if (dotABC(B, A, C) > 0) return dist(A, C);
        }
        return FABS(d);
    }

    /// Check if R lies on line segment (P - Q)
    bool onSegment(Point P, Point Q, Point R) {
        if (R.x >= min(P.x, Q.x) && R.x <= max(P.x, Q.x) &&
                R.y >= min(P.y, Q.y) && R.y <= max(P.y, Q.y)){
            return true;
        } else {
            return false;
        }
    }

    /// Check if line segment (P1-P2) and line segment (P3-P4) intersect
    bool segmentIntersect(Point P1, Point P2, Point P3, Point P4) {
        int o1 = orientation(P1, P2, P3);
        int o2 = orientation(P1, P2, P4);
        int o3 = orientation(P3, P4, P1);
        int o4 = orientation(P3, P4, P2);

        if (o1 != o2 && o3 != o4 && o1 != 0 && o2 != 0 && o3 != 0 && o4 != 0){
            return true;
        }

        if (o1 == 0 && onSegment(P1, P2, P3)) return true;
        if (o2 == 0 && onSegment(P1, P2, P4)) return true;
        if (o3 == 0 && onSegment(P3, P4, P1)) return true;
        if (o4 == 0 && onSegment(P3, P4, P2)) return true;
        return false;
    }

    /// Find intersection point of line (P1-P2) and (P3-P4)
    void intersectionPoint(Point P1, Point P2, Point P3, Point P4){
        piii L1 = lineEquation(P1,P2);
        int A1 = L1.ff.ff, B1 = L1.ff.ss, C1 = L1.ss;

        piii L2 = lineEquation(P3,P4);
        int A2 = L2.ff.ff, B2 = L2.ff.ss, C2 = L2.ss;

        int dif = A1*B2 - A2*B1; /// Slope difference of the two lines

        if(dif == 0){ /// Lines are either collinear or parallel.
            vector<Point> List;
            List.pb(P1); List.pb(P3); List.pb(P4); List.pb(P2);
            if (polygonArea(List) == 0){
                printf("Collinear\n");
            }else{
                printf("Parallel\n");
            }
        }else{
            double x = (B2 * C1 - B1 * C2) / dif;
            double y = (A1 * C2 - A2 * C1) / dif;
            cerr << x << " " << y << endl; /// Return if needed.
        }
    }

    /// Find a point C on line AB such that distance from A to C is D.
    Point pointAtDistanceD(Point A, Point B, double D){
        Point vecAB,C;
        vecAB.x = B.x - A.x;
        vecAB.y = B.y - A.y;
        double norm = sqrt(SQ(vecAB.x) + SQ(vecAB.y));
        vecAB.x /= norm;
        vecAB.y /= norm;
        C.x = A.x + D*vecAB.x; /// To find a point D distance away but outside the line then minus here.
        C.y = A.y + D*vecAB.y;
        return C;
    }

}lineGeo;

///...........................................................................................

///................................GEOMETRY CIRCLE.............................................

/// Circle Geometry
/// Use necessary functions related to circle
/// Don't forget to include base template

struct circleGeometry{

    /// Find the intersection points of a line and a circle
    /// Parameters: Circle center, radius, line end points P1 and P2
    pair<Point,Point> lineCircleIntersectionPoints(Point center, double r, Point P1, Point P2){
        double a1 = P2.x - P1.x;
        double a2 = P2.y - P1.y;
        double b1 = P1.x - center.x;
        double b2 = P1.y - center.y;

        // At^2 + Bt + C = 0
        double A = SQ(a1) + SQ(a2);
        double B = (a1*b1 + a2*b2)*2;
        double C = SQ(b1) + SQ(b2) - SQ(r);

        if((B*B - 4.0*A*C)<0){
            /// Does not intersect
        }else if((B*B - 4.0*A*C) == 0){
            /// The line is tangent with the circle at a single point
        }else{
            /// The line intersect the circle at two points
            double t1 = (-B - sqrt(B*B - 4.0*A*C))/2.0/A;
            double t2 = (-B + sqrt(B*B - 4.0*A*C))/2.0/A;

            Point E1 = {P1.x + a1*t1, P1.y + a2*t1};
            Point E2 = {P1.x + a1*t2, P1.y + a2*t2};
            return MP(E1,E2);
        }
    }

    /// Find intersected area of two circles
    /// Parameters: 1st circle center, radius, 2nd circle center, radius
    double circleCircleIntersectionArea(Point P0, double R0, Point P1, double R1) {
        double d = dist(P0, P1);
        if(R0 + R1 <= d) return 0;
        if(R0 >= R1 && (R0 - R1) >= d) return pi * SQ(R1);
        if(R0 <= R1 && (R1 - R0) >= d) return pi * SQ(R0);

        double CAD = 2.0 * acos((SQ(R0) + SQ(d) - SQ(R1)) / (2.0 * R0 * d));
        double CBD = 2.0 * acos((SQ(R1) + SQ(d) - SQ(R0)) / (2.0 * R1 * d));

        //double A1 = (0.5 * SQ(R0) * CAD) - (0.5 * SQ(R0) * sin(CAD));
        double A1 = 0.5 * SQ(R0) * (CAD - sin(CAD));
        //double A2 = (0.5 * SQ(R1) * CBD) - (0.5 * SQ(R1) * sin(CBD));
        double A2 = 0.5 * SQ(R1) * (CBD - sin(CBD));
        return (A1 + A2);
    }

    /// Find intersection points of two circles
    /// Parameters: 1st circle center, radius, 2nd circle center, radius
    void circleCircleIntersectionPoints(Point P0, double R0, Point P1, double R1) {
        double d = dist(P0, P1);

        if(d > R0 + R1){
            /// They don't intersect.

        }else if(d < FABS(R0 - R1)){
            /// One fully contains the other one.

        }else if(FABS(d - 0)<eps && R0 == R1){
            /// Both are same circle.

        }else{
            /// The circles intersect with each other

            double a = (SQ(R0) - SQ(R1) + SQ(d))/(2.0 * d);
            double b = d - a;
            double h = sqrt(SQ(R0) - SQ(a));

            double rx = -(P1.y - P0.y) * (h/d);
            double ry = (P1.x - P0.x) * (h/d);

            Point P2;
            P2.x = P0.x + (a * (P1.x - P0.x))/d;
            P2.y = P0.y + (a * (P1.y - P0.y))/d;

            Point E1 = {P2.x + rx, P2.y + ry};
            Point E2 = {P2.x - rx, P2.y - ry};

            /// E1, E2 are the intersection points. Return if needed.
        }
    }

    /// Find the center of the circle which pass through point a & b having radius R.
    void findCenterGivenTwoPointsOnIt(Point a, Point b, double R) {
        Point g1,g2;
        double x1 = a.x, x2 = b.x;
        double y1 = a.y, y2 = b.y;
        double d = dist(a, b);
        if (d * d > 4.0 * R * R) {
            /// Not Possible to Find any Center;
            return;
        }
        double x_part = sqrt(R * R - 0.25 * d * d) * (y1 - y2) / d;
        double y_part = sqrt(R * R - 0.25 * d * d) * (x2 - x1) / d;
        double x3 = 0.5 * (x1 + x2), y3 = 0.5 * (y1 + y2);
        g1 = Point(x3 + x_part, y3 + y_part); /// One possible center
        g2 = Point(x3 - x_part, y3 - y_part); /// Another possible center
    }

    /// Given 3 points A, B, C on the circumference of a circle
    /// Find the center of that circle
    Point circleCenter(Point A, Point B, Point C) {
        double yDelta_a = B.y - A.y;
        double xDelta_a = B.x - A.x;
        double yDelta_b = C.y - B.y;
        double xDelta_b = C.x - B.x;
        Point center = Point(0.0, 0.0);

        double aSlope = yDelta_a/xDelta_a;
        double bSlope = yDelta_b/xDelta_b;
        center.x = (aSlope*bSlope*(A.y - C.y) + bSlope*(A.x + B.x)
                    - aSlope*(B.x + C.x) )/(2* (bSlope - aSlope));
        center.y = -1*(center.x - (A.x + B.x)/2)/aSlope +  (A.y + B.y)/2;
        return center;
    }

}circleGeo;

///.....................................................................................

///..............................GEOMETRY POLYGON...........................................

/// Polygon Geometry

struct polygonGeometry{
    int N; /// Number of total points
    vector<Point> polygon; /// Contains all the polygon points

    void clear(){
        polygon.clear();
    }

    bool onSegment(Point P, Point Q, Point R){
        if (R.x >= min(P.x, Q.x) && R.x <= max(P.x, Q.x) && R.y >= min(P.y, Q.y)
                && R.y <= max(P.y, Q.y)){
            return true;
        }else{
            return false;
        }
    }

    bool doIntersect(Point P1, Point P2, Point P3, Point P4, bool &onLine){
        int o1 = orientation(P1, P2, P3);
        int o2 = orientation(P1, P2, P4);
        int o3 = orientation(P3, P4, P1);
        int o4 = orientation(P3, P4, P2);

        if (o1 != o2 && o3 != o4 && o1 != 0 && o2 != 0 && o3 != 0 && o4 != 0){
            return true;
        }

        if (o1 == 0 && onSegment(P1, P2, P3)){
            onLine = true; /// Change here, if point on line is not allowed
            return true;
        }

        if (o2 == 0 && onSegment(P1, P2, P4)) return true;
        if (o3 == 0 && onSegment(P3, P4, P1)) return true;
        if (o4 == 0 && onSegment(P3, P4, P2)) return true;
        return false;
    }

    /// Check if point P lie inside polygon
    bool isInsidePolygon(Point P) {
        Point Q;
        Q.y = P.y + 1e9; /// Change here, depends on maximum co ordinate value
        Q.x = P.x + 1e9+1;
        bool onLine = false; /// To check if the point lie on any segment
        int cnt = 0;
        for (int i = 0; i + 1 < polygon.size(); i++){
            if (doIntersect(polygon[i], polygon[i + 1], P, Q, onLine)) cnt++;
        }
        if (onLine) return true; /// Change here, if point on line is not allowed
        if (cnt % 2 == 1) return true;
        return false;
    }

    /// Given a convex hull it returns the center of masses or gravity of it
    Point centerOfMass(vector<Point> P) {
        double area = polygonArea(P);
        double cx = 0, cy = 0;
        int sz = P.size();
        for (int i = 0; i < sz; ++i) {
            Point cur = P[i];
            Point nxt = P[(i + 1) % sz];
            cx += (cur.x + nxt.x) * (cur.x * nxt.y - cur.y * nxt.x);
            cy += (cur.y + nxt.y) * (cur.x * nxt.y - cur.y * nxt.x);
        }
        cx = cx/(6.0 * area);
        cy = cy/(6.0 * area);
        return Point(cx, cy);
    }

}polygonGeo;

///..................................................................................

int main()
{

}
