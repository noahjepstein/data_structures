//-----------------------------------------------------------------------------
// Filename: package.h
// Author:   Noah J. Epstein
// Date: 11/11/2013
//
// Description: Defines a package and a package node. Just structs. No classes.
//
// Agknowledgements: None yet.
//-----------------------------------------------------------------------------

#ifndef PACKAGE_H
#define PACKAGE_H

#include <iostream>
using namespace std;

struct Package
{
    string orderID; //identifying string of a package

    int nUnits; //total units of work that a package has. doesn't change

    double unitsRemaining; //double becuase rate is a double. changes w/ work

    int arrivalTime; //time the package arrived

    int departureTime; //time the package is shipped from the line

    int line; //which line the package is processed on
};

//PackageNode is the elementary structure of a doubly-linked list of packages.
struct PackageNode
{
    Package data;

    PackageNode* next;

    PackageNode* prev;
};

#endif
