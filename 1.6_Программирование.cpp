/****************************
 * Автор:       Руднев Д.А. *
 * Дата:        26.09.2025  *
 * Название:    Вариант 11  *
 * **************************/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
  const double e = 2.718281;

  float indexI;
  float beta;
  float alpha;
  float gamma;
  float time;
  int electromotiveForce;
  float capacity;
  float inductance;
  int resistance;
  int count;

  count = 1;
  cout << "Enter time: ";
  // Время равно 0.001
  cin >> time;
  cout << "Enter electromotiveForce: ";
  // ЭДС рано 12
  cin >> electromotiveForce;

  while (count <= 4) {
    cout << "Enter capacity: ";
    // Задаем емкость: 0,03; 0,03; 0,3; 0,3;
    cin  >> capacity;
    cout << "Enter inductance: ";
    // Задаем индуктивность: 0,6; 6; 0,6; 6;
    cin >> inductance;
    cout << "Enter resistance: ";
    // Задаем сопротивление: 5000; 10000; 5000; 10000;
    cin >> resistance;

    gamma = resistance / (2.0f * inductance);
    alpha = (pow(10, 3) * electromotiveForce * pow(e, (-gamma * time))) / inductance;
    beta = (pow(10, 6) / (inductance * capacity)) - pow(gamma, 2);
   
    if (beta > 0) {
      indexI = (alpha * sin(sqrt(beta) * time)) / sqrt(beta);
      cout << fixed; cout.precision(4);
      cout << "beta = " << beta;
      cout << "\t\tindexI = " << indexI << endl;
    }
    else if (beta < 0) {
      indexI = (alpha * sinh(sqrt(-beta) * time)) / sqrt(-beta);
      cout << fixed; cout.precision(4);
      cout << "beta = " << beta;
      cout << "\t\tindexI = " << indexI << endl;
    }
    count += 1;
  }

  return 0;
}