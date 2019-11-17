#ifndef CENTERLINE_INTERNAL_H
#define CENTERLINE_INTERNAL_H

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Point_2.h>
#include <CGAL/Polygon_2.h>

#include <iostream>

using namespace std;

typedef CGAL::Exact_predicates_inexact_constructions_kernel Kernel;

typedef CGAL::Polygon_2<Kernel> Polygon;
typedef CGAL::Point_2<Kernel> Point;
typedef CGAL::Segment_2<Kernel> Segment;
typedef CGAL::Line_2<Kernel> Line;

const Point ORIGIN = Point(0, 0);
const Segment EMPTY_SEGMENT = Segment(ORIGIN, ORIGIN);

// parse.cpp
void parse_polygon(const string &filename, Polygon &poly);

void write_polygons(const string &filename, const vector<Polygon> &polygons);
void write_segments(const string &filename, const vector<Segment> &segments);

// simplify.cpp
Polygon simplify_polygon(const Polygon &poly);


// partition.cpp
void partition_polygon(const Polygon &poly, vector<Polygon> &part_polys);


// staright_skeleton.cpp
void long_skeletons(const vector<Polygon> &polys, vector<Segment> &skeletons);

#endif // CENTERLINE_INTERNAL_H
