//
// Created by Songyi on 2019/11/17.
//

#include "internal.h"

#include <boost/shared_ptr.hpp>
#include <CGAL/create_straight_skeleton_2.h>


typedef CGAL::Straight_skeleton_2<Kernel> Skeleton;
typedef boost::shared_ptr<Skeleton> SkeletonPtr;

using namespace std;

Segment longest_skeleton(const Polygon &poly) {
    SkeletonPtr sk_p = CGAL::create_interior_straight_skeleton_2(poly.vertices_begin(), poly.vertices_end());

    vector<double> lengths;
    vector<Segment> segments;

    for (auto half_edge = sk_p->halfedges_begin(); half_edge != sk_p->halfedges_end(); ++half_edge) {
        if (half_edge->is_inner_bisector()) {
            Point a = half_edge->vertex()->point();
            Point b = half_edge->opposite()->vertex()->point();
            Segment seg = Segment(a, b);
            lengths.push_back(seg.squared_length());
            segments.push_back(seg);
        }
    }

    if (lengths.empty())
        return EMPTY_SEGMENT;

    int max_index = max_element(lengths.begin(), lengths.end()) - lengths.begin();

    return segments[max_index];
}

void long_skeletons(const vector<Polygon> &polys, vector<Segment> &skeletons) {
    for (const Polygon &poly: polys) {
        Segment seg = longest_skeleton(poly);

        if (!seg.is_degenerate())
            skeletons.push_back(seg);
    }
}