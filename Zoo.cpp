#include "Zoo.h"
#include "Mermaid.h"
#include "GoldFish.h"
#include "Fish.h"
#include "Flamingo.h"
#include "Horse.h"


Zoo::Zoo() //default custructor - all memberes initialized to 0 or nullptr
{
    m_numOfAnimals = 0;
    m_name = nullptr;
    m_address = nullptr;
    m_ticketPrice = 0;
    m_closeHours = nullptr;
    m_openHours = nullptr;
    m_animals = nullptr;
}

Zoo::Zoo(const char* name, const char* address, float ticket, const char* open, const char* close)//c'tor with data - init class
{
    m_numOfAnimals = 0;
    m_name = new char[strlen(name) + 1];
    strcpy(m_name, name);
    m_address = new char[strlen(address) + 1];
    strcpy(m_address, address);
    m_ticketPrice = ticket;
    m_openHours = new char[strlen(open) + 1];
    strcpy(m_openHours, open);
    m_closeHours = new char[strlen(close) + 1];
    strcpy(m_closeHours, close);
    m_animals = nullptr;
}

Zoo::Zoo(ifstream& in_file)//c'tor that gets a binary file and loads the data of the zoo from the file
{
    int n;
    char type[2] = {0};
    //read the name
    in_file.read((char*)&n, sizeof(n));
    m_name = new char[n + 1];
    in_file.read(m_name, n);
    m_name[n] = '\0';

    //read the address
    in_file.read((char*)&n, sizeof(n));
    m_address = new char[n + 1];
    in_file.read(m_address, n);
    m_address[n] = '\0';

    //read the ticket price
    in_file.read((char*)&m_ticketPrice, sizeof(m_ticketPrice));

    //read the open hours
    in_file.read((char*)&n, sizeof(n));
    this->m_openHours = new char[n + 1];
    in_file.read(this->m_openHours, n);
    m_openHours[n] = '\0';

    //read the close hours
    in_file.read((char*)&n, sizeof(n));
	this->m_closeHours = new char[n + 1];
	in_file.read(this->m_closeHours, n);
    m_closeHours[n] = '\0';

    //read the numof animals
	in_file.read((char*)&m_numOfAnimals, sizeof(m_numOfAnimals));

    //read the whole animals
    this->m_animals = new Animal * [m_numOfAnimals];
    for (int i = 0; i < m_numOfAnimals; i++)
    {
        in_file.read(type, 2);
        if (strncmp(type, typeid(Flamingo).name() + 1, 2) == 0)
            m_animals[i] = new Flamingo(in_file);
        else if (strncmp(type, typeid(GoldFish).name() + 1, 2) == 0)
            m_animals[i] = new GoldFish(in_file);
        else if (strncmp(type, typeid(Horse).name() + 1, 2) == 0)
            m_animals[i] = new Horse(in_file);
        else if (strncmp(type, typeid(Mermaid).name() + 1, 2) == 0)
            m_animals[i] = new Mermaid(in_file);
    }


}
Zoo::~Zoo()//d'tor
{
    delete[] m_name; 
    delete[]m_address;
    delete[]m_closeHours;
    delete[]m_openHours;
    /*for (int i = 0; i < m_numOfAnimals; i++)
        if(m_animals[i]!=nullptr)
            delete (m_animals[i]);
    delete[]m_animals;*/
}


//gets the zoo name
const char* Zoo::GetName() const
{
	return m_name;
}



const char* Zoo::GetAddress() const
{
    return m_address;
}

float Zoo::GetTicketPrice() const
{
    return m_ticketPrice;
}

const char* Zoo::GetOpenHour() const
{
    return m_openHours;
}

const char* Zoo::GetCloseHour() const
{
    return m_closeHours;
}

int Zoo::GetNumOfAnimals() const
{
    return m_numOfAnimals;
}

Animal** Zoo::GetAnimals() const
{
    return m_animals;
}

void Zoo::AddAnimal(Animal* an)
{
    Animal** temp = new Animal * [m_numOfAnimals + 1];
    for (int i = 0; i < m_numOfAnimals; i++)
        temp[i] = m_animals[i];
    /*if (typeid(*an) == typeid(Fish))
    {
        Fish* fish = dynamic_cast<Fish*>(an);
        if (fish)
            temp[m_numOfAnimals] = new Fish(*fish);
    }*/
    if (typeid(*an) == typeid(Flamingo))
    {
        Flamingo* flamingo = dynamic_cast<Flamingo*>(an);
        if (flamingo)
            temp[m_numOfAnimals] = new Flamingo(*flamingo);
    }
    else if (typeid(*an) == typeid(GoldFish))
    {
        GoldFish* goldfish = dynamic_cast<GoldFish*>(an);
        if (goldfish)
            temp[m_numOfAnimals] = new GoldFish(*goldfish);
    }
    else if (typeid(*an) == typeid(Horse))
    {
        Horse* horse = dynamic_cast<Horse*>(an);
        if (horse)
            temp[m_numOfAnimals] = new Horse(*horse);
    }
    else if (typeid(*an) == typeid(Mermaid))
    {
        Mermaid* mermaid = dynamic_cast<Mermaid*>(an);
        if (mermaid)
        {
            temp[m_numOfAnimals] = new Mermaid(*mermaid);
        }
    }
    m_numOfAnimals++;
    m_animals = temp;
}

Zoo& Zoo::operator+=(Animal* other)
{
    AddAnimal(other);
    return *this;
}

Zoo& Zoo::operator+(Animal* an)
{
    Animal** temp = new Animal * [this->m_numOfAnimals + 1];
    for (int i = 0; i < m_numOfAnimals; i++)
    {
        temp[i] = m_animals[i];
    }
    temp[m_numOfAnimals] = an;
    m_numOfAnimals++;
    m_animals = temp;
    return *this;
}

Zoo Zoo::operator+(const Zoo& other) const
{
    Zoo* temp = new Zoo(m_name, m_address, m_ticketPrice, m_openHours, m_closeHours);
    temp->m_numOfAnimals = 0;
    temp->m_animals = new Animal * [temp->m_numOfAnimals];
    for (int i = 0; i < m_numOfAnimals; i++)
        temp->AddAnimal (m_animals[i]);
    for (int i = 0; i < other.m_numOfAnimals; i++)
        temp->AddAnimal(other.m_animals[i]);
    return *temp;
}

void Zoo::Save(ofstream& ofs) const
{
    ofs << m_name << endl;
    ofs << m_address << endl;
    ofs << m_openHours << endl;
    ofs << m_closeHours << endl;
    ofs << m_ticketPrice << endl;
    ofs << m_numOfAnimals << endl;
    for (int i = 0; i < m_numOfAnimals; i++)
        m_animals[i]->Save(ofs);
}

void Zoo::Load(ifstream& ifs)
{
    char type[3];
    //name
    char buffer[150];
    ifs.getline(buffer, 150);
    m_name = new char[strlen(buffer) + 1];
    strcpy(m_name, buffer);
    m_name[strlen(buffer)] = '\0';
    //address
    ifs.getline(buffer, 150);
    m_address = new char[strlen(buffer) + 1];
    strcpy(m_address, buffer);
    m_address[strlen(buffer)] = '\0';
    //open hours
    ifs.getline(buffer, 150);
    m_openHours = new char[strlen(buffer) + 1];
    strcpy(m_openHours, buffer);
    m_openHours[strlen(buffer)] = '\0';
    //close hours
    ifs.getline(buffer, 150);
    m_closeHours = new char[strlen(buffer) + 1];
    strcpy(m_closeHours, buffer);
    m_closeHours[strlen(buffer)] = '\0';
    ifs >> m_ticketPrice;
    ifs >> m_numOfAnimals;
    m_animals = new Animal * [m_numOfAnimals];
    for (int i = 0; i < m_numOfAnimals; i++)
    {
        ifs>>type;
        if (strncmp(type, typeid(Flamingo).name() + 1, 2) == 0)
            m_animals[i] = new Flamingo();
        else if (strncmp(type, typeid(GoldFish).name() + 1, 2) == 0)
            m_animals[i] = new GoldFish();
        else if (strncmp(type, typeid(Horse).name() + 1, 2) == 0)
        {
            m_animals[i] = new Horse();
        }
        else if (strncmp(type, typeid(Mermaid).name() + 1, 2) == 0)
            m_animals[i] = new Mermaid();
        m_animals[i]->Load(ifs);
    }

}

void Zoo::SaveBin(ofstream& ofs) const
{
    int n;
    //name
    n = strlen(m_name);
    ofs.write((char*)&n, sizeof(n));
    ofs.write(m_name, n);
    //address
    n = strlen(m_address);
    ofs.write((char*)&n, sizeof(n));
    ofs.write(m_address, n);
    //ticket price
    ofs.write((char*)&m_ticketPrice, sizeof(m_ticketPrice));
    //open hours
    n = strlen(m_openHours);
    ofs.write((char*)&n, sizeof(n));
    ofs.write(m_openHours, n);
    //close hours
    n = strlen(m_closeHours);
    ofs.write((char*)&n, sizeof(n));
    ofs.write(m_closeHours, n);
    //numbers of animals
    ofs.write((char*)&m_numOfAnimals, sizeof(m_numOfAnimals));
    //all of the animals
    for (int i = 0; i < m_numOfAnimals; i++)
        m_animals[i]->SaveBin(ofs);
}

//writes to the file
ofstream& operator<<(ofstream& out, const Zoo& z)
{
    z.Save(out);
    return out;
}
//loads from the file
ifstream& operator>>(ifstream& in, Zoo& z)
{
    z.Load(in);
    return in;
    // // O: insert return statement here
}
