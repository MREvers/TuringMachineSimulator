#pragma once
#include <string>
class DChar
{
public:
    DChar(char base, int i);
    ~DChar();

    bool operator==(const DChar& other) const;

    char getBase() const;
    int getDecorations() const;
    void setDecorations(int i);

    std::string getString() const;

private:
    char m_cBase;
    int m_iDecorations;
};

