#pragma once
#include "lve_window.hpp"
#include "lve_pipeline.hpp"
#include "my_engine_device.hpp"

namespace lve 
{
	class FirstApp 
	{
		public:
			static constexpr int WIDTH = 800;
			static constexpr int HEIGHT = 800;

			void run();
		private:
			LveWindow lveWindow{ WIDTH, HEIGHT, "Vulkan Window" };
			MyEngineDevice device{ lveWindow };
			LvePipeline lvePipeline{device, "simple_shader.vert.spv","simple_shader.frag.spv",LvePipeline::defaultPipelineConfigInfo(WIDTH,HEIGHT)};
	};
}