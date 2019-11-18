#include "internal.h"
#include <algorithm>

using namespace std;

struct LinkedSegment {
    Segment segment;
    int next_to[2]{-1, -1};

    LinkedSegment(Segment seg, int n1, int n2) {
        segment = seg;
        next_to[0] = n1;
        next_to[1] = n2;
    }
};

inline Point intersect(Segment seg1, Segment seg2) {
    double x1 = seg1.source().x();
    double y1 = seg1.source().y();
    double x2 = seg1.target().x();
    double y2 = seg1.target().y();

    double x3 = seg2.source().x();
    double y3 = seg2.source().y();
    double x4 = seg2.target().x();
    double y4 = seg2.target().y();

    double denominator = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
    if (abs(denominator) < 1e-12)
        return ORIGIN;

    double t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / denominator;

    double x = x1 + t * (x2 - x1);
    double y = y1 + t * (y2 - y1);

    return Point(x, y);
}

inline int index_of_min(const vector<double> &doubles) {
    return min_element(doubles.begin(), doubles.end()) - doubles.begin();
}

inline double squared_length_point_to_segment(Point p, Segment seg) {
    return min(Segment(p, seg.source()).squared_length(), Segment(p, seg.target()).squared_length());
}

void incident(const vector<Segment> &skeletons) {
    size_t n = skeletons.size();

    vector < LinkedSegment * > linked_segments(n);
    vector<double> lengths(n);

    for (size_t i = 0; i < n; ++i) {
        Segment seg = skeletons[i];

        // Source end
        Point sp = seg.source();
        for (size_t j = 0; j < n; ++j) {
            if (i != j) {
                lengths[j] = squared_length_point_to_segment(sp, skeletons[j]);
            } else {
                lengths[j] = DBL_MAX;
            }
        }

        int k1 = index_of_min(lengths);
        Point new_sp = intersect(seg, skeletons[k1]);

        if (Segment(new_sp, sp).squared_length() > seg.squared_length()) {
            k1 = -1;
            new_sp = sp;
        }

        // Target end
        Point tp = seg.target();
        for (size_t j = 0; j < n; ++j) {
            if (i != j) {
                lengths[j] = squared_length_point_to_segment(tp, skeletons[j]);
            } else {
                lengths[j] = DBL_MAX;
            }
        }

        int k2 = index_of_min(lengths);
        Point new_tp = intersect(seg, skeletons[k2]);

        if (Segment(new_tp, tp).squared_length() > seg.squared_length()) {
            k1 = -1;
            new_tp = tp;
        }

        if (new_sp != ORIGIN && new_tp != ORIGIN) {
            Segment new_seg = Segment(new_sp, new_tp);

            cout << new_sp << endl;
            cout << new_tp << endl;
            cout << endl;
        }
    }
}
