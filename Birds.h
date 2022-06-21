#ifndef BIRDS_H
#define BIRDS_H

#include "Animal.h"

class Birds : virtual public Animal
{
public:
	Birds();//set the default color to GRAY and other params to 0
	Birds( const char* color, int childs, float avgLifetime, float incubation );//init the Birds with a given attributes
	Birds( ifstream& in_file );//init the Birds from a binary file
	//Birds(const Birds& other);
	virtual ~Birds();

public:
	float		GetIncubationTime() const;//return the incubation time of the animal
    virtual void SaveBin(ofstream& out_file)const=0;
	virtual void SaveTypeBin(ofstream& out_file) const= 0;
	virtual void SaveAdditionBin(ofstream& out_file) const;
    virtual void Save(ofstream& out_file) const;
	virtual void SaveAddition(ofstream& out_file) const;
    virtual void Load(ifstream& in_file);
	virtual void LoadAddition(ifstream& in_file);
	virtual void LoadAdditionBin(ifstream& in_file);

protected:
	float m_incubationTime;
};

#endif // ifndef