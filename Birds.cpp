#include "Birds.h"

Birds::Birds()
{
	m_incubationTime = 0;
}

Birds::Birds(const char* color, int childs, float avgLifetime, float incubation)
{
	m_incubationTime = incubation;
}
//Birds::Birds(const Birds& other):Animal(other.m_color,other.m_childCount,other.m_avgLifetime)
//{
//	m_incubationTime = other.m_incubationTime;
//}

Birds::Birds(ifstream& in_file)
{
	LoadAddition(in_file);
}

void Birds::SaveBin(ofstream& out_file)const
{
	Animal::SaveBin(out_file);
	SaveAdditionBin(out_file);
}
void Birds::SaveAdditionBin(ofstream& out_file)const
{
	out_file.write((char*)&m_incubationTime, sizeof(m_incubationTime));
}

void Birds::Save(ofstream& out_file)const 
{
	Animal::Save(out_file);
	SaveAddition(out_file);
}
void Birds::SaveAddition(ofstream& out_file)const
{
	out_file << m_incubationTime << endl;
}

void Birds::Load(ifstream& in_file)
{
	Animal::Load(in_file);
	LoadAddition(in_file);
}
void Birds::LoadAddition(ifstream& in_file)
{
	in_file >> m_incubationTime;
}

void Birds::LoadAdditionBin(ifstream& in_file)
{
	in_file.read((char*)&m_incubationTime, sizeof(m_incubationTime));
}
Birds::~Birds()
{
}


float Birds::GetIncubationTime() const
{
	return m_incubationTime;
}
