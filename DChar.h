#pragma once
#include <string>
#include <vector>
class DChar
{
public:
    DChar(std::string base, int i);
	DChar(std::string base, std::vector < std::string > is);
    ~DChar();

    bool operator==(const DChar& other) const;

    std::string getBase() const;
    int getDecorations() const;
	std::vector < std::string> getHeaders() const;
    void setDecorations(int i);

    std::string getString() const;

private:
    std::string m_cBase;
	std::vector<std::string> m_vecHeads;
    int m_iDecorations;
};

