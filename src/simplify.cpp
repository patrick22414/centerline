#include "internal.h"

#include <CGAL/Polyline_simplification_2/simplify.h>

namespace PolySimp = CGAL::Polyline_simplification_2;

typedef PolySimp::Stop_above_cost_threshold Stop;
typedef PolySimp::Squared_distance_cost Cost;

Polygon simplify_polygon(const Polygon& poly) {

    Stop stop = Stop(1);
    Cost cost;

    return PolySimp::simplify(poly, cost, stop);
}