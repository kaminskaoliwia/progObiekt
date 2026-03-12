#include "SchoolBoy.h"

SchoolBoy::SchoolBoy( string name, int age, string className ) : Pupil( name, age, className )
{
	Pupil::mID = "M_" + mID;

}

void SchoolBoy::printOutfit()
{
	cout << "Biala koszula z krawatem i szkolna marynarka, granatowe/czarne spodnie, polbuty";
}