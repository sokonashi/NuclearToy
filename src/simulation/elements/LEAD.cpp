#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);
static int graphics(GRAPHICS_FUNC_ARGS);

void Element::Element_LEAD()
{
	Identifier = "DEFAULT_PT_LEAD";
	Name = "LEAD";
	Colour = PIXPACK(0x617CA9);
	MenuVisible = 1;
	MenuSection = SC_NUCLEAR;
	Enabled = 1;

	// element properties here

	AirLoss = 0.90f;
	Meltable = 1;
	Weight = 100;

	HeatConduct = 100;
	Description = "Neutron absorber with a low melting point.";

	Properties = TYPE_SOLID|PROP_NEUTPASS;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 600.5f;
	HighTemperatureTransition = PT_LAVA;

	Update = &update;
}

static int update(UPDATE_FUNC_ARGS)
{
	if (TYP(sim->photons[y][x]) == PT_NEUT) {
		if (RNG::Ref().chance(1, 4))
			sim->kill_part(ID(sim->photons[y][x]));
	}

	return 0;
}

static int graphics(GRAPHICS_FUNC_ARGS)
{
	// graphics code here
	// return 1 if nothing dymanic happens here

	return 0;
}

