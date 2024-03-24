#include "lve_pipeline.hpp"
#include <fstream>
#include <iostream>	

namespace lve{
	std::vector<char> LvePipeline::readFile(const std::string& filepath) 
	{
		std::ifstream file{ filepath,std::ios::ate | std::ios::binary };

		if (!file.is_open())
		{
			throw std::runtime_error("Failed to open file : " + filepath);
		}

		size_t fileSize = static_cast<size_t>(file.tellg());
		std::vector<char> buffer(fileSize);

		file.seekg(0);
		file.read(buffer.data(), fileSize);

		file.close();
		return buffer;
	}

	void LvePipeline::createGraphicsPipeline(const std::string& verFilePath, const std::string& fragFilePath) 
	{
		auto vertCode = readFile(verFilePath);
		auto fragCode = readFile(fragFilePath);

		std::cout << "Vertex Shader Code Size " << vertCode.size() << "\n";
		std::cout << "Fragment Shader Code Size " << fragCode.size() << "\n";

	}

	LvePipeline::LvePipeline(const std::string& verFilePath, const std::string& fragFilePath) 
	{
		createGraphicsPipeline(verFilePath, fragFilePath);
	}
}