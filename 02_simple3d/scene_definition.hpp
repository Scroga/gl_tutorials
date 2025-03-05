#pragma once

#include <memory>
#include <vector>
#include <ranges>

#include "scene_object.hpp"
#include "cube.hpp"

#include "material_factory.hpp"
#include "geometry_factory.hpp"
#include "simple_scene.hpp"


inline SimpleScene createCubeScene(MaterialFactory &aMaterialFactory, GeometryFactory &aGeometryFactory) {
	SimpleScene scene;
	//auto cube1 = std::make_shared<Cube>();
	//cube1->setName("CUBE");
	//cube1->addMaterial(
	//	"solid",
	//	MaterialParameters(
	//		"solid_color",
	//		RenderStyle::Solid,
	//		{
	//			{ "u_solidColor", glm::vec4(1.0f, 0.5f, 0.0f, 1.0f)}
	//		})
	//	);
	//cube1->prepareRenderData(aMaterialFactory, aGeometryFactory);
	//cube1->setRotation(glm::quat(glm::vec3(0.0f, glm::radians(45.0f), 0.0f)));
	//scene.addObject(cube1);

	int cubeCount = 20;
	for (int i = 1; i < cubeCount + 1; i++) {
		for (int j = 1; j < cubeCount + 1; j++) {
			Cube cube;
			cube.setName("Cube" + i + ':' + j);
			cube.setPosition(glm::uvec3(i - 1, j - 1, (float)cubeCount));
			cube.addMaterial(
				"solid",
				MaterialParameters(
					"solid_color",
					RenderStyle::Solid,{
						{ "u_solidColor", glm::vec4(1.0f / i, 1.0f / j, 0.0f, 1.0f)}
					}));
			cube.prepareRenderData(aMaterialFactory, aGeometryFactory);
			scene.addObject(std::make_shared<Cube>(cube));
		}
	}

	return scene;
}
