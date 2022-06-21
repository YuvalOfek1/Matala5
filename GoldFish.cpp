#include "GoldFish.h"

GoldFish::GoldFish()
{
	m_avgLength = 0;
	m_avgWeight = 0;
}

GoldFish::GoldFish(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, float avgW, float avgL):Animal(color,childs,avgLifetime), MammalsFish(color,childs,avgLifetime,preg,milk,fin,gills)
{
	m_avgWeight = avgW;
	m_avgLength = avgL;
}

GoldFish::GoldFish(ifstream& in_file):Animal(in_file)
{
	Mammals::LoadAdditionBin(in_file);
	Fish::LoadAdditionBin(in_file);
	LoadAdditionBin(in_file);
}
GoldFish::GoldFish(const GoldFish& other)
{
	Animal::m_avgLifetime = other.m_avgLifetime;
	Animal::m_childCount = other.m_childCount;
	Animal::m_color = new char[strlen(other.m_color) + 1];
	strcpy(Animal::m_color, other.m_color);
	MammalsFish::m_finCount = other.m_finCount;
	MammalsFish::m_gillsCount = other.m_gillsCount;
	MammalsFish::m_milkLiters = other.m_milkLiters;
	MammalsFish::m_pregnancyTime = other.m_pregnancyTime;
	m_avgLength = other.m_avgLength;
	m_avgWeight = other.m_avgWeight;
}
void GoldFish::SaveBin(ofstream& out_file)const
{
	SaveTypeBin(out_file);
	MammalsFish::SaveBin(out_file);
	SaveAdditionBin(out_file);
}

void GoldFish::SaveAdditionBin(ofstream& out_file)const
{
	out_file.write((char*)&m_avgWeight, sizeof(m_avgWeight));
	out_file.write((char*)&m_avgLength, sizeof(m_avgLength));
}
void GoldFish::SaveTypeBin(ofstream& out_file)const
{
	out_file.write("Go", 2);
}

void GoldFish::Save(ofstream& out_file)const
{
	SaveTypeBin(out_file);
	out_file << endl;
	MammalsFish::Save(out_file);
	SaveAddition(out_file);
}
void GoldFish::SaveAddition(ofstream& out_file)const
{
	out_file << m_avgWeight << endl;
	out_file << m_avgLength << endl;
}

void GoldFish::Load(ifstream& in_file)
{
	MammalsFish::Load(in_file);
	LoadAddition(in_file);
}
void GoldFish::LoadAddition(ifstream& in_file)
{
	in_file >> m_avgWeight;
	in_file >> m_avgLength;
}
void GoldFish::LoadAdditionBin(ifstream& in_file)
{
	in_file.read((char*)&m_avgWeight, sizeof(m_avgWeight));
	in_file.read((char*)&m_avgLength, sizeof(m_avgLength));
}

GoldFish::~GoldFish()
{
}

float GoldFish::GetWeight() const
{
	return m_avgWeight;
}

float GoldFish::GetLength() const
{
	return m_avgLength;
}
