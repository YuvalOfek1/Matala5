#include "Fish.h"

Fish::Fish()
{
    m_finCount = 0;
    m_gillsCount = 0;
}

Fish::Fish(const char* color, int childs, float avgLifetime, int fin, int gills)
{
    m_finCount = fin;
    m_gillsCount = gills;
}

Fish::Fish(ifstream& in_file)
{
    LoadAddition(in_file);
}
//Fish::Fish(const Fish& other):Animal(other.m_color, other.m_childCount, other.m_avgLifetime)
//{
//    m_finCount = other.m_finCount;
//    m_gillsCount = other.m_gillsCount;
//}
Fish::~Fish()
{
}

int Fish::GetFinCount() const
{
    return m_finCount;
}

int Fish::GetGillsCount() const
{
    return m_gillsCount;
}

void Fish::SaveBin(ofstream& out_file)const
{
    //SaveTypeBin(out_file);
    Animal::SaveBin(out_file);
    SaveAdditionBin(out_file);
}
void Fish::SaveAdditionBin(ofstream& out_file)const
{
    out_file.write((char*)&m_finCount, sizeof(m_finCount));
    out_file.write((char*)&m_gillsCount, sizeof(m_gillsCount));
}

void Fish::Save(ofstream& out_file)const
{
    Animal::Save(out_file);
    SaveAddition(out_file);
}
void Fish::SaveAddition(ofstream& out_file)const
{
    out_file << m_finCount << endl;
    out_file << m_gillsCount << endl;
}

void Fish::LoadAdditionBin(ifstream& in_file)
{
    in_file.read((char*)&m_finCount, sizeof(m_finCount));
    in_file.read((char*)&m_gillsCount, sizeof(m_gillsCount));
}

void Fish::Load(ifstream& in_file)
{
    Animal::Load(in_file);
    LoadAddition(in_file);
}
void Fish::LoadAddition(ifstream& in_file)
{
    in_file >> m_finCount;
    in_file >> m_gillsCount;
}
