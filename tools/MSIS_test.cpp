// FGMSIS test program


#include "FGMSIS.h"
#include <iostream>
using namespace std;
using namespace JSBSim;


int main(void) {

  int day = 135;           // May 15th UTC
  double sec = 72000.0;    // 2000 hrs UTC
  double alt = 0.0;        // altitude, feet
  double lat = 37.61833;   // geodetic latitude (-90 to 90), KSFO
  double lon = 237.625;    // geodetic longitude (-180 to 180), KSFO

 
  MSIS* msis = new MSIS();
  msis->InitModel();
  msis->Calculate(day, sec, alt, lat, lon);

  cout << "Day: " << day << ", sec: " << sec << ", alt: " << alt << 
          ", lat: " << lat << ", lon: " << lon << "\n";
  cout << "Temperature  (deg C):  " << msis->GetTemperature_C() << "\n";
  cout << "Density (slugs/ft^3):  " << msis->GetDensity_en() << "\n";
  cout << "Pressure (lb/ft^2):    " << msis->GetPressure_en() << "\n";
  
  delete msis;
  return 0;
}