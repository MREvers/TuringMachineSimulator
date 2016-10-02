#pragma once
#include <string>
#include <vector>
#include "DChar.h"
#include "DString.h"

enum TRANSITION { STAY = 0, LEFT = -1, RIGHT = 1};

class MachineTape
{
public:
	MachineTape();
	~MachineTape();

	bool performTransform(TRANSITION headMoveMent, DChar* write);

    void setState(std::string szState);
	void setState(DString szState);
    void setHeadPosition(int iHeadPos);

	const DChar& getState() const;
	std::vector<std::string> getDrawState(bool fixed) const;    

private:
	int m_iHeaderPos;
	DString m_szTape;

    bool writeChar(DChar* newRead);
};

