void myCode(List<String> args) {
  List<List<int>> seen = List.filled(3, List.filled(3, 0));

  seen[0][1] = 1;

  print(seen);
}
