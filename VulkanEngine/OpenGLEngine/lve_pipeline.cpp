#include "lve_pipeline.hpp"
#include <fstream>
#include <iostream>	
#include <stdexcept>

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

	void LvePipeline::createGraphicsPipeline(
		const std::string& verFilePath,
		const std::string& fragFilePath,
		const PipelineConfigInfo& configInfo)
	{
		auto vertCode = readFile(verFilePath);
		auto fragCode = readFile(fragFilePath);

		std::cout << "Vertex Shader Code Size " << vertCode.size() << "\n";
		std::cout << "Fragment Shader Code Size " << fragCode.size() << "\n";

	}

	LvePipeline::LvePipeline(
		MyEngineDevice& device,
		const std::string& verFilePath,
		const std::string& fragFilePath,
		const PipelineConfigInfo& configInfo) : myEngineDevice{device} {
		createGraphicsPipeline(verFilePath, fragFilePath, configInfo);
	}

	void LvePipeline::createShaderModule(const std::vector<char>& code,
		VkShaderModule* shaderModule) 
	{
		VkShaderModuleCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
		createInfo.codeSize = code.size();
		createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());

		if (vkCreateShaderModule(myEngineDevice.device(), &createInfo, nullptr, shaderModule) != VK_SUCCESS) 
		{
			throw std::runtime_error("Failed to create a shader module");
		}
	}
}