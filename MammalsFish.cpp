#include "MammalsFish.h"

MammalsFish::MammalsFish()
{
}

MammalsFish::MammalsFish(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills)
{
	Mammals::m_pregnancyTime = preg;
	Mammals::m_milkLiters = milk;
	Fish::m_finCount = fin;
	Fish::m_gillsCount = gills;
}

MammalsFish::MammalsFish(ifstream& in_file)
{
	Mammals::LoadAdditionBin(in_file);
	Fish::LoadAdditionBin(in_file);
}
void MammalsFish::SaveBin(ofstream& out_file)const
{
	Mammals::SaveBin(out_file);
	Fish::SaveAdditionBin(out_file);
}

void MammalsFish::Save(ofstream& out_file)const
{
	Mammals::Save(out_file);
	Fish::SaveAddition(out_file);
}
void MammalsFish::SaveAddition(ofstream& out_file)const
{
}
void MammalsFish::Load(ifstream& in_file)
{
	Mammals::Load(in_file);
	Fish::LoadAddition(in_file);
}
void MammalsFish::LoadAddition(ifstream& in_file)
{
}
void MammalsFish::LoadAdditionBin(ifstream& in_file)
{}
MammalsFish::~MammalsFish()
{
}
