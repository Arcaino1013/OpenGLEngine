#pragma once	
#include <string>
#include <vector>

namespace lve 
{
	class LvePipeline{
	public:
		LvePipeline(const std::string& verFilePath, const std::string& fragFilePath);

	private:
		static std::vector<char> readFile(const std::string& filepath);

		static void createGraphicsPipeline(const std::string& verFilePath, const std::string& fargFilePath);
	};
}