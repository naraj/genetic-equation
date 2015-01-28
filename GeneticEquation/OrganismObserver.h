#pragma once

class COrganism;

class COrganismObserver
{
public:
	COrganismObserver();
	~COrganismObserver();

	void vUpdate(long long, const COrganism*);
};

