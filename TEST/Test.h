#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "../Converter/Converter.h"

namespace TEST
{
	void FieldOfView()
	{
		auto DoTest([](const std::vector<std::string>& args) {
			for (const std::string& a : args)
			{
				std::cout << a << " ";
			}

			if (args.size() == 3)
			{
				FOV fov(std::stof(args[2]));

				if (args[0] == "H_FOV")
				{
					std::cout << "V_FOV " << fov.Vertical(std::stof(args[1])) << std::endl;
				}

				if (args[0] == "V_FOV")
				{
					std::cout << "H_FOV " << fov.Horizontal(std::stof(args[1])) << std::endl;
				}
			}
		});

		std::vector<std::string> args{ "V_FOV", "65", "1.6" };
		DoTest(args);
		args = { "H_FOV", "90", "1.6" };
		DoTest(args);
	}

	void CameraObscura()
	{
		auto DoTest([](const std::vector<std::string>& args) {
			for (const std::string& a : args)
			{
				std::cout << a << " ";
			}
			std::cout << std::endl;

			if (args.size() == 3)
			{
				::CameraObscura pinhole(std::stof(args[0]), std::stof(args[1]), std::stof(args[2]));

				std::cout << "H_FOV:" << pinhole.Horizontal() << std::endl;
				std::cout << "V_FOV:" << pinhole.Vertical() << std::endl;
			}
		});

		std::vector<std::string> args{ "30", "35", "1.37" };
		DoTest(args);
		args = { "60", "35", "1.37" };
		DoTest(args);
	}
}