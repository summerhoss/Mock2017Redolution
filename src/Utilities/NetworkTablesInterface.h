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
	static std::string getOrientation();
	double getAzimuth();
};

#endif /* UTILITIES_NETWORKTABLESINTERFACE_H_ */
