#include <stdio.h>
#include <math.h>


int main() {
  float v;
  float theta;
  float g = 9.8;
  printf("Enter initial speed v (m/s):\n");
  scanf("%f", &v);
  printf("Enter launch angle theta (radians):\n");
  scanf("%f", &theta);

  float max_height = (v * v * sin(theta) * sin(theta)) / (2 * g);
  float max_flight_time = (2 * v * sin(theta)) / g;

  printf("Maximum Height:\n");
  printf("--Exact: %.2f m\n", max_height);
  printf("--Floor: %.2f m\n", floor(max_height));
  printf("--Ceil : %.2f m\n", ceil(max_height));
  printf("Total Flight Time:\n");
  printf("--Exact: %.2f s\n", max_flight_time);
  printf("--Floor: %.2f s\n", floor(max_flight_time));
  printf("--Ceil : %.2f s\n", ceil(max_flight_time));
  return 0;
}