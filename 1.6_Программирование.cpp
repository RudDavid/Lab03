/****************************
 * Автор:       Руднев Д.А. *
 * Дата:        30.09.2025  *
 * Название:    Вариант 11  *
 * **************************/

#include <iostream>
#include <cmath>

using namespace std;

const double e = 2.718281;

int main() {
  double indexI;
  double beta;
  double alpha;
  double gamma;
  double time;
  double electromotiveForce;
  double capacity;
  double inductance;
  double resistance;
  double count;
  double border;

  count = 1.0;
  border = 4.0;
  cout << "Enter time: ";
  // Время равно 0.001
  cin >> time;
  cout << "Enter electromotiveForce: ";
  // ЭДС рано 12
  cin >> electromotiveForce;

  for (count = 1.0; count <= border; ++count) {
    cout << "Enter capacity: ";
    // Задаем емкость: 0,03; 0,03; 0,3; 0,3;
    cin  >> capacity;
    cout << "Enter inductance: ";
    // Задаем индуктивность: 0,6; 6; 0,6; 6;
    cin >> inductance;
    cout << "Enter resistance: ";
    // Задаем сопротивление: 5000; 10000; 5000; 10000;
    cin >> resistance;

    gamma = resistance / (2.0 * inductance);
    alpha = (pow(10.0, 3.0) * electromotiveForce * pow(e, (-gamma * time))) / inductance;
    beta = (pow(10.0, 6.0) / (inductance * capacity)) - pow(gamma, 2.0);
   
    if (beta > 0) {
      indexI = (alpha * sin(sqrt(beta) * time)) / sqrt(beta);
      cout << fixed; cout.precision(4);
      cout << "beta = " << beta;
      cout << "\t\tindexI = " << indexI << endl;
    }
    if (beta < 0) {
      indexI = (alpha * sinh(sqrt(-beta) * time)) / sqrt(-beta);
      cout << fixed << cout.precision(border) 
      << "beta = " << beta
      << "\t\tindexI = " << indexI << endl;
    }
    
  }
  return 0;
}
