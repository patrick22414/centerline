#include "internal.h"

#include <fstream>
#include <sstream>

using namespace std;

void parse_polygon(const string &filename, Polygon &poly) {
    ifstream fs(filename);

    if (!fs.is_open()) {
        cerr << "Parsing: cannot open file '" << filename << "'" << endl;
    }

    string line;
    while (getline(fs, line)) {
        // cout << "line: " << line << endl;

        if (line.front() == 'V') {
            string _tmp_1;
            string _tmp_2;
            double x = 0.0;
            double y = 0.0;

            istringstream(line) >> _tmp_1 >> _tmp_2 >> x >> y;

            // cout << "\tadd point: " << x << ", " << y << endl;
            poly.push_back(Point(x, y));
        }
    }

    fs.close();
}

void write_polygons(const string &filename, const vector<Polygon> &polygons) {
    ofstream fs(filename);

    if (!fs.is_open()) {
        cout << "Writing: cannot open file '" << filename << "'" << endl;
    }

    for (const Polygon &poly: polygons) {
        for (size_t i = 0; i < poly.size(); ++i) {
            Point p = poly[i];
            fs << p.x() << " " << p.y() << endl;
        }

        fs << poly[0].x() << " " << poly[0].y() << endl;

        fs << endl;
    }

    fs.close();
}

void write_segments(const string &filename, const vector<Segment> &segments) {
    ofstream fs(filename);

    if (!fs.is_open()) {
        cout << "Writing: cannot open file '" << filename << "'" << endl;
    }

    for (const Segment &seg: segments) {
        fs << seg.point(0) << endl;
        fs << seg.point(1) << endl;
        fs << endl;
    }

    fs.close();
}
