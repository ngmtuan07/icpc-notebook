// system should be translated from circle center
double triangle_circle_intersection(PT c, double r, PT a, PT b) {
    double sd1 = dist2(c, a), sd2 = dist2(c, b);
    if(sd1 > sd2) swap(a, b), swap(sd1, sd2);
    double sd = dist2(a, b);
    double d1 = sqrtl(sd1), d2 = sqrtl(sd2), d = sqrt(sd);
    double x = abs(sd2 - sd - sd1) / (2 * d);
    double h = sqrtl(sd1 - x * x);
    if(r >= d2) return h * d / 2;
    double area = 0;
    if(sd + sd1 < sd2) {
        if(r < d1) area = r * r * (acos(h / d2) - acos(h / d1)) / 2;
        else {
            area = r * r * ( acos(h / d2) - acos(h / r)) / 2;
            double y = sqrtl(r * r - h * h);
            area += h * (y - x) / 2;
        }
    } 
    else {
        if(r < h) area = r * r * (acos(h / d2) + acos(h / d1)) / 2;
        else {
            area += r * r * (acos(h / d2) - acos(h / r)) / 2;
            double y = sqrtl(r * r - h * h);
            area += h * y / 2;
            if(r < d1) {
                area += r * r * (acos(h / d1) - acos(h / r)) / 2;
                area += h * y / 2;
            } 
            else area += h * x / 2;
        }
    }
    return area;
}