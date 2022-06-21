#include "Mermaid.h"

Mermaid::Mermaid():Animal() 
{
	m_firstName = nullptr;
	m_lastName = nullptr;
}

Mermaid::Mermaid(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, const char* firstName, const char* lastName): Animal(color, childs, avgLifetime),MammalsFish(color, childs, avgLifetime,preg,milk,fin,gills)
{
	m_firstName = new char[strlen(firstName) + 1];
	strcpy(m_firstName, firstName);
	m_lastName = new char[strlen(lastName) + 1];
	strcpy(m_lastName, lastName);
}

Mermaid::Mermaid(ifstream& in_file) : Animal(in_file)
{
	Mammals::LoadAdditionBin(in_file);
	Fish::LoadAdditionBin(in_file);
	LoadAdditionBin(in_file);
}
Mermaid::Mermaid(const Mermaid& other)
{
	Animal::m_avgLifetime = other.m_avgLifetime;
	Animal::m_childCount = other.m_childCount;
	Animal::m_color = new char[strlen(other.m_color) + 1];
	strcpy(Animal::m_color, other.m_color);
	MammalsFish::m_finCount = other.m_finCount;
	MammalsFish::m_gillsCount = other.m_gillsCount;
	MammalsFish::m_milkLiters = other.m_milkLiters;
	MammalsFish::m_pregnancyTime = other.m_pregnancyTime;
	m_firstName = new char[strlen(other.m_firstName) + 1];
	strcpy(m_firstName, other.m_firstName);
	m_lastName = new char[strlen(other.m_lastName) + 1];
	strcpy(m_lastName, other.m_lastName);
   }

Mermaid::~Mermaid()
{
	delete[]m_firstName;
	delete[]m_lastName;
}
void Mermaid::SaveTypeBin(ofstream& out_file)const
{
	out_file.write("Me", 2);
}
void Mermaid::SaveBin(ofstream& out_file)const
{	
	SaveTypeBin(out_file);
	MammalsFish::SaveBin(out_file);
	SaveAdditionBin(out_file);
}
void Mermaid::SaveAdditionBin(ofstream& out_file)const
{
	int n;
	n = strlen(m_firstName);
	out_file.write((char*)&n, sizeof(n));
	out_file.write(m_firstName, n);

	n = strlen(m_lastName);
	out_file.write((char*)&n, sizeof(n));
	out_file.write(m_lastName, n);
}

void Mermaid::Save(ofstream& out_file)const
{
	SaveTypeBin(out_file);
	out_file << endl;
	MammalsFish::Save(out_file);
	SaveAddition(out_file);
}
void Mermaid::SaveAddition(ofstream& out_file)const
{
	out_file << strlen(m_firstName) << endl;
	out_file << m_firstName << endl;
	out_file << strlen(m_lastName) << endl;
	out_file << m_lastName << endl;
}

void Mermaid::Load(ifstream& in_file)
{
	MammalsFish::Load(in_file);
	LoadAddition(in_file);
}

void Mermaid::LoadAddition(ifstream& in_file)
{
	int n;
	in_file >> n;
	m_firstName = new char[n + 1];
	in_file >> m_firstName;
	m_firstName[n] = '\0';
	in_file >> n;
	m_lastName = new char[n + 1];
	in_file >> m_lastName;
	m_lastName[n] = '\0';
}
void Mermaid::LoadAdditionBin(ifstream& in_file)
{
	int first;
	in_file.read((char*)&first, sizeof(first));
	m_firstName = new char[first + 1];
	in_file.read(m_firstName, first);
	m_firstName[first] = '\0';
	int last;
	in_file.read((char*)&last, sizeof(last));
	m_lastName = new char[last + 1];
	in_file.read(m_lastName, last);
	m_lastName[last] = '\0';
}

const char* Mermaid::GetFirstName() const
{
	return m_firstName;
}

const char* Mermaid::GetLastName() const
{
	return m_lastName;
}
