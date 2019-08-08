int circleIntersect(LL x1, LL y1, LL x2, LL y2, LL r1, LL r2)  {
    LL distSq = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    LL radSumSq = (r1 + r2) * (r1 + r2);
    if (distSq == radSumSq) return 1; // touches
    else if (distSq > radSumSq) return -1; // does not touch or intersect 
    else return 0; // intersects
}
