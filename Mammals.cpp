#include "Mammals.h"

Mammals::Mammals()
{
    m_milkLiters = 0;
    m_pregnancyTime = 0;
}

Mammals::Mammals(const char* color, int childs, float avgLifetime, float preg, float milk)
{
    m_pregnancyTime = preg;
    m_milkLiters = milk;
}

Mammals::Mammals(ifstream& in_file)
{
    LoadAdditionBin(in_file);
}
void Mammals::SaveBin(ofstream& out_file)const
{
    Animal::SaveBin(out_file);
    Mammals::SaveAdditionBin(out_file);
}   
void Mammals::SaveAdditionBin(ofstream& out_file)const
{
    out_file.write((char*)&m_pregnancyTime, sizeof(m_pregnancyTime));
    out_file.write((char*)&m_milkLiters, sizeof(m_milkLiters));
}

void Mammals::Save(ofstream& out_file)const
{
    Animal::Save(out_file);
    Mammals::SaveAddition(out_file);
}
void Mammals::SaveAddition(ofstream& out_file)const
{
    out_file << m_pregnancyTime << endl;
    out_file<<m_milkLiters << endl;

}
void Mammals::Load(ifstream& in_file)
{
    Animal::Load(in_file);
    Mammals::LoadAddition(in_file);
}
void Mammals::LoadAddition(ifstream& in_file)
{
    in_file >> m_pregnancyTime;
    in_file >> m_milkLiters;
}
void Mammals::LoadAdditionBin(ifstream& in_file)
{
    in_file.read((char*)&m_pregnancyTime, sizeof(m_pregnancyTime));
    in_file.read((char*)&m_milkLiters, sizeof(m_milkLiters));
}
Mammals::~Mammals()
{
}

float Mammals::GetPregnanceTime() const
{
    return m_pregnancyTime;
}

float Mammals::GetMilk() const
{
    return m_milkLiters;
}
