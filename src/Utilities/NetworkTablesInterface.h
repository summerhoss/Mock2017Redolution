/*
 * NetworkTablesInterface.h
 *
 *  Created on: Jan 17, 2017
 *      Author: Dhruti
 */

#ifndef UTILITIES_NETWORKTABLESINTERFACE_H_
#define UTILITIES_NETWORKTABLESINTERFACE_H_

#include "NetworkTables/NetworkTable.h"

class NetworkTablesInterface {
public:
	//NetworkTablesInterface(); NOT REQUIRED
	//virtual ~NetworkTablesInterface(); NOT REQUIRED
	//static bool gearFound(); //checks if the gear has been detected
	//static double getGearDistance(); //gives the distance to the gear
	//static double getGearAltitude(); //gives the altitude for the gear
	//static double getGearAzimsuth(); //gives the azimuth for the gear
	//static bool boilerFound(); //checks if the boiler has been detected
	//static double getBoilerDistance(); //gives the distance to the boiler
	//static double getBoilerAltitude(); //gives the altitude to the boiler
	//static double getBoilerAzimuth(); //gsives the azimuth to the boiler
	static std::string getOrientation();
};

#endif /* UTILITIES_NETWORKTABLESINTERFACE_H_ */
