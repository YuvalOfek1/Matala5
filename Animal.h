#ifndef ANIMAL_H
#define ANIMAL_H

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <typeinfo>
#include <fstream>

using namespace std;

class Animal
{
protected:
	Animal();//set the default color to GRAY and other param's to 0
	Animal( const char* color, int childs, float avgLifetime);//init the Animal with a given attributes
	Animal( ifstream& in_file );//init the Animal from a binary file
	//Animal(const Animal& other);

public:
	virtual ~Animal();

public:
	const char* GetColor() const;//return the color of the animal
	int			GetChildCount() const;//return the child count of the animal
	float		GetLifetime() const;//return the life time of the animal
	virtual void SaveTypeBin(ofstream& out_file)const =0; //Save type - pure virtual function to save the first 2 letters of the object type
	virtual void SaveBin(ofstream& out_file)const; //Save to a binary file
	virtual void SaveAdditionBin(ofstream& out_file) const=0;
	virtual void Save(ofstream& out_file) const;//save to a txt file
	virtual void Load(ifstream& in_file); //load from a txt file
	virtual void SaveAddition(ofstream& out_file) const=0;
	virtual void LoadAddition(ifstream& in_file)=0;
	virtual void LoadAdditionBin(ifstream& in_file) = 0;

protected:
	char*	m_color;
	int		m_childCount;
	float	m_avgLifetime;
};

#endif // ifndef