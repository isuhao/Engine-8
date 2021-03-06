#pragma once
#include "Pickup.hpp"
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

namespace objects
{

	class PickupZone : public Object
	{
	public:
		PickupZone();
		~PickupZone();

		void draw(Layer& renderTarget);
		void update(InputData& inpData);
		void load(boost::property_tree::ptree& dataTree, ResourceManager& rman);

		boost::property_tree::ptree write();

		void changeSeason(const std::string& newSeason);

		Pickup generatePickup(ResourceManager& rman);


	private:

		void createDistribution();
		bool isInBounds(const int& val, const std::pair<int, int>& bound);

		bool displaying;

		Texture tex;

		std::string textureName;


		double yVal;
		double xValLeft;
		double xValRight;
		double thickness;

		sf::Vector2f position;
		sf::Vector2f size;

		std::string seasonName;

		std::map<std::pair<int, int>, std::string> distribution;
		int distrMax;
		double gapDist;

		//ResourceManager* resMan;

	};



}


