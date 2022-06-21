#include "Flamingo.h"

Flamingo::Flamingo():Birds()
{
	m_avgHeight = 0;
}

Flamingo::Flamingo(const char* color, int childs, float avgLifetime, float incubation, float avgHeight):Animal(color,childs,avgLifetime)
{
	Birds::m_incubationTime = incubation;
	m_avgHeight = avgHeight;
}

Flamingo::Flamingo(ifstream& in_file):Animal(in_file)
{
	Birds::LoadAdditionBin(in_file);
	LoadAdditionBin(in_file);
}
Flamingo::Flamingo(const Flamingo& other) :Animal(other.m_color, other.m_childCount,other.m_avgLifetime), Birds(other.m_color, other.m_childCount, other.m_avgLifetime, other.m_incubationTime)
{
	m_avgHeight = other.m_avgHeight;
}
Flamingo::~Flamingo()
{
}

void Flamingo::SaveBin(ofstream& out_file)const
{
	SaveTypeBin(out_file);
	Birds::SaveBin(out_file);
	SaveAdditionBin(out_file);
}

void Flamingo::SaveAdditionBin(ofstream& out_file)const
{
	out_file.write((char*)&m_avgHeight, sizeof(m_avgHeight));
}
void Flamingo::SaveTypeBin(ofstream& out_file)const
{
	out_file.write("Fl", 2);
}
void Flamingo::Save(ofstream& out_file)const
{
	SaveTypeBin(out_file);
	out_file << endl;
	Birds::Save(out_file);
	SaveAddition(out_file);
}
void Flamingo::SaveAddition(ofstream& out_file)const
{
	out_file << m_avgHeight << endl;
}

void Flamingo::Load(ifstream& in_file)
{
	Birds::Load(in_file);
	LoadAddition(in_file);
}
void Flamingo::LoadAddition(ifstream& in_file)
{
	in_file >> m_avgHeight;
}
void Flamingo::LoadAdditionBin(ifstream& in_file)
{
	in_file.read((char*)&m_avgHeight, sizeof(m_avgHeight));
}

float Flamingo::GetHeight() const
{
	return m_avgHeight;
}
