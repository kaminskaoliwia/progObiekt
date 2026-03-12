#include "SchoolGirl.h"

SchoolGirl::SchoolGirl( string name, int age, string className ) : Pupil( name, age, className )
{
	Pupil::mID = "F_" + mID;

}

void SchoolGirl::printOutfit()
{
	cout << "Biala bluzka z krawatem i szkolna marynarka, czarna/granatowa spodniczka, plaskie obuwie";
}
