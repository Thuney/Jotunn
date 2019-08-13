namespace Jotunn
{

	class Application
	{
		public:

			Application();
			virtual ~Application() = default;

			void Run();

			inline static Application& Get() { return *s_Instance; }

		private:

			bool m_Running = true;
			float m_LastFrameTime = 0.0f;

		private:
			static Application* s_Instance;
	};

	Application* CreateApplication();

}