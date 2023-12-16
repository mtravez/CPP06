#include "Data.hpp"

Data::Data() : content("default data content")
{}

Data::Data(Data &data) : content(data.content){}

Data::Data(std::string content) : content(content){}

Data::~Data() {}

Data &Data::operator=(Data &data)
{
	this->content = data.content;
	return *this;
}

void Data::printContent()
{
	std::cout << "This data's content is: " << this->content << std::endl;
}