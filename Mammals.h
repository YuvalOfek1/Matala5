#ifndef MAMMALS_H
#define MAMMALS_H

#include "Animal.h"

class Mammals : virtual public Animal
{
public:
	Mammals();//set the default color to GRAY and other params to 0
	Mammals( const char* color, int childs, float avgLifetime, float preg, float milk );//init the Mammals with a given attributes
	Mammals( ifstream& in_file );//init the Mammals from a binary file
	virtual ~Mammals();

public:
	float		GetPregnanceTime() const;//return the pregnance time of the animal
	float		GetMilk() const;//return the milk liters of the animal
	virtual void SaveBin(ofstream& out_file)const=0;
	virtual void SaveAdditionBin(ofstream& out_file) const;
	virtual void SaveTypeBin(ofstream& out_file) const=0;
	virtual void Save(ofstream& out_file)const;
	virtual void Load(ifstream& in_file) ;
	virtual void SaveAddition(ofstream& out_file) const;
	virtual void LoadAddition(ifstream& in_file);
	virtual void LoadAdditionBin(ifstream& in_file);
protected:
	float m_pregnancyTime;
	float m_milkLiters;
};

#endif // ifndef