int waterPlants(int plants[], int n, int cap1, int cap2) {
    int can1 = 0;
    int can2 = 0;
    int lo = 0;
    int hi = n-1;
    int numRefills = 0;
  
    while (lo < hi) {
      if (can1 < plants[lo]) {
        can1 = cap1;
        ++numRefills;
      }
      if (can2 < plants[hi]) {
        can2 = cap2;
        ++numRefills;
      }
  
      can1 -= plants[lo++];
      can2 -= plants[hi--];
    }

    if (lo == hi && (plants[lo] > can1 + can2))
      return ++numRefills;
    else
      return numRefills;
}
