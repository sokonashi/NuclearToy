#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);
static int graphics(GRAPHICS_FUNC_ARGS);

void Element::Element_THOR()
{
	Identifier = "DEFAULT_PT_THOR";
	Name = "THOR";
	Colour = PIXPACK(0x7069F5);
	MenuVisible = 1;
	MenuSection = SC_NUCLEAR;
	Enabled = 1;

	Advection = 0.4f;
	AirDrag = 0.01f * CFDS;
	AirLoss = 0.99f;
	Loss = 0.95f;
	Collision = 0.0f;
	Gravity = 0.4f;
	Diffusion = 0.00f;
	HotAir = 0.000f	* CFDS;
	Falldown = 1;

	Flammable = 0;
	Explosive = 0;
	Meltable = 0;
	Hardness = 0;
	PhotonReflectWavelengths = 0x003FC000;

	Weight = 50;

	DefaultProperties.temp = R_TEMP + 30.0f + 273.15f;
	HeatConduct = 300;
	Description = "Thorium. Can be breeded into URAN.";

	Properties = TYPE_PART | PROP_RADIOACTIVE | PROP_NEUTPASS;

	Update = &update;
}

static int update(UPDATE_FUNC_ARGS)
{
	if (!sim->legacy_enable && sim->pv[y/CELL][x/CELL]>0.0f) {
		if (parts[i].temp == MIN_TEMP) {
			parts[i].temp += 0.005f;
		} else {
		//	if (RNG::Ref().chance(1, 300) && RNG::Ref().chance(5.0*sim->pv[y/CELL][x/CELL], 5000))
		//		sim->create_part(i, x, y, PT_NEUT);

			parts[i].temp = restrict_flt((parts[i].temp*(1 + (sim->pv[y/CELL][x/CELL]/5000))) + MIN_TEMP, MIN_TEMP, MAX_TEMP);
		}
	}

	return 0;
}

