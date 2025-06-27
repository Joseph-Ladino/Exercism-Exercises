#if !defined(ROBOT_NAME_H)
#define ROBOT_NAME_H
#include <string>
#include <random>

namespace robot_name {

	struct robot {
		private:
			std::string n;
		
		public:
			void reset();
			std::string name() const;
		
		robot();
	};

}  // namespace robot_name

#endif // ROBOT_NAME_H