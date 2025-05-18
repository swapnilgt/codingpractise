List<List<int>> initIntegerMatrix(int numRows, int numCols, int defaultVal) {
  return List.generate(numRows, (_) => List.filled(numCols, defaultVal));
}
