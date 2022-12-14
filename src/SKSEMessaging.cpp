#include "SKSEMessaging.h"

namespace SKSE::Messaging
{
	namespace detail
	{
		class SKSEListener
		{
		public:
			using Callback = SKSE::MessagingInterface::EventCallback;
			using Message = SKSE::MessagingInterface::Message;

			static SKSEListener&	Get();

			void	OnMessage(Message* a_msg);
			bool	AddCallback(Callback* a_callback);

		private:
			bool	Init();

			bool					initialized{false};
			std::vector<Callback*>	callbacks;
		};

		SKSEListener& SKSEListener::Get() {
			static SKSEListener listener;
			return listener;
		}

		void SKSEListener::OnMessage(Message* a_msg) {
			for(auto& cb: callbacks) {
				cb(a_msg);
			}
		}

		bool SKSEListener::AddCallback(Callback* a_callback) {
			if (!a_callback) {
				return false;
			}

			if (!initialized && !Init()) {
				return false;
			}

			callbacks.push_back(a_callback);

			return true;
		}

		bool SKSEListener::Init() {
			if (!initialized) {
				initialized = SKSE::GetMessagingInterface()->RegisterListener("SKSE", [](Message* a_msg) {
					SKSEListener::Get().OnMessage(a_msg);
				});
			}

			return initialized;
		}
	}

	bool RegisterForSKSE(SKSE::MessagingInterface::EventCallback* a_callback) {
		return detail::SKSEListener::Get().AddCallback(a_callback);
	}
}