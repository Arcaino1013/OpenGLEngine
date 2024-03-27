#pragma once	
#include "my_engine_device.hpp"
#include <string>
#include <vector>

namespace lve 
{
	struct PipelineConfigInfo 
	{

	};
	class LvePipeline{
	public:
		LvePipeline(
			MyEngineDevice &device, 
			const std::string& verFilePath, 
			const std::string& fragFilePath, 
			const PipelineConfigInfo& configInfo);
		~LvePipeline() {}

		LvePipeline(const LvePipeline&) = delete;
		void operator=(const LvePipeline&) = delete;

		static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);

	private:
		static std::vector<char> readFile(const std::string& filepath);

		static void createGraphicsPipeline(
			const std::string& verFilePath, 
			const std::string& fragFilePath,
			const PipelineConfigInfo& configInfo);

		void createShaderModule(
			const std::vector<char>& code, 
			VkShaderModule* shaderModule);

		MyEngineDevice& myEngineDevice;
		VkPipeline graphicspipeline;
		VkShaderModule vertShaderModule;
		VkShaderModule fragShaderModule;
	};
}