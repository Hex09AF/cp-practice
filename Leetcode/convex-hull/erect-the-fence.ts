function orient(p: number[], q: number[], r: number[]): number {
    return (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1]);
}

function inBetween(p: number[], i: number[], q: number[]): boolean {
    const a = i[0] >= p[0] && i[0] <= q[0] || i[0] <= p[0] && i[0] >= q[0];
    const b = i[1] >= p[1] && i[1] <= q[1] || i[1] <= p[1] && i[1] >= q[1];
    return a && b;
}

function outerTrees(points: number[][]): number[][] {
    const hull = new Set<number[]>();
    if (points.length < 4) {
        points.forEach(p => {
            hull.add(p);
        });
        return [...hull];
    }
    points.sort((a, b) => a[0] - b[0] || a[1] - b[1]);
    let left_most = 0;
    for (let i = 0; i < points.length; i++)
        if (points[i][0] < points[left_most][0])
            left_most = i;
    let p = left_most;
    do {
        let q = (p + 1) % points.length;
        for (let i = 0; i < points.length; i++) {
            if (orient(points[p], points[i], points[q]) < 0) {
                q = i;
            }
        }
        for (let i = 0; i < points.length; i++) {
            if (i != p && i != q && orient(points[p], points[i], points[q]) == 0 && inBetween(points[p], points[i], points[q])) {
                hull.add(points[i]);
            }
        }
        hull.add(points[q]);
        p = q;
    } while (p != left_most);
    return [...hull];
}
