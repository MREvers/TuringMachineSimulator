#pragma once
#include <string>
#include <vector>
class DChar
{
public:
    DChar(char base, int i);
	DChar(char base, std::vector < std::string > is);
    ~DChar();

    bool operator==(const DChar& other) const;

    char getBase() const;
    int getDecorations() const;
	std::vector < std::string> getHeaders() const;
    void setDecorations(int i);

    std::string getString() const;

private:
    char m_cBase;
	std::vector<std::string> m_vecHeads;
    int m_iDecorations;
};

