w, h = map(int, input().split())
palette = input()
type, *data = input().split()
if type == "radial":
    cx, cy, cr = map(int, data)
else:
    x1, y1, x2, y2 = map(int, data)

dist = lambda x1, y1, x2, y2: ((x1-x2)**2 + (y1-y2)**2)**0.5

for y in range(h):
    for x in range(w):
        if type == "radial":
            pos = int(len(palette)*(dist(x, y, cx, cy)/cr))
        else:
            d, d1, d2 = dist(x1, y1, x2, y2), dist(x, y, x1, y1), dist(x, y, x2, y2)
            a = (d1**2+d**2-d2**2)/(2*d1*d) if d1 != 0 else 1
            dl = d1 * a
            pos = int(len(palette)*dl/d)
        print(palette[max(0, min(len(palette)-1, pos))], end="")
    print("")