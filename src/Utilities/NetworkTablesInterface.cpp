/*
 * NetworkTablesInterface.cpp
 *
 *  Created on: Jan 17, 2017
 *      Author: Dhruti
 */

#include "NetworkTablesInterface.h"

/*NetworkTablesInterface::NetworkTablesInterface() {
 // TODO Auto-generated constructor stub

 }

 NetworkTablesInterface::~NetworkTablesInterface() {
 // TODO Auto-generated destructor stub
 }*/

std::string NetworkTablesInterface::getOrientation()
{
	return NetworkTable::GetTable("cv")->GetString("orientation", "null");
}

double NetworkTablesInterface::getAzimuth()
{
	return NetworkTable::GetTable("cv")->GetNumber("azimuth",-1.0);
}
