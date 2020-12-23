#pragma once
//tabtenn0.h-- a table-tennis base class
//simple base class
class TableTennisPlayer {
private:
	enum{LIM = 20};
	char firstname[LIM];
	char lastname[LIM];
	bool hasTable;

public:
	TableTennisPlayer(const char* fn = "none",
		const char* ln = "none", bool ht = false);
	void Name()const;
	bool HasTable() { return hasTable; };
	void ResetTable(bool v) { hasTable = v; };
};