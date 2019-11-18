#include "internal.h"

using namespace std;

int main(int argc, const char *argv[]) {
    string input_file;
    string output_file;

    if (argc >= 2) {
        input_file = string(argv[1]);
        cout << "Using input file: " << input_file << endl;
    } else {
        cout << "No input file. Exiting" << endl;
        return 0;
    }

    if (strcmp(argv[2], "-o") == 0) {
        output_file = string(argv[3]);
        cout << "Using output file: " << output_file << endl;
    } else {
        output_file = "output.txt";
        cout << "No output file. Using ./output.txt instead" << endl;
    }

    Polygon poly;
    parse_polygon(input_file, poly);

    Polygon simp_poly;
    simp_poly = simplify_polygon(poly);

    vector<Polygon> part_polys;
    partition_polygon(simp_poly, part_polys);

    vector<Segment> skeletons;
    long_skeletons(part_polys, skeletons);

    incident(skeletons);

    write_polygons(output_file, part_polys);
    write_segments("./python/skeletons.txt", skeletons);

    return 0;
}
