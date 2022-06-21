#include "Horse.h"

Horse::Horse():Mammals(), Animal()
{
	m_type = nullptr;
}

Horse::Horse(const char* color, int childs, float avgLifetime, float preg, float milk, const char* type):Animal(color,childs,avgLifetime)
{
	Mammals::m_pregnancyTime = preg;
	Mammals::m_milkLiters = milk;
	m_type = new char[strlen(type) + 1];
	strcpy(m_type, type);
}
Horse::Horse(const Horse& other)
{
	Animal::m_color = new char[strlen(other.m_color) + 1];
	strcpy(Animal::m_color, other.m_color);
	Animal::m_childCount = other.m_childCount;
	Animal::m_avgLifetime = other.m_avgLifetime;
	Mammals::m_pregnancyTime = other.m_pregnancyTime;
	Mammals::m_milkLiters = other.m_milkLiters;
	m_type = new char[strlen(other.m_type) + 1];
	strcpy(m_type, other.m_type);
}
Horse::Horse(ifstream& in_file):Animal(in_file),Mammals(in_file)
{
	//Mammals::LoadAdditionBin(in_file);
	LoadAdditionBin(in_file);
}


void Horse::SaveTypeBin(ofstream& out_file)const
{
	out_file.write("Ho", 2);
}

void Horse::SaveBin(ofstream& out_file)const
{
	SaveTypeBin(out_file);
	Mammals::SaveBin(out_file);
	SaveAdditionBin(out_file);
}

void Horse::SaveAdditionBin(ofstream& out_file)const
{
	int size = strlen(m_type);
	out_file.write((char*)&size, sizeof(size));
	out_file.write(m_type, size);
}
void Horse::Save(ofstream& out_file)const
{
	SaveTypeBin(out_file);
	out_file << endl;
	Mammals::Save(out_file);
	SaveAddition(out_file);
}
void Horse::SaveAddition(ofstream& out_file)const
{
	out_file << strlen(m_type) << endl;
	out_file << m_type << endl;
}

void Horse::Load(ifstream& in_file)
{
	Mammals::Load(in_file);
	LoadAddition(in_file);
}

void Horse::LoadAdditionBin(ifstream& in_file)
{
	int n;
	in_file.read((char*)&n, sizeof(n)); //the m_type
	m_type = new char[n + 1];
	in_file.read(m_type, n);
	m_type[n] = '\0';
}

void Horse::LoadAddition(ifstream& in_file)
{
	int n=0;
	char buffer[50];
	in_file >> n;
	m_type = new char[n + 1];
	in_file.getline(buffer, 10);
	in_file.getline(m_type, n+1);
	m_type[n] = '\0';
}

Horse::~Horse()
{
	delete[]m_type;
}

const char* Horse::GetType() const
{
	return m_type;
}
