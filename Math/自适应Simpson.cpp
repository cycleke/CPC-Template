// 计算 \int_a^b f(x) dx
double simpson(double a, double b) {
  double c = a + (b - a) / 2;
  return (f(a) + 4 * f(c) + f(b)) * (b - a) / 6;
}
double integral(double a, double b, double eps, double A) {
  double c = a + (b - a) / 2;
  double L = simpson(a, c), R = simpson(c, b);
  if (fabs(L + R - A) <= 15 * eps) return L + R + (L + R - A) / 15;
  return integral(a, c, eps / 2, L) + integral(c, b, eps / 2, R);
}
double integral(double a, double b, double eps) {
  return integral(a, b, eps, simpson(a, b));
}
