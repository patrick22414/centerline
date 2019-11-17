from matplotlib import pyplot as plt


def draw(filename):
    polygons = [[]]

    with open(filename, "r") as fo:
        count = 0
        for line in fo:
            if len(line.strip()) == 0:
                count += 1
            else:
                values = line.split()
                if count >= len(polygons):
                    polygons.append([])
                polygons[count].append((float(values[0]), float(values[1])))

    for poly in polygons:
        xs = [v[0] for v in poly]
        ys = [v[1] for v in poly]
        plt.plot(xs, ys, ".-")


if __name__ == "__main__":
    # draw("result.txt")
    draw("skeletons.txt")
    plt.axis("equal")
    plt.show()
