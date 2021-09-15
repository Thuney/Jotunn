#pragma once

#define SPDLOG_FMT_EXTERNAL

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Jotunn
{
	/**
	 * @brief Stores static instances of spdlog::logger objects for the engine (core) and the client
	 * Allow for simple printing of formatted and colored console output.
	 */
	class Log
	{
		public:
			static void Init();

			inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
			inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
		
		private:
			//Loggers for the engine (core) and the client
			static std::shared_ptr<spdlog::logger> s_CoreLogger;
			static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Core log macros
#define JOTUNN_CORE_TRACE(...)    ::Jotunn::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define JOTUNN_CORE_INFO(...)     ::Jotunn::Log::GetCoreLogger()->info(__VA_ARGS__)
#define JOTUNN_CORE_WARN(...)     ::Jotunn::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define JOTUNN_CORE_ERROR(...)    ::Jotunn::Log::GetCoreLogger()->error(__VA_ARGS__)
#define JOTUNN_CORE_CRITICAL(...) ::Jotunn::Log::GetCoreLogger()->critical(__VA_ARGS__)

//Client log macros
#define JOTUNN_TRACE(...)         ::Jotunn::Log::GetClientLogger()->trace(__VA_ARGS__)
#define JOTUNN_INFO(...)          ::Jotunn::Log::GetClientLogger()->info(__VA_ARGS__)
#define JOTUNN_WARN(...)          ::Jotunn::Log::GetClientLogger()->warn(__VA_ARGS__)
#define JOTUNN_ERROR(...)         ::Jotunn::Log::GetClientLogger()->error(__VA_ARGS__)
#define JOTUNN_CRITICAL(...)      ::Jotunn::Log::GetClientLogger()->critical(__VA_ARGS__)