#include "Animal.h"
#include <string>

Animal::Animal():m_color((char*)"GRAY")
{
	m_childCount = 0;
	m_avgLifetime = 0;
}

Animal::Animal(const char* color, int childs, float avgLifetime)
{
	m_color = new char[strlen(color) + 1];
	strcpy(m_color, color);
	m_childCount = childs;
	m_avgLifetime = avgLifetime;
}

Animal::Animal(ifstream& in_file)
{
	int n;
	in_file.read((char*)&n, sizeof(n));
	m_color = new char[n + 1];
	in_file.read(m_color, n);
	m_color[n] = '\0';
	//reads the lifetime
	in_file.read((char*)&m_avgLifetime, sizeof(m_avgLifetime));
	//reads the children count
	in_file.read((char*)&m_childCount, sizeof(m_childCount));
 }

void Animal::SaveBin(ofstream& out_file)const
{
	int n = strlen(m_color);
	out_file.write((char*)&n, sizeof(n));
	out_file.write(m_color, n);
	out_file.write((char*)&m_avgLifetime, sizeof(m_avgLifetime));
	out_file.write((char*)&m_childCount, sizeof(m_childCount));
}

void Animal::Save(ofstream& out_file) const
{
	int n = strlen(m_color);
	out_file<<n<<endl;
	out_file << m_color << endl;
	out_file << m_childCount << endl;
	out_file << m_avgLifetime << endl;
}

//loads from a txt file
void Animal::Load(ifstream& in_file)
{
	int n;
	in_file >> n;
	m_color = new char[n + 1];
	in_file >> m_color;
	m_color[n] = '\0';
	//reads the children count
	in_file >> m_childCount;
	//reads the lifetime
	in_file >> m_avgLifetime;
}
//void Animal::Load(ifstream& in_file)
//{
//	int n=0;
//	in_file >> n;
//	m_color = new char[n + 1];
//	in_file >> m_color;
//	m_color[n] = '\0';
//	in_file >> m_childCount;
//	in_file >> m_avgLifetime;
//}

Animal::~Animal()
{
	if (m_color != "GRAY")
		delete[] m_color;
}

const char* Animal::GetColor() const
{
	return m_color;
}

int Animal::GetChildCount() const
{
	return m_childCount;
}

float Animal::GetLifetime() const
{
	return m_avgLifetime;
}
