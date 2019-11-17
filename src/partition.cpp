//
// Created by Songyi on 2019/11/17.
//

#include "internal.h"

#include <CGAL/Partition_traits_2.h>
#include <CGAL/partition_2.h>

typedef CGAL::Partition_traits_2<Kernel> PartitionTraits;
typedef PartitionTraits::Polygon_2 Polygon2;

void partition_polygon(const Polygon &poly, vector<Polygon> &part_polys) {

    // CGAL::Polygon_2<Kernel> to PartitionTraits::Polygon_2
    Polygon2 poly2 = Polygon2(poly.vertices_begin(), poly.vertices_end());

    // Optimal convex partition
    vector<Polygon2> part_polys2;
    PartitionTraits traits;

    CGAL::optimal_convex_partition_2(
            poly2.vertices_begin(),
            poly2.vertices_end(),
            back_inserter(part_polys2),
            traits
    );

    // PartitionTraits::Polygon_2 to CGAL::Polygon_2<Kernel>
    for (const Polygon2 &p2: part_polys2) {
        part_polys.emplace_back(p2.vertices_begin(), p2.vertices_end());
    }
}
